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
    cout << "Enter Input: ";
    char ch;

    while (true)
    {
        // cin >> ch;
        ch = getch(); // Read a character

        if (ch == '\033') // Escape character
        {
            cin.ignore(); // Ignore the '[' character
            ch = cin.get();

            // if (ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D')
            // {
            //     cout << ch << endl;
            // }

            switch (ch)
            {
            case 'A':
                cout << "Up Arrow" << endl;
                cout << "Character is: " << ch << endl;
                break;
            case 'B':
                cout << "Down Arrow" << endl;
                cout << "Character is: " << ch << endl;

                break;
            case 'C':
                cout << "Right Arrow" << endl;
                cout << "Character is: " << ch << endl;

                break;
            case 'D':
                cout << "Left Arrow" << endl;
                cout << "Character is: " << ch << endl;
                break;
            default:
                cout << "Unknown escape sequence" << endl;
            }
        }
        else
        {
            cout << "Character: " << ch << endl;
            cout << "Character is: " << ch << endl;
        }
    }

    return 0;
}

/*
"Perform a 'dry run' of the following code snippet, simulating the use of the Left Arrow key.

Step-by-Step Explanation: For each step in the code execution, provide a detailed explanation of:

The current state of the program.
The expected behavior upon pressing the Left Arrow key.
The specific lines of code that would be executed.
Any changes to variables or data structures.
Conceptual Understanding: Explain the underlying concepts involved in:

Key Handling: How the code typically receives and interprets key presses.
State Management: How the program's internal state is affected by key presses, particularly the Left Arrow key.
Data Flow: How data is processed and modified within the code in response to the key press.
By meticulously tracing the code's execution with the Left Arrow key input, you will gain a deeper understanding of its inner workings and identify any potential issues or areas for improvement."
*/

// Dry Run with Left Arrow Key Input
// Key sequence for the Left Arrow key:

// When the Left Arrow key is pressed, the terminal generates an escape sequence:
// '\033' (Escape character), '[', 'D'.
// Code Execution Line-by-Line
// 1. cout << "Input: ";

// Purpose: Displays the prompt "Input: " to indicate the program is waiting for user input.
// Expected Behavior: The terminal displays:
// css
// Copy code
// Input:
// 2. char ch = getch();

// Purpose: Reads a single character from the terminal using the getch() function.
// Behavior During Left Arrow Input:
// Escape Sequence Handling: The first character in the sequence is '\033' (Escape character). This is returned by getch() and stored in ch.
// State Update:

// ch = '\033'.
// 3. cout << "\nRead: " << ch << endl;

// Purpose: Displays the character stored in ch.
// Expected Output:
// makefile
// Copy code
// Read:
// The escape character '\033' is non-printable, so no visible output is shown after Read:.
// 4. if (ch == '\033')

// Purpose: Checks if the character read is the Escape character ('\033').
// Behavior:
// Since ch == '\033' (true for Left Arrow input), the code inside the if block executes.
// 5. cin.ignore();

// Purpose: Ignores the next character in the input buffer (usually '[' in escape sequences).
// Behavior During Left Arrow Input:
// '[' is skipped from the input stream.
// State Update:

// Input buffer now contains 'D'.
// 6. cout << "After Ignore: " << ch << endl;

// Purpose: Displays the current value of ch.
// Expected Output:
// mathematica
// Copy code
// After Ignore:
// Again, ch still holds '\033', which is non-printable.
// 7. ch = cin.get();

// Purpose: Reads the next character from the input buffer.
// Behavior During Left Arrow Input:
// The next character 'D' (part of the escape sequence) is read and stored in ch.
// State Update:

// ch = 'D'.
// 8. cout << "NewChar: " << ch << endl;

// Purpose: Displays the newly read character stored in ch.
// Expected Output:
// makefile
// Copy code
// NewChar: D
// 9. return 0;

// Purpose: Ends the program.
// Output After Execution:
// mathematica
// Copy code
// Input:
// Read:
// After Ignore:
// NewChar: D
// Conceptual Understanding
// 1. How getch() Works
// Purpose: Reads a single character from the terminal without waiting for Enter.
// How It Differs from cin.get():
// cin.get() waits for Enter and processes input in line mode.
// getch() uses non-canonical mode (ICANON disabled), allowing immediate character-by-character input.
// 2. Role of tcgetattr() and tcsetattr()
// tcgetattr(STDIN_FILENO, &oldt):

// Retrieves the current terminal settings and stores them in oldt.
// tcsetattr(STDIN_FILENO, TCSANOW, &newt):

// Applies the modified terminal settings immediately (TCSANOW).
// Disables canonical mode (ICANON) for character-by-character input.
// Disables echo (ECHO), preventing input from being displayed on the terminal.
// tcsetattr(STDIN_FILENO, TCSANOW, &oldt):

// Restores the original terminal settings after reading input.
// 3. Significance of if (ch == '\033')
// Purpose: Detects escape sequences that begin with the Escape character ('\033').
// How It Works:
// Escape sequences for special keys (like arrow keys) begin with '\033' and are followed by additional characters (e.g., '[', 'D' for Left Arrow).
// 4. Potential Issues with Current Implementation
// Limited Handling:

// The code assumes all escape sequences have the same structure (e.g., '\033' followed by '[' and a single additional character). This is not always the case.
// Some keys or terminals may produce longer or differently formatted escape sequences.
// Input Buffer Issues:

// cin.ignore() skips exactly one character, which might not work for escape sequences with more than two characters.
// 5. Alternative Approaches
// Using the curses Library:

// Provides robust terminal handling for special keys and input modes.
// Example: Detecting arrow keys directly without parsing escape sequences.
// Reading Full Escape Sequences:

// Use a loop to read all characters in an escape sequence:
// cpp
// Copy code
// string seq;
// seq += ch; // Add '\033'
// while (cin.peek() != EOF && isprint(cin.peek())) {
//     seq += cin.get();
// }
// Mapping Escape Sequences:

// Use a map or conditional checks to handle known escape sequences:
// cpp
// Copy code
// if (seq == "\033[D") {
//     cout << "Left Arrow Key pressed!" << endl;
// }
// Limitations of Current Code
// Assumes Fixed Format: Assumes escape sequences are always two characters ('\033' and one more), which may not cover all cases.
// Platform-Specific: Works well in Linux terminals but not necessarily on other platforms.
// No Error Handling: Does not validate the escape sequence or handle unknown inputs.
// Expected Output During Left Arrow Key Input
// plaintext
// Copy code
// Input:
// Read:
// After Ignore:
// NewChar: D
// Let me know if you’d like an improved version of the code or more details on any section!