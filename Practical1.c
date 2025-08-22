
// Design a feature for a basic text editor that allows users to perform undo and redo operations using a stack

#include <stdio.h>
#define SIZE 1000

int main()
{
    char text[SIZE], undo[SIZE], undoc[SIZE], redo[SIZE], redoc[SIZE];
    int len = 0, utop = -1, rtop = -1, ch;
    char c;

    while (1)
    {
        printf("\nText: ");
        for (int i = 0; i < len; i++)
        {

            printf("%c", text[i]);
        }
        printf("\n 1.Insert\n 2.Undo\n 3.Redo\n 4.Exit\nChoose: ");
        scanf("%d", &ch);
        getchar();

        if (ch == 1)
        {
            printf("Enter char: ");
            c = getchar();
            getchar();
            if (len < SIZE)
            {
                text[len++] = c;
                undo[++utop] = 'i';
                undoc[utop] = c;
                rtop = -1;
            }
        }
        else if (ch == 2)
        {
            if (utop >= 0)
            {
                char op = undo[utop];
                char uc = undoc[utop];
                if (op == 'i')
                {
                    len--;
                }
                else if (op == 'd')
                {
                    text[len++] = uc;
                }
                redo[++rtop] = op;
                redoc[rtop] = uc;
                utop--;
            }
            else
            {
                printf("Nothing to undo.\n");
            }
        }
        else if (ch == 3)
        {
            if (rtop >= 0)
            {
                char op = redo[rtop];
                char rc = redoc[rtop];
                if (op == 'i')
                {
                    text[len++] = rc;
                }
                else if (op == 'd')
                {
                    len--;
                }
                undo[++utop] = op;
                undoc[utop] = rc;
                rtop--;
            }
            else
            {
                printf("Nothing to redo.\n");
            }
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
