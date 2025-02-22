// #include <iostream>
// #include <termios.h>
// #include <unistd.h>
// #include <stdio.h>

// using namespace std;
// enum KEYS
// {
//     KEY_BACK = 127, // ASCII for backspace key
//     KEY_RET = 10,   // ASCII for carriage return/Enter key
//     KEY_ONE = 49,   // ASCII for key '1'
//     KEY_UP = 65,    // ASCII for key up arrow key (escape sequence)
//     KEY_DOWN = 66,  // ASCII for key down arrow key (escape sequence)
//     KEY_LEFT = 68,  // ASCII for key left arrow key (escape sequence)
//     KEY_RIGHT = 67, // ASCII for key right arrow key (escape sequence)
//     KEY_ESC = 27    // ASCII for escape key
// };

// int getch()
// {
//     struct termios oldt, newt;
//     int ch;
//     tcgetattr(STDIN_FILENO, &oldt); // Save current terminal settings
//     newt = oldt;
//     newt.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode and echo
//     tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings immediately
//     ch = getchar();                          // Read the character
//     tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
//     return ch;
// }

// int main()
// {

//     int ch;
//     cout << "Enter the Key: ";

//     while (true)
//     {
//         ch = getch(); // Read a character

//         switch (ch)
//         {
//         case KEY_UP:
//             cout << KEY_UP << endl;
//             cout << "Up Arrow" << endl;
//             break;
//         case KEY_DOWN:
//             cout << "Down Arrow" << endl;
//             break;
//         case KEY_LEFT:
//             cout << "Left Arrow" << endl;
//             break;
//         case KEY_RIGHT:
//             cout << "Right Arrow" << endl;
//             break;
//         case 27: // Escape
//             cout << "Escape" << endl;
//             break;
//         case 10: // Enter
//             cout << "Enter" << endl;
//             break;
//         case 8: // Backspace
//             cout << "Backspace" << endl;
//             break;
//         default:
//             cout << "Unknown Key: " << ch << endl;
//             break;
//         }

//         if (ch == 27)
//         { // Exit on Escape
//             break;
//         }
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// enum Days
// {
//     Sun = 13,
//     Mon = 2,
//     Tues = 3,
//     Wed = 4,
//     Thues = 5,
//     Fri = 6
// };

// int main()
// {
//     char value;
//     cout << "Enter the Value: ";
//     cin >> value;
//     cout << "A " << static_cast<int>(value) << endl;

//     // Days fri = Mon;
//     // cout << "Fri value: " << fri << endl;

//     if (value == Sun)
//     {
//         cout << "Sunday ";
//     }
//     else
//     {
//         cout << "Not sunday ";
//     }

//     cout << endl;
//     return 0;
// }

// #include <curses.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>


// ^[[A

using namespace std;
enum KEYS{
    KEY_BACK = 127, // ASCII for backspace key
    KEY_RET = 10,   // ASCII for carriage return/Enter key
    KEY_ONE = 49,   // ASCII for key '1'
    KEY_UP = 65,    // ASCII for key up arrow key (escape sequence)
    KEY_DOWN = 66,  // ASCII for key down arrow key (escape sequence)
    KEY_LEFT = 68,  // ASCII for key left arrow key (escape sequence)
    KEY_RIGHT = 67, // ASCII for key right arrow key (escape sequence)
    KEY_ESC = 27    // ASCII for escape key
};


char getch() {
  struct termios oldt, newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );           // Save current terminal settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);           // Disable canonical mode and echo
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );   // Apply new settings immediately
  ch = getchar();                            // Read the character
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );   // Restore old settings
  return ch;
}

int main()
{


    char ch;

    while (true)
    {
        ch = getch(); // Read a character

        switch (ch)
        {
        case KEY_UP:
            cout << "Up Arrow" << endl;
            break;
        case KEY_DOWN:
            cout << "Down Arrow" << endl;
            break;
        case KEY_LEFT:
            cout << "Left Arrow" << endl;
            break;
        case KEY_RIGHT:
            cout << "Right Arrow" << endl;
            break;
        case 27: // Escape
            cout << "Escape" << endl;
            break;
        case 10: // Enter
            cout << "Enter" << endl;
            break;
        case 8: // Backspace
            cout << "Backspace" << endl;
            break;
        default:
            cout << "Unknown Key: " << ch << endl;
            break;
        }

        if (ch == 27)
        { // Exit on Escape
            break;
        }
    }

    

    // endwin(); // Terminate ncurses mode

    return 0;
}
























































































