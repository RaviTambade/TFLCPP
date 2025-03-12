
#include <stdio.h>
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    long nc;
    nc = 0;
    while (getchar() != EOF)
        nc++;
    printf("%ld\n", nc);

}
 