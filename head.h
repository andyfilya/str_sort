#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
struct line
{
    int len_line;;
    char* line_begin;
};
struct data
{
    size_t file_size;
    char* input_string;
    line* mini_string;
};
void print_program(data *text, int cnt_str, FILE *f_out);
int cnt_str(data *text);
void construct_text(data *text);
int comporator(const void * ptr1, const void * ptr2);
int fileread(data *text, FILE *f_in);
size_t size_of_file(FILE *f);
void original_sort(data *text);
int comporator_by_end(const void * ptr1, const void * ptr2);
void destruct_text(data *text);
void make_output(data *text, int counter_of_strings, FILE *f_out);


enum PROGRAM_RES
{
    PROGRAM_SUCESS = 0,
    PROGRAM_ERROR = 1,
};