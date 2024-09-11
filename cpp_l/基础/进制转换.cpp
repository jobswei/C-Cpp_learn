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

    string s="101001";
    int num=stoi(s,nullptr,2) ;// 将某个进制的字符串转化为整数
    return 0;
}

string toHexString(int n) {
    // write your code here......
    bitset<16> bi(n);
    stringstream res;
    res.str("");
    res<<hex<<bi.to_ullong();
    return res.str();
    
}