/*
 * Exercise 2-1 of K&R 2nd Ed.
 * limits.c - display the minimal and maximal values for different numerical types in C.
 */

#include <limits.h>
#include <float.h>
#include <stdio.h>

int main(void)
{
	printf("char: %d bits %d\t%d\n", CHAR_BIT, CHAR_MIN, CHAR_MAX);
	printf("int: %d\t%d\n", INT_MIN, INT_MAX);
	printf("long: %ld\t%ld\n", LONG_MIN, LONG_MAX);
	printf("signed char: %d\t%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("short: %d\t%d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned char: %d\n", UCHAR_MAX);
	printf("unsigned int: %u\n", UINT_MAX);
	printf("unsigned long: %lu\n", ULONG_MAX);
	printf("unsigned short: %d\n", USHRT_MAX);
	printf("float: %d radix, %d digits %f epsilon %f\t%f\n", FLT_RADIX, FLT_DIG, FLT_EPSILON, FLT_MIN, FLT_MAX);
	printf("double: %d digits %f epsilon %f\t%f\n", DBL_DIG, DBL_EPSILON, DBL_MIN, DBL_MAX);
	return 0;
}
