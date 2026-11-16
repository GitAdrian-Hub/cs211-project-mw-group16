IN ORDER TO TEST MOVEMENTS AND MERGING, RANDOM TILE INSERTION WAS TEMPORARLY DISABLED UNLESS STATED OTHERWISE.
1a. TESTING: Sliding & Merging in all four directions.
  Starting board:
  0 2 0 2 0
  2 2 2 0 0
  2 2 2 2 2
  2 2 4 0 0
  4 4 8 0 0
  INPUT: u
  EXPECTED RESULT: Tiles move upward, matching tiles merge, lone tiles go all the way up
  4 4 4 4 2
  2 4 4 0 0
  4 4 8 0 0
  0 0 0 0 0
  0 0 0 0 0
  ACTUAL RESULT: Resulting board matched expected board.
  PASS

1b. TESTING: Sliding & Merging in all four directions.
  Starting board:
  0 2 0 2 0
  2 2 2 0 0
  2 2 2 2 2
  2 2 4 0 0
  4 4 8 0 0
  INPUT: d
  EXPECTED RESULT: Tiles move downward, matching tiles merge, lone tiles go all the way down
  0 0 0 0 0
  0 0 0 0 0
  2 4 4 0 0
  4 4 4 0 0
  4 4 8 4 2
  ACTUAL RESULT: Resulting board matched expected board.
  PASS

1c. TESTING: Sliding & Merging in all four directions.
  Starting board:
  0 2 0 2 0
  2 2 2 0 0
  2 2 2 2 2
  2 2 4 0 0
  4 4 8 0 0
  INPUT: l
  EXPECTED RESULT: Tiles move left, matching tiles merge, lone tiles go all the way to the left
  4 0 0 0 0
  4 2 0 0 0
  4 4 2 0 0
  4 4 0 0 0
  8 8 0 0 0
  ACTUAL RESULT: Resulting board matched expected board.
  PASS

1d. TESTING: Sliding & Merging in all four directions.
  Starting board:
  0 2 0 2 0
  2 2 2 0 0
  2 2 2 2 2
  2 2 4 0 0
  4 4 8 0 0
  INPUT: r
  EXPECTED RESULT: Tiles move right, matching tiles merge, lone tiles go all the way to the right
  0 0 0 0 4
  0 0 0 2 4
  0 0 2 4 4
  0 0 0 4 4
  0 0 0 8 8
  ACTUAL RESULT: Resulting board matched expected board.
  PASS

2a. TESTING: No tiles merge twice in one move using three equal tiles, then four equal tiles.
   CREATED TEMPORARY BOARD: 3 equal tiles
   2 2 2 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   INPUT: l
   EXPECTED RESULT: Two leftmost 2s merge into a 4. Third 2 remains a 2 and does not merge with newly created 4.
   4 2 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   ACTUAL RESULT: Tiles merged as expected. Third tile remained 2.
   PASS
2b. TESTING: No tiles merge twice in one move using three equal tiles, then four equal tiles. 
 CREATED TEMPORARY BOARD: 4 equal tiles
   2 2 2 2 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   INPUT: l
   EXPECTED RESULT: Two leftmost 2s merge into a 4. Rightmost 2s also merge into a 4. Tiles go no farther than merging with closest matching tile.
   4 4 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   ACTUAL RESULT: Tiles merged as expected.
   PASS

3. TESTING: A successful slide with no merge: one new 2, one counted move, no score gain.
   CREATED TEMPORARY BOARD: 
   0 0 2 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   Current score: 0
   Successful moves: 0
   INPUT: l
   EXPECTED RESULT: Tile moves all the way in the direction that is inputted. Score does not increase. Successful move counter goes up by 1. New tile inserted.
   2 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0 //new tile inserted somewhere randomly.
   0 0 0 0 0
   0 0 0 0 0
   Expected score: 0
   Expected moves: 1
   ACTUAL RESULT: Tile moved all the way to the left, score remained the same, move counter went up by 1, new tile inserted.
   PASS

