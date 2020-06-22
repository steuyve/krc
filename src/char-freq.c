/*
 * Exercise 1-14 of K&R 2nd Ed.
 * char-freq.c - Print a histogram of the frequencies of characters in its input.
 */

#define START '!'
#define LAST '~'

#include <stdio.h>

int main(void) {
    int range = LAST - START;
    int characters[LAST - START];
    int c, i, j;
    int spaces= 0;
    int tabs = 0;
    int newlines = 0;
    int other = 0;

    for(i = 0; i < range; ++i) {
        characters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= START && c <= LAST) {
            ++characters[c - START];
        } else if (c == ' ') {
            ++spaces;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == '\n') {
            ++newlines;
        } else {
            ++other;
        }
    }

    for (i = 0; i < range; ++i) {
        printf("%c: ", i + START);
        for (j = 0; j < characters[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
    printf("spaces: %d\n", spaces);
    printf("tabs: %d\n", tabs);
    printf("newlines: %d\n", newlines);
    printf("other: %d\n", other);

    return 0;
}
