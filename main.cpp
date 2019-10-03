#include <iostream>
//#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;


void computerMove(char board[][3]);
int randIndx();
bool isDraw(char board[][3]);
char *diagonalsCrossed(char board[][3]);
char *columnCrossed(char board[][3]);
char *rowCrossed(char board[][3]);
void fillCell(char board[][3], int cellNo, char player);
bool isCellFee(char board[][3], int cellNo);
void printGameInstructions();
void printGameBoard(char board[][3]);


int main() {
    // Tic-Tac-Toe game
    int cellNo;
    char board[4][3] = {{' ',' ',' '},{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}} ;
    bool gamePlaying = true;
    char inStr[1];
    srand(time(NULL));

    printGameInstructions();
    printf("\n");

    printf("Computer starts the game since it doing random moves");
    computerMove (board);
    printf("\nNew situation:\n");
    printGameBoard(board);

    while (gamePlaying == true)
    {

        printf("\nPlease enter your move: numbers 1-9\n");
        cin >> inStr;
        cellNo = atoi (inStr);

        if (isCellFee(board, cellNo) != true)
        {
            printf("The cell is not empty, please select the wright one.");
            continue;
        } else
        {
            fillCell(board, cellNo, 'H');
        }
        printf("New situation\n");
        printGameBoard(board);

        if(strcmp(rowCrossed(board), "HUMAN") == 0 ||
           strcmp(columnCrossed(board), "HUMAN") == 0 ||
           strcmp(diagonalsCrossed(board), "HUMAN") == 0)
        {
            printf ("\nHuman has won. Game over.");
            return 0;
        }
        if (isDraw(board) == true)
        {
            printf ("\nResult is draw. Game over.");
            return 0;
        }

        computerMove (board);
        printf("\nNew situation\n");
        printGameBoard(board);

        if(strcmp(rowCrossed(board), "COMPUTER") == 0 ||
           strcmp(columnCrossed(board), "COMPUTER") == 0 ||
           strcmp(diagonalsCrossed(board), "COMPUTER") == 0)
        {
            printf ("\nComputer has won. Game over.");
            return 0;
        }
        if (isDraw(board) == true)
        {
            printf ("\nResult is draw. Game over.");
            return 0;
        }
    }
}

void computerMove(char board[][3])
{
    bool isMovedPC = false;
    int rndIndx =0;

    while (isMovedPC == false)
    {
        rndIndx = randIndx();
        //printf("\nrndIndx= %d\n", rndIndx);
        if (isCellFee(board, rndIndx))
        {
            fillCell(board, rndIndx, 'C');
            isMovedPC = true;
        }
    }
}

int randIndx()
{
    double rnd;
    int rndIndx;

    rnd = (double)rand() / ((double)RAND_MAX + 1);
    rndIndx = (int) round(rnd*8) + 1;

    return rndIndx;
}

bool isDraw(char board[][3])
{
    static bool isDraw = false;
    for(int i=1; i<4; i++)
    {
        if (board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
            board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ' &&
            board[3][0] != ' ' && board[3][1] != ' ' && board[3][2] != ' ')
            isDraw = true;
        else
            isDraw = false;
    }
    return isDraw;
}

char *diagonalsCrossed(char board[][3])
{
    static char resultHuman[10] = "HUMAN", resultComputer[10] = "COMPUTER", resultNobody[10]= "NOBODY";

    if (board[1][0] == board[2][1] && board[2][1] == board[3][2] && board[1][0] == 'X')
    {
        return  resultHuman;
    }
    if (board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[1][2] == 'X')
    {
        return  resultHuman;
    }
    if (board[1][0] == board[2][1] && board[2][1] == board[3][2] && board[1][0]  == 'O')
    {
        return  resultComputer;
    }
    if (board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[1][2] == 'O')
    {
        return  resultComputer;
    }

    return resultNobody;
}

char *rowCrossed(char board[][3])
{
    static char resultHuman[10] = "HUMAN", resultComputer[10] = "COMPUTER", resultNobody[10]= "NOBODY";
    for (int i=1; i<4; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'X')
        {
            return  resultHuman;
        }
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'O')
        {
            return  resultComputer;
        }
    }
    return resultNobody;
}

char *columnCrossed(char board[][3])
{
    static char resultHuman[10] = "HUMAN", resultComputer[10] = "COMPUTER", resultNobody[10]= "NOBODY";
    for (int j=0; j<3; j++)
    {
        if (board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[1][j] == 'X')
        {
            return  resultHuman;
        }

        if (board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[1][j] == 'O')
        {
            return  resultComputer;
        }
    }
    return resultNobody;
}

void fillCell(char board[][3], int cellNo, char player)
{
    switch (cellNo)
    {
        case 1 :
            if(player == 'H')
                board[1][0] = 'X';
            else
                board[1][0] = 'O';
            break;
        case 2 :
            if(player == 'H')
                board[1][1] = 'X';
            else
                board[1][1] = 'O';
            break;
        case 3 :
            if(player == 'H')
                board[1][2] = 'X';
            else
                board[1][2] = 'O';
            break;
        case 4 :
            if(player == 'H')
                board[2][0] = 'X';
            else
                board[2][0] = 'O';
            break;
        case 5 :
            if(player == 'H')
                board[2][1] = 'X';
            else
                board[2][1] = 'O';
            break;
        case 6 :
            if(player == 'H')
                board[2][2] = 'X';
            else
                board[2][2] = 'O';
            break;
        case 7 :
            if(player == 'H')
                board[3][0] = 'X';
            else
                board[3][0] = 'O';
            break;
        case 8 :
            if(player == 'H')
                board[3][1] = 'X';
            else
                board[3][1] = 'O';
            break;
        case 9 :
            if(player == 'H')
                board[3][2] = 'X';
            else
                board[3][1] = 'O';
            break;
    }
}

bool isCellFee(char board[][3], int cellNo)
{
    bool isFree = true;
    switch (cellNo)
    {
        case 1 :
            if(board[1][0] == ' ' )
                isFree = true;
            else
                isFree = false;
            break;
        case 2 :
            if(board[1][1] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
        case 3 :
            if(board[1][2] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
        case 4 :
            if(board[2][0] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
        case 5 :
            if(board[2][1] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
        case 6 :
            if(board[2][2] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
        case 7 :
            if(board[3][0] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
        case 8 :
            if(board[3][1] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
        case 9 :
            if(board[3][2] == ' ')
                isFree = true;
            else
                isFree = false;
            break;
    }
    return isFree;
}

void printGameBoard(char board[][3])
{
    for (int i=1; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (j==0)
                printf ("\t %c |", board[i][j]);
            else if (j==1)
                printf (" %c |", board[i][j]);
            else if (j==2)
                printf (" %c ", board[i][j]);
        }
        if (i != 3)
            printf("\n\t-----------\n");
    }
}


void printGameInstructions()
{
    printf("TIC-TAC_TOE GAME\n");
    printf("The player has to type cell number in order to put X on the board:\n\n");
    printf("\t 1 | 2 | 3 \n");
    printf("\t-----------\n");
    printf("\t 4 | 5 | 6 \n");
    printf("\t-----------\n");
    printf("\t 7 | 8 | 9\n");
}
