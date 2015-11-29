// Lab 14
// Programmer: Dhanush Patel
// Editor(s) used: Eclipse
// Compiler(s) used: Eclipse

#include <iostream>
using namespace std;

#include <ctime>
#include <cstdlib>

struct Number{
	int num;
	Number* next;
};

int main()
{
	srand(time(0));

	cout << "Programmer: Dhanush Patel" << endl;
	cout << "Description: This programs makes a user guess the right number between 1-100." << endl;
	cout << endl;

	int numberToGuess = 1 + (rand() % 100);

	// int MAX_GUESSES = 100;
	//int nGuesses = 0;
	//int guess[MAX_GUESSES];
	Number* start = 0;

	int numberGuessed;
	cout << "I'm thinking of a number between 1 and 100. Guess what it is: ";
	do{
	cin >> numberGuessed;

	bool match = false;
	for(Number* p = start; p; p = p->next){
		if(p->num==numberGuessed){
			cout << "You already guessed " << p->num << " -- guess again: ";
			match = true;
		}
	}
	if(!match){
		if (numberGuessed == numberToGuess){
			cout << "That's right -- it's " << numberToGuess << endl;
			break;
		}
		if (numberGuessed < numberToGuess){
			Number* s = new Number;
			s->num = numberGuessed;
			s->next = start;
			start = s;
			cout << "That's too low -- guess again: ";
		}
		else{
			Number* s = new Number;
			s->num = numberGuessed;
			s->next = start;
			start = s;
			cout << "That's too high -- guess again: ";
		}
	}
	}while(numberGuessed != numberToGuess);
}
