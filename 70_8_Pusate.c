// 8. Infix to prefix
// Roll Number: 70
#include <stdio.h>
#include <conio.h>

#define MAX 30

int isopd(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    else
        return 0;
}

int isopr(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')  
        return 1;
    else
        return 0;
}

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    else
        return 1;
}

int main()
{
    char infix[15], stack[MAX], opd[15];
    int i = 0, j = 0, top = -1;
    char ch;

    printf("\n\tEnter the expression:   ");
    scanf("%s", infix);

    while (infix[i] != '\0')  
    {
        ch = infix[i];
        printf("\n\tCharacter at %d is %c", i, ch);

        if (isopd(ch))
        {
            opd[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                opd[j] = stack[top];
                j++;
                top--;
            }
            if (top != -1 && stack[top] == '(')
                top--;
        }
        else if (isopr(ch))
        {
            while (top != -1 && stack[top] != '(' && priority(stack[top]) >= priority(ch))
            {
                opd[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = ch;
        }
        i++;
    }

    while (top != -1)
    {
        opd[j] = stack[top];
        j++;
        top--;
    }

    opd[j] = '\0';

    printf("\n\tPostfix Expression is: %s", opd);

    return 0;
}