// #define KEY_DOWN	0402		/* down-arrow key */
// #define KEY_UP		0403		/* up-arrow key */
// #define KEY_LEFT	0404		/* left-arrow key */
// #define KEY_RIGHT	0405		/* right-arrow key */
// #define KEY_HOME	0406		/* home key */
// #define KEY_BACKSPACE	0407		/* backspace key */
// #define KEY_F0		0410		/* Function keys.  Space for 64 */
// #define KEY_F(n)	(KEY_F0+(n))	/* Value of function key n */
// #define KEY_DL		0510		/* delete-line key */
// #define KEY_IL		0511		/* insert-line key */
// #define KEY_DC		0512		/* delete-character key */
// #define KEY_IC		0513		/* insert-character key */
// #define KEY_EIC		0514		/* sent by rmir or smir in insert mode */
// #define KEY_CLEAR	0515		/* clear-screen or erase key */
// #define KEY_EOS		0516		/* clear-to-end-of-screen key */
// #define KEY_EOL		0517		/* clear-to-end-of-line key */
// #define KEY_SF		0520		/* scroll-forward key */
// #define KEY_SR		0521		/* scroll-backward key */
// #define KEY_NPAGE	0522		/* next-page key */
// #define KEY_PPAGE	0523		/* previous-page key */
// #define KEY_STAB	0524		/* set-tab key */
// #define KEY_CTAB	0525		/* clear-tab key */
// #define KEY_CATAB	0526		/* clear-all-tabs key */
// #define KEY_ENTER	0527		/* enter/send key */
// #define KEY_PRINT	0532		/* print key */
// #define KEY_LL		0533		/* lower-left key (home down) */
// #define KEY_A1		0534		/* upper left of keypad */
// #define KEY_A3		0535		/* upper right of keypad */
// #define KEY_B2		0536		/* center of keypad */
// #define KEY_C1		0537		/* lower left of keypad */
// #define KEY_C3		0540		/* lower right of keypad */
// #define KEY_BTAB	0541		/* back-tab key */
// #define KEY_BEG		0542		/* begin key */
// #define KEY_CANCEL	0543		/* cancel key */
// #define KEY_CLOSE	0544		/* close key */
// #define KEY_COMMAND	0545		/* command key */
// #define KEY_COPY	0546		/* copy key */
// #define KEY_CREATE	0547		/* create key */
// #define KEY_END		0550		/* end key */
// #define KEY_EXIT	0551		/* exit key */
// #define KEY_FIND	0552		/* find key */
// #define KEY_HELP	0553		/* help key */
// #define KEY_MARK	0554		/* mark key */
// #define KEY_MESSAGE	0555		/* message key */
// #define KEY_MOVE	0556		/* move key */
// #define KEY_NEXT	0557		/* next key */
// #define KEY_OPEN	0560		/* open key */
// #define KEY_OPTIONS	0561		/* options key */
// #define KEY_PREVIOUS	0562		/* previous key */
// #define KEY_REDO	0563		/* redo key */
// #define KEY_REFERENCE	0564		/* reference key */
// #define KEY_REFRESH	0565		/* refresh key */
// #define KEY_REPLACE	0566		/* replace key */
// #define KEY_RESTART	0567		/* restart key */
// #define KEY_RESUME	0570		/* resume key */
// #define KEY_SAVE	0571		/* save key */




// #include <iostream>
// #include <termios.h>
// #include <unistd.h>
// #include <stdio.h>

// using namespace std;
// char getch()
// {
//     struct termios oldt, newt;
//     int ch;
//     tcgetattr(STDIN_FILENO, &oldt); // Save current terminal settings
//     newt = oldt;
//     newt.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode and echo
//     tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings immediately
//     ch = getchar();                          // Read the character
//     tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
//     return ch;
// }

// int main()
// {
//     char ch;

//     while (true)
//     {
//         // cin >> ch;
//         ch = getch(); // Read a character

//         if (ch == '\033') // Escape character
//         {
//             cin.ignore(); // Ignore the '[' character
//             ch = cin.get();

//             switch (ch)
//             {
//             case 'A':
//                 cout << "Up Arrow" << endl;
//                 cout << "Character is: " << ch << endl;
//                 break;
//             case 'B':
//                 cout << "Down Arrow" << endl;
//                 cout << "Character is: " << ch << endl;

//                 break;
//             case 'C':
//                 cout << "Right Arrow" << endl;
//                 cout << "Character is: " << ch << endl;

//                 break;
//             case 'D':
//                 cout << "Left Arrow" << endl;
//                 cout << "Character is: " << ch << endl;
//                 break;
//             default:
//                 cout << "Unknown escape sequence" << endl;
//             }
//         }
//         else
//         {
//             cout << "Character: " << ch << endl;
//             cout << "Character is: " << ch << endl;
//         }
//     }

