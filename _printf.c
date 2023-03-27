#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produce output according to a format
 * @format: format string containing zero or more directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char ch;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while ((ch = *format++) != '\0')
	{
		if (ch == '%')
		{
			ch = *format++; /* get the next character after the '%' */
			handle_specifier(ch, args, &count); /* handle the specifier */
		}
		else
		{
			putchar(ch); /* output the character */
			count++;
		}
	}

	va_end(args);
	return (count);
}

/**
 *  handle_specifier - to handle the conversion specifiers
 *
 *  @format: format string
 *  @args: list of arguments
 *  @count: pointer
 *
 *  Return: 0
 */
void handle_specifier(char format, va_list args, int *count)
{
	switch (format)
	{
	case 'c':{
		char c = va_arg(args, int); /* get the next argument as a char */

		putchar(c); /* print the char */
		(*count)++;
		break;
		}
	case 's':{
		char *str = va_arg(args, char*); /* get the next argument as a string */

		fputs(str, stdout); /* print the string */
		(*count) += strlen(str);
		break;
	}
	case '%':{
		putchar('%'); /* print a '%' character */
		(*count)++;
		break;
		}
	case 'd':
	case 'i':{
		int num = va_arg(args, int);

		printf("%d", num);
		(*count) += (num < 0) ? 2 : 1;
		break;
	}
	default:{
		/* handle unknown conversions specifier */
		printf("%%%c", format);
		(*count) += 2;
		break;
	}
	}
}
