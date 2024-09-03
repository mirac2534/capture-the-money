

# Project Name: Capture The Money

Date: 03.08.2024  

This game is capture the money. The rules of the game are simply that the player who collects the most money wins the game. Two players cannot overlap and are not allowed off the board. I used 4 functions in this project. These are initializeBoard, displayBoard, hasCapturedMoney, and movePlayer.


## Planning

### 1. initializeBoard Function
-Firstly, initializeBoard function is for printing the board for the game. It creates a board in the size of the number you entered (provided that it is at least 5). Then he randomly places the money on this board.

### 2. displayBoard Function
- Another function, displayBoard function is for showing the board that has a print. 

### 3. hasCapturedMnoney Function
- hasCapturedMnoney function is for ending the game when all money on the board have been collected. 

### 4. movePlayer Fuction
- This is for players can go in the board with spesific rules.
-- If your chooice is U, you go to up.
-- If your chooice is D, you go to down.
-- If your chooice is L, you go to left.
--If your chooice is R, you go to right.
!!Don't forget this four letters must be Shift!!
- Two characters cannot overlap, and characters cannot exit the board. When you do one of these two, you stay still in your place. 

### 5. main Function
- Firstly, you enter the size of board. If board size you entered is smaller than 5, writes eror message. After the size information is received, the board creation function is called. Then places player1 and player2. Afterward the game stars. If all money is collected, the game is over. The player who collects the most money wins the game. Don't forget you can win by collecting  less money quantity. 
- Enjoy this game :)
