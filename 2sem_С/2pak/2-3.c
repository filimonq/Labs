#include <stdio.h>

int main()
{
    #if defined(__GNUC__) && !defined(__clang__)
        printf("Compiler: GCC\n");
    #elif defined(__TINYC__)
        printf("Compiler: TCC\n");
    #else
        printf("Compiler: clang\n");
    #endif

    #if defined(__x86_64__) || defined(__LP64__)
        printf("Bitness: 64\n");
    #else
        printf("Bitness: 32\n");
    #endif
    
    #if defined(NDEBUG)
        printf("Asserts: disabled\n");
    #else
        printf("Asserts: enabled\n");
    #endif
    return 0;
}

// Compiler: GCC
// Bitness: 64
// Asserts: disabled
