#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stack>

using namespace std;

// Function to read a single character without waiting for Enter
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
    char ch;
    stack<char> s; // Stack to store arrow key inputs

    while (true)
    {
        ch = getch(); // Read a character

        if (ch == '\033') // Escape character (start of an arrow key sequence)
        {
            cin.ignore();  // Ignore the '[' character
            ch = cin.get(); // Get the arrow key indicator ('A', 'B', 'C', 'D')

            switch (ch)
            {
            case 'A':
                cout << "Up Arrow" << endl;
                s.push('A'); // Push 'A' into the stack
                break;
            case 'B':
                cout << "Down Arrow" << endl;
                s.push('B'); // Push 'B' into the stack
                break;
            case 'C':
                cout << "Right Arrow" << endl;
                s.push('C'); // Push 'C' into the stack
                break;
            case 'D':
                cout << "Left Arrow" << endl;
                s.push('D'); // Push 'D' into the stack
                break;
            default:
                cout << "Unknown escape sequence" << endl;
            }
        }
        else if (ch == 'q') // Quit the program when 'q' is pressed
        {
            cout << "Exiting program..." << endl;
            break;
        }
        else
        {
            cout << "Character: " << ch << endl;
            s.push(ch); // Push other characters into the stack
        }

        // Display the contents of the stack for verification
        cout << "Stack contents (top to bottom): ";
        stack<char> temp = s; // Create a temporary stack to display contents
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    return 0;
}
