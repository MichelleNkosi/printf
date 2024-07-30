#include "main.h"
/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
int count = 0;
int i = 0;
va_list args;
va_start(args, format);
if (!format)
return (-1);
while (format && format[i])
{
if (format[i] == '%' && format[i + 1] != '\0')
{
i++;
switch (format[i])
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
count += putchar(*str++);
break;
}
case '%':
count += putchar('%');
break;
default:
count += putchar('%');
count += putchar(format[i]);
break;
}
}
else
{
count += putchar(format[i]);
}
i++;
}
va_end(args);
return (count);
}
