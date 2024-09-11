#include <cstdlib>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include "function.h"
#include <plotter.h>

using namespace std;

inline void LennardJones(const double r[3], double f[3])
{
  double r2 = sqr(r[0])+sqr(r[1])+sqr(r[2]);
  double fc = 24 * (2 * pow(r2, -7) - pow(r2, -4));
  f[0] = r[0]*fc;
  f[1] = r[1]*fc;
  f[2] = r[2]*fc;
}

void Force(const function2D<double>& r, function2D<double>& a)
{
  a=0;
  for (int i=0; i<r.size_N()-1; i++)     // loop over all distinct pairs i,j
    for (int j=i+1; j<r.size_N(); j++){ 
      double rij[3], fij[3];            // position of i relative to j and force
      for (int k=0; k<3; k++) rij[k] = r(i,k) - r(j,k);
      LennardJones(rij,fij);
      for (int k=0; k < 3; k++) {
	a[i][k] += fij[k];
	a[j][k] -= fij[k];
      }
    }
}

void Initialize(double L, double Vmax, function2D<double>& r, function2D<double>& v)
{
  int N = r.size_N();
  int n = int(ceil(pow(N, 1./3.))); // number of atoms in each direction
  double a0 = L/n;                  // lattice spacing
  // initialize positions
  int p = 0; // particles are not placed close to the boundary but rather 0.5*a0 from the boundary!                        
  for (int ix = 0; ix < n; ix++) 
    for (int iy = 0; iy < n; iy++) 
      for (int iz = 0; iz < n; iz++) {
	if (p < N) {
	  r(p,0) = (ix + 0.5) * a0;
	  r(p,1) = (iy + 0.5) * a0;
	  r(p,2) = (iz + 0.5) * a0;
	}
	++p;
      }
  
  // initialize velocities
  for (int p = 0; p < N; p++)
    for (int i = 0; i < 3; i++)
      v(p,i) = Vmax * (2 * drand48()-1);
}

// Velocity-Verlet algorithm written for very general system of variables
template <class storage, class functor>
void velocityVerlet(int N, int M, double dh, storage& r, storage& v, storage& a, functor& F)
{
  F(r,a);// Computes acceleration "a" using function "F" which depends solely on posions "r".
  for (int i=0; i<N; i++){
    for (int k=0; k<M; k++){
      v[i][k] += 0.5*a[i][k]*dh;
      r[i][k] += v[i][k]*dh;
    }
  }
  F(r,a);
  for (int i=0; i<N; i++)
    for (int k=0; k<M; k++)
      v[i][k] += 0.5*a[i][k]*dh;
}

double instantaneousTemperature(function2D<double>& v){
  double sum = 0;
  for (int i=0; i<v.size_N(); i++)
    for (int k=0; k<v.size_Nd(); k++)
      sum += sqr(v[i][k]);
  return sum/(3*(v.size_N() - 1));
}

void Print(const function2D<double>& r, const function2D<double>& v, const function2D<double>& a)
{
  using namespace std;
  for (int i=0; i<r.size_N(); i++){
    cout<<setw(25)<<r(i,0)<<" "<<setw(25)<<r(i,1)<<" "<<setw(25)<<r(i,2)<<"    ";
    cout<<setw(25)<<v(i,0)<<" "<<setw(25)<<v(i,1)<<" "<<setw(25)<<v(i,2)<<"    ";
    cout<<setw(25)<<a(i,0)<<" "<<setw(25)<<a(i,1)<<" "<<setw(25)<<a(i,2)<<"    ";
    cout<<endl;
  }
}

int cmp(const vector<double>& r1, const vector<double>& r2)// Only for sorting atoms according to their z coordinate
{ return r1[2]>r2[2];}

