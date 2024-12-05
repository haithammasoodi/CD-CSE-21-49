#include <stdio.h>
#include <ctype.h>

int isConstant(char str[]) {
    int i = 0, hasDecimal = 0;

    if (str[i] == '+' || str[i] == '-') 
        i++;

    for (; str[i] != '\0'; i++) {
        if (isdigit(str[i])) 
            continue;
        else if (str[i] == '.' && !hasDecimal) 
            hasDecimal = 1;
        else 
            return 0;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isConstant(str))
        printf("The string is a constant.\n");
    else
        printf("The string is NOT a constant.\n");

    return 0;
}
