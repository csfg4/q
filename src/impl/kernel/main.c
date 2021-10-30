#include "print.h"

void kernel_main()
{
    print_clear();
    print_set_colour(PRINT_COLOUR_GREEN, PRINT_COLOUR_BLACK);
    print_str("hello");
}