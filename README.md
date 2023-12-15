# Mancala
C++ Mancala Board Game by Jon Binder

This is my final project for my class, ELEC 3150, Object Oriented Programming.

This program uses five object types: Pit, Board, EasyCPU, MediumCPU, and HardCPU.
The Board object contains 14 Pit objects. Each of these Pits can hold Marbles.

As the Player, you will be going against a CPU of your choice.. Easy, Medium, or Hard.
The CPU objects MediumCPU and HardCPU are child objects of the class EasyCPU.
Each CPU has a technique to win, building on each other as their difficulty increases.

# Rules
Marbles move counterclockwise, skipping the opponent's Mancala.
The bigger Pits or Stores on the top and bottom of the board are called Mancalas.
Each Player has 6 Pits, starting with 4 Marbles in each.
The Pits on the left are the Player’s and the Pits on the right are the CPU's.
On the Player’s turn, a Pit is picked and marbles are placed by one around the board.

On the Player’s turn:
If the last Marble lands in the Player’s Mancala, an extra turn is awarded.
If the last Marble lands in an empty Pit on the Player’s side a capture takes place.
Capturing takes the single marble placed in the Player's empty pit and all the Marbles on the opponent's opposite side.
These Marbles are added to the Player’s Mancala.

When a Player’s side runs out of Marbles, remaining Marbles are placed into their Player’s Mancala.
Whoever has the most Marbles in their Mancala Wins!
