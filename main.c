#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER1 '1'
#define PLAYER2 '2'
#define MONEY 'M'

int MONEY_VALUES[7] = {1, 2, 5, 10, 20, 50, 100};

char** initializeBoard(int size);
void displayBoard(char** board, int size);
int hasCapturedMoney(char** board, int x, int y, int *moneyValue);
void movePlayer(char** board, int size, int* x, int* y, char direction, int* score);

int main() {
    int player1Score = 0, player2Score = 0;
    int size;

    printf("Enter the size:\n");
    scanf("%d", &size);
    if (size < 5) {
        printf("Size can be min 5\n");
        return 1;
    }

    char** board = initializeBoard(size);
    int player1X = 0, player1Y = 0; // Player 1 starting position
    int player2X = size - 1, player2Y = size - 1; // Player 2 starting position
    board[player1X][player1Y] = PLAYER1;
    board[player2X][player2Y] = PLAYER2;

    printf("!!Welcome to Capture the Money!!\n");
    printf("Player 1 (1) starts at (0, 0) and Player 2 (2) starts at (%d, %d).\n", size - 1, size - 1);
    printf("The money is hidden on the board. Move your player to capture it.\n");

    while (1) {
        printf("\nCurrent Board:\n");
        displayBoard(board, size);

        // Player 1's turn
        printf("\nPlayer 1's turn (1): Enter move (U/D/L/R): ");
        char move;
        scanf(" %c", &move);
        movePlayer(board, size, &player1X, &player1Y, move, &player1Score);

        printf("\nCurrent Board:\n");
        displayBoard(board, size);

        // Player 2's turn
        printf("\nPlayer 2's turn (2): Enter move (U/D/L/R): ");
        scanf(" %c", &move);
        movePlayer(board, size, &player2X, &player2Y, move, &player2Score);

        // Check if all money is captured
        if (player1Score + player2Score == 188) { // Sum of all money values
            printf("Game Over!\n");
            printf("Player 1 Score: %d\n", player1Score);
            printf("Player 2 Score: %d\n", player2Score);
            if (player1Score > player2Score) {
                printf("Player 1 wins!\n");
            } else if (player2Score > player1Score) {
                printf("Player 2 wins!\n");
            } else {
                printf("It's a draw!\n");
            }
            break;
        }
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

char** initializeBoard(int size) {
    char** board = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        board[i] = (char*)malloc(size * sizeof(char));
        for (int j = 0; j < size; j++) {
            board[i][j] = '.';
        }
    }
    srand(time(NULL));
    for (int i = 0; i < 7; i++) {
        int x = rand() % size;
        int y = rand() % size;
        while (board[x][y] == MONEY) {
            x = rand() % size;
            y = rand() % size;
        }
        board[x][y] = MONEY;
    }

    return board;
}

void displayBoard(char** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int hasCapturedMoney(char** board, int x, int y, int *moneyValue) {
    if (board[x][y] == MONEY) {
        for (int i = 0; i < 7; i++) {
            if (MONEY_VALUES[i] != 0) {
                *moneyValue = MONEY_VALUES[i];
                MONEY_VALUES[i] = 0;  // Mark this money as captured
                return 1;
            }
        }
    }
    return 0;
}

void movePlayer(char** board, int size, int* x, int* y, char direction, int* score) {
    int newX = *x, newY = *y;
    char playerId = board[*x][*y];

    switch (direction) {
        case 'U':
            newX--;
            break;
        case 'D':
            newX++;
            break;
        case 'L':
            newY--;
            break;
        case 'R':
            newY++;
            break;
    }
    // Check if the new position is valid and move the player
    if (newX >= 0 && newX < size && newY >= 0 && newY < size && board[newX][newY] != PLAYER1 && board[newX][newY] != PLAYER2) {
        board[*x][*y] = '.';
        *x = newX;
        *y = newY;
        int moneyValue = 0;
        if (hasCapturedMoney(board, *x, *y, &moneyValue)) {
            *score += moneyValue;
        }
        board[*x][*y] = playerId;
    }
}
