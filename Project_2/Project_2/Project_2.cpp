/*
	Jeanine Bray
	EGR 111
	Professor Gary Landes
	October 1, 2018

		This program will be calculating and displaying the heat transfer through a substance. The user will be asked for the substances's
	thermal conductivity, width, and two temperatures on either side. Units will be determined, item by item, then converted for consistency
	(i.e. SI or U.S.). The final result will be output as both unit systems.
*/

#include<iostream>

int main()
{
	float width, tCond, temp1, temp2;

	std::cout << "Please enter the substance's thermal conductivity: " << std::endl;
	std::cin >> tCond;

	std::cout << "Please enter the width of the substance: " << std::endl;
	std::cin >> width;

	std::cout << "Please enter your first temperature reading: " << std::endl;
	std::cin >> temp1;

	std::cout << "Please enter your second temperature reading: " << std::endl;
	std::cin >> temp2;


	system("pause");
	return 0;
}