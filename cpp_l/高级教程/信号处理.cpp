#include<iostream>
#include<csignal>
#include<unistd.h>
#include<windows.h>
using namespace std;

//signal(registered signal, signal handler)

void signalandler(int signum){
    cout<<"Interrupe signal ("<<signum<<") received.\n";
    exit(signum);
}

int main(){
    // 注册信号SIGINT和信号处理程序
    signal(SIGINT, signalandler);
    int i=0;
    while(++i>0){
        cout<<"Going to sleep...."<<endl;
        Sleep(1000);
        if(i==3){
            raise(SIGINT);
        }
    }
    return 0;
}