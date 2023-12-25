#include <stdio.h>
#include <ctype.h>

void printPapan(char board[3][3]) {
    printf("================\n");
    int i;
    for (i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("==============\n");
    }
}


int winningCondition(char board[3][3], char player) {
	int i;
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;  
        }
    } //horizontal & vertikal

   
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;  
    } //diagonal

    return 0;  
}


int Full(char board[3][3]) {
	int i;
	int j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  //Board is not full
            }
        }
    }
    return 1;  //Board is full
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    char playerper = 'X';

    do {printPapan(board);
        printf("Player %c, enter your move\n",playerper);
		printf("Row (1-3): ");
        scanf("%d", &row);
        row--;
        printf("Collumn (1-3): ");
        scanf("%d", &col);
        col--;

        
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("SALAH\n");
            continue;
        }
        board[row][col] = playerper;

        
        if (winningCondition(board, playerper)) {
            printPapan(board);
            printf("Player %c wins!\n", playerper);
            break;
        }

      
        if (Full(board)) {
            printPapan(board);
            printf("Seri!\n");
            break;
        }

       
        playerper = (playerper == 'X') ? 'O' : 'X';
    	
    } while (1);
    
    printf("Thank You for Playing!\n");

    return 0;
}
