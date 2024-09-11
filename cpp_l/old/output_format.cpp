#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // 开头设置宽度为 4，后面的 runoob 字符长度大于 4，所以不起作用
    cout << setw(4) << "runoob" << endl;
    // 中间位置设置宽度为 4，后面的 runoob 字符长度大于 4，所以不起作用
    cout << "runoob" << setw(4) << "runoob" << endl;
    // 开头设置间距为 14，后面 runoob 字符数为6，前面补充 8 个空格
    cout << setw(14) << "runoob" << endl;
    // 中间位置设置间距为 14 ，后面 runoob 字符数为6，前面补充 8 个空格
    cout << "runoob" << setw(14) << "runoob" << endl;
    return 0;
}