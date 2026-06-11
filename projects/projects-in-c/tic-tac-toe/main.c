#include <stdio.h>
#include <stdbool.h>

bool isLegalMove(int size, int arr[size][size], int row, int col)
{
    if (arr[row][col] != 0)
        return false;
    else
        return true;
}

bool playerHasWon (int size, int arr[size][size], int player)
{
    // check for rows
    for (int row = 0; row < size; row++)
    {
        if(arr[row][0]==arr[row][1]&&
           arr[row][1]==arr[row][2])
           {
               if(arr[row][0]==player)
               {
                printf("Player %d won!\n winning sequence was row: %d - %d - %d", player, arr[row][0], arr[row][1], arr[row][2]);
                return true;
               }
           }
    }

    //check for columns
    for (int col = 0; col < size; col++)
    {
        if(arr[0][col]==arr[1][col]&&
           arr[1][col]==arr[2][col])
           {
               if(arr[0][col]==player)
               {
                printf("Player %d won!\n winning sequence was col: %d - %d - %d", player, arr[0][col], arr[1][col], arr[2][col]);
                return true;
               }
           }
    }

    //check for diagonals
    if(arr[0][0]==arr[1][1] &&
     arr[1][1]==arr[2][2])
    {
    if(arr[0][0]==player)
       {
        printf("Player %d won!\n winning sequence was ltr diagonal: %d - %d - %d", player, arr[0][0], arr[1][1], arr[2][2]);
        return true;
       }
    }

    if(arr[0][2]==arr[1][1] &&
    arr[1][1]==arr[2][0])
      {
        if(arr[0][2]==player)
           {
            printf("Player %d won!\n winning sequence was rtl diagonal: %d - %d - %d", player, arr[0][2], arr[1][1], arr[2][0]);
            return true;
           }
      }

      return false;
}

bool isFinished(int size, int arr[size][size])
{
    if (playerHasWon(size, arr, 1))
    {
        return true;
    }
    else if (playerHasWon(size, arr, 2))
    {
        return true;
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[i][j] == 0)
                return false;
    return true;
}

void placeMove (int size, int arr[size][size], int row, int col, int player)
{
    if (isLegalMove(size, arr, row, col))
    {
        arr[row][col] = player;
        boardStatus(size, arr);
    }
    else
    {
        printf("Illegal move\n");
        boardStatus(size, arr);
    }
}

void boardStatus(int size, int arr[size][size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if((j+1)%3==0)
                printf("%d\n", arr[i][j]);
            else
               printf("%d", arr[i][j]);


}

int main()
{
    int size = 3;
    int array[size][size];
    int p1row;
    int p1col;
    int p2row;
    int p2col;

    // Initialize empty nested array
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            array[i][j] = 0;
            if ((j+1)%3==0)
                printf("%d\n", array[i][j]);
            else
                printf("%d", array[i][j]);
        }


    while (!isFinished(size, array))
    {
        printf("Player 1 turn:\n");
        scanf("%d", &p1row);
        scanf("%d", &p1col);
        placeMove(size, array, p1row, p1col, 1);

        printf("Player 2 turn:\n");
        scanf("%d", &p2row);
        scanf("%d", &p2col);
        placeMove(size, array, p2row, p2col, 2);
    }
}


