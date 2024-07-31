#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: A character string composed of zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
int count = 0;
const char *p;
va_list args;
va_start(args, format);
if (!format)
{
return (-1);
}
for (p = format; *p != '\0'; p++)
{
if (*p == '%')
{
p++;
switch (*p)
{
case 'c':
{
char c = (char) va_arg(args, int);
write(1, &c, 1);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);
if (!s)
s = "(null)";
while (*s)
{
write(1, s, 1);
s++;
count++;
}
break;
}
case '%':
write(1, "%", 1);
count++;
break;
default:
write(1, "%", 1);
write(1, p, 1);
count += 2;
break;
}
}
else
{
write(1, p, 1);
count++;
}
}
va_end(args);
return (count);
}
