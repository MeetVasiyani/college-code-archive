#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tokens[100];
int i = 0;

char* lookahead() {
    return tokens[i];
}

void error(const char *msg) {
    printf("Syntax error: %s\n", msg);
    exit(1);
}

void match(const char *t) {
    if (strcmp(lookahead(), t) == 0)
        i++;
    else
        error("unexpected token");
}

/* Forward declarations */
void E();
void E_prime();
void T();
void T_prime();
void F();

/* Grammar functions */

void E() {
    T();
    E_prime();
}

void E_prime() {
    if (strcmp(lookahead(), "+") == 0) {
        match("+");
        T();
        E_prime();
    }
    /* epsilon */
}

void T() {
    F();
    T_prime();
}

void T_prime() {
    if (strcmp(lookahead(), "*") == 0) {
        match("*");
        F();
        T_prime();
    }
    /* epsilon */
}

void F() {
    if (strcmp(lookahead(), "id") == 0)
        match("id");
    else
        error("expected id");
}

/* Driver */

int main() {
    /* Example input: id + id * id */
    char *input[] = {"id", "+", "id", "*", "id", "$"};

    for (int j = 0; j < 6; j++)
        tokens[j] = input[j];

    E();

    if (strcmp(lookahead(), "$") == 0)
        printf("Parsing successful\n");
    else
        printf("Extra input remaining\n");

    return 0;
}
