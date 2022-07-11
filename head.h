#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <sys/stat.h>

size_t size_of_file(FILE *f);


struct line
{
    int len_line;;
    char* line_begin;
};
enum PROGRAM_RES
{
    PROGRAM_SUCESS = 0,
    PROGRAM_ERROR = 1,
};