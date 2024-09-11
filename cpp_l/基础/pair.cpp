#include<utility>
#include<iostream>

using namespace std;

int main(){
    pair<int,int> p(1,2);

    p=make_pair(1,2);
    p=pair<int,int>(3,4);  // 临时构建pair

    p.first=4;
    p.second=5;
    cout<<p.first<<p.second<<endl;

    // pair比较大小，默认先比较第一个，第一个相等时，会比较第二个

    return 0;
}