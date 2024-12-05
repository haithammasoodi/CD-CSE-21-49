#include <stdio.h>
#include <ctype.h>

int isIdentifier(char str[]) {
    int i = 0;

    if (!(isalpha(str[i]) || str[i] == '_'))
        return 0;

    for (i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return 0;
    }

    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isIdentifier(str))
        printf("The string is a valid identifier.\n");
    else
        printf("The string is NOT a valid identifier.\n");

    return 0;
}
