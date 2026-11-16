# CS211 Group Project - MW Group 16
**Repository URL:** [https://github.com/GitAdrian-Hub/cs211-project-mw-group16](https://github.com/GitAdrian-Hub/cs211-project-mw-group16)
**Team Members & GitHub Usernames:**
  * Member A: GitAdrian-Hub
  * Member B: laneabn
  * Member C: JM-Aero
---
## Program One: 2048 Game
A playable 5x5 console-based implementation of the popular 2048 game. Players slide and merge tiles to reach the 2048 tile, track scores, and utilize file persistence to save or load game states.
### Build and Run Commands
```bash
g++ -std=c++17 -Wall -Wextra -pedantic game2048/main.cpp game2048/2048_helper.cpp -o game2048_app
./game2048_app'''
### Game Controls 
u / d / l / r: Move Up, Down, Left, or Right   s: Save current game state to savegame.txt   o: Open/load game state from savegame.txt[cite: 3, 4]n: Start a new game (after confirmation)   h: Display help menu   e: Exit program[cite: 3]
### Save File Behavior 
The game reads and writes to a file named savegame.txt in the current working directory. Saving replaces any existing save slot. Malformed or invalid save files are strictly rejected to protect the active game state.  
