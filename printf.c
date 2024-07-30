#include "main.h"

/**
 * printf - gives output according to a format.
 * @format: A character string with format specifiers.
 * Return: The number of characters printed null.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *p;
char *str;
char ch;

if (format == NULL)
return (-1);

va_start(args, format);
for (p = format; *p != '\0'; p++)
{
if (*p == '%')
{
p++;
if (*p == '\0')
break;
if (*p == 'c')
{
ch = (char)va_arg(args, int);
count += write(1, &ch, 1);
}
else if (*p == 's')
{
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
count += write(1, str++, 1);
}
else if (*p == '%')
{
count += write(1, "%", 1);
}
else
{
count += write(1, "%", 1);
count += write(1, p, 1);
}
}
else
{
count += write(1, p, 1);
}
}
va_end(args);
return (count);
}
