/*

*/


#include<iomanip> //Header file for functions that help with formatting the program's output.
#include<iostream>
#include<Windows.h> //Header file for Windows API functions
#include<chrono>
#include<vector>
#include<algorithm>

int nScreenWidth = 120; //Default screen
int nScreenHeight = 40;


float fPlayerX = 8.0f; //Players starting coordinates
float fPlayerY = 8.0f;
float fPlayerA = 0.0f; //Player start rotation

int nMapHeight = 16; //World Dimensinos
int nMapWidth = 16;

float fFOV = 3.14159f / 4.0f; //Players FOV
float fDepth = 16.0f; //Maximum rendering distance

int main()
{
	//Creates a default screen buffer	
	wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hconsole);
	DWORD dwBytesWritten = 0;
	

	//Left-hand corner map display
	std::wstring map;
	map += L"################";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";

	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();

	//Game Loop
	while (1)
	{
		
		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();
		
		//Player controls
		//Handle clockwise and counterclockwise rotation
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
		{
			fPlayerA -= (0.8f)  * fElapsedTime;
		}

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
		{
			fPlayerA += (0.8f) * fElapsedTime;
		}

		//Forward and backward movement
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000)
		{
			fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;

			//Collision detection for forward motion
			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#')
			{
				fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

		if (GetAsyncKeyState((unsigned short)'S') & 0x8000)
		{
			fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;

			//Collision detection for backwards motion
			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#')
			{
				fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

			for (int x = 0; x < nScreenWidth; x++)
			{
				//For each column, calculate the projected ray angle into world space
				float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

				float fDistanceToWall = 0;
				bool bHitWall = false;
				bool bBoundary = false;

				float fEyeX = sinf(fRayAngle);
				float fEyeY = cosf(fRayAngle); //Unit vector for ray in player space

				while (!bHitWall && fDistanceToWall < fDepth)
				{
					fDistanceToWall += 0.1f;

					int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
					int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

					//Test if ray is out of bounds
					if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
					{
						bHitWall = true; //Just set distance to maximum depth
						fDistanceToWall = fDepth;
					}
					else
					{
						//Ray is inbounds so test to see if the ray cell is a wall block
						if (map[nTestY * nMapWidth + nTestX] == '#')
						{
							bHitWall = true;

							std::vector<std::pair<float, float>> p; //Distance, angle between the two vectors
							
							for (int tx = 0; tx < 2; tx++)
							{
								for (int ty = 0; ty < 2; ty++)
								{
									float vy = (float)nTestY + ty - fPlayerY;
									float vx = (float)nTestX + tx - fPlayerX;
									float d = sqrt(vx * vx + vy * vy);
									float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
									p.push_back(std::make_pair(d, dot));
								}
							}

							std::sort(p.begin(), p.end(), [](const std::pair<float, float> &left, const std::pair<float, float> &right) { return left.first < right.first; });
							
							float fBound = 0.001;
							if (acos(p.at(0).second) < fBound) bBoundary = true;
							if (acos(p.at(1).second) < fBound) bBoundary = true;
							if (acos(p.at(2).second) < fBound) bBoundary = true;
							
						}
					}
				}

				//Calculate distance to ceiling and floor
				float nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
				float nFloor = nScreenHeight - nCeiling;

				short nShade = ' ';

				//Shades walls based upon players distance from it
				if (fDistanceToWall <= fDepth / 4.0f)     nShade = 0x2588; //FOV is close
				else if (fDistanceToWall < fDepth / 3.0f) nShade = 0x2593;
				else if (fDistanceToWall < fDepth / 2.0f) nShade = 0x2592;
				else if (fDistanceToWall < fDepth)        nShade = 0x2591;
				else                                      nShade = ' '; //FOV too far away
				
				//Adds depth to wall boundaries, such as corners, and shades them blank
				if (bBoundary) nShade = ' '; 
				

				for (int y = 0; y < nScreenHeight; y++)
				{
					if (y < nCeiling)
					{
						screen[y * nScreenWidth + x] = ' ';
					}
					else if (y > nCeiling && y <= nFloor)
					{
						screen[y * nScreenWidth + x] = nShade;
					}
					else
					{
						//Shadeing of floor based on distance
 						float b = 1.0f - (((float)y - nScreenHeight / 2.0f) / ((float)nScreenHeight / 2.0f));
						if (b < 0.25)       nShade = '#';
						else if (b < 0.5)   nShade = 'x';
						else if (b < 0.75)  nShade = '.';
						else if (b < 0.9)   nShade = '-';
						else                nShade = ' ';
						screen[y * nScreenWidth + x] = nShade;
					}

				}
			}

			//Display Stats
			swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS = %3.2f", fPlayerX, fPlayerY, fPlayerA, 1.0f / fElapsedTime);

			//Display Map
			for (int nx = 0; nx < nMapWidth; nx++)
			{
				for (int ny = 0; ny < nMapWidth; ny++)
				{
					screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
				}
			}

			screen[((int)fPlayerY + 1) * nScreenWidth + (int)fPlayerX] = 'P';

			screen[nScreenWidth * nScreenHeight - 1] = '\0';
			WriteConsoleOutputCharacter(hconsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);


		}
		return 0;
	}
