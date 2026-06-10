#include <stdio.h>
#include <stdbool.h>

bool isFinished(int size, int arr[size][size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[i][j] == 0)
                return false;
    return true;
}

bool isLegalMove(int size, int arr[size][size], int row, int col)
{
    if (arr[row][col] != 0)
        return false;
    else
        return true;
}

bool playerHasWon (int size, int arr[size][size], int row, int col, int player)
{

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


