#include "head.h"

int main()
{
    FILE *f = fopen("text.txt", "rb");
    int file_size = size_of_file(f);
    printf("%d", file_size);
}