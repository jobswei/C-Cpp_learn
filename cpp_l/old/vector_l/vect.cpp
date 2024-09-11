#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void display(vector<int> a){
    for(vector<int>::iterator it=a.begin();it<a.end();it++){
        cout<<*it;
    }
    cout<<endl;
}

void print(int num){
    cout<<num<<" ";
}
void display2(vector<int> a){
    for_each(a.begin(),a.end(),print);
}
int main(){
    vector<int> a;
    a.assign(10,0);
    a[0]=1;
    cout<<a.empty()<<endl;
    cout<<a.size()<<endl;
    display(a);
    a.erase(a.begin(),a.begin()+1);
    display(a);
    a.insert(a.begin()+1,3,5);
    display(a);
    a.push_back(123);
    display(a);
    a.pop_back();
    display(a);
    cout<<a.capacity()<<" "<<a.size()<<endl;
    a.reserve(100);
    cout<<a.capacity()<<" "<<a.size()<<endl;
    display(a);
    sort(a.begin(),a.end());
    display(a);
    a.push_back(1);
    reverse(a.begin(),a.end());
    display(a);
    vector<int> b(a.size());
    copy(a.begin(),a.end(),b.begin());
    display(b);
    vector<int>::iterator it=find(a.begin(),a.end(),1);
    cout<<it-a.begin()<<endl;

    vector<int> c={1,2};
    display(c);
    sort(c.begin(),c.end(),greater<int>()); // 从大到小
    display2(c);
    // 求最大值
    auto it=max_element(c.begin(),c.end());
    cout<<*it<<endl;
    // 求和
    int sum=accumulate(c.begin(),c.end(),0);  // 0是求和的初始值

    vector<int> m(10,0);
    vector<int> n(m);
    return 0;
}