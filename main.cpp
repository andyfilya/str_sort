#include "head.h"

int main()
{
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
    int file_size = size_of_file(f_in);
    char* input_string = (char *)calloc(file_size, sizeof(char));
    if(input_string == NULL)
    {
        printf("ERROR: WE CAN'T ALLOCATE MEMORY FOR INPUT STRING");
        return PROGRAM_ERROR;
    }
    if(fileread(input_string, file_size, f_in) != PROGRAM_SUCESS)
    {
        printf("ERROR: WE CAN'T OPEN YOUR FILE FOR READING");
        return PROGRAM_ERROR;
    }
    int counter_of_strings = cnt_str(file_size, input_string);
    struct line* mini_string = (line *)calloc(counter_of_strings, sizeof(line));
    if (mini_string == NULL)
    {
        printf("ERROR: WE CAN'T ALLOCATE MEMORY FOR INPUT STRING");
        return PROGRAM_ERROR;
    }

    construct_text(file_size, mini_string, input_string);
    qsort(mini_string, counter_of_strings, sizeof(struct line), comporator);
    print_program(mini_string, counter_of_strings, f_out);

    qsort(mini_string, counter_of_strings,sizeof(struct line), comporator_by_end);
    print_program(mini_string, counter_of_strings,f_out);
    
    original_sort(file_size, input_string);
    fwrite(input_string, sizeof(char), file_size, f_out);
    free(input_string);
    free(mini_string);
}