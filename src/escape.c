/*
 * Exercise 3-2 of K&R 2nd. Ed.
 * escape.c - converts characters like newline and tab to visible escape sequences and vice versa.
 */

#define MAX_BUFLEN 1024

#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);

int main(void)
{
	char line[MAX_BUFLEN] = "Hello\tWorld\n";
	char copied[MAX_BUFLEN];
	char copied2[MAX_BUFLEN];
	escape(copied, line);
	descape(copied2, copied);
	printf("%s", line);
	printf("%s\n", copied);
	printf("%s", copied2);
	return 0;
}

/* escape: converts newlines and tabs to \n and \t while copying string t to s. */
void escape(char s[], char t[])
{
	int i;
	int j = 0;
	for (i = 0; i < MAX_BUFLEN; ++i) {
		switch (t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				++j;
				break;
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				++j;
				break;
			default:
				s[j] = t[i];
				++j;
				break;
		}
	}
	s[j] = '\0';
}

/* descape: converts literal '\t' and '\n' into tabs and newlines while copying string to s. */
void descape(char s[], char t[])
{
	int i;
	int j = 0;
	for (i = 0; i < MAX_BUFLEN; ++i) {
		if (t[i] == '\\') {
			++i;
			switch (t[i]) {
				case 't':
					s[j] = '\t';
					++j;
					break;
				case 'n':
					s[j] = '\n';
					++j;
					break;
				default:
					s[j] = t[--i];
					++j;
					break;
			}
		} else {
			s[j] = t[i];
			++j;
		}
	}
	s[j] = '\0';
}
