#include "2048_helper.h"   
#include <iostream>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>
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
bool move_right(int board[5][5], int size, int& current_score) {   
    bool board_changed = false;
    for(int r = 0; r < size; r++) // will go through every row (5 of them)
    {
        int insertposition = size - 1; // size - 1 starts at the rightmost part of the row
        for(int c = size - 1; c >= 0; c--) // this loop goes through every column from right to left
        {
            if (board[r][c] != 0) // checks each section for a number
            {
                if(c != insertposition) // checks if the tile selected is not already too far right
                {
                    board[r][insertposition] = board[r][c]; // puts the number into the spot on the right
                    board[r][c] = 0; // original position is moved to 0 after number moves right
                    board_changed = true; // a move happened
                }
                insertposition--; // moves 1 to the left to check the next block
            }
        }
        // code needed to merge the tiles to the right
        for (int c = size - 1; c > 0; c--) // stop 1 before the left end to check adjacent blocks safely
        {
            if(board[r][c] != 0 && board[r][c] == board[r][c-1]) // compares the block to the block directly left
            {
                board[r][c] = board[r][c] * 2; // double the value upon merging
                current_score = current_score + board[r][c]; // add merged value to total score
                board[r][c-1] = 0; // the spot that was just merged from the left becomes 0
                board_changed = true;
                // move the rest of the row to the right to fill the gap
                for (int k = c - 1; k > 0; k--) 
                {
                    board[r][k] = board[r][k-1]; // shift blocks to the right
                }
                board[r][0] = 0; // makes the very first block on the row 0
            }
        }
    }
    return board_changed;
}
bool move_up(int board[5][5], int size, int& current_score) {
    bool board_changed = false;
    for(int c = 0; c < size; c++) // will go through every column (5 of them)
    {
        int insertposition = 0; // 0 starts at the topmost part of the column
        for(int r = 0; r < size; r++) // this loop goes through every row from top to bottom
        {
            if (board[r][c] != 0) // checks each section for a number
            {
                if(r != insertposition) // checks if the tile is not already too high up
                {
                    board[insertposition][c] = board[r][c]; // moves the number upward
                    board[r][c] = 0; // original position becomes 0
                    board_changed = true; // a move happened
                }
                insertposition++; // moves 1 down to check the next row position
            }
        }
        // code needed to merge the tiles upwards
        for (int r = 0; r < size - 1; r++) // stop 1 before the bottom to check adjacent rows safely
        {
            if(board[r][c] != 0 && board[r][c] == board[r+1][c]) // compares current block to the one directly below it
            {
                board[r][c] = board[r][c] * 2; // double the value upon merging
                current_score = current_score + board[r][c]; // add merged value to total score
                board[r+1][c] = 0; // the spot below that was merged becomes 0
                board_changed = true;
                // move the rest of the column upward to fill the gap
                for (int k = r + 1; k < size - 1; k++) 
                {
                    board[k][c] = board[k+1][c]; // shift blocks upward
                }
                board[size - 1][c] = 0; // makes the very bottom block 0
            }
        }
    }
    return board_changed;
}
bool move_down(int board[5][5], int size, int& current_score) {
    bool board_changed = false;
    for(int c = 0; c < size; c++) // will go through every column (5 of them)
    {
        int insertposition = size - 1; // size - 1 starts at the bottommost part of the column
        for(int r = size - 1; r >= 0; r--) // this loop goes through every row from bottom to top
        {
            if (board[r][c] != 0) // checks each section for a number
            {
                if(r != insertposition) // checks if the tile is not already too far down
                {
                    board[insertposition][c] = board[r][c]; // moves the number downward
                    board[r][c] = 0; // original position becomes 0
                    board_changed = true; // a move happened
                }
                insertposition--; // moves 1 up to check the previous row position
            }
        }
        // code needed to merge the tiles downwards
        for (int r = size - 1; r > 0; r--) // stop 1 before the top to check adjacent rows safely
        {
            if(board[r][c] != 0 && board[r][c] == board[r-1][c]) // compares current block to the one directly above it
            {
                board[r][c] = board[r][c] * 2; // double the value upon merging
                current_score = current_score + board[r][c]; // add merged value to total score
                board[r-1][c] = 0; // the spot above that was merged becomes 0
                board_changed = true;
                // move the rest of the column downward to fill the gap
                for (int k = r - 1; k > 0; k--) 
                {
                    board[k][c] = board[k-1][c]; // shift blocks downward
                }
                board[0][c] = 0; // makes the very top block 0
            }
        }
    }
    return board_changed;
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

void insert_random(int board[5][5], int numrows) 
{
	int r, c;
	int empty_count = 0;
	for (int r = 0; r < numrows; r++) 
	{
		for (int c = 0; c < 5; c++) 
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}
	if (empty_count > 0) 
	{
		while (true) 
		{
			r = rand() % numrows;
			c = rand() % numrows;
			if (board[r][c] == 0) 
			{
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}
	}
}
bool save_game(int board[5][5], int size, int current_score, int successful_moves)//SAVE GAME, write down current score, # of moves, what the matrix looked like when game was saved 
{
    ofstream sfile; //creates ofstream variable named "sfile" for save file
    sfile.open("savegame.txt"); //attaches savegame.txt to ofstream
    
    if(!sfile) //this checks whether the file failed to open 
    {
        cout<<"Error: Unable to open save file."<<endl;
        return false; //says saving was Unsuccessful
    }
    
    sfile<<"CS211_2048_V1"<<endl; //use sfile instead of cout since we are writing this in the file we made, NOT the terminal
    sfile<<current_score<<" "<<successful_moves<<endl; //writing current score and movements in file EX: 8 3
    
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            sfile<<board[r][c]<<" ";
        }
        
        sfile<<endl;
    }
    
    sfile.close(); //closes file
    
    if(!sfile) //checks writing and closing success 
    {
        cout<<"Error: Unable to write save file."<<endl;
        return false;
        
    }
    
    return true; //saving successful AFTER verfying
}
bool load_game(int board[5][5], int size, int& current_score, int& successful_moves)//LOAD GAME, reads what is in the save file and loads it 
{
    ifstream sfile; //input file 
    sfile.open("savegame.txt");//connects to our saved game
    
    if(!sfile) //checks if file failed to open
    {
        cout<<"Error: Unable to open save file."<<endl;
        return false; //says loading was Unsuccessful
    }
    
    string loadversion; //read load version from the file
    sfile>>loadversion; //^
    
    if(loadversion != "CS211_2048_V1")
    {
        cout<<"Error: Invalid save file version."<<endl;
        return false;
    }
    
    int temp_score;
    int temp_moves;
    
    sfile>>temp_score>>temp_moves; //reads and stores score and moves 
    
    if(!sfile)
    {
        cout<<"Error: Missing or invalid save file counters."<<endl;
        return false;
    }
    if(temp_score < 0 or temp_moves < 0) //makes sure no negatives, otherwise rejects file
    {
        cout<<"Error: Invalid save file counters."<<endl;
        return false;
    }
    
    int temp_board[5][5]; //creating temp board to verify everything is correct before transfering values into actual board
    
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            sfile>>temp_board[r][c];
            
            if(!sfile)
            {
                cout<<"Error: Missing or invalid board data."<<endl; //checking success
                return false;
            }
            
            bool valid_tile = false; //checking each tile is valid

            if(temp_board[r][c] == 0) //check tile = 0
            {
                valid_tile = true;
            }
            else if(temp_board[r][c] >= 2) //check tile atleast 2 if not = 0 
            {
                int value = temp_board[r][c];

                while(value % 2 == 0) //loop continues while value is divisible by 2
                {
                    value = value / 2;
                }

                if(value == 1) //cheking if value is exactly 1, if not then value is invalid 
                {
                    valid_tile = true;
                }
            }

            if(!valid_tile) //rejects invalid tiles
            {
                cout<<"Error: Invalid tile value."<<endl;
                return false;
            }
        }
    }
    
    //check for extra values, must only have 25 
    char extravalues;
    
    if(sfile>>extravalues)
    {
        cout<<"Error: Extra content found in file."<<endl;
        return false;
        
    }
    
    //copy values from temp board onto actual after verifying
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            board[r][c] = temp_board[r][c];
        }
    }
    
    current_score = temp_score;
    successful_moves = temp_moves;
    
    sfile.close();

    return true;
}

