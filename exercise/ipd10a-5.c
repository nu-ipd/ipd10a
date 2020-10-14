#include <libipd.h>
#include <stdbool.h>

// Determines whether the string `s` is a palindrome.
//
// Examples: See test_is_palindrome()
bool is_palindrome(const char* s)
{
    // TODO: For most arguments this function returns the an incorrect
    // result. Make it always return the correct result.
    return true;
}

void test_is_palindrome(void)
{
    CHECK( is_palindrome("aba") );
    CHECK( ! is_palindrome("abc") );

    // TODO: You need more tests here!
}


// Determines whether the string `needle` is prefix of the string
// `haystack`.
//
// This is the case when the first `strlen(needle)` characters of
// `haystack` are the same as the characters of `needle`.
//
// Examples:
//
//   - is_prefix_of("hello", "hello, world") == true
//   - is_prefix_of("hello", "hell world")   == false
//   - is_prefix_of("abcde", "a")            == false
//   - is_prefix_of("",      "abc")          == true
//
bool is_prefix_of(const char* needle, const char* haystack)
{
    // TODO: For most arguments this function returns the an incorrect
    // result. Make it always return the correct result.
    return true;
}

void test_is_prefix_of(void)
{
    // TODO: Write tests for is_prefix_of() here.
}


int main(void)
{
    test_is_palindrome();
    test_is_prefix_of();
}
