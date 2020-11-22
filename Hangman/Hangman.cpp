// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
<<<<<<< HEAD

int main()
{
    std::cout << "Hello World!\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
=======
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    //Start screen
    char start{};

    cout << "Welcome to Hangman\n" << "by PennynDime\n";
    cout << "_______________" << endl;
    cout << "|      |       " << endl;
    cout << "|      O       " << endl;
    cout << "|      |       " << endl;
    cout << "|    / | \\    " << endl;
    cout << "|   /  |  \\   " << endl;
    cout << "|     / \\     " << endl;
    cout << "|    /   \\    " << endl;
    cout << "Press any key to start" << endl;
    cin >> start;

    //Game
    //Set variables used throughout the game
    int tries{ 6 }; //7 tries to guess correctly
    string word; //This will be the word the player has to guess
    string wordList[99];  //Array with 100 strings

    //Get random word
    srand(time(NULL)); //Create random seed - used to get random word in above array
    ifstream randomWord; //This file stream reads in the variable
    randomWord.open("Words.txt"); //Reads in this file (list of words)

    for (int i = 0; i < 99; i++) {
        randomWord >> wordList[i]; //Filling the array with the words in the list
        cout << wordList[i];
    }



    while (tries >= 0) {
        switch (tries) {
        case 6: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            tries--;
            break;
        }
        case 5: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            tries--;
            break;
        }
        case 4: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|      |   " << endl;
            tries--;
            break;
        }

        case 3: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|      |   " << endl;
            cout << "|      |   " << endl;
            tries--;
            break;
        }

        case 2: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|    / | \\    " << endl;
            cout << "|   /  |  \\   " << endl;
            tries--;
            break;
        }
        case 1: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|    / | \\    " << endl;
            cout << "|   /  |  \\   " << endl;
            cout << "|       \\     " << endl;
            cout << "|        \\    " << endl;
            tries--;
            break;
        }
        case 0: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|    / | \\    " << endl;
            cout << "|   /  |  \\   " << endl;
            cout << "|     / \\     " << endl;
            cout << "|    /   \\    " << endl;
            cout << "Game Over!";
            tries = -1;
            break;
        }
        default:
            cout << "Something went terribly wrong..";
        }
    }

}
>>>>>>> startapp
