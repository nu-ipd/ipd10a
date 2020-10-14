// sort - reads in some numbers (doubles), sorts them, and prints
// them one per line

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100000

// Reads up to `capacity` doubles into `numbers[]` and returns
// the number of values stored.
//
// Errors: exits with error status if more than `capacity` numbers
// are available to read, if the input contains anything that cannot
// be read as a number, or if an IO error occurs.
size_t read_numbers(double numbers[], size_t capacity);

// Sorts the `count` elements of the array `numbers`.
void sort_numbers(double numbers[], size_t count);

// Prints out the `count` elements of array `numbers`.
void print_numbers(double numbers[], size_t count);

int main(int argc, char* argv[])
{
    double numbers[MAX_NUMBERS];
    size_t count = read_numbers(numbers, MAX_NUMBERS);
    sort_numbers(numbers, count);
    print_numbers(numbers, count);
}

size_t read_numbers(double numbers[], size_t capacity)
{
    size_t count = 0;

    // read in numbers
    double temp;
    while (scanf("%lf", &temp) == 1) {
        if (count == capacity) {
            fprintf(stderr, "sort: i am full, sorry\n");
            exit(1);
        }

        numbers[count] = temp;
        ++count;
    }

    if (ferror(stdin)) {
        perror("sort");
        exit(2);
    }

    if (! feof(stdin)) {
        fprintf(stderr, "sort: i only read doubles\n");
        return(3);
    }

    return count;
}

void sort_numbers(double numbers[], size_t count)
{
    // sort the numbers
    for (size_t i = 0; i < count; ++i) {
        size_t best = i;
        for (size_t j = i + 1; j < count; ++j) {
            if (numbers[j] < numbers[best]) {
                best = j;
            }
        }

        double old_i = numbers[i];
        numbers[i] = numbers[best];
        numbers[best] = old_i;
    }
}

void print_numbers(double numbers[], size_t count)
{
    // print the numbers [0, count)
    for (size_t i = 0; i < count; ++i) {
        printf("%g\n", numbers[i]);
    }
}
