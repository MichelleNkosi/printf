#include <stdarg.h>
#include <unistd.h>

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
