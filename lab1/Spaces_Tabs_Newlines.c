#include <stdio.h>

int main() {
    char ch;
    int spaceCount = 0, tabCount = 0, newlineCount = 0;

    printf("Enter text (Press Ctrl+D or Ctrl+Z to stop):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ')
            spaceCount++;
        else if (ch == '\t')
            tabCount++;
        else if (ch == '\n')
            newlineCount++;
    }

    printf("\nNumber of spaces: %d\n", spaceCount);
    printf("Number of tabs: %d\n", tabCount);
    printf("Number of newlines: %d\n", newlineCount);

    return 0;
}
