/*
This program will be calculating the volume and surface area of three geometric shapes: Sphere, Cylinder, and Cone.
The user will be prompted for a single radius and height value, and based upon the input, will perform a calculation for each shape.
Following each calculation, the original radius and height values will be displayed along with the volume and surface area of each
geometric shape, listed in the order above.
*/

#include<iostream> //Header file for functions that help with input/output such as 'cout' and 'cin'.
#include<iomanip> //Header file for functions that help with formatting the program's output.
#include<cmath> //Header file for functions that allow for more complex math operations.

//Declaring the pi constant
const double pi = 3.14159;

//Classes for each of the geometric shapes which will calculate surface area and volume based on the users input for height and radius
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
}; 

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

int main()
{
	using namespace std;

	double rad, ht;

	//Instantiating each classes so that the internal functions can be used to call a result
	Sphere sphere;
	Cylinder cylinder;
	Cone cone;

	//Asking the user for input
	std::cout << "Please enter a radius: " << std::endl;
	std::cin >> rad;
	system("cls");

	std::cout << "Please enter a height: " << std::endl;
	std::cin >> ht;
	system("cls");

	//This takes the input from the user adds them to the classes that perform each calculation
	sphere.getValues(rad, ht);
	cylinder.getValues(rad, ht);
	cone.getValues(rad, ht);

	//Formatted table displaying the original inputs and the output from each calculation
	cout << "           Sphere       Cylinder        Cone     \n--------------------------------------------------\n";
	cout << "Height" << setw(9) << ht << setw(13) << ht << setw(14) << ht << "\n--------------------------------------------------\n";
	cout << "Radius" << setw(9) << rad << setw(13) << rad << setw(14) << rad << "\n--------------------------------------------------\n";
	cout << "S. Area" << setw(12) << sphere.getSurfaceArea() << setw(13) << cylinder.getSurfaceArea() << setw(14) << cone.getSurfaceArea() << "\n--------------------------------------------------\n";
	cout << "Volume " << setw(12) << sphere.getVolume() << setw(13) << cylinder.getVolume() << setw(14) << cone.getVolume() << "\n--------------------------------------------------\n";

	system("pause"); //Please ignore. Visual Studio does not stay open outside of debug mode so for testing this was added.
	return 0;
}

