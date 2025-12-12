#include <stdio.h>
void main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "w");

    char ch = getc(fp1);
    while (ch != EOF)
    {
        if (ch == '/')
        {
            ch = getc(fp1);
            if (ch == '/')
            {
                while (ch != '\n')
                {
                    ch = getc(fp1);
                }
            }
            else if (ch == '*')
            {
                while (1)
                {
                    ch = getc(fp1);
                    while (ch != '*')
                    {
                       ch = getc(fp1);
                    }
                    if((ch = getc(fp1)) == '/'){
                        break;
                    }else{
                        ungetc(ch,fp1);
                    }
                }
            }
            else{
                ungetc(ch,fp1);
                fputc('/',fp2);
            }
        }
        else
        {
            putc(ch, fp2);
        }
        ch = getc(fp1);
    }
}