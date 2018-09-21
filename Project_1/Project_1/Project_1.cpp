/*
This program will be calculating the volume and surface area of three geometric shapes: Sphere, Cylinder, and Cone.
The user will be prompted for a single radius and height value, and based upon the input, will perform a calculation for each shape.
Following each calculation, the original radius and height values will be displayed along with the volume and surface area of each
geometric shape, listed in the order above.
*/

#include<iostream>
#include<iomanip> //Header file for functions that help with formatting the program's output.
#include<cmath> //Header file for functions that allow for more complex math operations.
#include<Windows.h> //Header file for functions related to the Windows API.

const double pi = 3.14159;

class Sphere
{
	double radius, height, volume, surfaceArea;

public:
	void getValues(double r, double h)
	{
		radius = r;
		height = h;
	}

	double getVolume()
	{
		volume = ((4 * pi * (pow(radius, 3))) / 3);

		return volume;
	}

	double getSurfaceArea()
	{
		surfaceArea = (4 * pi * (pow(radius, 2)));

		return surfaceArea;
	}
}; //

class Cylinder
{
	double radius, height, volume, surfaceArea;

	public:
		void getValues(double r, double h)
		{
			radius = r;
			height = h;
		}

		double getVolume()
		{
			volume = (pi * (pow(radius, 2)) * height);

			return volume;
		}

		double getSurfaceArea()
		{
			surfaceArea = ((2 * (pi * (pow(radius, 2)))) + 2 * pi * radius * height);

			return surfaceArea;
		}


};

class Cone
{
	double radius, height, volume, surfaceArea;

	public:
		void getValues(double r, double h)
		{
			radius = r;
			height = h;
		}

		double getVolume()
		{
			volume = ((pi * (pow(radius, 2)) * height) / 3);

			return volume;
		}

		double getSurfaceArea()
		{
			surfaceArea = (pi * radius * (radius + sqrt(pow(height, 2) + (pow(radius, 2)))));

			return surfaceArea;
		}


};

double results();

int main()
{
	double rad, ht;

	Sphere sphere;
	Cylinder cylinder;
	Cone cone;

	std::cout << "Please enter a radius: " << std::endl;
	std::cin >> rad;
	system("cls");

	std::cout << "Please enter a height: " << std::endl;
	std::cin >> ht;
	system("cls");

	sphere.getValues(rad, ht);
	cylinder.getValues(rad, ht);
	cone.getValues(rad, ht);





	/*
	std::cout << "|" << "Cylinder" << "|" << std::setw(5) << "|" << std::setw(5) << "|" << std::setw(5) << "|" << std::setw(5) << "|" << std::endl;
	std::cout << "|" << "Cone" << "|" << std::setw(5) << "|" << std::setw(5) << "|" << std::setw(5) << "|" << std::setw(5) << "|" << std::endl;
	*/
	
	system("pause"); //Please ignore. Visual Studio does not stay open outside of debug mode so for testing this was added.
	return 0;
}

double results()

{
	return 0.0;
}
