#include "main.h"

/**
 * _strlen - return the number of characters in a string.
 * @str: Input string.
 * Return: The number of characters in the string.
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strcmp - compares two strings.
 *
 * @s1: input string 1,
 * @s2: input string 2,
 *
 * Return: returns an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the strings are equal
 *		• A negative value if s1 is less than s2
 *		• A positive value if s1 is greater than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strncmp - compares two strings.
 *
 * @s1: input string 1,
 * @s2: input string 2,
 * @n: input int
 *
 * Return: returns an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the s1 and s2 are equal
 *		• A negative value if s1 is less than s2
 *		• A positive value if s1 is greater than s2
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strcpy - copy the contents of source string to the destination string.
 *
 * @dest:  Destination string to copy to.
 * @src: Source string to copy from.
 *
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strcat - appends the source string to the destination string.
 *
 * @dest: Destination string to append to.
 * @src: Source string to append.
 *
 * Return: void
 */
char *_strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
