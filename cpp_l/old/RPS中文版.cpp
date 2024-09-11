#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;

int main()
{
	int begin;
	int count = 0;
	int count_win = 0, count_lose = 0;
	 
	cout << "这是一个“剪刀、石头、布”的小游戏，R或r代表石头（rock），P或p代表布（paper），S或s代表剪刀（scissors）。\n";
	cout << "按任意非上述字符的按键可以退出。\n";
	cout << "祝你好运!\n";
	cout << "准备好了吗？（按1以开始）\n";
	cin >> begin;
	if (begin == 1)
	{

	

			
		char second;
		cout << "请出牌：\n";
		cin >> second;
			
		while ((second == 'R') || (second == 'r') || (second == 'S') || (second == 's') || (second == 'P') || (second == 'p'))
		{
			char first;
			int number;
			srand((int)time(0));
			number = rand() % 3 + 1;
			if (number == 1)
			{
				first = 'R';
			}
			else if (number == 2)
			{
				first = 'S';
			}
			else
			{
				first = 'P';
			}
			switch (first)
			{
				case 'R':
				case 'r':
					if ((second == 'R') || (second == 'r'))
					{
						cout << "平局\n";
						cout << "我们都出了石头\n";
					}
					else if ((second == 'S') || (second == 's'))
					{
						count_lose ++;
						cout << "哈哈，我赢了\n";
						cout << "你出的剪刀，我出的石头\n";
					}
					else if ((second == 'P') || (second == 'p'))
					{
						count_win ++;
						cout << "哈哈，你赢了\n";
						cout << "你出的布，我出的石头\n";
					}
					break;
				case 'S':
				case 's':
					if ((second == 'R') || (second == 'r'))
					{
						count_win ++;
						cout << "哈哈，你赢了\n";
						cout << "你出的石头，我出的剪刀\n";
					}
					else if ((second == 'S') || (second == 's'))
					{
						cout << "平局\n";
						cout << "我们都出的剪刀\n";
					}
					else if ((second == 'P') || (second == 'p'))
					{
						count_lose ++;
						cout << "哈哈，我赢了\n";
						cout << "你出的布，我出的剪刀\n";
					}
					break;
				case 'P':
				case 'p':
					if ((second == 'R') || (second == 'r'))
					{
						count_lose ++;
						cout << "哈哈，我赢了\n";
						cout << "你出的石头，我出的布\n";
					}
					else if ((second == 'S') || (second == 's'))
					{
						count_win ++;
						cout << "哈哈，你赢了\n";
						cout << "你出的剪刀，我出的布\n";
					}
					else if ((second == 'P') || (second == 'p'))
					{
						cout << "平局\n";
						cout << "我们都出的布\n";
					}
					break;
				default:
					cout << "对不起，程序出bug了\n";
				}
			cout << "==========================================================\n";
			cout << "请出牌：\n";
			cin >> second;
			count ++;		
		}
			

			cout << "==========================================================\n";
			

			
		
		cout << "我们玩了" << count << "局\n";
		cout << "你赢了" << count_win << "局\n";
		cout << "我赢了" << count_lose << "局\n";
		if (count_win > count_lose)
		{
			cout << "祝贺，你赢了\n";
		}
		else if (count_win < count_lose)
		{
			cout << "哈哈，我赢了\n";
		}
		else if (count_win == count_lose)
		{
			cout << "最终平局\n";
		}
		cout << "再见\n";
	
	}
	system("pause");
	return 0;
}
