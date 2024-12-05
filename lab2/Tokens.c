#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    char *keywords[] = {
        "int", "float", "if", "else", "while", "do", "return", "for", "void", "break", "char", "double"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/%=";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int isDelimiter(char ch) {
    char delimiters[] = ",;(){}[]";
    for (int i = 0; delimiters[i] != '\0'; i++) {
        if (ch == delimiters[i])
            return 1;
    }
    return 0;
}

int isRealNumber(char *token) {
    int hasDecimal = 0;
    for (int i = 0; token[i] != '\0'; i++) {
        if (isdigit(token[i]))
            continue;
        else if (token[i] == '.' && !hasDecimal)
            hasDecimal = 1;
        else
            return 0;
    }
    return hasDecimal;
}

int isIdentifier(char *token) {
    if (!isalpha(token[0]) && token[0] != '_')
        return 0;
    for (int i = 1; token[i] != '\0'; i++) {
        if (!isalnum(token[i]) && token[i] != '_')
            return 0;
    }
    return 1;
}

void analyzeToken(char *token) {
    if (isKeyword(token))
        printf("'%s' is a Keyword\n", token);
    else if (isRealNumber(token))
        printf("'%s' is a Real Number\n", token);
    else if (isdigit(token[0]))
        printf("'%s' is a Constant\n", token);
    else if (isIdentifier(token))
        printf("'%s' is an Identifier\n", token);
    else
        printf("'%s' is Unknown\n", token);
}

int main() {
    char str[200], token[50];
    printf("Enter the program code:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("\nTokens and their types:\n");

    for (int i = 0; str[i] != '\0'; i++) {
        if (isDelimiter(str[i])) {
            if (token[0] != '\0') {
                analyzeToken(token);
                memset(token, 0, sizeof(token));
            }
            printf("'%c' is a Delimiter\n", str[i]);
        } else if (isOperator(str[i])) {
            if (token[0] != '\0') {
                analyzeToken(token);
                memset(token, 0, sizeof(token));
            }
            printf("'%c' is an Operator\n", str[i]);
        } else if (!isspace(str[i])) {
            int len = strlen(token);
            token[len] = str[i];
            token[len + 1] = '\0';
        } else {
            if (token[0] != '\0') {
                analyzeToken(token);
                memset(token, 0, sizeof(token));
            }
        }
    }

    if (token[0] != '\0') {
        analyzeToken(token);
    }

    return 0;
}
