#include<iostream>

using namespace std;

//类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员
// 既有友元函数，也有友元类

class Box{
    int width; // 没有访问声明时默认是private
    public:
        double length;
        Box(int length, int width);
        // 这个程序里box作为参数了，所以应该有拷贝构造函数。但是你不写也行，编译器会自动生成
        // Box(const Box& obj);
        friend void printWidth(Box box);
        friend class Box2; // 友元类也要写在这里
};

Box :: Box(int length,int width):width(width),length(length){
    // 赋值变量和成员变量名称相同时
    // 使用成员初始化列表初始化成员变量
}

void printWidth(Box box){ // 外面就不用写friend了
    cout<<box.width<<endl;
}

int main(){
    Box box1(10,20);
    printWidth(box1);
    cout<<box1.length<<endl;

    return 0;
}