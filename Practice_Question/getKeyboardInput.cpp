#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Function to set terminal to raw mode for capturing key inputs
void setRawMode(bool enable)
{
    static struct termios oldt, newt;
    if (enable)
    {
        // Save current terminal settings
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        // Disable canonical mode and echoing
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
    else
    {
        // Restore original terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

int main()
{
    char c;
    bool running = true;

    // Set terminal to raw mode
    setRawMode(true);

    cout << "Press arrow keys, backspace, or ESC to interact (ESC to exit):" << endl;

    while (running)
    {
        c = getchar(); // Get a single character input

        if (c == 27) // ESC key starts with 27
        {
            c = getchar(); // Read the next character (for arrow keys)
            if (c == 91)
            {
                c = getchar(); // Determine the arrow key direction
                switch (c)
                {
                case 'A':
                    cout << "Up arrow key pressed!" << endl;
                    break;
                case 'B':
                    cout << "Down arrow key pressed!" << endl;
                    break;
                case 'C':
                    cout << "Right arrow key pressed!" << endl;
                    break;
                case 'D':
                    cout << "Left arrow key pressed!" << endl;
                    break;
                default:
                    break;
                }
            }
            else
            {
                cout << "ESC key pressed! Exiting..." << endl;
                running = false; // Terminate the loop
            }
        }
        else if (c == 127) // Backspace key
        {
            cout << "Backspace key pressed!" << endl;
        }
        else
        {
            cout << "Other key pressed: " << c << endl;
        }
    }

    // Restore terminal to original settings
    setRawMode(false);

    return 0;
}
