#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * _printf - prints char
 * @format: takes format specifier, arg counter
 * Return: printed text
 */
int _printf(const char *format, ...)
{
int i;
char c;
int len;
const char *p;
int count;
va_list args;
va_start(args, format);
p = format;
count = 0;
while (*p != '\0')
{
if (*p == '%')
{
p++;
if (*p == 's')
{
char *s = va_arg(args, char *);
len = strlen(s);
for (i = 0; i < len; i++)
{
write(1, &s[i], 1);
count++;
}
}
else if (*p == 'c')
{
c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (*p == '%')
{
c = '%';
write(1, &c, 1);
count++;
}
else
{
char *err = "Error";
len = strlen(err);
for (i = 0; i < len; i++)
{
write(1, &err[i], 1);
}
}
}
else
{
write(1, p, 1);
count++;
}
p++;
}
va_end(args);
return (count);
}
