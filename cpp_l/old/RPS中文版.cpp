#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;

int main()
{
	int begin;
	int count = 0;
	int count_win = 0, count_lose = 0;
	 
	cout << "����һ����������ʯͷ��������С��Ϸ��R��r����ʯͷ��rock����P��p������paper����S��s���������scissors����\n";
	cout << "������������ַ��İ��������˳���\n";
	cout << "ף�����!\n";
	cout << "׼�������𣿣���1�Կ�ʼ��\n";
	cin >> begin;
	if (begin == 1)
	{

	

			
		char second;
		cout << "����ƣ�\n";
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
						cout << "ƽ��\n";
						cout << "���Ƕ�����ʯͷ\n";
					}
					else if ((second == 'S') || (second == 's'))
					{
						count_lose ++;
						cout << "��������Ӯ��\n";
						cout << "����ļ������ҳ���ʯͷ\n";
					}
					else if ((second == 'P') || (second == 'p'))
					{
						count_win ++;
						cout << "��������Ӯ��\n";
						cout << "����Ĳ����ҳ���ʯͷ\n";
					}
					break;
				case 'S':
				case 's':
					if ((second == 'R') || (second == 'r'))
					{
						count_win ++;
						cout << "��������Ӯ��\n";
						cout << "�����ʯͷ���ҳ��ļ���\n";
					}
					else if ((second == 'S') || (second == 's'))
					{
						cout << "ƽ��\n";
						cout << "���Ƕ����ļ���\n";
					}
					else if ((second == 'P') || (second == 'p'))
					{
						count_lose ++;
						cout << "��������Ӯ��\n";
						cout << "����Ĳ����ҳ��ļ���\n";
					}
					break;
				case 'P':
				case 'p':
					if ((second == 'R') || (second == 'r'))
					{
						count_lose ++;
						cout << "��������Ӯ��\n";
						cout << "�����ʯͷ���ҳ��Ĳ�\n";
					}
					else if ((second == 'S') || (second == 's'))
					{
						count_win ++;
						cout << "��������Ӯ��\n";
						cout << "����ļ������ҳ��Ĳ�\n";
					}
					else if ((second == 'P') || (second == 'p'))
					{
						cout << "ƽ��\n";
						cout << "���Ƕ����Ĳ�\n";
					}
					break;
				default:
					cout << "�Բ��𣬳����bug��\n";
				}
			cout << "==========================================================\n";
			cout << "����ƣ�\n";
			cin >> second;
			count ++;		
		}
			

			cout << "==========================================================\n";
			

			
		
		cout << "��������" << count << "��\n";
		cout << "��Ӯ��" << count_win << "��\n";
		cout << "��Ӯ��" << count_lose << "��\n";
		if (count_win > count_lose)
		{
			cout << "ף�أ���Ӯ��\n";
		}
		else if (count_win < count_lose)
		{
			cout << "��������Ӯ��\n";
		}
		else if (count_win == count_lose)
		{
			cout << "����ƽ��\n";
		}
		cout << "�ټ�\n";
	
	}
	system("pause");
	return 0;
}
