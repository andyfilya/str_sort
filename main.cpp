#include "head.h"

int main()
{
    data text;
    char in_file_name[256];
    char out_file_name[256];

    FILE *f_in = NULL;
    FILE *f_out = NULL;

    printf ("Enter the name of input file\n");
    if(scanf("%s", in_file_name) != 1)
    {
        printf("ERROR: YOU NEED TO WRITE NAME OF INPUT FILE!");
        return PROGRAM_ERROR;
    }
    f_in = fopen(in_file_name, "rb");
    if(f_in == NULL)
    {
        printf("ERROR: WE CAN'T OPEN YOUR INPUT FILE");
        return PROGRAM_ERROR;
    }
    printf ("Enter the name of output file\n");
    if(scanf("%s", out_file_name) != 1)
    {
        printf("ERROR: YOU NEED TO WRITE NAME OF OUTPUT FILE!");
        return PROGRAM_ERROR;
    }
    f_out = fopen(out_file_name, "wb");
    if(f_out == NULL)
    {
        printf("ERROR: WE CAN'T OPEN YOUR OUTPUT FILE");
        return PROGRAM_ERROR;
    }
    if(fileread(&text, f_in) != PROGRAM_SUCESS)
    {
        printf("ERROR: WE CAN'T OPEN YOUR FILE FOR READING");
        return PROGRAM_ERROR;
    }
    int counter_of_strings = cnt_str(&text);
    text.mini_string = (line *)calloc(counter_of_strings, sizeof(line));
    if (text.mini_string == NULL)
    {
        printf("ERROR: WE CAN'T ALLOCATE MEMORY FOR INPUT STRING");
        return PROGRAM_ERROR;
    }
    make_output(&text, counter_of_strings, f_out);
    destruct_text(&text);
}