/*



*/


#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>

//Calculates angle and distance of shot
class DistAng
{
	public:
		double airTime;
		double distShot;
		double inAngle;

		double distAng(double inAngle)
		{
			inAngle = (inAngle * pi) / 180;

			airTime = (2.0 * velocity * sin(inAngle)) / gravity;
			distShot = round((velocity * cos(inAngle)) * airTime);

			return distShot;
		}

	private:
		double velocity = 200;
		double gravity = 32.2;
		double pi = 3.1415;
};

//Reads/saves high score from/to file
class HighScore
{
 public:
	 void highScore(int score)
	 {
		 std::ifstream readScoreSheet("HighScore.art");

		 //Checks current high score first
		 if (readScoreSheet.is_open())
		 {
			 readScoreSheet >> initHighScore;
			 readScoreSheet.close();
		 }

		 //If no highscore has been input before
		 else
		 {
			 std::cout << "No current high score" << std::endl;
		 }

		 //If highscore has not been replaced
		 if (initHighScore > score)
		 {
			 std::cout << "The current high score is " << initHighScore << " eliminations!" << std::endl;
		 }

		 //If new high score was found
		 else if (initHighScore < score)
		 {
			 std::ofstream writeScoreSheet("HighScore.art");

			 //Replace old score
			 if (writeScoreSheet.is_open())
			 {
				 std::cout << "New high score!" << std::endl;
				 writeScoreSheet << score;
				 writeScoreSheet.close();
			 }

			 else
			 {
				 std::cout << "Unable to open file";
			 }
		 }
	 }

 private:
	 int initHighScore;
};

//Main game loop
class Game
{
	public:
		int enemyDistance = 0;
		bool killedEnemy = false;
		int shots = 0;
		int kills = 0;
		double inAngle;
		char done;
		
		void game()
		{
			do
			{
				//Generating enemy distance every instance of game
				srand(time(0));
				enemyDistance = 200 + (rand() % 900);

				std::cout << "The enemy is " << enemyDistance << " feet away!" << std::endl;

				//Constructors for distance/angle and highscore class
				DistAng calculate;
				HighScore submit;

				//Determines enemy deaths and reset every round
				killedEnemy = false;

				//Loop for user input
				do
				{
					std::cout << "Please enter an angle in degrees: " << std::endl;

					//Error check for input
					while (!(std::cin >> calculate.inAngle))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Invalid input. Try again: ";
					}

					//Keep track of shots
					shots++;

					//Counter for shots taken
					if (enemyDistance == calculate.distAng(calculate.inAngle))
					{
						kills++;
						killedEnemy = true;
						std::cout << "You hit the target!" << std::endl;
						std::cout << "It took you " << shots << " shots to defeat the enemy." << std::endl;

					}

					//If target was missed
					else if (enemyDistance < calculate.distAng(calculate.inAngle))
					{
						std::cout << "You over shot by " << calculate.distAng(calculate.inAngle) - enemyDistance << std::endl;
					}
					else if (enemyDistance > calculate.distAng(calculate.inAngle))
					{
						std::cout << "You under shot by " << enemyDistance - calculate.distAng(calculate.inAngle) << std::endl;
					}

				} while (shots != 10);

				//Enemy killed or player is out of rounds
				if (shots == 10 && killedEnemy == false)
				{
					shots = 0;
					std::cout << "You rand out of cannon balls" << std::endl;
					std::cout << "You've eliminated " << kills << " of the enemy." << std::endl;
					submit.highScore(kills); //Records enemies eliminated
					kills = 0;

					//New game?
					do
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Would you like to play again? (Y/N) ";
						std::cin >> done;
					} while (done != 'Y' && done != 'N');
				}

				else
				{
					shots = 0;
					std::cout << "You have eliminated " << kills << " of the enemy" << std::endl;

					//Checks for a new round
					do
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin >> done;
					} while (done != 'Y' && done != 'n');
				}
			} while (done != 'N');

			return;
		}
};

//Displays game introduction
class Startup
{
	public:
		void startup()
		{
			std::cout << "Welcome to Tank Wars!" << std::endl;

			return;
		}

	private:

};

int main()
{
	//Constructor for game startup
	Startup run;
	run.startup();

	//Constructor for main game loop
	Game game;
	game.game();
	

	return 0;
}