// sort - reads in some lines of text and prints them sorted
// lexicographically in ascending order.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_COUNT     10
#define MAX_LINE_LENGTH     7

// Reads up to `MAX_LINE_COUNT` lines of maximum length
// `MAX_LINE_LENGTH` each into `lines[]` and returns the number of lines
// stored.
//
// Errors: exits with error status if more than `MAX_LINE_COUNT` lines
// are available to read or if an IO error occurs.
size_t read_lines(char* lines[], size_t capacity);

// Sorts the `count` elements of the array `lines`.
void sort_lines(char* lines[], size_t count);

// Prints out the `count` elements of array `lines`.
void print_lines(char* lines[], size_t count);


int main(void)
{
    char line_storage[MAX_LINE_COUNT][MAX_LINE_LENGTH + 1];
    char* line_ptrs[MAX_LINE_COUNT];

    for (size_t i = 0; i < MAX_LINE_COUNT; ++i) {
        line_ptrs[i] = line_storage[i];
    }

    size_t count = read_lines(line_ptrs, MAX_LINE_COUNT);
    sort_lines(line_ptrs, count);
    print_lines(line_ptrs, count);
}


// Reads from `stdin` into buffer `buf` until reading the character
// `until`, reaching EOF, or filling all `capacity` bytes of `buf`.
// Returns the number of characters stored in `buf`, including the 0
// delimiter. Returns 0 on end-of-file, and returns `EOF` on I/O errors.
int read_until(char* buf, char until, size_t capacity)
{
    int length = 0;
    int c;

    for (;;) {
        c = getchar();

        if (c == until) {
            break;
        }

        if (c == EOF) {
            if (feof(stdin)) {
                if (length) {
                    break;
                } else {
                    return 0;
                }
            }

            return EOF;
        }

        if (length + 2 < capacity) {
            buf[length++] = c;
        } else {
            fprintf(stderr, "Can't handle lines this long. Gonna split!\n");
            ungetc(c, stdin);
            break;
        }
    }

    buf[length++] = 0;

    return length;
}

size_t read_lines(char* lines[], size_t capacity)
{
    size_t count = 0;

    // read in numbers
    int result;
    char temp[MAX_LINE_LENGTH + 1];
    while ( (result = read_until(temp, '\n', sizeof temp)) > 0 ) {
        if (count == capacity) {
            fprintf(stderr, "sort: i am full, sorry\n");
            exit(1);
        }

        memcpy(lines[count], temp, result);
        ++count;
    }

    if (result == EOF) {
        perror("sort");
        exit(2);
    }

    return count;
}

// Compares `s` and `t` lexicographically. Returns a negative value
// if `s` is less, a positive value if `t` is less, and 0 if they're
// equal.
int cmp_lines(const char* s, const char* t)
{
    while (*s && *s == *t)
    {
        ++s;
        ++t;
    }

    return *s - *t;
}

void sort_lines(char* lines[], size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        size_t best = i;
        for (size_t j = i + 1; j < count; ++j) {
            if (cmp_lines(lines[j], lines[best]) < 0) {
                best = j;
            }
        }

        char* temp = lines[i];
        lines[i] = lines[best];
        lines[best] = temp;
    }
}

void print_lines(char* lines[], size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        printf("%s\n", lines[i]);
    }
}
