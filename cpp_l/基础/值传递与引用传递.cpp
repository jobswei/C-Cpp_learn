#include <iostream>
using namespace std;

// 值传递
void valuePassing(int num) {
    num = 100;
}

// 引用传递
void referencePassing(int& num) {
    num = 100;
}

int main() {
    int num1 = 10;
    cout << "Before valuePassing: " << num1 << endl;
    valuePassing(num1);
    cout << "After valuePassing: " << num1 << endl;

    int num2 = 10;
    cout << "Before referencePassing: " << num2 << endl;
    referencePassing(num2);
    cout << "After referencePassing: " << num2 << endl;

    return 0;
}
