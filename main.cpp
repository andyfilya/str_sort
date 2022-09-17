#include "head.h"

int main(int argc, const char* argv[])
{
    data text;

    char in_file_name[256];
    char out_file_name[256];

    FILE *f_in = NULL;
    FILE *f_out = NULL;

    if(argc > 1)
    {
        if(sizeof(argv[1]) > 1) strcpy(in_file_name, argv[1]);
        if(sizeof(argv[2]) > 1) strcpy(out_file_name, argv[2]);
        else
        {
            printf("INPUT INCORRECTLY...");
            return PROGRAM_ERROR;
        }
    }

    f_in = fopen(in_file_name, "rb");
    if(f_in == NULL)
    {
        printf("ERROR: WE CAN'T OPEN YOUR INPUT FILE");
        return PROGRAM_ERROR;
    }

    f_out = fopen(out_file_name, "wb");
    if(f_out == NULL)
    {
        printf("ERROR: WE CAN'T OPEN YOUR OUTPUT FILE");
        return PROGRAM_ERROR;
    }


    if(FileRead(&text, f_in) != PROGRAM_SUCESS)
    {
        printf("ERROR: WE CAN'T OPEN YOUR FILE FOR READING");
        return PROGRAM_ERROR;
    }

    int counter_of_strings = CounterStrings(&text);
    text.mini_string = (line *)calloc(counter_of_strings, sizeof(line));
    if (text.mini_string == NULL)
    {
        printf("ERROR: WE CAN'T ALLOCATE MEMORY FOR INPUT STRING");
        return PROGRAM_ERROR;
    }
    
    MakeOutput(&text, counter_of_strings, f_out);
    DestructText(&text);
}