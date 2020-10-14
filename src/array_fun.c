#include <stdio.h>

struct dog
{
    const char*   name;
    size_t        n_toys;
};

void print_dog(struct dog a_dog)
{
    printf("%s has %zu toys.\n", a_dog.name, a_dog.n_toys);
}

void add_to_toys(struct dog *a_dog_ptr, size_t d_toys)
{
    a_dog_ptr->n_toys += d_toys;
}

void all_dogs_get_all_toys(struct dog* all_dogs, size_t n)
{
    size_t toy_count = 0;

    for (size_t i = 0; i < n; ++i) {
        toy_count += all_dogs[i].n_toys;
    }

    for (size_t i = 0; i < n; ++i) {
        all_dogs[i].n_toys = toy_count;
    }
}

int main(void)
{
    struct dog dogs[3];
    dogs[0].name = "Olaf";
    dogs[0].n_toys = 4;
    dogs[1].name = "Luna";
    dogs[1].n_toys = 3;
    dogs[2].name = "Roxy";
    dogs[2].n_toys = 7;

    all_dogs_get_all_toys(dogs, 3);
    
    printf("\n");
    print_dog(dogs[0]);
    print_dog(dogs[1]);
    print_dog(dogs[2]);
}
