#include <iostream>
using namespace std;
#define DEBUG
 
#define MIN(a,b) (((a)<(b)) ? a : b)
// # 运算符会把 replacement-text 令牌转换为用引号引起来的字符串
#define MKSTR( x ) #x
// ## 运算符用于连接两个令牌
#define CONCAT( x, y )  x ## y
int main ()
{
   int i, j;
   i = 100;
   j = 30;
#ifdef DEBUG
   cerr <<"Trace: Inside main function" << endl;
#endif
 
#if 0
   /* 这是注释部分 */
   cout << MKSTR(HELLO C++) << endl;
#endif
 
   cout <<"The minimum is " << MIN(i, j) << endl;

   cout << MKSTR(HELLO C++) << endl;
    int xy = 100;
   cout << CONCAT(x, y)<<endl;
#ifdef DEBUG
   cerr <<"Trace: Coming out of main function" << endl;
#endif


    return 0;
}