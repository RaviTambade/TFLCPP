#include <stdio.h>
int main(){
    int no;
    char c;
    printf("entr the no");
    scanf("%d",&no);
    while (no<=255)
    {
        printf("%d,%c\n",no,no);//%d is a format specifier that tells printf to print the integer value of no.
          no++;                      // %c is a format specifier that tells printf to print the character that corresponds to the ASCII value of no.
    }
    return 0;
}