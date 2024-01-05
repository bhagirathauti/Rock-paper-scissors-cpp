#include <cstdlib> 
#include <ctime> 
#include <iostream> 
using namespace std; 

// COMPUTER TURN
char getComputerTurn() 
{ 
	int move; 
	// RANDOM NUMBER GENERATION
	srand(time(NULL)); 
	move = rand() % 3; 

	// RETURNING TURN BASED ON RANDOM NUMBER GENERATION
	if (move == 0) { 
		return 'p'; 
	} 
	else if (move == 1) { 
		return 's'; 
	} 
	return 'r'; 
} 

// GETTING GAME RESULTS
int getResults(char playerTurn, char computerTurn) 
{ 
	// DRAW CONDITION
	if (playerTurn == computerTurn) { 
		return 0; 
	} 

	// GAME CONDITIONS
	if (playerTurn == 's' && computerTurn == 'p') { 
		return 1; 
	} 
	if (playerTurn == 's' && computerTurn == 'r') { 
		return -1; 
	} 
	if (playerTurn == 'p' && computerTurn == 'r') { 
		return 1; 
	} 
	if (playerTurn == 'p' && computerTurn == 's') { 
		return -1; 
	} 
	if (playerTurn == 'r' && computerTurn == 'p') { 
		return -1; 
	} 
	if (playerTurn == 'r' && computerTurn == 's') { 
		return 1; 
	} 
	
	return 0; 
} 

// DRIVER CODE
int main() 
{ 

	char playerTurn; 

	cout << "\n\n\n\t\t\tWelcome to Stone Paper Scissor "
			"Game\n"; 

	cout << "\n\t\tEnter r for ROCK, p for PAPER, and s "
			"for SCISSOR\n\t\t\t\t\t"; 

	//USER TURN
	while(1) { 
		cin >> playerTurn; 
		if (playerTurn == 'p' || playerTurn == 'r' || playerTurn == 's') { 
			break; 
		} 
		else { 
			cout << "\t\t\tInvalid Player Turn!!! Please Try Again." << endl; 
		} 
	} 
	
	//COMPUTER TURN 
	char computerTurn = getComputerTurn(); 

	int result = getResults(playerTurn, computerTurn); 

	// RESULTS 
	if (result == 0) { 
		cout << "\n\t\t\tGame Draw!\n"; 
	} 
	else if (result == 1) { 
		cout << "\n\t\t\tCongratulations! Player won the "
				"game!\n"; 
	} 
	else { 
		cout << "\n\t\t\tOh! Computer won the game!\n"; 
	} 

	// SHOWING INPUTS OF PLAYER AND COMPUTER
	cout << "\t\t\tYour Turn: " << playerTurn << endl; 
	cout << "\t\t\tComputer's Turn: " << computerTurn << endl; 

	return 0; 
}
