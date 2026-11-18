#include <stdio.h>

int main(int argc, char *argv[]) {
    int c = 0;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
    return 0;
}
