#include <libchessviz/include/io_module.h>
#include <stdio.h>

void writeline(const char* str)
{
    printf("%s\n", str);
    printf("Press Enter to continue...\n");
    while (getchar() != '\n')
        ;
}

char* readline(uptr_t* length)
{
    char* output = NULL;
    getline(&output, length, stdin);
    return output;
}