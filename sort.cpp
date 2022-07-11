#include "head.h"

size_t size_of_file(FILE *f)
{
    assert(f);
    struct stat buff;
    if (f != NULL)
    {
        fstat(fileno(f), &buff);
        return buff.st_size;
    }
    return PROGRAM_ERROR;
}
int fileread(int file_size, FILE *f, char* my_line, char* name_of_file)
{
    assert(f);
    assert(my_line);

    int co
}