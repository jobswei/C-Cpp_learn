#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<time.h>

using namespace std;

//线性同余法产生随机数
double random_linear(void);
//计算N次投针计数情况
int m_count(int,int);
//用于产生随机数的全局变量
double M = pow(2.0,32.0), a = 16807.0;
double seed=10392.0;
int main()
{
    ofstream outfile;
    outfile.open("experiment_pi.txt", ios::trunc);
    double pi_experiment;
    int N,n=0 , num_example;
    // cout << "蒙特卡洛模拟最高次数"<<endl;
    // cin >> N;
    // cout << "蒙特卡洛模拟实验次数"<<endl;
    // cin >> num_example;
    N=1000000;
    num_example=100;
    int example[num_example];
    clock_t start_time, end_time;

    start_time=clock();
    for (int i=0;i<num_example;i++)
    {
        if ((i + 1)*(N / num_example) < N)
        {
            example[i] = (i + 1)*(N / num_example);
        }
    }

    double ex_pi[num_example] , result_pi[num_example];
    for (int i=0;i<(sizeof(example)/sizeof(example[0]));i++)
    {
        if (i==0)
        {
            ex_pi[i] = (double)m_count(0,example[0]);
        }
        else
        {
            ex_pi[i] = ex_pi[i-1] + (double)m_count(example[i-1],example[i]);
        }    
    }

    for (int i = 0;i < (sizeof(example)/sizeof(example[0]));i++)
    {
        result_pi[i] = ex_pi[i] * 4.0 / (double)example[i];
    }
    cout << result_pi[1] << endl;

    for (int i = 0; i < (sizeof(example)/sizeof(example[0])); i++)
    {
        outfile << fixed << setprecision(8) << result_pi[i] << " " <<  example[i] << endl;
    }
    outfile.close();

    end_time=clock();
    printf("time: %lf\n",(double)(end_time - start_time) / CLOCKS_PER_SEC);
    return 0;
}

double random_linear()
{
    seed = fmod(a * seed , M);
    return seed/M;
}

int m_count(int start,int end)
{
    int y = 0;
    double a,b;
    for (int i=start;i<end;i++)
    {
        a = random_linear();
        b = random_linear();
        double s = pow(a-0.5,2.0)+pow(b-0.5,2.0);
        if (s <= 0.25) y += 1;
    }
    return y;
}