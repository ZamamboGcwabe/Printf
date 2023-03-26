#include "main.h"

/**
  *_printf - produces output according to a format
  *@format: character string
  *Return: Void
  */
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	int len;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			case 'c':
			{
				char c = (char) va_arg(args, int);

				write(STDOUT_FILENO, &c, 1);
				printed++;
				break;
			}
			case 's':
			{
				char *s = va_arg(args, char *);

				len = 0;
				while (s[len] != '\0') len++;

				write(STDOUT_FILENO, s, len);
				printed += len;
				break;
			}
			case '%':
			{
				write(STDOUT_FILENO, "%", 1);
				printed++;
				break;
			}
			default:
			break;
		}
	} else
	{
		write(STDOUT_FILENO, format, 1);
		printed++;
	}
	format++;

	va_end(args);
	return (printed);
}
