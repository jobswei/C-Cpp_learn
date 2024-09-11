#include<iostream>

using namespace std;

// 拷贝构造函数的三个主要用�?
// 1. 通过使用另一个同类型的对象来初始化新创建的对�?
// 2. 复制对象把它作为参数传递给函数
// 3. 复制对象，并从函数返回这个对�?
/*
通常情况下，在拷贝构造函数的参数中使�? const 是一个好的实践�?
这样做可以确保拷贝构造函数不会修改传入的对象，而只是进行数据的复制�?
这符合拷贝构造函数的目的，即创建一个新对象并复制传入对象的值�?

如果不加 const，意味着拷贝构造函数可以修改传入的对象。这可能会引起意外的行为，并违反了拷贝构造函数的约定
*/
class Line{
    public:
        int getLength(void);
        void setLength(int length);
        Line(int len);
        Line(const Line &obj); // 拷贝构造函�?
        ~Line();
    private :
        int* ptr;
};
Line :: Line(int length){
    cout<<"调用构造函数"<<endl;
    // 为指针分配内�?
    ptr=new int ;
    *ptr=length;
}
Line::Line(const Line &obj){
    cout<<"调用构造函数并为指针ptr分配内存"<<endl;
    ptr=new int ;
    *ptr=*obj.ptr; // 拷贝�?
}
// 在C++中，类的成员函数（包括构造函数和拷贝构造函数）可以直接访问同类的其他对象的私有成员。
Line::~Line(){
    cout<<"释放内存"<<endl;
    delete ptr;
}
int Line::getLength(){
    return *ptr;
}
void Line::setLength(int length){
    *ptr=length;
}


void display(Line obj){ // 对象作为函数的输�?
    cout<<"Line 大小"<<obj.getLength()<<endl;
}

int main(){
    Line line1(10);
    display(line1);
    Line line2=line1;
    display(line2);
    return 0;
}
/* 注意这里会输出两�? 释放内存 ，是因为
在函数调用时，参数传递过程中会涉及对象的复制构造?
�? display 函数被调用时，会创建一个新�? Line 对象 obj，并使用传递给函数�? line 对象来初始化它�?
这涉及到调用拷贝构造函�? Line(const Line &obj)�?

由于C++传参默认是复制传参，
所以类要想把类作为函数的参数，必须要加 拷贝构造函数�?
*/
