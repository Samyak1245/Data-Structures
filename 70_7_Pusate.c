// 7. Infix to postfix
// Roll Number: 70

#include <stdio.h>
#include <ctype.h>
#define MAX 100

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int pre(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    char in[MAX], post[MAX], stk[MAX];
    int i = 0, j = 0, top = -1;
    char ch;

    printf("\n\tEnter infix expression: ");
    scanf("%[^\n]", in);  

    while (in[i] != '\0')
    {
        ch = in[i];

        if (isdigit(ch))
        {
            while (isdigit(in[i]))
            {
                post[j++] = in[i++];
            }
            post[j++] = ' ';  
            continue;
        }
        else if (ch == '(')
        {
            stk[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top != -1 && stk[top] != '(')
            {
                post[j++] = stk[top--];
                post[j++] = ' ';
            }
            if (top != -1 && stk[top] == '(')
                top--; 
        else if (isOperator(ch))
        {
            while (top != -1 && pre(stk[top]) >= pre(ch) && stk[top] != '(')
            {
                post[j++] = stk[top--];
                post[j++] = ' ';
            }
            stk[++top] = ch;
        }

        i++;
    }

    while (top != -1)
    {
        post[j++] = stk[top--];
        post[j++] = ' ';
    }

    post[j] = '\0';

    printf("\n\tpostfix expression: %s", post);

    return 0;
}
