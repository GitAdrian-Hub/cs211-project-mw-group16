#include "2048_helper.h"   
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
bool move_left(int board[5][5], int size, int& current_score)
{
    bool board_changed = false; 
    for(int r = 0; r<size; r++) //will go through every row (5 of them)
    {
        int insertposition = 0;  //0 starts at the leftmost part of the row
        for(int c = 0; c < size; c++ ) //this loop goes through every column from left to right
        {
            if (board[r][c] != 0) //checks each section for a number (2, 4, 8) 
            {
                if(c != insertposition) //checks if the tile selected is not already too far left
                {                       
                    board[r][insertposition] = board[r][c]; //puts the number into the spot on the left
                    board[r][c] = 0;       //original position is moved to 0 after number moves left
                    board_changed = true; //a move happened so a new number block can be added
                }
                insertposition++;       //moves 1 to the right to check the next block
            }   
        }
      //code needed to merge the tiles now
        for (int c = 0; c<size - 1; c++) //stop 1 before the end so we can check the rightmost block without trying to check outside the array
        {
            if(board[r][c] != 0 && board[r][c] == board[r][c+1]) //this compares the block to the block directly right to see if its equal
             {
                board[r][c] = board[r][c] * 2; //multiply 2 to 4, 4 to 8, etc if numbers equal 
                current_score = current_score + board[r][c]; //the value of the block is now added to the total score
                board[r][c+1] = 0; //the spot that was just merged from the right is now 0   
                board_changed = true;
                //i need to move the rest of the row to the left
                for (int k = c + 1;  k < size - 1; k++) //start at the gap left from the merged or move on the right, k is - 1 so it doesnt check outside the array
                {
                    board[r][k] = board[r][k+1]; //takes the block to the right of [r][k] and moves it to the left
                }
                board[r][size -1] = 0; //makes the very last block on the row 0 cuz it would have to be 0 if a move happened 
            }                                                
        } 
    }
    return board_changed;    
}  
bool move_right(int board[5][5], int size, int& current_score) {   //this is where the rest of the movement needs to begin
	return false;
}
bool move_up(int board[5][5], int size, int& current_score) {
	return false;
}
bool move_down(int board[5][5], int size, int& current_score) {
	return false;
}
void print_board(int board[5][5], int numrows) {
	cout << endl << "\t-----------------------------------------" << endl;
	for (int r = 0; r < numrows; r++) {
		for (int c = 0; c < 5; c++) {
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}
	cout << "\t" << endl << endl;
}

void insert_random(int board[5][5], int numrows) {
	int r, c;
	int empty_count = 0;
	for (int r = 0; r < numrows; r++) {
		for (int c = 0; c < 5; c++) {
			if (board[r][c] == 0)
				empty_count++;
		}
	}
	if (empty_count > 0) {
		while (true) {
			r = rand() % numrows;
			c = rand() % numrows;
			if (board[r][c] == 0) {
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}
	}
}
