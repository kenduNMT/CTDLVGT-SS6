#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

struct Stack
{
    char data[MAX_SIZE];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, char c)
{
    if (!isFull(s))
    {
        s->data[++(s->top)] = c;
    }
}

char pop(struct Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[(s->top)--];
    }
    return '\0';
}

void reverseString(char *input)
{
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(input); i++)
    {
        push(&s, input[i]);
    }

    int i = 0;
    while (!isEmpty(&s))
    {
        input[i++] = pop(&s);
    }
}

int main()
{
    char str[MAX_SIZE];

    printf("Nhap chuoi: ");
    fgets(str, MAX_SIZE, stdin);

    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    reverseString(str);

    printf("Chuoi dao nguoc: %s\n", str);

    return 0;
}