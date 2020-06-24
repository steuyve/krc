/*
 * Exercise 1-18 of K&R 2nd Ed.
 * rm-trailing.c - removes trailing whitespace at the end of lines in its input. Leaves entirely blank lines alone.
 */

#define MAX_LEN 120

#include <stdio.h>

int getline(char s[]);

int main(void)
{
	char line[MAX_LEN];
	int i, j, c, last, length;

	while ((length = getline(line)) > 0) {
		i = 0;
		last = -1;

		for (i = 0; i < length; ++i) {
			c = line[i];
			if (c != ' ' && c != '\t' && c != '\n') {
				last = i;
			}
		}

		if (last > -1) {
			j = 0;
			while (j <= last) {
				putchar(line[j]);
				++j;
			}
			putchar('\n');
		} else {
			putchar('\n');
		}
	}

	return 0;
}

/* getline: loads a line no longer than MAX_LEN into s[]. Returns the length of the line. */
int getline(char s[])
{
	int c, i;
	for (i = 0; i < MAX_LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}
