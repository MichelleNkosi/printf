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

return (0);
}
