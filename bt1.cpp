#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Stack
{
    int stack[MAX_SIZE];
    int top = -1;
};

typedef struct Stack stack;

void initStack(stack *stack, int n)
{
    if (n >= 100)
        return;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("nhap gia tri ngan thu %d: ", i + 1);
        scanf("%d", &value);
        stack->top++;
        stack->stack[stack->top] = value;
    }
}

void displayStack(stack *stack)
{
    if (stack->top < 0)
    {
        printf("Stack rong!\n");
        return;
    }
    printf("Cac phan tu trong stack:\n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->stack[i]);
    }
}

int main()
{
    stack stack;
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    initStack(&stack, n);
    displayStack(&stack);

    return 0;
}