/*
	Jeanine Bray
	Professor Gary Landes
	EGR 111 Engineering Computations
	November 29, 2018


	A file will be loaded which will then be aligned as an x by y matrix.  
	The root of the simultaneous equations will then be determined using the row echelon reduction method of solution.  
	The method can be reviewed online via a google search.  The basic concept is given in the class notes.  
	First, multiply the first coefficient of each first variable in the matrix and then multiply though the entire matrix. 
	This will allow subtraction of the first equation from each of the successive equations. 
	Now you will have a coefficient for the first equations and zeroes for each of the first coefficients of the successive equations.  
	Now repeat the process at the second coefficient of the second equation.  
	Continue this pattern until you have an echelon of zeroes in successive equations first-variable columns.
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

float printMatrix(float A[][6]);
void rowReduction(float A[][6]);

int main()
{
	std::ifstream dataIn("matrixin.txt");		//Input for 2D array
	std::ofstream dataOut("matrixout.txt");		//Output file for Matrix

	float A[5][6] = {};							//Initializing Array

	while (!dataIn.eof())
	{
		int row = 5;
		int col = 6;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				dataIn >> A[i][j];
			}
		}
	}

	printMatrix(A);
	std::cout << std::endl;
	rowReduction(A);								//Perform row reduction

	if (!dataOut.eof())
	{
		dataOut << printMatrix(A) << " " << std::endl;		//Prints Matrix to file
	}

	std::cout << std::endl;

	system("pause");
	return 0;
}

float printMatrix(float A[][6])
{
	int nRow = 5;		//Number of rows
	int nCol = 6;		//Number of columns


	for (int i = 0; i < nRow; i++)		//For each row...
	{
		for (int j = 0; j < nCol; j++)	//For each col...
		{
			std::cout << A[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}

void rowReduction(float A[][6])
{
	const int nRow = 5;		//Number of array rows
	const int nCol = 6;		//Number of array columns

	int lead = 0;		//Column position

	while (lead < nRow)
	{
		float divide, multip;
		
		//Calculations for multiplier and divisor
		divide = A[lead][lead];
		multip = A[nRow][lead] / A[lead][lead];

		for (int i = 0; i < nRow; i++)		//For each row...
		{
			for (int j = 0; j < nCol; j++)		//For each col...
			{
				//Perform these calculations
				if (i == lead)
				{
					A[i][j] /= divide;			//Make pivot 1
				}

				else
				{
					A[i][j] -= A[lead][j] * multip;		//Make pivot 0
				}
			}
		}

		lead++;
		printMatrix(A);
		std::cout << std::endl;
	}

	
	return;
}
