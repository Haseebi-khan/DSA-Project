#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

char getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt); // Save current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings immediately
    ch = getchar();                          // Read the character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    return ch;
}

int main()
{
    cout << "Input: ";
    char ch = getch(); // Read a character
    cout << "\nRead: " << ch << endl;

    if (ch == '\033') // Escape character
    {
        cin.ignore(); // Ignore the '[' character
        cout << "After Ignore: " << ch << endl;
        ch = cin.get();
        cout << "NewChar: " << ch << endl;
    }

    cout << endl;
    return 0;
}