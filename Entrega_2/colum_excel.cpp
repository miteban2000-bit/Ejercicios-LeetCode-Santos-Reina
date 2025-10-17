#include <stdio.h>
#include <string.h>

int titleToNumber(const char* columnTitle) {
    int result = 0;
    int length = strlen(columnTitle);

    for (int i = 0; i < length; i++) {
        result = result * 26 + (columnTitle[i] - 'A' + 1);
    }

    return result;
}

int main() {
    char columnTitle[10];

    printf("Ingresa el título de columna Excel: ");
    scanf("%s", columnTitle);

    int number = titleToNumber(columnTitle);

    printf("El número correspondiente es: %d\n", number);

    return 0;
}