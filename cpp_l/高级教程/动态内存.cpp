#include<iostream>
#include<cstring>
using namespace std;

int main(){
    double * pvalue=NULL;
    pvalue=new double;
    *pvalue=1.11;
    cout<<*pvalue<<endl;
    delete pvalue;
    char * str=NULL;
    str=new char[100];
    strcpy(str,"Fuck you");
    cout<<str<<endl;
    return 0;

}