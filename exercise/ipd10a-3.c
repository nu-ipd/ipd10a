#include <libipd.h>
#include <stdio.h>

// A dog and its number of toys.
struct dog
{
    const char* name;
    size_t      n_toys;
};


// Swaps the toy counts of the two given dogs.
//
// Example: See test_swap_n_toys()
void swap_n_toys(struct dog* a_dog, struct dog* b_dog)
{
    // TODO: This function doesn’t do anything yet. Make it do the right
    // thing.
}

void test_swap_n_toys(void)
{
    struct dog olaf = { "Olaf", 4 },
               luna = { "Luna", 0 };

    swap_n_toys(&olaf, &luna);

    // Check that the n_toys fields were swapped:
    CHECK_SIZE( olaf.n_toys, 0 );
    CHECK_SIZE( luna.n_toys, 4 );

    // Make sure that the names were NOT swapped:
    CHECK_STRING( olaf.name, "Olaf" );
    CHECK_STRING( luna.name, "Luna" );

    // This is probably sufficient testing for this function :)
}


int main(void)
{
    test_swap_n_toys();
}
