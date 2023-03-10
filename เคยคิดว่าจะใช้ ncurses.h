//เป็นcodeแบบเก่าที่เคยคิดไว้ว่าจะทำเกมส์ใน teminal//
#include <ncurses.h>
#include <vector>
#include <string>
int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    // Define menu options
    std::vector<std::string> options = {"Option 1", "Option 2", "Option 3"};
    int selected_option = 0;

    // Display menu and handle input
    while (true) {
        // Clear the screen
        clear();

        // Print menu options
        for (int i = 0; i < options.size(); i++) {
            if (i == selected_option) {
                attron(A_REVERSE);
            }
            printw("%s\n", options[i].c_str());
            attroff(A_REVERSE);
        }

        // Get input from the user
        int key = getch();

        switch (key) {
            case KEY_UP:
                if (selected_option > 0) {
                    selected_option--;
                }
                break;
            case KEY_DOWN:
                if (selected_option < options.size() - 1) {
                    selected_option++;
                }
                break;
            case '\n':
                clear();
                printw("You selected: %s", options[selected_option].c_str());
                refresh();
                getch();
                return 0;
            default:
                break;
        }

        // Update the display
        refresh();
    }
}
