#include <iostream>
#include "library.hpp"

int main ( void )
{
    printf("Calling the shared library\n");
    value_to_be_printed(10);
    printf("Completed\n");
    return 0;
}
