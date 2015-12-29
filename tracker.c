/*
 * tracker.c
 * Edward Ahn
 * edhyah@gmail.com
 *
 * Compiling and Running:
 * > gcc tracker.c -o tracker
 * > ./tracker
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rio.h"

#define BUFLEN  20

/* Function prototypes */
void print_hdrs();
void print_prompt();
void error(char *msg);
void eval(char *cmd);

/*
 * print_hdrs - print introductory message
 */
void print_hdrs() {
    printf("\n-- Expense Tracker --\n");
    printf("Copyright 2015 Edward Ahn.\n");
    fflush(stdout);
}

/*
 * print_prompt - print instructions and ask for input
 */
void print_prompt() {
    printf("\nWhat would you like to do?\n");
    printf("\tenter 'a' to add a new expense\n");
    printf("\tenter 'v' to view all expenses from this month\n");
    printf("\tenter 'i' to view these instructions again\n");
    printf("\tenter 'q' to quit this program\n");
    printf("\n");
    fflush(stdout);
}

/*
 * eval - evaluate command that user typed in
 */
void eval(char *cmd) {

    /* Handle incorrect inputs */
    if (strlen(cmd) > 1) {
        printf("Command not recognized. Try again.\n");
        fflush(stdout);
        return;
    }
    if (strstr("aviq", cmd) == NULL) {
        printf("Command not recognized. Try again.\n");
        fflush(stdout);
        return;
    }

    /* Handle input */
    switch(cmd[0]) {

        case 'a':           /* add expense */
            break;

        case 'v':           /* view expenses */
            break;

        case 'i':           /* display instructions */
            print_prompt();
            break;

        case 'q':           /* quit */
            printf("\n-- Thanks for using Expense Tracker! --\n");
            printf("\n");
            fflush(stdout);
            exit(0);
            break;

    }

    return;
}

/*
 * main - main routine
 */
int main() {
    char buf[BUFLEN];

    /* print instructions */
    print_hdrs();
    print_prompt();

    while (1) {
        /* get input */
        printf("> ");
        fflush(stdout);
        if ((fgets(buf, BUFLEN, stdin) == NULL) && ferror(stdin))
            error("fgets error");
        if (feof(stdin)) {
            printf("\n");
            fflush(stdout);
            fflush(stderr);
            exit(0);
        }

        /* remove trailing newline */
        buf[strlen(buf) - 1] = '\0';

        eval(buf);
        fflush(stdout);
    }

    return 0;
}

/*
 * error - prints error message and exits
 */
void error(char *msg) {
    fprintf(stdout, "%s\n", msg);
    exit(1);
}
