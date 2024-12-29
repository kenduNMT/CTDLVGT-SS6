#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return '\0';
}

int isEmpty()
{
    return top == -1;
}

int isOpenBracket(char c)
{
    return (c == '(' || c == '[' || c == '{');
}

int isCloseBracket(char c)
{
    return (c == ')' || c == ']' || c == '}');
}

int isMatchingPair(char open, char close)
{
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}

int checkBalance(char *expr)
{
    top = -1;

    for (int i = 0; i < strlen(expr); i++)
    {
        if (!isOpenBracket(expr[i]) && !isCloseBracket(expr[i]))
        {
            continue;
        }
        if (isOpenBracket(expr[i]))
        {
            push(expr[i]);
        }
        else if (isCloseBracket(expr[i]))
        {
            if (isEmpty())
            {
                return 0;
            }
            char openBracket = pop();
            if (!isMatchingPair(openBracket, expr[i]))
            {
                return 0;
            }
        }
    }
    return isEmpty();
}

int main()
{
    char expr[MAX_SIZE];

    printf("Nhap bieu thuc: ");
    fgets(expr, MAX_SIZE, stdin);

    if (expr[strlen(expr) - 1] == '\n')
    {
        expr[strlen(expr) - 1] = '\0';
    }

    if (checkBalance(expr))
    {
        printf("Bieu thuc hop le\n");
    }
    else
    {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}