#include <iostream>
#include<queue>
using namespace std;


struct matter{
    string name="";
    int price=0;

    friend bool operator < (matter m1,matter m2){
        return m1.price<m2.price;
    }
};
struct cmp
{
    bool operator () (matter m1,matter m2){
        return m1.price<m2.price;
    }
};



int main(){
    priority_queue<int,vector<int>,less<int>> a;   // 数字越大的优先级越高，放在前面
    priority_queue<int,vector<int>,greater<int>> b; // 数字越小的优先级越高，放在后面
    // 对于其他的结构，可以通过重载运算符的方式

    priority_queue<matter> m;
    priority_queue<matter,vector<matter>,cmp> m2;
    
}