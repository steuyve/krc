/*
 * Exercise 1-18 of K&R 2nd Ed.
 * rm-trailing.c - removes trailing whitespace at the end of lines in its input. Leaves entirely blank lines alone.
 */

#define MAX_LEN 120

#include <stdlib.h>
#include <stdio.h>

void getline(char s[]);

int main(void) {
    char line[MAX_LEN];
    int i, c, last;
    int j;

    while (1) {
        i = 0;
        last = -1; /* start at -1 because we could have just a blank line */

        getline(line);

        /* increment counter until we reach the end of the string, save position of last non-whitespace character */
        while ((c = line[i]) != '\0') {
            if (c != ' ' && c != '\t' && c != '\n') {
                last = i;
            }
            ++i;
        }

        /* strip trailing whitespace */
        if (last > -1) {
            j = 0;
            while (j <= last) {
                putchar(line[j]);
                ++j;
            }
            putchar('\n');
        } else { /* just recreate the blank line in this case */
            putchar('\n');
        }
    }

    return 0;
}

/* getline: loads a line no longer than MAX_LEN into s[]. Exit on EOF. */
void getline(char s[]) {
    int c, i;
    for (i = 0; i < MAX_LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == EOF) {
        exit(EXIT_SUCCESS);
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}
