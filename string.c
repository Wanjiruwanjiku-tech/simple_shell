#include "main.h"
#include <stdio.h>

int print_str(char *str);
int _strcmp(char *command, char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *, char *, int);
char *_strdup(char *);
char *_strcpy_at(char *s1, char *s2, int n);



int _strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
		{
			i++;
		}
		else
			break;
	}

	if (*(s1 + i) == *(s2 + i) || i == n)
	{
		return (0);
	}
	else
		return ((int)(*(s1 + i)) - (int)(*(s2 + i)));
}

char *_strcpy_at(char *s1, char *s2, int n)
{
	int i = 0, j = 0, len = _strlen(s2);

	if (s2 == NULL)
		return (NULL);

	while (i < len && s2[i] != '\0')
	{
		if (i < n)
		{
			i++;
			continue;
		}
		s1[j] = s2[i];
		i++;
		j++;
	}

	len = _strlen(s1);
	while (j < len)
		s1[j++] = '\0';

	return (s1);
}
char *_strcat(char *dest, char *src)
{
	int i, j, destLen, srcLen;

	destLen = _strlen(dest);
	srcLen = _strlen(src);
	j = 0;

	for (i = destLen; i < (destLen + srcLen); i++)
	{
		*(dest + i) = *(src + j);
		j++;
		if (*(src + j) == '\0')
		{
			return (dest);
		}
	}
	return (dest);
}
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = _strlen(src);
	i = 0;

	while (i <= len)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
int _strlen(char *s)
{
	int i, len;

	i = 0;
	len = 0;

	while (*(s + i) != '\0')
	{	len++;
		i++;
	}

	return (len);
}
char *_strdup(char *src)
{
	char *dest;
	int i = 0, len;

	if (src == NULL)
		return (NULL);

	len = _strlen(src);
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);

	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
int _strcmp(char *command, char *str)
{
	int i = 0;

	while (command[i] && str[i])
	{
		if (command[i] != str[i])
			return (-1);
		i++;
	}

	return (0);
}
int print_str(char *str)
{
	int len = 0;

	if (str == NULL)
		return (-1);

	/* handling if write fails */
	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
