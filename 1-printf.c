#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
  *_printf - produces output according to a format
  *@format: character string
  */
int _printf(const char *format, ...)
{
	int num_chars_printed = 0;
	int len;
	va_list arg_list;

	va_start(arg_list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
		}
		switch (*format)
		{
			case 'c':
				{
					char c = (char) va_arg(arg_list, int);
					write(STDOUT_FILENO, &c, 1);
					num_chars_printed++;
					break;
				}
			case 's':
				{
					char *str = va_arg(arg_list, char*);
					len = 0;
					while (str[len] != '\0') 
						len++;
					write(STDOUT_FILENO, str, len);
					num_chars_printed += len;
					break;
				}
			case '%':
				{
					write(STDOUT_FILENO, "%", 1);
					num_chars_printed++;
					break;
				}
			default:
				{
					write(STDOUT_FILENO, &format[-1], 2);
					num_chars_printed += 2;
					break;
				}
		}
	}
	write(STDOUT_FILENO, format, 1); 
	num_chars_printed++;

	format++;

	va_end(arg_list);

	return (num_chars_printed);
}
