// #include <stdio.h>

// void main(){
//     FILE *fp;
//     fp = fopen("abc.txt","r+");
//     char ch = getc(fp);
//     char temp;
//     int cc = 0, sc = 0,nlc = 0,tc = 0,wc = 0;
//     while(ch != EOF){
//         cc++;
//         if(ch == ' '){
//             sc++;
//         }
//         else if(ch == '\n'){
//             nlc++;
//         }
//         else if(ch == '\t'){
//             tc++;
//         }
//         temp = ch;
//         ch = getc(fp);
//         if((ch == ' ') && (temp != ' ')){
//             wc++;
//         }
//     }
//     if(wc == 0 && cc != 0){
//         wc = 1;
//     }
//     printf("%d %d %d %d %d",cc,sc,tc,nlc,wc+nlc+tc);
// }


// #include <stdio.h>

// void main(){
//     FILE *fp1, *fp2;
//     fp1 = fopen("xyz.txt","a+");
//     fp2 = fopen("abc.txt","r+");
//     char ch = getc(fp2);
//     while(ch != EOF){
//         putc(ch,fp1);
//         ch = getc(fp2);
//     }
// }

#include <stdio.h>

void main(){
    FILE *fp1, *fp2;
    fp1 = fopen("xyz.txt","a+");
    fp2 = fopen("abc.txt","r+");
    int flag = 0;
    char ch = getc(fp2);
    while(ch != EOF){
        if(flag == 0){
            putc(ch-32,fp1);
            flag = 1;
            ch = getc(fp2);
            continue;
        }
        if(ch == ' '){
            flag = 0;
        }
        putc(ch,fp1);
        ch = getc(fp2);
    }
}