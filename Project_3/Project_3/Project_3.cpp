/*
Jeanine Bray
Professor Gary Landes
EGR 111 Engineering Computations
October 15, 2018

	This program determines how far a ball will travel, after being struck. The user will enter the distance to pin, the depth of the green, the type of club,
and type of swing. Then the club type, swing type, distance traveled, yard shortage, and whether or not the green was hit will display in the console.
*/

#include<iostream>
#include<cmath>
#include<iomanip>

int main()
{
	int d2Pin, depthOfG, club, swing;

	std::cout << "Please enter the distance to the pin in yards: " << std::endl;
	std::cin >> d2Pin;

	std::cout << "Please enter the depth of the green in yards: " << std::endl;
	std::cin >> depthOfG;

	std::cout << "Please enter a club number (2-10) with 10 being a wedge: " << std::endl;
	std::cin >> club;

	std::cout << "Please enter the swing type (1-4) with 1 being a quarter and 4 being a full: " << std::endl;
	std::cin >> swing;

	std::cout << "Club" << "Swing" << "Distance (yds)" << "Error (yds)" << "Has the player hit the green?" << std::endl;
	

	return 0;
}