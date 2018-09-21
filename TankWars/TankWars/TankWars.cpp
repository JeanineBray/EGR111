/*

*/


#include<iostream>
#include<windows.h> //Header file that contains declarations for all functions included in the Windows API, i.e. HANDLE.
#include<iomanip> //Header file for functions that help with formatting the program's output.

//#include<string>

void setCMDSizeAndTitle(short, short, std::wstring); //Function prototype for setting the size and title of the console window.
std::wstring s2WS(const std::string&); //Function prototype to convert string to wstring.


int main()
{
	setCMDSizeAndTitle(30, 80, s2WS("Tank Wars!"));

	system("pause"); //Please ignore. Visual Studio does not stay open outside of debug mode so for testing this was added.
	return 0;
}

void setCMDSizeAndTitle(short height, short width, std::wstring title) //Function definition.
{
	COORD coord = { width, height }; //Setting the 'x' and 'y' coordinates to take the values passed through from width and height.
	SMALL_RECT rect = { 0, 0, height - 1, width - 1 };
	LPCWSTR TEXT = title.c_str();

	SetConsoleTitle(TEXT); //The string to be displayed in the console window's title bar.

	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	return;
}

std::wstring s2WS(const std::string &str) //Function definition that performs the conversion.
{
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);

	return wstrTo;
}
