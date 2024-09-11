#include<map>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(){
    std::map<std::string,int> mp;
    mp["a"]=1;
    mp["b"]=2;
    mp["c"]=3;
    for (std::map<std::string,int>::iterator it=mp.begin();it!=mp.end();it++){
        std::cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<mp["a"];
    cout<<mp.size()<<endl;
    map<string,int>::iterator it=mp.find("b"); // ֻ��Ѱ�Ҽ�
    mp.erase(it,mp.end());
    cout<<mp.size()<<endl;
  
}