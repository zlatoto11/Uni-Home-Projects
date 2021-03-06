// Hangman Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctime>


int main()
{
	srand(time(NULL));	//normal rand isnt actually random , this randoms the seed so its different each time
	char randomWords[][16] = {
		"Random 1", //0 Index 0
		"Random 12",
		"Random 13",
		"Random 1424",
		"Random 142",
		"Random 15",
		"Random 1215",
		"Random 1785",
		"Random 18",
		"Random 195865",
		"Random 15585" // Index 10
	};
	//Indexes for random word
	int randomIndex = rand() % 10; //10 is max index	rand is between 0-32765 selects random word
	int loopIndex, fullrand, oldCorrect, reguessed = 0;
	int quit = 0;
	int numCorrect = 0;
	int numOfHearts = 5;

	int wordLength = strlen(randomWords[randomIndex]); //Stores length of word from index
	int lettersGuessed[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // array to keep track of letters guessed correctly

	char guess[16];
	char letterEntered;

	printf("guessWords: %s randomIndex: %d wordLength: %d\n",//Debugging purposes
		randomWords[randomIndex],
		randomIndex,
		wordLength);

	while (numCorrect < wordLength) { //game loop

		printf("Number of correct guesses so far:%d\n", numCorrect);
		printf("Enter your guess letter:");
		fgets(guess, 16, stdin); // take up to size 16 input

		if (strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}

		letterEntered = guess[0]; // letter entered is equal to first letter of user input
		reguessed = 0;
		printf("letterGuessed: %c\n", letterEntered);

		oldCorrect = numCorrect;
		printf("Old correct = %s New Correct = %s", oldCorrect, numCorrect);

		for (loopIndex = 0; loopIndex < wordLength; loopIndex++) {

			if (lettersGuessed[loopIndex] == 1) {
				continue;
			}

			if (letterEntered == randomWords[randomIndex][loopIndex]) {
				lettersGuessed[loopIndex] = 1;
				numCorrect++;
			}
		}

		if ( oldCorrect == numCorrect ) {
			numOfHearts--;
			printf("Sorry, wrong guess.");
			if (numOfHearts == 0) {
				break;
			}
			else {
				printf("Correct Guess");
			}
		}
		
		if (quit == 1) {
			printf("\n The user has quit early\n");
		} else if (numOfHearts == 0) {
			printf("\nSorry you lose , the word was %s\n",
				randomWords[randomIndex]);
		} else {
			printf("\nYou Win!! :) \n");
		}
		
	}
}