// Hangman.cpp : Hangman game using C++

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    //Start screen
    char start;

    system("CLS");
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

    //Clear screen
    system("CLS");

    //Game
    //Set variables used throughout the game
    int tries{ 6 }; //number of attempts to guess correctly
    char guess;
    bool correctGuess = false;
    char previousGuesses[7]; //an array of guesses, needs to be one longer than the user can guess
    previousGuesses[0] = '\0';
    for (int i = 1; i < 6; i++) {
        previousGuesses[i] = '-';
    }
    previousGuesses[6] = '\0';

    string word; //This will be the word the player has to guess
    string wordList[99];  //Array with 100 strings

    //Get random word
    srand(time(NULL)); //Create random seed - used to get random word in above array
    ifstream randomWord; //This file stream reads in the variable
    randomWord.open("Words.txt"); //Reads in this file (list of words)

    for (int i = 0; i < 99; i++) {
        randomWord >> wordList[i]; //Filling the array with the words in the list
        //cout << wordList[i] << endl; //Testing if words are being assigned to array
    }

    int randomNum = rand() % 100; // returns random number 0-99
    word = wordList[randomNum];
    //cout << word << endl; //Testing to see if random word in wordList is displayed
    randomWord.close();

    //Make word a mystery
    string mysteryWord(word.length(), '*'); //Replaced each letter of the word with an '*' and stores it in mysteryWord
    //cout << mysteryWord << endl; //Testing to see if word was replaced with '*'

    while (tries >= 0) {
        //reset bool 
        correctGuess = false;

        //Display information related to the word for the player
        cout << "The word you have to guess is: " << endl;
        cout << mysteryWord << endl;
        cout << "There are " << mysteryWord.length() << " letters in the word." << endl;
        cout << "You have " << tries << " guesses to get the word correct.\n" << endl;
        if (previousGuesses[0] == '\0') {
            cout << endl;
        }
        else {
            cout << "You have guessed: " << previousGuesses << endl;
        }
        
        //get player guess
        cout << "Guess a letter: ";
        cin >> guess;
        cout << "\n\n";

        //Check is the guess correct
        for (int i = 0; i < mysteryWord.length(); i++) { //for the length of the word, using mystery, do the following
            if (word[i] == guess) { //check if the word has the guessed letter
                mysteryWord[i] = guess;
                correctGuess = true;
            }
        }
        if (word == mysteryWord) {
            cout << "Congrats! You got the word correct! The word was: " << mysteryWord << endl;
            break;
        }
        if (correctGuess == false) {
            tries--;
            cout << "Sorry, " << guess << " is not part of the word." << endl;
        }
        else {
            cout << "Nice! " << guess << " is one of the letters" << endl;
        }
    
        switch (tries) {
        case 6: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|              " << endl;
            cout << "\n\n";
            break;
        }
        case 5: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|              " << endl;
            cout << "\n\n";
            if (correctGuess == false) {
                previousGuesses[0] = guess;
            }
            break;
        }
        case 4: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|      |       " << endl;
            cout << "\n\n";
            if (correctGuess == false) {
                previousGuesses[1] = guess;
            }
            break;
        }

        case 3: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|      |       " << endl;
            cout << "|      |       " << endl;
            cout << "\n\n";
            if (correctGuess == false) {
                previousGuesses[2] = guess;
            }
            break;
        }

        case 2: {
            cout << "_______________" << endl;
            cout << "|      |       " << endl;
            cout << "|      O       " << endl;
            cout << "|      |       " << endl;
            cout << "|    / | \\    " << endl;
            cout << "|   /  |  \\   " << endl;
            cout << "\n\n";
            if (correctGuess == false) {
                previousGuesses[3] = guess;
            }
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
            cout << "\n\n";
            if (correctGuess == false) {
                previousGuesses[4] = guess;
            }
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
            cout << "\n\n";
            cout << "Game Over!";
            tries = -1;
            break;
        }
        default:
            cout << "Something went terribly wrong..";
        }
    }
    return 0;
}
