#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int stack[100];
    int top = -1;
};
typedef struct Stack stack;

void initStack(stack *s, int n)
{
    if (n >= 100)
        return;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("nhap ngan xep thu %d :", i + 1);
        scanf("%d", &value);
        s->top++;
        s->stack[s->top] = value;
    }
}
int peek(stack *s)
{
    if (s->top < 0)
    {
        printf("stack rong \n");
    }
    return s->stack[s->top];
}

int main()
{
    stack s;
    int n;
    printf("Nhap so luong phan tu (khong qua 100): ");
    scanf("%d", &n);
    initStack(&s, n);

    printf("phan tu tren cung la : %d ", peek(&s));
}