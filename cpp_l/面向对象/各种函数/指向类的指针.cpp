#include<iostream>

using namespace std;

//类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员
// 既有友元函数，也有友元类

class Box{
    int width; // 没有访问声明时默认是private
    public:
        double length;
        Box(int length, int width);
};

Box :: Box(int length,int width){
    this->width=width;
    this->length=length;// 也可以这样初始化
}


int main(){
    Box box1(10,20);
    Box* bb;
    bb=&box1;
    cout<<bb->length<<endl;

    return 0;
}