#include <stdio.h>

// Global board: index 1–9 used, index 0 unused for convenience
char board[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// Function prototypes
void drawBoard(void);
int markBoard(int choice, char mark);
int checkForWin(void);

int main(void)
{
    int player = 1;
    int gameStatus = -1;    // -1 = game continues, 0 = draw, 1 = win
    int choice;
    char mark;

    while (gameStatus == -1)
    {
        drawBoard();

        // Decide current player
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d (%c), enter a number (1-9): ", player, mark);
        scanf("%d", &choice);

        // Try to mark the board; if invalid, repeat same player's turn
        if (!markBoard(choice, mark))
        {
            printf("Invalid move! Try again.\n");
            // Don't switch player if move was invalid
            // (decrement player so next iteration keeps same player)
            player--;
        }

        gameStatus = checkForWin();
        player++;  // move to next player (or finalize if game over)
    }

    drawBoard();

    if (gameStatus == 1)
    {
        // We incremented player after the last valid turn, so winner is player - 1
        printf("==> Player %d wins! \n", --player);
    }
    else
    {
        printf("==> Game is a draw.\n");
    }

    return 0;
}

// -------------------- drawBoard --------------------
void drawBoard(void)
{
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", board[7], board[8], board[9]);
    printf("     |     |     \n\n");
}

// -------------------- markBoard --------------------
// Returns 1 if move is valid and applied, 0 if invalid
int markBoard(int choice, char mark)
{
    // Check if choice is in range
    if (choice < 1 || choice > 9)
        return 0;

    // Move is valid only if that cell still has its original number
    if (board[choice] == ('0' + choice)) // e.g. '0' + 1 = '1' (generates char representation of numbers)
    {
        board[choice] = mark;
        return 1;
    }
    else
    {
        return 0;
    }
}

// -------------------- checkForWin --------------------
// Returns:
// 1  if someone has won
// 0  if game is a draw (no empty spaces)
// -1 if the game should continue
int checkForWin(void)
{
    // Winning combinations: rows, columns, diagonals
    if (board[1] == board[2] && board[2] == board[3])
        return 1;
    else if (board[4] == board[5] && board[5] == board[6])
        return 1;
    else if (board[7] == board[8] && board[8] == board[9])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[3] == board[6] && board[6] == board[9])
        return 1;
    else if (board[1] == board[5] && board[5] == board[9])
        return 1;
    else if (board[3] == board[5] && board[5] == board[7])
        return 1;

    // Check for draw: no positions with original numbers left
    else if (board[1] != '1' &&
             board[2] != '2' &&
             board[3] != '3' &&
             board[4] != '4' &&
             board[5] != '5' &&
             board[6] != '6' &&
             board[7] != '7' &&
             board[8] != '8' &&
             board[9] != '9')
    {
        return 0;  // draw
    }

    // Otherwise game is still going
    else
    {
        return -1;
    }
}
