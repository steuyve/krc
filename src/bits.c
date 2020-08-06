/*
 * Exercises 2-6, 2-7 of K&R 2nd Ed.
 * bits.c - functions for manipulating bit fields.
 */
#include <stdio.h>

void showbits(unsigned int x);
unsigned int getbits(unsigned int x, int p, int n);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int invert(unsigned int x, int p, int n);

int main(void)
{
	unsigned int x = 0x12345678;
	unsigned int y = 0xffffffff;
	showbits(x);
	showbits(y);
	showbits(setbits(x, 4, 3, y));
	showbits(invert(x, 4, 3));
	return 0;
}

/* showbits: display the corresponding bit field represented by an unsigned int. */
void showbits(unsigned int x)
{
	int i;
	for (i = (sizeof(int) * 8) - 1; i >= 0; --i) {
		getbits(x, i, 1) ? putchar('1') : putchar('0');
		if (!(i % 4))
			putchar(' ');
	}
	printf("\n");
}

/* getbits: returns the n bits of x starting at position p (from right to left starting at 0). */
unsigned int getbits(unsigned int x, int p, int n)
{
	/*
	 * ~0 is all 1's
	 * ~0 << n shifts the 1's to the left with the rest padded 0's.
	 * ~(~0 << n) inverts the above line (0's on left, 1's on right).
	 * So we have n 1-bits in the least significant part of the number.
	 * (x >> (p+1-n)) shifts the bits in x right so the least significant
	 * n bits are the ones starting at position p.
	 */
	return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: sets the n bits of x at position p to be the rightmost n bits of y. */
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	unsigned int mask = ~(~0 << n);
	/*
	 * mask << (p+1-n) shifts the mask to the correct position.
	 * x & ~(shifted mask) zeros out correct bits.
	 * (y & mask) leaves only the correct bits.
	 * desired bits << (p+1 -n) shifts them to correct location.
	 * bitwise or sets the bits in x.
	 */
	return (x & ~(mask << (p+1-n))) | ((y & mask) << (p+1-n));
}

/* invert: inverts the n bits of x starting at position p. */
unsigned int invert(unsigned int x, int p, int n)
{
	unsigned int mask = ~(~0 << n);
	/*
	 * ~x >> (p+1-n) shifts the desired bits to rightmost edge.
	 * & mask then zeros out the rest.
	 * << (p+1-n) shifts them back to the original position.
	 * | with LHS sets the correct bits.
	 * Could also do setbits(x, p, n, (~x >> (p+1-n)));
	 */
	return (x & ~(mask << (p+1-n))) | ((~x >> (p+1-n)) & mask) << (p+1-n);
}

