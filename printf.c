#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/**
 * _printf - Gives output according to a format.
 * @format: The format string containing the characters and the specifiers.
 * Return: The number of characters printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += write(1, &va_arg(args, int), 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    count += write(1, str, _strlen(str));
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, &format[i - 1], 1);
                    count += write(1, &format[i], 1);
                    break;
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return (count);
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to be measured.
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;
    
    return (len);
}
