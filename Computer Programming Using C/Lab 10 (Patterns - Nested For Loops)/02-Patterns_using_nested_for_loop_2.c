/*1. Print following patterns */
/*
(a) 
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 */
/*
#include <stdio.h>
void main() {
    int i, num = 1;

    for (i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }
}
*/
/*
(b) 
1 
0 1 
0 1 0 
1 0 1 0 
1 0 1 0 1
*/
/*
#include <stdio.h>
void main(){
	int i,j,count=0;
	for (i=1;i<=5;i++){
		for(j=1;j< i;j++){
			count++;
			if(count%2==0){
			printf("0");
			}
			else{
				printf("1");
			}
		}
		printf("\n");
    }
}
*/
/*
(c) 
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
*/
/*
#include <stdio.h>
void main(){
	int i,j;
	for(i=10;i>=5;i--){
		for(j=10;j>=i;j--){
			printf(" ");
		}
		for(j=6;j<=i;j++){
			printf(" *");
		}
		
		printf("\n");
	}
}
*/
/*
(d) 
    1 
   A B 
  1 2 3 
 C D E F 
1 2 3 4 5 
*/
/*
#include <stdio.h>
void main() {
int i, j, count = 1;
char ch = 'A';
    for ( i = 1; i <= 5; i++) {
        for (j = 1; j <= 5 - i; j++) {
            printf(" ");
            }
        for (j = 1; j <= i; j++) {
            if (i % 2 != 0) {
                printf("%d ", count++);
            } 
            else {
                printf("%c ", ch++);
            }
        }
        printf("\n");
    }
}
*/
/*
(e) 
*  *  *  *  * 
*           * 
*           * 
*           * 
*  *  *  *  * 
*/
/*
#include <stdio.h>
void main(){
	int i,j;
	for(i=1;i<=5;i++){
		for(j=1;j<=5;j++){
			if(i==1||i==5||j==1||j==5){
				printf("  *");
			}
			else{
				printf("   ");
			}
		}
		printf("\n");
	}
}
*/
