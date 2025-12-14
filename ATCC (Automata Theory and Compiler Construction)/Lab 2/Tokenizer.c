#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main()
{
    FILE *fp2;
    char punctuations[100][100];
    char operators[100][100];
    int constants[100];
    char code_keywords[100][100];
    char identifiers[100][100];

    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    fp2 = fopen("file2.txt", "r");

    int i = 0, j = 0, l = 0, m = 0, n = 0;
    char ch;
    while ((ch = getc(fp2)) != EOF)
    {
        if (ch == '/' || ch == '*' || ch == '+' || ch == '-' || ch == '%' || ch == '=' || ch == '<' || ch == '>' || ch == '!' || ch == '&' || ch == '|' || ch == '^' || ch == '~')
        {
            operators[i][0] = ch;
            operators[i][1] = '\0';
            i++;
        }
        else if (isalnum(ch))
        {
            char temp[100];
            int k = 0;
            int flag = 0;
            temp[k++] = ch;
            while ((ch = getc(fp2)) != EOF && isalnum(ch))
            {
                temp[k] = ch;
                k++;
            }
            ungetc(ch, fp2);
            temp[k] = '\0';

            for (int x = 0; x < 32; x++)
            {
                if (strcmp(temp, keywords[x]) == 0)
                {
                    strcpy(code_keywords[l], temp);
                    l++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                int z = 0;
                int isNumber = 1;
                while (temp[z] != '\0')
                {
                    if (!isdigit(temp[z]))
                    {
                        isNumber = 0;
                        break;
                    }
                    z++;
                }
                z = 0;
                if (isNumber == 1)
                {
                    int result = 0;
                    while (temp[z] != '\0')
                    {
                        result = result * 10 + (temp[z] - '0');
                        z++;
                    }
                    constants[m] = result;
                    m++;
                }
                else
                {
                    strcpy(identifiers[n], temp);
                    n++;
                }
            }
        }
        else if (ispunct(ch))
        {
            punctuations[j][0] = ch;
            punctuations[j][1] = '\0';
            j++;
        }
    }
    fclose(fp2);

    printf("Punctuations:");
    for (int x = 0; x < j; x++)
    {
        printf("%s, ", punctuations[x]);
    }
    printf("\nOperators:");
    for (int x = 0; x < i; x++)
    {
        printf("%s, ", operators[x]);
    }
    printf("\nCode Keywords:");
    for (int x = 0; x < l; x++)
    {
        printf("%s, ", code_keywords[x]);
    }
    printf("\nIdentifiers:");
    for (int x = 0; x < n; x++)
    {
        printf("%s, ", identifiers[x]);
    }
    printf("\nConstants:");
    for (int x = 0; x < m; x++)
    {
        printf("%d, ", constants[x]);
    }
    printf("\n");
}