//By F1T1L.         //
//////////////////////
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isCorrect(int g, int a)
{
	if (g == a)
		return true;

	if (g < a)
		cout << "Too low. Try again.\n? ";
	else
		cout << "Too high. Try again.\n? ";

	return false;
} 

void guessGame()
{
	int answer;
	int guess;
	char response; // 'y' or 'n' response to continue game

	// loop until user types 'n' to quit game
	do {

		answer = 1 + rand() % 1000;
	
		cout << "I have a number between 1 and 1000.\n"
		     << "Can you guess my number?\n"
		     << "Please type your first guess." << endl << "? ";
		cin >> guess;

		while ( !isCorrect( guess, answer ) )  
			cin >> guess;

		// prompt for another game
		cout << "\nExcellent! You guessed the number!\n"
		     << "Would you like to play again (y or n)? ";
		cin >> response;

		cout << endl;
	} while ( response == 'y' );
}



int main()
{
	system("COLOR F5");
	setlocale(0, "");

	guessGame();

	return 0;

}
