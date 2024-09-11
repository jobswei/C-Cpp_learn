#include<iostream>

using namespace std;
// 类继承中初始化父类的方法
class Base{
    public :
        int baseValue;
        Base(int baseValue):baseValue(baseValue){
            cout<<"Base constructor called."<<endl;
        }
};

class Derived:public Base{
    public:
        int derivedValue;
        Derived(int baseValue,int derivedValue):Base(baseValue),derivedValue(derivedValue){
            cout<<"Derived constroctor called."<<endl;
        }
};

int main(){
    Derived derived(1,2);
    return 0;
}
