#pragma once

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
    int len_line;
    char* line_begin;
};
struct data
{
    size_t file_size;
    char* input_string;
    line* mini_string;
};
void Print(data *text, int cnt_str, FILE *f_out);
int CounterStrings(data *text);
void ConstructText(data *text);
int ComparatorStart(const void * ptr1, const void * ptr2);
int FileRead(data *text, FILE *f_in);
size_t size_of_file(FILE *f);
void OriginalSort(data *text);
int ComparatorEnd(const void * ptr1, const void * ptr2);
void DestructText(data *text);
void MakeOutput(data *text, int counter_of_strings, FILE *f_out);
void Myqsort(void *base, size_t counter_of_strings,  int(*compare) (const void *, const void *));
void Swap(struct line* FirstElem, struct line* LastElem);

enum PROGRAM_RES
{
    PROGRAM_SUCESS = 0,
    PROGRAM_ERROR = 1
};
