/* Prancing Rabbit
Show how to update and re-draw screen
*/

using namespace std;
#include<iostream>     
#include<string>
#include<iomanip>
#include<io.h>
#include<windows.h>

int main()
{
	char rabbit[5][9] = { {"    0 0 "},
					   {"    0 0 "},
					   {"   /  *|"},
					   {"  /    |"},
					   {"*|_____|"} };
	char rabbitb[5][9] = { {" 0 0    "},
						{" 0 0    "},
						{"|*   \\  "},
						{"|     \\ "},
						{"|_____|*"} };
	int i = 8, z, q = 10, direction = 0, reverse = 0;
	while (1)
	{
		if (i == 80)
			reverse = 1;
		else if (i == 8)
			reverse = 0;
		if (reverse)
		{
			system("CLS");
			// Put out endl to change the position of the bunny each iteration
			for (z = q; z > 1; z--)
			{
				cout << endl;
			}
			for (z = 0; z < 5; z++)
			{
				cout << setw(i) << rabbitb[z] << endl;
			}
			Sleep(40);
			if (direction == 0)
				q--;
			else
				q++;
			if (q == 1)
			{
				direction = 1;
			}
			else
			{
				if (q == 10)
					direction = 0;
			}
			i--;
		}
		else
		{
			system("CLS");
			// Put out endl to change the position of the bunny each iteration
			for (z = q; z > 1; z--)
			{
				cout << endl;
			}
			cout << endl;
			for (z = 0; z < 5; z++)
			{
				cout << setw(i) << rabbit[z] << endl;
			}
			Sleep(40);
			if (direction == 0)
				q--;
			else
				q++;
			if (q == 1)
			{
				direction = 1;
			}
			else
			{
				if (q == 10)
					direction = 0;
			}
			i++;
		}
	}

	//system ("pause");
	return 0;
}

