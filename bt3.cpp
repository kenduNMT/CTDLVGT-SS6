#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack
{
    int stack[MAX];
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
int isEmpty(stack *s)
{
    return s->top == -1;
}
int main()
{
    stack s;
    int n;
    printf("Nhap so luong phan tu (khong qua 100): ");
    scanf("%d", &n);
    initStack(&s, n);
    if (isEmpty(&s))
    {
        printf("Ngan xep  rong");
    }
    else
    {
        printf("Ngan xep khong rong");
    }
}