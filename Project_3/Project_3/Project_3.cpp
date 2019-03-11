#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// returns score for the target and data value
// as described in th problem
int getScore(int target, int data)
{
    int score = 0;
    while(target > 0)
    {
        int a = target % 10;
        int b = data % 10;
        target /= 10;
        data /= 10;
        score += abs(a-b);
    }
    return score;
}

// main funciton
int main()
{
    //opens candidates file
    ifstream indata("candidates.txt");
    //opens target file
    ifstream target("targets.txt");
    //creates results file to output
    ofstream output("results.txt");

    int data, targ, location;
    int minScore, score;
    cout << "Target\t\tCandidate\tScore" << endl;
    output << "Target\t\tCandidate\tScore" << endl;

    //loop through target file data
    while(!target.eof())
    {
        //gets target value
        target >> targ;
        location = 0;
        minScore = 100;
        // loops through indata file
        for(int i=0;i<10;i++)
        {           
            //gets data
            indata >> data;
            //calculates score
            score = getScore(targ, data);

            //writes the values to the both console and output file
            cout << targ << "\t\t" << data << "\t\t" << score << endl;           
            output << targ << "\t\t" << data << "\t\t" << score << endl;           

            // finds minimum score location
            if(minScore > score)
            {
                minScore = score;
                location = i+1;
            }
        }       

        // writes the min score location to both screen and output file
        cout << "loaction of the closest candidate to the target " <<targ << " is: "<< location << endl <<endl;
        output << "loaction of the closest candidate to the target " <<targ << " is: "<< location << endl << endl;

        //clear eof bit of indata file
        indata.clear();
        //seeks pointer to the starting of the indata file
        //to read data from starting
        indata.seekg(0);
    }

    //closes all opened files
    indata.close();
    target.close();
    output.close();

    return 0;
}
