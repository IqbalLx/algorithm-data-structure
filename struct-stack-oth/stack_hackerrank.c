#include <stdio.h>
#include <string.h>

#define MAX_GAMES 50
#define MAX_DATA 100

struct Stack
{
    int data[MAX_DATA];
    int top;
};

struct Game
{
    int max_sum;
    struct Stack stack_a;
    struct Stack stack_b;
};

int isEmpty(struct Stack stack)
{
    return stack.top == -1;
}

int isFull(struct Stack stack)
{
    return stack.top == MAX_DATA - 1;
}

int pop(struct Stack *stack)
{
    if (isEmpty(*stack))
    {
        return -1;
    }

    int data = (*stack).data[(*stack).top];
    (*stack).top--;

    return data;
};

void push(struct Stack *stack, char kurung)
{
    if (isFull(*stack))
    {
        printf("Stack penuh!\n");
        return;
    }

    (*stack).top++;
    (*stack).data[(*stack).top] = kurung;
};

int peek(struct Stack stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }

    return stack.data[stack.top];
};

void printStack(char name, struct Stack stack)
{
    printf("Stack %c: ", name);
    for (int i = stack.top; i >= 0; i--)
    {
        printf("%d ", stack.data[i]);
    }

    printf("\n");
}

int main()
{
    int g;
    struct Game games[MAX_GAMES];

    scanf("%d", &g);

    for (int i = 0; i < g; i++)
    {
        struct Game *game = &games[i];

        int m, n;
        scanf("%d %d %d", &m, &n, &game->max_sum);
        (*game).stack_a.top = m - 1;
        (*game).stack_b.top = n - 1;

        // Read values for stack a
        for (int j = m - 1; j >= 0; j--)
        {
            scanf("%d", &game->stack_a.data[j]);
        }

        // Read values for stack b
        for (int j = n - 1; j >= 0; j--)
        {
            scanf("%d", &game->stack_b.data[j]);
        }
    }

    // process
    int scores = 0;
    for (int i = 0; i < g; i++)
    {
        struct Game game = games[i];
        printf("Game %d:\n", i + 1);
        printf("Initial Stack:\n");
        printStack('A', game.stack_a);
        printStack('B', game.stack_b);
        printf("\n");

        int local_sum = 0;
        while (1)
        {
            int top_a = peek(game.stack_a);
            int top_b = peek(game.stack_b);

            if (top_a == -1 && top_b == -1)
            {
                break;
            }

            int value;
            if (top_a != -1 && top_a <= top_b)
            {
                value = pop(&game.stack_a);
            }
            else if (top_b != -1)
            {
                value = pop(&game.stack_b);
            }
            else
            {
                if (top_a == -1)
                {
                    value = pop(&game.stack_b);
                }
                else
                {
                    value = pop(&game.stack_a);
                }
            }

            if (local_sum + value <= game.max_sum)
            {
                local_sum = local_sum + value;
                scores++;

                printf("Step %d:\n", scores);
                printStack('A', game.stack_a);
                printStack('B', game.stack_b);
                printf("Popped Value: %d\n", value);
                printf("\n");
            }
            else
            {
                break;
            }
        }
    }

    printf("%d\n", scores);

    return 0;
}