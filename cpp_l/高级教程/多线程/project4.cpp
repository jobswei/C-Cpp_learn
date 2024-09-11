#include<iostream>
#include<vector>
#include<map>
#include<string>

#include<thread>

using namespace std;
void myPrint(){
    cout<<"My thread begin"<<endl;


    cout<<"My thread finishes"<<endl;
}
int main(){
    cout<<"I love china"<<endl;

    thread myjob(myPrint);
    myjob.join();
    cout<<"I love china"<<endl;

    return 0;
}
