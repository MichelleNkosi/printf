#include "main.h"
#include <stdio.h>

int main(void)
{
int count;

    /* character conversion test */
count = _printf("Character: %c\n", 'M');
printf("count: %d\n", count);

    /* string conversion test */
count = _printf("String: %s\n", "Hello, UNIVERSE!");
printf("count: %d\n", count);

    /* percent literal test */
count = _printf("Percent: %%\n");
printf("count: %d\n", count);

    /* null string test */
count = _printf("Null string: %s\n", NULL);
printf("count: %d\n", count);

    /* unknown specifier test */
count = _printf("Unknown specifier: %x\n");
printf("count: %d\n", count);

    /* integer conversion test with 'd' */
count = _printf("Integer (d): %d\n", 12345);
printf("count: %d\n", count);

    /* negative integer conversion test with 'd' */
count = _printf("Negative Integer (d): %d\n", -6789);
printf("count: %d\n", count);

    /* integer conversion test with 'i' */
count = _printf("Integer (i): %i\n", 54321);
printf("count: %d\n", count);

    /* negative integer conversion test with 'i' */
count = _printf("Negative Integer (i): %i\n", -9876);
printf("count: %d\n", count);

return (0);
}
