#include <libipd.h>
#include <stdio.h>

// A dog and its number of toys.
struct dog
{
    const char* name;
    size_t      n_toys;
};

// Finds the dog with the most toys.
//
// Given a pointer array an array of `struct dog`s `all_dogs`
// and the array’s size `n`, returns a pointer to the dog with
// the most toys. Ties go to earlier dog in the array. Returns NULL when
// `n` is 0.
//
// Examples: See test_most()
const struct dog*
dog_with_the_most_toys(const struct dog all_dogs[], size_t n)
{
    // TODO: This result is usually wrong. Make it always right.
    return NULL;
}

void test_most(void)
{
    struct dog two_dogs[] = {
        "Olaf", 4,
        "Luna", 0,
    };

    CHECK_POINTER( dog_with_the_most_toys(two_dogs, 2),
                   &two_dogs[0] );

    struct dog three_dogs[] = {
        "Luna", 3,
        "Roxy", 7,
        "Olaf", 4,
    };

    CHECK_POINTER( dog_with_the_most_toys(three_dogs, 3),
                   &three_dogs[1] );

    // TODO: You need a bunch more test cases. Add them right here.
}


// Sorts an array of `n` dogs in place by their toy counts.
//
// Examples: See test_sort
void sort_dogs_by_toys(struct dog all_dogs[], size_t n)
{
    // TODO: Right now, this function is only correct if `all_dogs` is
    // already sorted when the function is called. Fix it so that it’s
    // always correct.
}

void test_sort(void)
{
    struct dog two_dogs[] = {
        "Olaf", 4,
        "Luna", 0,
    };

    sort_dogs_by_toys(two_dogs, 2);

    CHECK_STRING( two_dogs[0].name, "Luna" );
    CHECK_SIZE( two_dogs[0].n_toys, 0 );
    CHECK_STRING( two_dogs[1].name, "Olaf" );
    CHECK_SIZE( two_dogs[1].n_toys, 4 );

    // TODO: You need a bunch more test cases. Add them right here.
}


int main(void)
{
    test_most();
    test_sort();
}
