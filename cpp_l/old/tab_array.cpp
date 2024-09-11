#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void cao(int *lis)
{
    *(lis+1)=999;
    return;
}
int *getrandom(){
    static int r[10]; //static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。

    for( int i=0;i<10;i++){
        r[i]=rand();
    }
    return r;
}

int main(){
    int lis[]={1,2,3,4,5};
    cao(lis);
    cout<<*(lis+1)<<endl;

    int *ran;
    ran=getrandom();
    cout<<ran[2]<<endl;
    return 0;
}