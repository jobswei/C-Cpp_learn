#include <iostream>

using namespace std;


class Base {};
class Derived : public Base {};
int main(){
    // 枚举类型
    // 默认情况下，第一个名称的值为 0，第二个名称的值为 1，第三个名称的值为 2.
    // 也可以给名称赋予一个特殊的值, 每个名称都会比它前面一个名称大 1
    enum color{red, blue=5, green} c,d,e;
    c=red;
    d=blue; e=green;
    cout<<c<<d<<e<<endl;

    // 静态类型转换
    // 通常用于类型相近的数据类型转换，不会进行类型检查
    int i=0;
    float j=static_cast<float>(i);
    j=(float)i;// 老式的转换，不安全
    cout<<j<<endl;
    // 动态类型转换
    // 通常用于将一个基类指针转化为派生类指针
    // 报错
    // Base * base= new Derived;
    // Derived * derived=dynamic_cast<Derived*>(base);
    // 重新解释转换
    // 将一个指针或引用转换为另一种类型的指针或引用.它只是将数据的位模式重新解释为另一种类型.
    i=10;
    j=reinterpret_cast<float&>(i);
    cout<<j<<endl;
}