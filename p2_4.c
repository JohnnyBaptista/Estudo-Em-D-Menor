#include <stdio.h>
#include <stdlib.h>

void Remove_Caractere(char *Str, char ch)
{
    int i, j;
    for(i=0; *(Str+i)!= '\0'; i++) {
        if(*(Str+i) == ch) {
                for(j=i ; *(Str+j) != '\0'; j++) {
                    *(Str+j) = *(Str+j+1);
                }
                i--;
        }

    }
    return;
}

int main(void)
{
    char str[10000], ch;
    printf("Entre com uma string: \n");
    fgets(str, 1000, stdin);
    printf("Que caractere deseja remover? \n");
    scanf("%c", &ch);
    Remove_Caractere(str, ch);
    puts(str);
    return 0;
}

