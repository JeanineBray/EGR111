/*
Jeanine Bray
Professor Gary Landes
EGR 111 Engineering Computations
October 22, 2018





*/

#include<iostream>
#include<cmath>
#include<iomanip>
#include<numeric>

class calculations
{
	public:
		const float pi = 3.14;
		double magnitude, direction;

	private:
		double polar() 
		{
			return pi * direction / 180;
		}
		double xComp()
		{
			return magnitude * cos(direction);
		}

		double yComp()
		{
			return magnitude * sin(direction);
		}

		double resultant()
		{
			return sqrt((xComp() * xComp()) + (yComp() * yComp()));
		}

		double angle()
		{
			return atan(xComp() / yComp());
		}

};

int main()
{
	int numVect;
	double magArray[5], dirArray[5];

	do
	{
			std::cout << "Please enter the amount of vectors you would like to add up, with a max number of 5: " << std::endl;
			std::cin >> numVect;

	} while (numVect >= 5 || numVect <= 0);
	
	for (int i = 1 ; i <= numVect; i++)
	{
		std::cout << "Please enter a magnitude: " << std::endl;
		std::cin >> magArray[i];

		std::cout << "Please enter a angle (in degrees): " << std::endl;
		std::cin >> dirArray[i];
	}


	for (int t = 1; t <= numVect; t++)
	{
		std::cout << magArray[t] << dirArray[t] << std::endl;
	}
		

	
	return 0;
}