void Draw(double alpha, double theta, int pixsize, Plotter& plotter, const function2D<double>& r)
{
  // 3D->2D projection (Cavalier projection)
  double c1 = cos(theta)/tan(alpha);
  double c2 = sin(theta)/tan(alpha);
  
  plotter.erase();
  plotter.filltype(1);
  // atoms that have larger z coordinate should be plotted first to have the right stacking order in 3D plot
  // need to sort coordinates
  list<vector<double> > coord;
  for (int i=0; i<r.size_N(); i++){
    vector<double> r0(3);
    r0[0] = r[i][0];
    r0[1] = r[i][1];
    r0[2] = r[i][2];
    coord.push_back(r0);
  }
  coord.sort(cmp);

  // We will draw more distant atoms by dark color and closer by bright color
  // Need the minimum and maximum z coordinate
  double zmin = (*coord.begin())[2];
  double zmax = (*(--coord.end()))[2];
  
  for (list<vector<double> >::iterator ri=coord.begin(); ri!=coord.end(); ri++){
    double xp = (*ri)[0]+(*ri)[2]*c1;// projected coordinates
    double yp = (*ri)[1]+(*ri)[2]*c2;
    int color = static_cast<int>(((*ri)[2]-zmin)/(zmax-zmin)*65530);
    plotter.fillcolor(color,color,color);// only grey colors used
    plotter.circle(static_cast<int>(xp*pixsize),static_cast<int>(yp*pixsize),static_cast<int>(pixsize));
  }
  plotter.flushpl();// to flush output, otherwise some atoms might be missing on the display
}

int main(int argc, char *argv[], char *env[])
{
  int N=64;// Number of particles
  double L=10;// Linear size of cubic volume
  double Vmax=0.2;// Maximum initial velocity component
  int MaxSteps=2000;
  double dt = 0.01; // Time-step
  int i=0;
  while (++i<argc){
    std::string str(argv[i]);
    if (str=="-N" && i<argc-1)  N = atoi(argv[++i]);
    if (str=="-L" && i<argc-1)  L = atof(argv[++i]);
    if (str=="-Vmax" && i<argc-1) Vmax = atof(argv[++i]);
    if (str=="-dt" && i<argc-1) dt = atof(argv[++i]);
    if (str=="-Ms" && i<argc-1) MaxSteps = atoi(argv[++i]);
    if (str=="-h" || str=="--help"){
      std::clog<<"********* Molecular dynamics for argon **************\n";
      std::clog<<"**                                                **\n";
      std::clog<<"**      Copyright Kristjan Haule, 26.09.2005      **\n";
      std::clog<<"****************************************************\n";
      std::clog<<"\n";
      std::clog<<"dla [-N int] [-h]\n" ;
      std::clog<<"Options:   -N       Total number of particles ("<<N<<")\n";
      std::clog<<"           -L       Linear system size ("<<L<<")\n";
      std::clog<<"           -Vmax    Maximum initial velocity ("<<Vmax<<")\n";
      std::clog<<"           -Ms      Maximum number of steps ("<<MaxSteps<<")\n";
      std::clog<<"           -dt      Time-step ("<<dt<<")\n";
      std::clog<<"*****************************************************\n";
      return 0;
    }
  }
  /************** Initialization of plotter **************************/
  PlotterParams params; // set a Plotter parameter
  params.setplparam ("PAGESIZE", (char *)"letter");
  XPlotter plotter(cin, cout, cerr, params); // declare Plotter
  if (plotter.openpl () < 0){ // open Plotter      
    cerr << "Couldn't open Plotter\n";
    return 1;
  }
  int pixsize=500;
  plotter.fspace (-pixsize*L, -pixsize*L, pixsize*L*3, pixsize*L*3); // specify user coor system
  /*************************************************************************/

  // Data structures to store position, velocity and acceleartion
  function2D<double> r(N,3), v(N,3), a(N,3);
  
  /************** Initialization of random number gen. *********************/
  int random_seed = time(0);
  srand48(random_seed);
  /*************************************************************************/
  Initialize(L,Vmax,r,v);// Initialize the position and velocities of atoms

  for (int i=0; i<MaxSteps; i++){
    std::cout<<i<<" "<<instantaneousTemperature(v)<<std::endl;
    velocityVerlet(N, 3, dt, r, v, a, Force);// Actual simulation
    if  (i%50==0){
      Draw(0.25*M_PI, 0.25*M_PI, pixsize, plotter, r);
    }
  }

  /************** Plotter Done**************************/
  clog<<"DONE"<<endl;
  if (plotter.closepl () < 0){ // close Plotter
    cerr << "Couldn't close Plotter\n";
    return 1;
  }
  /*****************************************************/
  return 0;
}
