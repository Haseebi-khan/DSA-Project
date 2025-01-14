// I have to remove unneccessary Libraries.
#include <iostream>
#include <termios.h> // for struct termios and terminal control
#include <unistd.h>  // for usleep() function
#include <stdio.h>
#include <string>

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

void gotoXY(int x, int y)
{
    cout << "\033[" << x << ";" << y << "H";
}

void textColor(int colorIndex, bool bold = false)
{
    // ANSI escape codes for text color
    string colorCode;

    // Handle color selection
    switch (colorIndex)
    {
    case 0: // Black
        colorCode = "\033[30m";
        break;
    case 1: // Red
        colorCode = "\033[31m";
        break;
    case 2: // Green
        colorCode = "\033[32m";
        break;
    case 3: // Yellow
        colorCode = "\033[33m";
        break;
    case 4: // Blue
        colorCode = "\033[34m";
        break;
    case 5: // Magenta
        colorCode = "\033[35m";
        break;
    case 6: // Cyan
        colorCode = "\033[36m";
        break;
    case 7: // White
        colorCode = "\033[37m";
        break;
    default:
        // Default to white if colorIndex is out of range
        colorCode = "\033[37m";
        break;
    }

    // Apply bold effect if required
    if (bold)
    {
        colorCode = "\033[1m" + colorCode; // Add bold before color
    }

    cout << colorCode;
}

void showCursor(bool showFlag)
{
    if (showFlag)
    {
        cout << "\033[?25h"; // Show cursor
    }
    else
    {
        cout << "\033[?25l"; // Hide cursor
    }
}

// Stack

class Player
{
public:
    string Name;
    double Score = 5000;
    Player(string n = "UnKnown") : Name(n) {}
};

class Node
{
public:
    char data;
    Node *next;
    Node *pre;
    Node(char value) : data(value), next(nullptr), pre(nullptr) {}
};

class NodeS
{
public:
    char data;
    NodeS *next;
    NodeS(char d = '\0') : data(d), next(nullptr) {}
};

class Stack
{
    NodeS *top;

public:
    Stack() : top(nullptr) {}

    void push(char ch)
    {
        NodeS *newNode = new NodeS(ch);
        if (top == nullptr)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
            return;

        NodeS *temp = top;
        top = top->next;
        delete temp;
    }

