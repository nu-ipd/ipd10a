// sort - reads in some lines of text and prints them sorted
// lexicographically in ascending order.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_COUNT     10
#define MAX_LINE_LENGTH     7

// Holds one line of input.
typedef struct line
{
    char data[MAX_LINE_LENGTH + 1];
} line_t;

// Reads up to `MAX_LINE_COUNT` lines of maximum length
// `MAX_LINE_LENGTH` each into `lines[]` and returns the number of lines
// stored.
//
// Errors: exits with error status if more than `MAX_LINE_COUNT` lines
// are available to read or if an IO error occurs.
size_t read_lines(line_t lines[], size_t capacity);

// Sorts the `count` elements of the array `lines`.
void sort_lines(line_t lines[], size_t count);
void sort_lines2(line_t lines[], size_t count);

// Prints out the `count` elements of array `lines`.
void print_lines(line_t lines[], size_t count);


int main(void)
{
    line_t lines[MAX_LINE_COUNT];

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

    for (int c = getchar(); c != until && c != EOF; c = getchar()) {
        if (length + 2 < capacity) {
            buf[length++] = c;
        } else {
            fprintf(stderr, "Can't handle lines this long. Gonna split!\n");
            ungetc(c, stdin);
            break;
        }
    }

    if (ferror(stdin))
        return EOF;

    if (feof(stdin) && !length)
        return 0;

    buf[length++] = 0;

    return length;
}

size_t read_lines(line_t lines[], size_t capacity)
{
    size_t count = 0;

    // read in numbers
    int result;
    line_t temp;
    while ( (result = read_until(temp.data, '\n', sizeof temp.data)) > 0 ) {
        if (count == capacity) {
            fprintf(stderr, "sort: i am full, sorry\n");
            exit(1);
        }

        memcpy(lines[count].data, temp.data, result);
        ++count;
    }

    if (result == EOF) {
        perror("sort");
        exit(2);
    }

    return count;
}

void sort_lines(line_t lines[], size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        size_t best = i;
        for (size_t j = i + 1; j < count; ++j) {
            if (strcmp(lines[j].data, lines[best].data) < 0)
                best = j;
        }

        line_t temp = lines[i];
        lines[i] = lines[best];
        lines[best] = temp;
    }
}

// This function is the same as sort_lines(), but it uses pointers
// instead of array indicies. As always, array algorithms can be written
// in pointer style if you like.
void sort_lines2(line_t lines[], size_t count)
{
    line_t* limit = lines + count;

    for ( ; lines < limit; ++lines) {
        line_t* best = lines;
        for (line_t* each = lines + 1; each < limit; ++each) {
            if (strcmp(each->data, best->data) < 0)
                best = each;
        }

        line_t temp = *lines;
        *lines = *best;
        *best = temp;
    }
}

void print_lines(line_t lines[], size_t count)
{
    for (size_t i = 0; i < count; ++i)
        printf("%s\n", lines[i].data);
}