//     return 0;
// }




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

Dry Run with Left Arrow Key Input
Key sequence for the Left Arrow key:

When the Left Arrow key is pressed, the terminal generates an escape sequence:
'\033' (Escape character), '[', 'D'.
Code Execution Line-by-Line
1. cout << "Input: ";

Purpose: Displays the prompt "Input: " to indicate the program is waiting for user input.
Expected Behavior: The terminal displays:
css
Copy code
Input: 
2. char ch = getch();

Purpose: Reads a single character from the terminal using the getch() function.
Behavior During Left Arrow Input:
Escape Sequence Handling: The first character in the sequence is '\033' (Escape character). This is returned by getch() and stored in ch.
State Update:

ch = '\033'.
3. cout << "\nRead: " << ch << endl;

Purpose: Displays the character stored in ch.
Expected Output:
makefile
Copy code
Read: 
The escape character '\033' is non-printable, so no visible output is shown after Read:.
4. if (ch == '\033')

Purpose: Checks if the character read is the Escape character ('\033').
Behavior:
Since ch == '\033' (true for Left Arrow input), the code inside the if block executes.
5. cin.ignore();

Purpose: Ignores the next character in the input buffer (usually '[' in escape sequences).
Behavior During Left Arrow Input:
'[' is skipped from the input stream.
State Update:

Input buffer now contains 'D'.
6. cout << "After Ignore: " << ch << endl;

Purpose: Displays the current value of ch.
Expected Output:
mathematica
Copy code
After Ignore: 
Again, ch still holds '\033', which is non-printable.
7. ch = cin.get();

Purpose: Reads the next character from the input buffer.
Behavior During Left Arrow Input:
The next character 'D' (part of the escape sequence) is read and stored in ch.
State Update:

ch = 'D'.
8. cout << "NewChar: " << ch << endl;

Purpose: Displays the newly read character stored in ch.
Expected Output:
makefile
Copy code
NewChar: D
9. return 0;

Purpose: Ends the program.
Output After Execution:
mathematica
Copy code
Input: 
Read: 
After Ignore: 
NewChar: D
Conceptual Understanding
1. How getch() Works
Purpose: Reads a single character from the terminal without waiting for Enter.
How It Differs from cin.get():
cin.get() waits for Enter and processes input in line mode.
getch() uses non-canonical mode (ICANON disabled), allowing immediate character-by-character input.
2. Role of tcgetattr() and tcsetattr()
tcgetattr(STDIN_FILENO, &oldt):

Retrieves the current terminal settings and stores them in oldt.
tcsetattr(STDIN_FILENO, TCSANOW, &newt):

Applies the modified terminal settings immediately (TCSANOW).
Disables canonical mode (ICANON) for character-by-character input.
Disables echo (ECHO), preventing input from being displayed on the terminal.
tcsetattr(STDIN_FILENO, TCSANOW, &oldt):

Restores the original terminal settings after reading input.
3. Significance of if (ch == '\033')
Purpose: Detects escape sequences that begin with the Escape character ('\033').
How It Works:
Escape sequences for special keys (like arrow keys) begin with '\033' and are followed by additional characters (e.g., '[', 'D' for Left Arrow).
4. Potential Issues with Current Implementation
Limited Handling:

The code assumes all escape sequences have the same structure (e.g., '\033' followed by '[' and a single additional character). This is not always the case.
Some keys or terminals may produce longer or differently formatted escape sequences.
Input Buffer Issues:

cin.ignore() skips exactly one character, which might not work for escape sequences with more than two characters.
5. Alternative Approaches
Using the curses Library:

Provides robust terminal handling for special keys and input modes.
Example: Detecting arrow keys directly without parsing escape sequences.
Reading Full Escape Sequences:

Use a loop to read all characters in an escape sequence:
cpp
Copy code
string seq;
seq += ch; // Add '\033'
while (cin.peek() != EOF && isprint(cin.peek())) {
    seq += cin.get();
}
Mapping Escape Sequences:

Use a map or conditional checks to handle known escape sequences:
cpp
Copy code
if (seq == "\033[D") {
    cout << "Left Arrow Key pressed!" << endl;
}
Limitations of Current Code
Assumes Fixed Format: Assumes escape sequences are always two characters ('\033' and one more), which may not cover all cases.
Platform-Specific: Works well in Linux terminals but not necessarily on other platforms.
No Error Handling: Does not validate the escape sequence or handle unknown inputs.
Expected Output During Left Arrow Key Input
plaintext
Copy code
Input: 
Read: 
After Ignore: 
NewChar: D
Let me know if you’d like an improved version of the code or more details on any section!