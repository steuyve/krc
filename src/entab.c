/*
 * Exercise 1-21 of K&R 2nd Ed.
 * entab2.c - replace consecutive blanks of specified length with tabs in its input.
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, c, count, j;

	if (argc != 2) {
		fprintf(stderr, "usage: entab n - where n is the number of spaces to replace by a tab character.\n");
		exit(EXIT_FAILURE);
	}

	n = atoi(argv[1]);
	count = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++count;
			if (count == n) {
				putchar('\t');
				count = 0;
			}
		} else {
			/* on other characters, put count number of spaces */
			for (j = 0; j < count; ++j) {
				putchar(' ');
			}
			putchar(c);
			count = 0;
		}
	}

	return 0;
}
