#include<iostream>
#include<fstream>

using namespace std;

int main(){
    setlocale(LC_ALL, "zh_CN.GB2312"); // 或者 setlocale(LC_ALL, "zh_CN.GBK")

    char str[]="hello!";
    cout<<"Value of str is "<<str<<endl;
    char name[50];
    cout<<"Your name is: ";
    cin>>name;
    cout<<"Your name: "<<name<<endl;
    // cerr 没有缓冲，立即输出
    cerr<<"error"<<name<<endl;
    // clog优先存储在缓冲区，缓冲区满或者刷新时才会输出
    clog<<"error"<<name<<endl;

    // 文件的读写
    // 操作类型声明在ios命名空间
    char data[100];
    ofstream outfile;
    outfile.open("file1.txt",ios::out|ios::trunc);//以写入模式打开文件，并希望截断文件，以防文件已存在
    outfile <<"file"<<endl ;
    outfile.close();
    
    fstream file;
    file.open("file1.txt",ios::app|ios::in);// 同时可以追加形式写入和读取
    
    cout<<"Enter your name:"<<endl;
    cin.ignore(); // 加一个ignore清理一下，防止前面多余的换行符等干扰
    cin.getline(data,100); // 读入一整行
    file<<data<<endl;
    cout<<"Enter your age:"<<endl;
    cin>>data;
    cin.ignore();
    file<<data<<endl;
    file.close();

    ifstream infile;
    infile.open("file1.txt");
    char data2[100];
    infile>>data2; // 一次读入只能读入一行
    cout<<data2<<endl;
    cout<<"\ninput all"<<endl;
    infile.seekg(0,ios::beg); // 定位指针到开头
    infile.read(data2,100);
    cout<<data2;

    // 关于指针的定位
    infile.seekg(10,ios::cur); // 从流的当前位置开始，定位到后面的第10个字节
    infile.seekg(2,ios::end); // 从末尾向前移动10字节
    infile>>data2;
    cout<<data2;
    infile.seekg(0,ios::end); // 定位到末尾
    return 0;

}