#include <stdio.h>
#include <string.h>

#define show_me(C) show_me_fun(#C, sizeof(C), (C))

void show_me_fun(const char* source, size_t static_len, int value)
{
    printf("sizeof %-7s is %zu,\nits value is %d,\nand it prints"
           " like ‘%c’\n\n",
           source, static_len, value, value);
}

int main(void)
{
    show_me('A');
    show_me('\t');
    show_me('\n');
    show_me(0);
    show_me('\0');
    show_me('\000');
    show_me('\x00');
    show_me('\xfe');
}
    
