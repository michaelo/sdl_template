#include <stdio.h>
#include <assert.h>

#include "app.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    printf("Running tests\n");
    assert(app_dummy() == 42);
    return 0;
}
