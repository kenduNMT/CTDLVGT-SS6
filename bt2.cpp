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
        printf("nhap gia tri ngan dau tien: ");
        scanf("%d", &value);
        s->top++;
        s->stack[s->top] = value;
    }
}
void printStack(stack *s)
{
    printf("gia tri cua stack la: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d", s->stack[i]);
    }
}
int pop(stack *s)
{
    if (s->top < 0)
    {
        printf("Stack rong!\n");
        return -1;
    }

    int value = s->stack[s->top];
    s->top--;
    return value;
}
int main()
{
    stack s;
    int n;
    printf("Nhap so luong phan tu (khong qua 100): ");
    scanf("%d", &n);

    initStack(&s, n);
    printStack(&s);

    int popped_value = pop(&s);

    printf("Phan tu bi xoa: %d\n", popped_value);
    printf("Cac phan tu trong ngan xep con lai:\n");
    printStack(&s);

    return 0;
}