#include<iostream>

using namespace std;

// mutable 表示类中的成员变量可以在const成员函数中被修改
class Example{
    public:
    int get_value() const{
        return value_;  // const关键字表示该成员函数不会修改对象中的数据成员
    }

    void set_value(int value) const{
        value_=value; // mutable 关键字允许变量的值在const成员函数中修改
    }
    private:
    mutable int value_;
};

// static 使变量在程序的整个生命周期内都存在
// 当static修饰全局变量时，会使变量的作用域限制在声明他的文件中
void example_function(){
    static int j=0;
    j++;
};

int main(){
    // const 定义常量，表示该变量的值不能被修改。
    const int num=10;
    const int* ptr=&num; // 不能被修改

    // volatile 该变量的值在任意时刻可能被外部因素修改，比如硬件或其他线程
    volatile int i=20;

    // register  声明变量储存在寄存器中，方便频繁调用
    // 但是是否真的储存在寄存器中是由编译器决定的
    register int cont=0;

}
