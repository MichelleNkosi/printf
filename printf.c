#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int _printf(const char *format, ...);
int _strlen(const char *s);

int main(void)
{
    _printf("Character: %c\n", 'M');
    _printf("String: %s\n", "Hello, Universe!");
    _printf("Percent sign: %%\n");
    _printf("Multiple: %c %s %%\n", 'X', "example");

    return (0);
}

/* Function implementations */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;
    char ch;

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
                    ch = va_arg(args, int);
                    count += write(1, &ch, 1);
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

int _strlen(const char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;
    
    return (len);
}