    char peek()
    {
        if (top == nullptr)
        {
            return '\0';
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
    void show()
    {
        if (top == nullptr)
        {
            return;
        }
        NodeS *temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Doubly Linked List (DLL)

class doublyLinkedList
{
protected:
    Node *head, *tail;

    Stack s1, s2;

    void addNode(char value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    void undo()
    {
        if (!s1.isEmpty())
        {
            s2.push(s1.peek());
            s1.pop();
        }
    }

    void redo()
    {
        if (!s2.isEmpty())
        {
            s1.push(s2.peek());
            s2.pop();
        }
    }

public:
    // Node *getHead() const
    // {
    //     return head;
    // }
    // Node *getTail() const
    // {
    //     return tail;
    // }
    void Box()
    {
        showCursor(true);
        // left line
        for (int i = 4; i < 16; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 2);

            if (i == 8)
            {
                cout << "├";
            }
            else if (i == 12)
            {
                cout << "├";
            }
            else
            {
                cout << "│";
            }

            // Inner left
            if (i >= 5)
            {
                gotoXY(i, 11);
                if (i == 8)
                {
                    cout << "┼";
                }
                else if (i == 12)
                {
                    cout << "┼";
                }

                else
                {
                    cout << "│";
                }
            }
        }
        // Upper line
        for (int i = 2; i < 30; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(4, i);
            if (i == 2)
            {
                cout << "┌";
            }
            else if (i == 29)
            {
                cout << "┐";
            }
            else if (i == 11)
            {
                cout << "┬";
            }
            else if (i == 20)
            {
                cout << "┬";
            }
            else
            {
                cout << "─";
                // Inner Upper
                if (i >= 3)
                {
                    if (i == 11 || i == 20 || i == 29)
                    {
                        continue;
                    }
                    else
                    {
                        gotoXY(8, i);
                        cout << "─";
                    }
                }
            }
        }
        // Right line
        for (int i = 5; i < 16; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 29);
            if (i == 8)
            {
                cout << "┤";
            }
            else if (i == 12)
            {
                cout << "┤";
            }
            else
            {
                cout << "│";
            }

            // Inner Right
            if (i >= 5)
            {
                gotoXY(i, 20);
                if (i == 8)
                {
                    cout << "┼";
                }
                else if (i == 12)
                {
                    cout << "┼";
                }

                else
                {
                    cout << "│";
                }
            }
        }
        // Lower line
        for (int i = 2; i < 30; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(16, i);
            if (i == 2)
            {
                cout << "└";
            }
            else if (i == 29)
            {
                cout << "┘";
            }
            else if (i == 11)
            {
                cout << "┴";
            }
            else if (i == 20)
            {
                cout << "┴";
            }
            else
            {
                cout << "─";
                // Inner Lower
                if (i >= 3)
                {
                    if (i == 11 || i == 20 || i == 29)
                    {
                        continue;
                    }
                    else
                    {
                        gotoXY(12, i);
                        cout << "─";
                    }
                }
            }
        }
        cout << endl;

        showCursor(false);
        textColor(4, true);

        gotoXY(6, 6);
        cout << head->data;
        gotoXY(6, 15);
        cout << head->next->data;
        gotoXY(6, 24);
        cout << head->next->next->data;

        gotoXY(10, 6);
        cout << head->next->next->next->data;

        gotoXY(10, 15);
        cout << head->next->next->next->next->data;

        gotoXY(10, 24);
        cout << head->next->next->next->next->next->data;

        gotoXY(14, 6);
        cout << head->next->next->next->next->next->next->data;

        gotoXY(14, 15);
        cout << head->next->next->next->next->next->next->next->data;

        gotoXY(14, 24);
        cout << head->next->next->next->next->next->next->next->next->data;
    }
    // Constructor
    doublyLinkedList()
    {
        head = tail = nullptr;

        string numbers = "";

        int low = 1, high = 8;
        int count = 0;
        srand(time(0));

        while (count < (high - low + 1))
        {
            bool found = false;
            int random_number = low + rand() % (high - low + 1);

            for (char ch : numbers)
            {

                if (ch - '0' == random_number)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Unique Number is: " << random_number << endl;
                numbers += to_string(random_number);
                count++;
            }
        }

        for (int i = 0; i < 8; i++)
        {
            addNode(numbers[i]);
        }

        addNode(' ');
    }
    // Destructor
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Display()
    {
        if (head == nullptr)
        {
            cout << "Linked list Underflow.\n";
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Search for a node with a given value and
    // delete it from the doubly linked list.
    Node *indexAddress(int pos)
    {
        Node *current = head;
        int count = 1;
        while (current != nullptr && count < pos)
        {
            current = current->next;
            count++;
        }
        // 1 2 3 4 5 6 7 8 0
        // 1 2 3 4 5 6 7 8 9

        return current;
    }

    int searchZero()
    {

        bool found = false;
        Node *current = head;
        int iteration = 1;
        while (current != nullptr)
        {
            if (current->data == 32)
            {
                // cout << "Value is: " << current->data;
                // cout << " Index is: " << iteration << endl;
                found = true;
                break;
            }
            current = current->next;
            iteration++;
        }

        if (found)
        {
            // cout << "Iteration: " << iteration << endl;
            return iteration;
        }
        return -1;
    }

    char opreate()
    {
        int zeroIndex = searchZero();
        // cout << "zeroIndex: " << zeroIndex <<endl;
        Node *zeroAddress = indexAddress(zeroIndex);

        if (zeroIndex == ' ')
        {
            cout << "Space is Not Found.\n";
            return 'q';
        }

        char input = '\0';
        Node *swapNode = nullptr;
        gotoXY(17, 11);

        cout << "Move Input: ";
        input = getch();

        // // Validate input
        // while (input != 'w' && input != 'W' &&
        //        input != 's' && input != 'S' &&
        //        input != 'a' && input != 'A' &&
        //        input != 'd' && input != 'D')
        // {
        //     cout << "Please enter a valid input.\n";
        //     cout << "Enter valid move input: ";
        //     cin >> input;
        // }

        if (input == 'u')
        {
            undo();
            if (!s1.isEmpty())
            {
                input = s1.peek();
            }
            else
            {
                input = '\0';
            }
        }
        else if (input == 'r')
        {
            redo();
            if (!s2.isEmpty())
            {
                input = s2.peek();
            }
            else
            {
                input = '\0';
            }
        }

        if (input == '\033')
        {
            char nextChar = cin.get();
            if (nextChar == '[')
            {
                input = cin.get();
            }

            // Move up
            if (input == 'A' || input == 'B' || input == 'C' || input == 'D')
            {
                if (input == 'B') // || input == 's'
                {
                    s1.push('A');

                    if (zeroIndex > 3)
                    {
                        swapNode = indexAddress(zeroIndex - 3);
                        Swap(zeroAddress, swapNode);
                    }
                    else
                    {
                        cout << "Move not allowed." << endl;
                    }
                }
                // Move down
                else if (input == 'A') // || input == 'w'
                {
                    s1.push('B');

                    if (zeroIndex <= 6)
                    {
                        swapNode = indexAddress(zeroIndex + 3);
                        Swap(zeroAddress, swapNode);
                    }
                    else
                    {
                        cout << "Move not allowed." << endl;
                    }
                }
                // Move left
                else if (input == 'C') // || input == 'd'
                {
                    s1.push('D');

                    if (zeroIndex == 9)
                    {
                        swapNode = indexAddress(zeroIndex - 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 8)
                    {
                        swapNode = indexAddress(zeroIndex - 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 6)
                    {
                        swapNode = indexAddress(zeroIndex - 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 5)
                    {
                        swapNode = indexAddress(zeroIndex - 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 3)
                    {
                        swapNode = indexAddress(zeroIndex - 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 2)
                    {
                        swapNode = indexAddress(zeroIndex - 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 1 || zeroIndex == 4 || zeroIndex == 7)
                    {
                        cout << "Move not allowed." << endl;
                    }
                    else
                    {
                        cout << "ERROR!.\n";
                    }
                }
                // Move right
                else if (input == 'D') // || input == 'a'
                {
                    s1.push('C');

                    if (zeroIndex == 1)
                    {
                        swapNode = indexAddress(zeroIndex + 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 2)
                    {
                        swapNode = indexAddress(zeroIndex + 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 4)
                    {
                        swapNode = indexAddress(zeroIndex + 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 5)
                    {
                        swapNode = indexAddress(zeroIndex + 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 7)
                    {
                        swapNode = indexAddress(zeroIndex + 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 8)
                    {
                        swapNode = indexAddress(zeroIndex + 1);
                        Swap(zeroAddress, swapNode);
                    }
                    else if (zeroIndex == 3 || zeroIndex == 6 || zeroIndex == 9)
                    {
                        cout << "Move not allowed." << endl;
                    }
                    else
                    {
                        cout << "ERROR!.\n";
                    }
                }
                // showData();
                // opreate();
            }
        }
        else if (input == 'q')
        {
            return 'q';
        }
        else
        {
            cout << "Use Arrow Key.\n";
        }

        return input;
    }

    void Swap(Node *Node1, Node *Node2)
    {
        if (Node1 && Node2)
        {
            int temp = Node1->data;
            Node1->data = Node2->data;
            Node2->data = temp;
        }
    }
};

class GameLogics : private doublyLinkedList
{
private:
    // Player player;

public:
    void Play()
    {
        char input = '\0';
        do
        {
            system("clear");
            Box();
            input = opreate();
        } while (input != 'q');
    }
};

int main()
{
    GameLogics a;
    a.Play();

    cout << endl;
    return 0;
}