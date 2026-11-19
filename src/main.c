#include <ncurses.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) return 1;
    int c, ch, x = 0, y = 0;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) return 1;
    initscr();
    noecho();

    /* Main code */
    while ((c = fgetc(file)) != EOF) addch(c);
    while ((ch = getch()) != '-') {
        switch (ch) {
            case 'h': x--; break;
            case 'j': y++; break;
            case 'k': y--; break;
            case 'l': x++; break;
            default: break;
        }

        move(y, x);
        refresh();
    }

    endwin();
    fclose(file);
    return 0;
}
