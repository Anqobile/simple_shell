#include "shell.h"

/**
 * _strcat - concatenates two strings to make oene string
 * @dest: Destination string
 * @src: Origin(source) string
 * Return: Always 0
 */

char *_strcat(char *dest, char *src)
{
	int x, b = 0;

	for (x = 0; dest[x] != '\0'; x++)
	{
	}
	for (b = 0; src[b] != '\0'; b++)
	{
		dest[x] = src[b];
		x++;

	}
	dest[x] = '\0';
	return (dest);
}



/**
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 * Return: multiple returns
 */

int _strcmp(char *s1, char *s2)
{
	int x = 0;
	int valoo;

	while (s1[x] != 0 && s2[x] != 0 && s1[x] == s2[x])
		x++;
	valoo = s1[x] - s2[x];
	return (valoo);

}

/**
 * _strlen - gets the size/length of a string
 * @s: the string to get size of
 * Return: the length/size of the string
 */

int _strlen(char *s)
{
	int j;

	for (j = 0; s[j] != 0; j++)
		;

	return (j);
}

/**
 *_strncmp -  function that compares two strings.
 *@s1: string one
 *@s2: string two
 *@n: number of characters
 * Return: diference
 */

size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t x, b;

	for (b = 0; s1[b] != '\0' && b < n; b++)
	{
		x = s1[b] - s2[b];

		if (x != 0)
		{
			return (x);
		}
	}
	return (0);
}

/**
 * _strcpy - copies the string from src into dest
 * @dest: destination of the copy
 * @src: source to copy
 * Return: char pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	for (x = 0; src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}
	dest[x + 1] = 0;
	return (dest);
}
