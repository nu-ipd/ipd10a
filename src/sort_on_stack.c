// sort - reads in some lines of text and prints them sorted
// lexicographically in ascending order.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_COUNT     10
#define MAX_LINE_LENGTH     7
#define STRIDE          (MAX_LINE_LENGTH + 1)

// Reads up to `MAX_LINE_COUNT` lines of maximum length
// `MAX_LINE_LENGTH` each into `lines[]` and returns the number of lines
// stored.
//
// Errors: exits with error status if more than `MAX_LINE_COUNT` lines
// are available to read or if an IO error occurs.
size_t read_lines(char lines[][STRIDE], size_t capacity);

// Sorts the `count` elements of the array `lines`.
void sort_lines(char lines[][STRIDE], size_t count);

// Prints out the `count` elements of array `lines`.
void print_lines(char lines[][STRIDE], size_t count);

int main(void)
{
    char lines[MAX_LINE_COUNT][STRIDE];
    size_t count = read_lines(lines, MAX_LINE_COUNT);
    sort_lines(lines, count);
    print_lines(lines, count);
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

size_t read_lines(char lines[][STRIDE], size_t capacity)
{
    size_t count = 0;

    // read in numbers
    int result;
    char temp[STRIDE];
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

// Swaps the contents of the line buffers pointed to by `s` and `t`.
// PRECONDITION: `s` and `t` are no longer than `STRIDE - 1` and each
// has sufficient capacity to hold the other.
void swap_lines(char* s, char* t)
{
    char temp[STRIDE];
    strcpy(temp, s);
    strcpy(s, t);
    strcpy(t, temp);
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

void sort_lines(char lines[][STRIDE], size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        size_t best = i;
        for (size_t j = i + 1; j < count; ++j) {
            if (cmp_lines(lines[j], lines[best]) < 0) {
                best = j;
            }
        }

        swap_lines(lines[i], lines[best]);
    }
}

void print_lines(char lines[][STRIDE], size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        printf("%s\n", lines[i]);
    }
}
