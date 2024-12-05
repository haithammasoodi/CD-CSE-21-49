#include <stdio.h>
#include <string.h>

int isKeyword(char str[]) {
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", 
        "default", "do", "double", "else", "enum", "extern", 
        "float", "for", "goto", "if", "int", "long", 
        "register", "return", "short", "signed", "sizeof", 
        "static", "struct", "switch", "typedef", "union", 
        "unsigned", "void", "volatile", "while"
    };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isKeyword(str))
        printf("The string is a keyword.\n");
    else
        printf("The string is NOT a keyword.\n");

    return 0;
}
