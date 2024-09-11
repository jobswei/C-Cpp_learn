#include<iostream>

using namespace std;

class Shape{
    protected:
        int width,height;
    public:
        virtual int area(){
            cout<<"Partent area"<<endl;
            return 0;
        }
        virtual void name()=0; // 纯虚函数
        Shape(int a,int b){
            width=a;
            height=b;
        }
};

class Rectangle:public Shape{
    public:
        Rectangle(int a,int b):Shape(a,b){}
        int area() override{
            cout<<"Rectangle area"<<endl;
            return height*width;
        }
        void name() override{
            cout<<"Rectangle"<<endl;
        }
};

int main(){
    Shape* shape;
    Rectangle Rect(2,3);
    shape=&Rect;
    int lll=shape->area();
    cout<<lll<<endl;
    shape->name();
    return 0;
}
