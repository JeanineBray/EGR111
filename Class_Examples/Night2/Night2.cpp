/*
	This program takes 3 integers from the user and outputs an average.
*/

#include<iostream>

int main()
{
	int a, b, c;
	std::cout << "Please enter your first number: ";
	std::cin >> a;

	std::cout << "Please enter your second number: ";
	std::cin >> b;

	std::cout << "Please enter your third number: ";
	std::cin >> c;

	std::cout << "Your average is: " << ((a + b + c) / 3) << std::endl;

	
	system("pause");
    return 0;
}
