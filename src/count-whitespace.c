/*
 * Exercise 1-8 of K&R 2nd Ed.
 * count-whitespace.c - count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main(void) {
    int c;
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == '\n') {
            ++newlines;
        }
    }

    printf("blanks: %d\n", blanks);
    printf("tabs: %d\n", tabs);
    printf("newlines: %d\n", newlines);

    return 0;
}
