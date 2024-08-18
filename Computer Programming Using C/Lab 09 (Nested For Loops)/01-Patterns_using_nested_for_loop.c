/*1. Print following patterns */
/*
(a) 
* 
** 
*** 
**** 
***** */
/*
#include <stdio.h>
void main() {
    int i, j;
    for(i = 1; i <= 5; i++) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}*/

/*
(b) 
1 
12 
123 
1234 
12345 */
/*
#include <stdio.h>
void main() {
    int i, j;
    for(i = 1; i <= 5; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}
*/
/*
(c) 
5 
54 
543 
5432 
54321 
*/
/*
#include <stdio.h>
void main() {
    int i, j;
    for(i = 1; i <= 5; i++) {
        for(j = 5; j >= 6 - i; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}
*/
/*
(d) 
1 
22 
333 
4444 
55555
*/
/*#include <stdio.h>
void main() {
    int i, j;
    for(i = 1; i <= 5; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }
}
*/
