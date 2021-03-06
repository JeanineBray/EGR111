/*
Jeanine Bray
Professor Gary Landes
EGR 111 Engineering Computations
November 9, 2018

This program will determine how well a pattern of target numbers matches a set of candidate numbers by reading both targets and candidates in from a file 
and outputing the results to another file, as well as the console.
*/

#include<iostream>
#include<fstream>
#include<iomanip>

//Prototype for score getter function
int getScore(int target, int data);

int main()
{
	int data, target, location, minScore, score;

	std::ifstream dataIn("candidates.txt");		//Opening candidates file
	std::ifstream targetIn("targets.txt");		//Opening targets file
	std::ofstream dataOut("results.txt");		//Output file for results

	//Loop for target's file input
	while (!targetIn.eof())
	{
		std::cout << "Target" << "\t\tCandidate" << "\tScore" << std::endl;
		std::cout << "---------------------------------------" << std::endl;

		targetIn >> target;						//Get target value
		location = 0;
		minScore = 100;

		for (int i = 0; i < 10; i++)
		{
			dataIn >> data;						//Get data

			score = getScore(target, data);

			//Output results to console and results file
			std::cout << target << std::setw(17) << data << std::setw(12) << score << std::endl;
			dataOut << target << std::setw(17) << data << std::setw(12) << score << std::endl;

			if (minScore > score)				//Find minimum score location
			{
				minScore = score;
				location = i + 1;
			}
		}

		//Writes minimum score location to console and results file
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "Closest candidate to target " << target << " is: " << location << std::endl << std::endl;;
		dataOut << "Closest candidate to target " << target << " is: " << location << std::endl;

		dataIn.clear();
		dataIn.seekg(0);
	}

	dataIn.close();
	targetIn.close();
	dataOut.close();

	system("pause");
	return 0;
}

int getScore(int target, int data)
{
	int score = 0;

	while (target > 0)
	{
		int a = target % 10;
		int b = data % 10;

		target /= 10;
		data /= 10;

		score += abs(a - b);

		return score;
	}

	return 0;
}