4. An unchanged move: no inserted tile and no changed counters.
   Starting board:
   2 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   Current score: 0
   Successful moves: 0
   INPUT: l
   EXPECTED RESULT: Board, move counter, and score remain unchanged. No random tile inserted.
   Expected score: 0
   Expected moves: 0
   ACTUAL RESULT: Everything remained the same and worked as expected.
   PASS

5a. A full board with a possible merge, and a full board with no possible moves.
   CREATED TEMPORARY BOARD: Full board with possible merge.
   2, 2, 4, 8, 16
   4, 8, 16, 32, 64
   8, 16, 32, 64, 128
   16, 32, 64, 128, 256
   32, 64, 128, 256, 512
   INPUT: l
   EXPECTED RESULT: First two 2s merge into a 4. One new random tile inserted into empty cell.
   4, 4, 8, 16, 0 //random tile inserted in empty cell
   4, 8, 16, 32, 64
   8, 16, 32, 64, 128
   16, 32, 64, 128, 256
   32, 64, 128, 256, 512
   ACTUAL RESULT: First 2s merged and one new random tile was inserted into the remaining empty cell.
   PASS
   
5b. A full board with a possible merge, and a full board with no possible moves.
     CREATED TEMPORARY BOARD: Full board with no possible moves.
     2, 4, 8, 16, 32
     4, 8, 16, 32, 64
     8, 16, 32, 64, 128
     16, 32, 64, 128, 256
     32, 64, 128, 256, 512
     INPUT: u,d,l,r
     EXPECTED RESULT: Score, counter, board remain unchanged after every command. No tiles inserted. Each move reports no movement.
     ACTUAL RESULT: Everything remained unchanged, no tiles inserted, message: "Move resulted in no changes." no matter the direction.
     PASS

6a. Several merges in one move, correct score updates, and reaching the 2048 target.
   CREATED TEMPORARY BOARD: Serveral merges in one move.
    2 2 4 4 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
   Current score: 0
   Sucessful moves: 0
   INPUT: l
   EXPECTED RESULT:The 2s merge together to create a 4 and the 4s merge together to create an 8 when a direction is selected once. 
   Score increases by 12, move increases by 1.
   4 8 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   0 0 0 0 0
   Expected score: 12
   Expected moves: 1
   ACTUAL RESULT: The matching tiles merged together using ONE move. Score increased by 12, move increased by 1.
   PASS
   
6b. Several merges in one move, correct score updates, and reaching the 2048 target.

6c. Several merges in one move, correct score updates, and reaching the 2048 target.
     CREATED TEMPORARY BOARD: Reaching the 2048 target.
     1024 1024 0 0 0 
     0 0 0 0 0 
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     Current score: 0
     Sucessful moves: 0
     INPUT: l
     EXPECTED RESULT: The two 1024 tiles merge into one 2048 tile. Score increase by 2048, moves increase by 1. Program gives user message congratulating them.
     2048 0 0 0 0 
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     Expected score: 2048
     Expected moves: 1
     ACTUAL RESULT: 1024 tiles merged into one 2048 tile, score increased by 2048, moves increased by 1. Message to user: "Congratulations! You reached 2048!".
     PASS
     
7. Save, change the game, and load: exact restoration of all cells and counters.
   Starting board:
   0 2 0 2 0
   2 2 2 0 0
   2 2 2 2 2
   2 2 4 0 0
   4 4 8 0 0
   Current score: 0
   Sucessful moves: 0
   INPUT:u,d,s,l,r
   EXPECTED RESULT: Game should return to the exact state of when it was first saved. Count and score save their values. Every tile returns to its saved position.
   Loading does not interfere with count,score, or add a new random tile when the load command is used.
   Board when save command used:
   0 0 0 4 0
   0 0 0 0 0
   4 0 0 0 0
   2 8 8 0 0
   4 8 8 4 2
   Current score: 44
   Successful moves: 2
   ACTUAL RESULT: After using up and down commands, game was saved, then left and right commands were used. The load command was then used
   to load the board, score, and counter of when the game was first saved before the left and right command. Everything stayed intact,
   scores saved their values along wit tile positions and laod command did not interfere with any other command or add new tiles when used.
   PASS

