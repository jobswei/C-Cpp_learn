#include <iostream>
#include <string>
#include<bitset>
#include<sstream>
using namespace std;

string toHexString(int n);

int main() {

    int n;
    cin >> n;

    string hexStr = toHexString(n);
    cout << hexStr << endl;

    return 0;
}

string toHexString(int n) {
    // write your code here......
    bitset<16> bi(n);  // 16位二进制
    stringstream res; // istringstream只能读，不能写（只能初始化），stringstream能读能写
    res.str("");
    res<<hex<<bi.to_ullong(); // 转成usigned long， tostr()转成字符串
    // int k=stoi(res,nullptr,16); 转10进制
    return res.str();
    
}