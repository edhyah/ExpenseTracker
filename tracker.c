/*
 * tracker.c
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFLEN  20

/* Function prototypes */
void print_hdrs();
void print_prompt();
void error(char *msg);

/*
 * print_hdrs - print introductory message
 */
void print_hdrs() {
    printf("\nExpense Tracker\n");
    printf("Copyright 2015 Edward Ahn.\n");
}

/*
 * print_prompt - print instructions and ask for input
 */
void print_prompt() {
    printf("\nWhat would you like to do?\n");
    printf("\tenter 'a' to add a new expense\n");
    printf("\tenter 'v' to view all expenses from this month\n");
    printf("\n");
}

/*
 * main - main routine
 */
int main() {
    char buf[BUFLEN];

    /* print headers */
    print_hdrs();
    print_prompt();

    /* get input */
    printf("> ");
    if ((fgets(buf, BUFLEN, stdin) == NULL) && ferror(stdin))
        error("fgets error");
    if (feof(stdin)) {
        printf("\n");
        fflush(stdout);
        fflush(stderr);
        exit(0);
    }

    printf("%s\n", buf);
    return 0;
}

/*
 * error - prints error message and exits
 */
void error(char *msg) {
    fprintf(stdout, "%s\n", msg);
    exit(1);
}