8a. Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.
   LOADING A MISSING FILE
   INPUT: o
   EXPECTED RESULT: An error message appears because the save file cannot be opened. The active board,score, and successful move count remain unchanged.
   ACTUAL RESULT: The program displayed "Error: Unable to open save file." because the save file was missing.
   PASS
8b. Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.
   LOADING AN INCOMPLETE SAVE FILE
   SAVE FILE(savegame.txt): Contains the correct version marker, score, move count, but only four rows of board data.
   INPUT: o
   EXPECTED RESULT: An error message appears because the save file is incomplete. The active board, score, and successful move count remain unchanged.
   ACTUAL RESULT: The program rejected the incomplete save file and displayed "Error: Missing or invalid board data." The active game remained unchanged.
   PASS
8c.  Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.
   LOADING A MALFORMED SAVE
   SAVE FILE: Contains an incorrect version marker
   instead of CS211_2048_V1.
   INPUT: o
   EXPECTED RESULT: The program rejects the save file and displays an error message. The active board, score, and successful move count remain unchanged.
   ACTUAL RESULT: The program rejected the save file
   because of the incorrect version marker. Program displayed "Error: Invalid save file version." The active game remained unchanged.
   PASS
8d. Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.
    LOADING SAVE WITH INVALID TILE VALUE
   SAVE FILE: Contains the invalid tile value 3.
   INPUT: o
   EXPECTED RESULT: The program rejects the save file and displays an error message. The active board, score, and successful move count remain unchanged.
   ACTUAL RESULT: The program rejected the save file because it contained an invalid tile value. Error message "Error: Invalid tile value." was displayed.
   The active game remained unchanged.
   PASS
9a. Help, invalid commands, new-game confirmation, and exit behavior.
    HELP COMMAND
   INPUT: h
   EXPECTED RESULT: The program displays instructions explaining the available commands, including how to save and load games. It also explains that saving
   again replaces the previous savegame.txt file.
   ACTUAL RESULT: The help instructions displayed successfully and explained the available commands and save-file behavior.
   PASS
9b. Help, invalid commands, new-game confirmation, and exit behavior.
    INVALID COMMANDS
    INPUT: z
     EXPECTED RESULT: The program displays an invalid command message, does not crash, and allows the user to enter another command. The board, score,
     and successful move count remain unchanged.
     ACTUAL RESULT: The program displayed the message "Invalid command. Please try again." and continued running normally.
     The game state remained unchanged.
     PASS
9c. Help, invalid commands, new-game confirmation, and exit behavior.
    NEW GAME
   INPUT: n, then y
   EXPECTED RESULT: The program asks for confirmation. If confirmed, the board resets, the score and successful move count return to 0, and two starting
   tiles are inserted.
   ACTUAL RESULT: The program requested confirmation. After entering y, a new game started successfully. The board reset, counters returned to 0, and two
   random tiles (a 2 and a 4) were inserted.
   PASS
   INPUT: n, then n
   EXPECTED RESULT: The program cancels the new game. The current board, score, and successful move count remain unchanged.
   ACTUAL RESULT: The program displayed "New game cancelled!" and preserved the current board and counter values.
   PASS
9d. Help, invalid commands, new-game confirmation, and exit behavior.
    EXIT COMMAND
    INPUT: e
    EXPECTED RESULT: The program exits the game normally and displays the user's final score. No additional movement or random tile should occur. 
    ACTUAL RESULT: The program exited normally and displayed the user's final score. No errors occurred.
    PASS
       
   
