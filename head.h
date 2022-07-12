#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

void print_program(struct line* mini_string, int cnt_str, FILE *f_out);
int cnt_str(int file_size, char* input_string);
void construct_text(int file_size, struct line* mini_string, char* input_string);
int comporator(const void * ptr1, const void * ptr2);
int fileread(char * big_string, int file_size, FILE *f_in);
size_t size_of_file(FILE *f);
void original_sort(int file_size, char* input_string);
int comporator_by_end(const void * ptr1, const void * ptr2);

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