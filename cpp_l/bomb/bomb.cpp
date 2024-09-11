#include<iostream>
#include<ctime>
#include<cstdlib>
#include<graphics.h>
using namespace std;

void drawmap(int map[][12],IMAGE *img)
{
 int i, j;
 for (i = 1; i <= 10; i++)
 {
 for (j = 0; j <= 10; j++)
 {
 int x = 50 * (i - 1);//得到位置
 int y = 50 * (j - 1);
 if (map[i][j]>25)
 {
 putimage(x, y, &img[9]);//标记flag
 }
 else
 {
 switch (map[i][j])
 {
 case 9:
  putimage(x, y, &img[11]);//输出图片雷
  break;
 case 10:
  putimage(x, y, &img[0]);//0
  break;
 case 11:
  putimage(x, y, &img[1]);//1
  break;
 case 12:
  putimage(x, y, &img[2]);//2
  break;
 case 13:
  putimage(x, y, &img[3]);//3
  break;
 case 14:
  putimage(x, y, &img[4]);//4
  break;
 case 15:
  putimage(x, y, &img[5]);//5
  break;
 case 16:
  putimage(x, y, &img[6]);//6
  break;
 case 17:
  putimage(x, y, &img[7]);//7
  break;
 case 18:
  putimage(x, y, &img[8]);//8
  break;
 default:
  putimage(x, y, &img[10]);//地图
  break;
 }
 }
 }
 }
}
int mousedown(int map[][12])
{
 MOUSEMSG m; //定义鼠标消息变量
 while (1)
 {
 //获取鼠标消息
 m = GetMouseMsg();
 int mi = m.x / 50 + 1;
 int mj = m.y / 50 + 1;

 //判断鼠标消息
 switch (m.uMsg)
 {
 case WM_LBUTTONDOWN:
 if (map[mi][mj] > 9) //已翻开的情况
 {
 continue;
 }
 if (map[mi][mj] == 0) //如果点击为0，则翻开一片。
 {
 //使用递归函数
 swap(map, mi, mj);
 }
 else
 {
 map[mi][mj] += 10;
 sum += 1;
 }
 return map[mi][mj];
 break;
 case WM_RBUTTONDOWN:
 if (map[mi][mj] > 9&& map[mi][mj] < 25) //已翻开的情况
 {
 continue;
 }
 if (map[mi][mj] > 25) //再次点击取消flag
 {
 map[mi][mj] -= 30;
 }
 else
 {
 map[mi][mj] += 30;
 }
 return map[mi][mj];
 break;
 }
 }
}
void swap(int map[][12],int mi,int mj)
{
 map[mi][mj] = 10;
 sum += 1;
 for (int i = mi - 1; i <= mi + 1; i++)
 {
 for (int j = mj - 1; j <= mj + 1; j++)
 {
 //数组下标不能越界
 if (i >= 1 && i <= 10 && j >= 1 && j <= 10)
 {
 //翻开的只能是数字
 if (map[i][j] < 9)
 {
  //如果为0，则进行递归。
  if (map[i][j] == 0)
  {
  swap(map, i, j);
  }
  else
  {
  map[i][j] += 10;
  sum += 1;
  }
 }
 }
 }
 }
}
void startgame()
{
 initgraph(500, 500); //初始化地图500x500
 int map[12][12] = { 0 };
 int i,j,m,n;
 //随机函数种子
 srand((unsigned int)time(NULL));
 //随机生成10个雷
 for (n = 0; n < 10;)
 {
 i = rand() % 10 + 1; //[1,10]
 j = rand() % 10 + 1;
 if (map[i][j] == 0) //排除本来就有雷的情况
 {
 map[i][j] = -1; //-1表示有雷
 n++;
 }
 }
 //产生数字
 for (i = 1; i <= 10; i++)
 {
 for (j = 1; j <= 10; j++)
 {
 //排除是雷的情况
 if (map[i][j] != -1)
 {
 for (m = i - 1; m <= i + 1; m++) //判断周围是否有雷
 {
  for (n = j - 1; n <= j + 1; n++)
  {
  if (map[m][n] == -1)
  {
  map[i][j]++;
  }
  }
 }
 }
 }
 }
 IMAGE img[12]; //定义图片变量
 loadimage(&img[0], "E:\\C++ project\\minesweeping\\0.jpg", 50, 50);
 loadimage(&img[1], "E:\\C++ project\\minesweeping\\1.gif", 50, 50);//加载图片
 loadimage(&img[2], "E:\\C++ project\\minesweeping\\2.gif", 50, 50);
 loadimage(&img[3], "E:\\C++ project\\minesweeping\\3.gif", 50, 50);
 loadimage(&img[4], "E:\\C++ project\\minesweeping\\4.gif", 50, 50);
 loadimage(&img[5], "E:\\C++ project\\minesweeping\\5.gif", 50, 50);
 loadimage(&img[6], "E:\\C++ project\\minesweeping\\6.gif", 50, 50);
 loadimage(&img[7], "E:\\C++ project\\minesweeping\\7.gif", 50, 50);
 loadimage(&img[8], "E:\\C++ project\\minesweeping\\8.gif", 50, 50);
 loadimage(&img[9], "E:\\C++ project\\minesweeping\\flag.gif", 50, 50);
 loadimage(&img[10], "E:\\C++ project\\minesweeping\\地图.gif", 50, 50);
 loadimage(&img[11], "E:\\C++ project\\minesweeping\\雷.gif", 50, 50);
 while (1)
 {
 drawmap(map, img);
 //点到地雷
 if (mousedown(map)==9)
 {
 sum = 0; //重置判断变量
 drawmap(map, img);
 MessageBox(hwnd,"你踩到雷了！","Game Over",MB_OK);
 return;
 }
 //成功完成游戏
 if (sum == 90)
 {
 sum = 0; //重置判断变量
 drawmap(map, img);
 MessageBox(hwnd, "你成功完成了游戏！", "Game Over", MB_OK);
 return;
 }
 }
}
#include<iostream>
#include<time.h>
#include<graphics.h> //图形库头文件 easyx
#include <conio.h> //调用_getch函数
using namespace std;
HWND hwnd;
int sum = 0;//用于表示目前已经点开的格子数
//声明函数
void drawmap(int map[][12], IMAGE* img);
int mousedown(int map[][12]);
void swap(int map[][12], int mi, int mj);
//初始化游戏

//绘制地图

//鼠标点击

//递归函数

int main()
{
 while (1)
 {
 startgame();
 if (MessageBox(hwnd, "再来一次", "结束游戏", MB_YESNO)==IDNO)
 break;
 }
 //_getch(); //防止闪屏
 closegraph();
 return 0;
}