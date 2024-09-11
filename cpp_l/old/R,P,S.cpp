#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;

int main()
{
	int begin;
	int count = 0;
	int count_win = 0, count_lose = 0;
	 
	cout << "This is a program for \"Rock, Paper, Scissors\".\nYou need to input \"R\" or \"r\" for rock, \"P\" or \"p\" for paper and \"S\" or \"s\" for scissors.\n";
	cout << "If you want to exit, just input anything except \"P\", \"p\", \"R\", \"r\", \"S\" and \"s\".\n";
	cout << "Good luck!\n";
	cout << "Are you ready? (Press \"1\" and enter to begin, press \"0\" to exit)\n";
	cin >> begin;
	if (begin == 1)
	{

	

			
		char second;
		cout << "Please give me your choice(Enter):\n";
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
							cout << "No winner.\n";
							cout << "Both you and me choose R.\n";
						}
						else if ((second == 'S') || (second == 's'))
						{
							count_lose ++;
							cout << "I win.\n";
							cout << "You choose S and I choose R.\n";
						}
						else if ((second == 'P') || (second == 'p'))
						{
							count_win ++;
							cout << "You win.\n";
							cout << "You choose P and I choose R.\n";
						}
						else
						{
							cout << "Your value is illegal.\n";
						}
						break;
					case 'S':
					case 's':
						if ((second == 'R') || (second == 'r'))
						{
							count_win ++;
							cout << "You win.\n";
							cout << "You choose R and I choose S.\n";
						}
						else if ((second == 'S') || (second == 's'))
						{
							cout << "No winner.\n";
							cout << "Both you and me choose S.\n";
						}
						else if ((second == 'P') || (second == 'p'))
						{
							count_lose ++;
							cout << "I win.\n";
							cout << "You choose P and I choose S.\n";
						}
						else
						{
							cout << "Your value is illegal.\n";
						}
						break;
					case 'P':
					case 'p':
						if ((second == 'R') || (second == 'r'))
						{
							count_lose ++;
							cout << "I win.\n";
							cout << "You choose R and I choose P.\n";
						}
						else if ((second == 'S') || (second == 's'))
						{
							count_win ++;
							cout << "You win.\n";
							cout << "You choose S and I choose P.\n";
						}
						else if ((second == 'P') || (second == 'p'))
						{
							cout << "No winner.\n";
							cout << "Both you and me choose P.\n";
						}
						else
						{
							cout << "Your value is illegal.\n";
						}
						break;
					default:
						cout << "Sorry, there must be something wrong with this program.\n";
				}
			cout << "==========================================================\n";
			cout << "Please give me your choice(Enter):\n";
			cin >> second;
							count ++;
		}
			

			cout << "==========================================================\n";
			

			
		
		cout << "We have played " << count << " time(s).\n";
		cout << "You have won " << count_win << " time(s).\n";
		cout << "I have won " << count_lose << " time(s).\n";
		if (count_win > count_lose)
		{
			cout << "So you win finally.\n";
		}
		else if (count_win < count_lose)
		{
			cout << "So I win finally.\n";
		}
		else if (count_win == count_lose)
		{
			cout << "So nobody wins.\n";
		}
		cout << "Goodbye.\n";
	
	}
	system("pause");
	return 0;
}
