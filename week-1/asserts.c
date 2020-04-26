/*
    use asserts within a trivial program
    26/04/2020
*/
#define NDEBUG // put before the assert.h, it removes the assert statements. it is used to wipe out asserts once the program is deemed correct
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    assert(0); // assertion allows for detailed debugging as the output clearly shows which assert has failed
    printf("This program runs!\n");
    return 0;
}