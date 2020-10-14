#include <stdio.h>
#include <string.h>

#define show_me(C) show_me_fun(#C, sizeof(C), (C))

void show_me_fun(const char* source, size_t static_len,
                 const char* value)
{
    size_t dynamic_len = strlen(value);
    
    printf("sizeof %s  == %zu\n"
           "strlen(%s) == %zu\n"
           "its address is %p\n",
           source, static_len,
           source, dynamic_len,
           (const void*) value);

    printf("The values of its bytes are {\n    ");

    size_t limit = dynamic_len > static_len ? dynamic_len : static_len;
    for (size_t i = 0; i < limit; ++i) {
        printf("%3d", value[i]);
        printf(i % 8 == 7 ? ",\n    " : ", ");
    }
    
    printf("%3d\n}\n\n", 0);
}

int main(void)
{
    show_me("");
    show_me("A");
    show_me("hello,\nworld");
    show_me("a\t\\t\\\t\"'"".");
    show_me("\1\2\3\4\5\6\7\10\11\12\13\14\15\16\17\20");
    show_me("\x41\x62\x43\x64");

    const char* s = "meow";
    const char* t = "the cat's meow";
    show_me(s);
    show_me(t + 10);

    const char u[] = "u";
    show_me(u);
    const char* v = "v";
    show_me(v);
}
    
