/*1. Print following patterns */
/*(a) 
***** 
**** 
*** 
** 
* 
*/
/*
#include <stdio.h>
void main() {
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
*/
/*
(b) 
12345 
1234 
123 
12 
1 */
/*
#include <stdio.h>
void main() {
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}
    */
/*
(c) 
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
*/
/*
#include <stdio.h>
void main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}
*/
/*
(d) 
    1 
   1 2 
  1 2 3 
 1 2 3 4 
5 4 3 2 1 
*/
/*
#include <stdio.h>
void main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}
*/
