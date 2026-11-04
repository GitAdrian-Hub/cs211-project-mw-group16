#include <iostream>
#include "2048_helper.h"
using namespace std;

int main()
{
	int size = 5;
	int board[5][5] = {
		{0, 2, 0, 2, 0},
		{2, 2, 2, 0, 0},
		{2, 2, 2, 2, 2},
		{2, 2, 4, 0, 0},
		{4, 4, 8, 0, 0},
	};
	//while getch == x loop for up down left right

	cout << "Initial Board : [5x5] :" << endl;
	print_board(board, size);

	char choice = 'u';	//initialized
	int current_score = 0; //to keep track of score to be updated as the game is played
	while (choice != 'e')
	{
        bool changed = false; //check if movement happened
		cout << "Please enter choice:{u,d,l,r,e} for UP, DOWN, LEFT, RIGHT, Exit: " << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 'u')
			move_up(board, size, current_score);
		else if (choice == 'd')
			move_down(board, size, current_score);
		else if (choice == 'l') //this to move left 
			changed = move_left(board, size, current_score); 
		else if (choice == 'r')
			move_right(board, size, current_score);

		if (changed == true)
		{
		    insert_random(board, size);
		}
		print_board(board, size);

	}


	return 0;
}
