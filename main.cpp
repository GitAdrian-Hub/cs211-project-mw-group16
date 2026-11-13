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
	int successful_moves = 0; //when game starts, move counter initialized to 0
	bool win_announced = false;
	while (choice != 'e')
	{
        bool changed = false;
        bool movement_command = false; //distinguishes movement commands from save/load commands
		cout << "Current Score: " << current_score << endl;
		cout <<"Successful moves: "<<successful_moves<<endl; //displays how many successful moves for user
		cout << "Please enter choice:{u,d,l,r,e,s,o,n,h}" <<endl;
		cout<<"UP, DOWN, LEFT, RIGHT, Exit, Save, Load, NEW GAME, HELP"<<endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 'u')
		{
			changed = move_up(board, size, current_score);
			movement_command = true;
		}
		else if (choice == 'd')
		{
			changed = move_down(board, size, current_score);
			movement_command = true;
		}
		else if (choice == 'l') //this to move left 
	    {
			changed = move_left(board, size, current_score);
		    movement_command = true;
        }
		else if (choice == 'r')
		{
			changed = move_right(board, size, current_score);
			movement_command = true;
		}
		else if(choice == 'h') //implemented help command
        {
            cout<<"\n========== 2048 HELP =========="<<endl;
            cout<<"u - Move UP"<<endl;
            cout<<"d - Move DOWN"<<endl;
            cout<<"l - Move LEFT"<<endl;
            cout<<"r - Move RIGHT"<<endl;
            cout<<"s - Save current game"<<endl;
            cout<<"o - Load saved game"<<endl;
            cout<<"n - Start a new game"<<endl;
            cout<<"h - Display help instructions"<<endl;
            cout<<"e - Exit game"<<endl;
            cout<<"==============================="<<endl;
            cout<<"Saving again replaces your previous save file."<<endl;
        }
		else if (choice == 's')
		{
		    if(save_game(board, size, current_score, successful_moves))
		       cout<<"Game saved successfully!"<<endl;
		}
		else if (choice == 'o')
		{
		    if(load_game(board, size, current_score, successful_moves))
		    {
    		    cout<<"Game loaded successfully!"<<endl;
    		    win_announced = false;
		    }
		}
		else if (choice == 'n') //create a new game, clears board, resets score and move counter
        {
            char confirm;

            cout<<"Are you sure you want to start a new game? (y/n): ";
            cin>>confirm;

            if(confirm == 'y' or confirm == 'Y')
            {
                for(int r = 0; r < size; r++)
                {
                    for(int c = 0; c < size; c++)
                    {
                        board[r][c] = 0;
                    }
                }

                current_score = 0;
                successful_moves = 0;
        
                insert_random(board, size);
                insert_random(board, size);
                win_announced = false;
                cout<<"New game started!"<<endl;
            }
            else
            {
                cout<<"New game cancelled."<<endl;
            }
        }
		else if (choice == 'e')
		{
			break;
		}
		else
		{
		    cout<<"Invalid command. Please try again."<<endl;
		}

    if(movement_command)
    {
		if (changed == true)
		{
		    successful_moves++; //increases variable by one when changes detected
		    insert_random(board, size);
		    cout << "Move successful!" << endl;
		}
		else
		{
		 cout << "Move resulted in no changes." << endl;
		}
    }	
    
    bool found_2048 = false;

    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            if(board[r][c] >= 2048)
            {
                found_2048 = true;
            }
        }
    }
    
    if(found_2048 == true and win_announced == false)
    {
        cout<<"\nCongratulations! You reached 2048!"<<endl;
        win_announced = true;
    }
	print_board(board, size);
	
	}

	cout << "Final Score: " << current_score << endl;



	return 0;
}
