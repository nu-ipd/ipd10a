// sort - reads in some numbers (doubles), sorts them, and prints
// them one per line

#include <stdio.h>

#define MAX_NUMBERS 100000

int main(int argc, char* argv[])
{
    double numbers[MAX_NUMBERS];
    size_t count = 0;

    // read in numbers
    double temp;
    while (scanf("%lf", &temp) == 1) {
        if (count == MAX_NUMBERS) {
            fprintf(stderr, "%s: i am full, sorry\n", argv[0]);
            return 1;
        }

        numbers[count] = temp;
        ++count;
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 2;
    }

    if (! feof(stdin)) {
        fprintf(stderr, "%s: i only read doubles\n", argv[0]);
        return 3;
    }

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

    // print the numbers [0, count)
    for (size_t i = 0; i < count; ++i) {
        printf("%g\n", numbers[i]);
    }
}
