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

int fileread(data *text, FILE *f_in)
{
    assert(f_in);
    assert(text);

    text->file_size = size_of_file(f_in);
    text->input_string = (char*)calloc(text->file_size, sizeof(char));
    if(!(text->input_string))
    {
        printf("ERROR: WE CAN'T ALLOCATE MEMORY\n");
        return PROGRAM_ERROR;
    }
    if (fread(text->input_string, sizeof(char), text->file_size, f_in) != text->file_size)
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
void construct_text(data *text)
{
    assert(text->mini_string && text->input_string);
    bool flag = true;
    int begin_of_line = 0, order_of_line = 0;

    for(int j = 0; j <= text->file_size; j++)
    {
        if((isalpha(text->input_string[j])) && (flag == true))
        {
            text->mini_string[order_of_line].line_begin = &text->input_string[j];
            begin_of_line = j;
            flag = false;
        }
        if(text->input_string[j] == '\0')
        {
            text->mini_string[order_of_line].len_line = j - begin_of_line;
            int end_of_line = j;
            flag = true;
            while(isalpha(text->input_string[end_of_line]) == 0)
            {
                end_of_line -= 1;
                text->mini_string[order_of_line].len_line -= 1;
            }
            text->mini_string[order_of_line].len_line += 1;
            order_of_line += 1;
        }
    }
}
void destruct_text(data *text)
{
    assert(text);
    
    free(text->input_string);
    text->input_string = nullptr;

    free(text->mini_string);
    text->mini_string = nullptr;
}
int cnt_str(data *text)
{
    assert(text->input_string);
    int j = 0;
    int counter_of_strings = 0;
    for(j = 0; j < text->file_size; j++)
    {
        if (text->input_string[j] == '\n')
        {
            counter_of_strings += 1;
            text->input_string[j] = '\0';
        }
    }
    text->input_string[j] = '\0';
    counter_of_strings  += 1;
    return counter_of_strings;
}

void print_program(data *text, int cnt_str, FILE *f_out)
{
    for (int j = 0; j < cnt_str; j++)
    {
        fputs(text->mini_string[j].line_begin, f_out);
        fputs("\n", f_out);
    }
    fputs("\n\n\n -------------------------- \n\n\n", f_out);
}
void original_sort(data *text)
{
    int i = 0;
    for (i = 0; i < text->file_size; i++)
    {
        if (text->input_string[i] == '\0')
        {
            text->input_string[i] = '\n';
        }
    }
    text->input_string[i] = '\n';
}
void make_output(data *text, int counter_of_strings, FILE *f_out)
{
    construct_text(text);
    qsort(text->mini_string, counter_of_strings, sizeof(struct line), comporator);
    print_program(text, counter_of_strings, f_out);

    qsort(text->mini_string, counter_of_strings,sizeof(struct line), comporator_by_end);
    print_program(text, counter_of_strings,f_out);
    
    original_sort(text);
    fwrite(text->input_string, sizeof(char), text->file_size, f_out);
}