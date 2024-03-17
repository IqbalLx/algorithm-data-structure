#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int mapInput(char input)
{
    switch (input)
    {
    case 'J':
        return 11;

    case 'Q':
        return 12;

    case 'K':
        return 13;

    default:
        return -1;
    }
}

void printOutput(int output)
{
    switch (output)
    {
    case 11:
        printf("J");
        break;

    case 12:
        printf("Q");
        break;

    case 13:
        printf("K");
        break;

    default:
        printf("%d", output);
        break;
    }
}

void swap(int *xp, int *yp, int swap_count, int count, int *numbers)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

    printf("Pertukaran %d: ", swap_count);
    for (size_t i = 0; i < count; i++)
    {
        printOutput(*(numbers + i));
        printf(" ");
    }

    printf("\n");
}

void sort(int *numbers, int count)
{
    int swap_count = 0;
    for (size_t i = 0; i < count - 1; i++)
    {
        int minIndex = i;
        for (size_t j = i; j < count; j++)
        {
            if (numbers[j] < numbers[minIndex])
            {
                minIndex = j;
            };
        }

        if (minIndex != i)
        {
            swap_count++;
            swap(numbers + minIndex, numbers + i, swap_count, count, numbers);
        }
    }

    printf("%d\n", swap_count);
}

int main()
{
    int count;
    scanf("%d", &count);

    int *numbers = (int *)malloc(count * sizeof(int));
    if (numbers == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        char input;
        scanf(" %c", &input);

        int digit;
        if (isdigit(input))
        {
            digit = input - '0';
            if (digit < 0 || digit > 10)
            {
                printf("Invalid input!\n");
                return 1;
            }
        }
        else
        {
            digit = mapInput(input);
            if (digit == -1)
            {
                printf("Invalid input!\n");
                return 1;
            }
        }

        numbers[i] = digit;
    }

    sort(numbers, count);

    return 0;
}
