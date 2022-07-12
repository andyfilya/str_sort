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

int fileread(char * big_string, int file_size, FILE *f_in)
{
    assert(f_in);
    assert(big_string);
    if (fread(big_string, sizeof(char), file_size, f_in) != file_size)
    {
        printf("We can't read your file, sorry");
        return PROGRAM_ERROR;
    }
    return PROGRAM_SUCESS;
}

int comporator(const void * ptr1, const void * ptr2)
{
    assert(ptr1 && ptr2);
    assert(ptr1 != ptr2);

    const struct line* pptr1 = (const struct line*) ptr1;
    const struct line* pptr2 = (const struct line*) ptr2;

    return strcmp(pptr1->line_begin, pptr2->line_begin);
}
int comporator_by_end(const void * ptr1, const void * ptr2)
{
    assert(ptr1 && ptr2);
    assert(ptr1 != ptr2);

    const struct line* pptr1 = (const struct line*) ptr1;
    const struct line* pptr2 = (const struct line*) ptr2;

    char *ptr1End = pptr1->line_begin + pptr1->len_line - 1;
    char *ptr2End = pptr2->line_begin + pptr2->len_line - 1;

    int min = 0;
    if (pptr1->len_line > pptr2->len_line)
        min = pptr2->len_line;
    else
        min = pptr1->len_line;
    for (int i = 0; i <= min; i++)
    {
        if(*(ptr1End) < *(ptr2End))
        {
            return -1;
        }
        if(*(ptr1End) > *(ptr2End))
        {
            return 1;
        }
        ptr1End--;
        ptr2End--;
    }
    return 0;
}
void construct_text(int file_size, struct line* mini_string, char* input_string)
{
    assert(mini_string && input_string);
    bool flag = true;
    int begin_of_line = 0, order_of_line = 0;

    for(int j = 0; j <= file_size; j++)
    {
        if((isalpha(input_string[j])) && (flag == true))
        {
            mini_string[order_of_line].line_begin = &input_string[j];
            begin_of_line = j;
            flag = false;
        }
        if(input_string[j] == '\0')
        {
            mini_string[order_of_line].len_line = j - begin_of_line;
            int end_of_line = j;
            flag = true;
            while(isalpha(input_string[end_of_line]) == 0)
            {
                end_of_line -= 1;
                mini_string[order_of_line].len_line -= 1;
            }
            mini_string[order_of_line].len_line += 1;
            order_of_line += 1;
        }
    }
}

int cnt_str(int file_size, char* input_string)
{
    assert(input_string);
    int j = 0;
    int counter_of_strings = 0;
    for(j = 0; j < file_size; j++)
    {
        if (input_string[j] == '\n')
        {
            counter_of_strings += 1;
            input_string[j] = '\0';
        }
    }
    input_string[j] = '\0';
    counter_of_strings  += 1;
    return counter_of_strings;
}

void print_program(struct line* mini_string, int cnt_str, FILE *f_out)
{
    for (int j = 0; j < cnt_str; j++)
    {
        fputs(mini_string[j].line_begin, f_out);
        fputs("\n", f_out);
    }
    fputs("\n\n\n -------------------------- \n\n\n", f_out);
}
void original_sort(int file_size, char* input_string)
{
    int i = 0;
    for (i = 0; i < file_size; i++)
    {
        if (input_string[i] == '\0')
        {
            input_string[i] = '\n';
        }
    }
    input_string[i] = '\n';
}