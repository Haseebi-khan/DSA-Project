#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

void setNonCanonicalMode(bool enable)
{
    static struct termios oldt, newt;
    if (enable)
    {
        tcgetattr(STDIN_FILENO, &oldt);  // Save old terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
    else
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore old settings
    }
}

int main()
{
    setNonCanonicalMode(true);  // Enable non-canonical mode

    cout << "Press arrow keys or ESC (Press 'q' to quit):\n";

    while (true)
    {
        char ch = getchar();

        if (ch == 27)  // ESC or Arrow key
        {
            ch = getchar();
            if (ch == 91)  // Arrow key sequence
            {
                ch = getchar();
                switch (ch)
                {
                case 'A':
                    cout << "Up arrow pressed\n";
                    break;
                case 'B':
                    cout << "Down arrow pressed\n";
                    break;
                case 'C':
                    cout << "Right arrow pressed\n";
                    break;
                case 'D':
                    cout << "Left arrow pressed\n";
                    break;
                }
            }
            else
            {
                cout << "ESC key pressed\n";
                break;
            }
        }
        else if (ch == 'q')  // Press 'q' to quit
        {
            break;
        }
    }

    setNonCanonicalMode(false);  // Restore canonical mode
    cout << "Program exited.\n";

    return 0;
}


// /////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT, ESC };

void setNonCanonicalMode(bool enable)
{
    static struct termios oldt, newt;
    if (enable)
    {
        tcgetattr(STDIN_FILENO, &oldt);  // Save old terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
    else
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore old settings
    }
}

Direction getArrowKey()
{
    char ch = getchar();
    if (ch == 27)  // ESC or Arrow key
    {
        ch = getchar();
        if (ch == 91)  // Arrow key sequence
        {
            ch = getchar();
            switch (ch)
            {
            case 'A':
                return UP;
            case 'B':
                return DOWN;
            case 'C':
                return RIGHT;
            case 'D':
                return LEFT;
            }
        }
    }
    return ESC;
}

int main()
{
    setNonCanonicalMode(true);  // Enable non-canonical mode

    cout << "Press arrow keys or ESC (Press 'q' to quit):\n";

    while (true)
    {
        Direction dir = getArrowKey();

        if (dir == ESC)  // ESC key pressed
        {
            cout << "ESC key pressed. Exiting...\n";
            break;
        }
        else if (dir == UP)
        {
            cout << "Up arrow pressed\n";
        }
        else if (dir == DOWN)
        {
            cout << "Down arrow pressed\n";
        }
        else if (dir == LEFT)
        {
            cout << "Left arrow pressed\n";
        }
        else if (dir == RIGHT)
        {
            cout << "Right arrow pressed\n";
        }

        char ch = getchar();
        if (ch == 'q')  // Quit the program with 'q'
        {
            break;
        }
    }

    setNonCanonicalMode(false);  // Restore canonical mode
    cout << "Program exited.\n";

    return 0;
}
