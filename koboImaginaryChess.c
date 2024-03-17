#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard)
{
    // possibility below only paired up if the index is on the same type, either odd or even
    // for example, possibleY[1] only get paired with possibleX[1] or possibleX[3] (all index are odd)
    // and, possibleY[0] only get paired with possibleX[0] or possibleX[2] (all index are even)
    int possibleY[4] = {i + 2, i + 1, i - 2, i - 1};
    int possibleX[4] = {j + 1, j + 2, j - 1, j - 2};

    for (size_t k = 0; k < 4; k++)
    {
        if ((possibleY[k] < size) && (possibleY[k] >= 0))
        {
            // to match with index requirement, start the loop with the remainder of k / 2 (giving either 0 or 1)
            // and increase the step by 2
            for (size_t l = k % 2; l < 4; l += 2)
            {
                if ((possibleX[l] < size) && (possibleX[l] >= 0))
                {
                    // pointer reference on 2-dimensional array are flattened
                    // meaning row 2 is located after the last element of row 1
                    // thats why when accessing row > 1, we need to multiply the row by array size
                    // after that to access element on that row, just add the column index
                    *((chessBoard + possibleY[k] * size) + possibleX[l]) = 1;
                }
            }
        }
    }
}

int main()
{
    int size = 8;
    int chessBoard[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    int i, j;
    scanf("%d %d", &i, &j);

    if (i < 0 || i >= size || j < 0 || j >= size)
    {
        printf("Input invalid!\n");
        return 1;
    }

    koboImaginaryChess(i, j, size, (int *)chessBoard);

    for (size_t k = 0; k < size; k++)
    {
        for (size_t l = 0; l < size; l++)
        {
            printf("%d ", chessBoard[k][l]);
        }

        printf("\n");
    }

    return 0;
}
