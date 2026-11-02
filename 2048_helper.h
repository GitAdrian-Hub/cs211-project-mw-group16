#ifndef HELPER_2048_H  //this and the endif statement prevent the .h file from being read multiple times
#define HELPER_2048_H

bool move_left(int board[5][5], int size, int& current_score);
bool move_right(int board[5][5], int size, int& current_score);
bool move_up(int board[5][5], int size, int& current_score);
bool move_down(int board[5][5], int size, int& current_score);
void print_board(int board[5][5], int size);
void insert_random(int board[5][5], int size);

#endif
