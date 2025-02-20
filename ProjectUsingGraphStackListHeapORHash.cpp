#include <iostream>
#include <vector>
#include <list>
#include <termios.h> // for struct termios and terminal control
#include <unistd.h>  // for usleep() function
#include <stdio.h>
#include <string>
#include <thread> // For sleep_for and chrono
#include <chrono> // For duration
// #include <iterator>
using namespace std;

string Higest_Score_Name = "";
int Higest_Score = 0;

// char Trace = '\0';

enum
{
    upMove = 'A',
    downMove = 'B',
    leftMove = 'C',
    rightMove = 'D'

};

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

string toUpperCase(const string &str)
{
    string result = str;
    for (char &c : result)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = c - 32;
        }
    }
    return result;
}

void Win()
{
    showCursor(false);
    for (int i = 4; i < 16; i++)
    {
        textColor(2);
        gotoXY(i, 2);
        cout << "│";
    }

    for (int i = 2; i < 30; i++)
    {
        textColor(2);
        gotoXY(4, i);
        if (i == 2)
        {
            cout << "┌";
        }
        else if (i == 29)
        {
            cout << "┐";
        }
        else
        {
            cout << "─";
        }
    }

    for (int i = 5; i < 16; i++)
    {
        textColor(2);
        gotoXY(i, 29);
        cout << "│";
    }

    for (int i = 2; i < 30; i++)
    {
        textColor(2);
        gotoXY(16, i);
        if (i == 2)
        {
            cout << "└";
        }
        else if (i == 29)
        {
            cout << "┘";
        }
        else
        {
            cout << "─";
        }
    }

    gotoXY(10, 12);
    textColor(4);
    cout << "YOU WIN";

    showCursor(false);

    gotoXY(33, 12);
}

void Lose()
{
    showCursor(false);
    for (int i = 4; i < 16; i++)
    {
        textColor(2);
        gotoXY(i, 2);
        cout << "│";
    }

    for (int i = 2; i < 30; i++)
    {
        textColor(2);
        gotoXY(4, i);
        if (i == 2)
        {
            cout << "┌";
        }
        else if (i == 29)
        {
            cout << "┐";
        }
        else
        {
            cout << "─";
        }
    }

    for (int i = 5; i < 16; i++)
    {
        textColor(2);
        gotoXY(i, 29);
        cout << "│";
    }

    for (int i = 2; i < 30; i++)
    {
        textColor(2);
        gotoXY(16, i);
        if (i == 2)
        {
            cout << "└";
        }
        else if (i == 29)
        {
            cout << "┘";
        }
        else
        {
            cout << "─";
        }
    }

    gotoXY(10, 12);
    textColor(1);
    cout << "YOU LOSE";

    showCursor(false);
}

class Player
{
public:
    string Name;
    double Score;
    Player(string n = "UnKnown") : Name(n), Score(5000) {}
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

class Edge
{
public:
    int destinationId;
    Edge(int id = -1) : destinationId(id) {}
};

class Vertex
{

public:
    int vertexId;
    char vertexName;
    list<Edge> edgesList;

    Vertex(int id = -1, char name = ' ') : vertexId(id), vertexName(name) {}
    void setVertex(int id = -1, char name = ' ')
    {
        vertexId = id;
        vertexName = name;
    }
    void printEdges() const
    {
        cout << "[";
        for (auto it = edgesList.begin(); it != edgesList.end(); ++it)
        {
            cout << it->destinationId << " -> ";
        }
        cout << "]";
    }
};

class Graph
{
public:
    Player player;
    Stack s1, s2;
    vector<Vertex> vertices;

    Graph()
    {
        Vertex v;
        char name;
        int id1, id2;
        for (int i = 1; i < 10; i++)
        {

            id1 = i;
            name = 48 + i;
            if (i != 9)
            {
                v.setVertex(id1, name);
            }
            else
            {
                v.setVertex(id1, ' ');
            }
            addVertex(v);
        }

        connectAllEdges();
        printGraph();
    }
    void connectAllEdges()
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (i % 3 != 0)
            {
                addEdgesById(i, i + 1);
            }
        }

        for (int i = 1; i <= 6; ++i)
        {
            addEdgesById(i, i + 3);
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

    void updateVertex(int vertexId, char newName)
    {
        int idx = getVertexIndex(vertexId);
        if (idx != -1)
        {
            vertices[idx].vertexName = newName;
        }
        else
        {
            cout << "Vertex " << vertexId << " not found.\n";
        }
    }

    bool checkEdgeExist(int fromVertex, int toVertex)
    {
        int idx = getVertexIndex(fromVertex);
        if (idx == -1)
        {
            cout << "Source vertex not found.\n";
            return false;
        }
        for (const auto &edge : vertices[idx].edgesList)
        {
            if (edge.destinationId == toVertex)
                return true;
        }
        return false;
    }

    void printGraph()
    {
        for (const auto &vertex : vertices)
        {
            cout << vertex.vertexName << "(" << vertex.vertexId << ") --> ";
            vertex.printEdges();
            cout << "\n";
        }
        cout << "\n";
    }

    bool checkVertexExist(int id)
    {
        for (const auto &vertex : vertices)
        {
            if (vertex.vertexId == id)
            {
                return true;
            }
        }
        return false;
    }

    int getVertexIndex(int id)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).vertexId == id)
                return i;
        }
        return -1;
    }

    void addVertex(Vertex newVertex)
    {
        if (!checkVertexExist(newVertex.vertexId))
        {
            vertices.push_back(newVertex);
            cout << "Vertex added.\n";
        }
        else
        {
            cout << "Vertex already exists.\n";
        }
    }

    void addEdgesById(int fromVertex, int toVertex)
    {
        if (checkVertexExist(fromVertex) && checkVertexExist(toVertex))
        {
            int idx = getVertexIndex(fromVertex);
            if (idx == -1)
            {
                cout << "Source vertex not found.\n";
                return;
            }
            vertices.at(idx).edgesList.push_back(Edge(toVertex));
            cout << "Edge added from " << fromVertex << " to " << toVertex << ".\n";
        }
        else
        {
            cout << "Invalid vertex id(s) entered.\n";
        }
    }

    void deleteEdgesById(int fromVertex, int toVertex)
    {
        int idx = getVertexIndex(fromVertex);
        if (idx == -1)
        {
            cout << "Source vertex not found.\n";
            return;
        }
        for (auto it = vertices.at(idx).edgesList.begin(); it != vertices.at(idx).edgesList.end(); it++)
        {
            if (it->destinationId == toVertex)
            {
                vertices.at(idx).edgesList.erase(it);
                cout << "Edge deleted.\n";
                return;
            }
        }
        cout << "Edge does not exist.\n";
    }

    void Box()
    {

        showCursor(true);
        // left line
        gotoXY(3, 3);
        textColor(1, true);
        cout << "Score: " << player.Score;

        for (int i = 4; i < 16; i++)
        {
            textColor(2);
            // Set text color to Blue (colorIndex 4)
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
        cout << vertices[0].vertexName;
        gotoXY(6, 15);
        cout << vertices[1].vertexName;
        gotoXY(6, 24);
        cout << vertices[2].vertexName;

        // Row 2 (y=10): Columns 6, 15, 24
        gotoXY(10, 6);
        cout << vertices[3].vertexName;
        gotoXY(10, 15);
        cout << vertices[4].vertexName;
        gotoXY(10, 24);
        cout << vertices[5].vertexName;

        // Row 3 (y=14): Columns 6, 15, 24
        gotoXY(14, 6);
        cout << vertices[6].vertexName;
        gotoXY(14, 15);
        cout << vertices[7].vertexName;
        gotoXY(14, 24);
        cout << vertices[8].vertexName;

        // gotoXY(6, 6);
        // cout << head->data;
        // gotoXY(6, 15);
        // cout << head->next->data;
        // gotoXY(6, 24);
        // cout << head->next->next->data;

        // gotoXY(10, 6);
        // cout << head->next->next->next->data;

        // gotoXY(10, 15);
        // cout << head->next->next->next->next->data;

        // gotoXY(10, 24);
        // cout << head->next->next->next->next->next->data;

        // gotoXY(14, 6);
        // cout << head->next->next->next->next->next->next->data;

        // gotoXY(14, 15);
        // cout << head->next->next->next->next->next->next->next->data;

        // gotoXY(14, 24);
        // cout << head->next->next->next->next->next->next->next->next->data;
    }

    bool checkSequence()
    {
        std::string target = "12345678";
        if (vertices.size() < target.size() + 1)
        {
            return false;
        }
        for (size_t i = 0; i < target.size(); ++i)
        {
            if (vertices[i].vertexName != target[i])
            {
                return false;
            }
        }
        return vertices[target.size()].vertexName == ' ';
    }

    int searchZeroIndex()
    {
        for (size_t i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].vertexName == ' ')
            {
                return static_cast<int>(i + 1);
            }
        }
        return -1;
    }

    Vertex *indexAddress(int pos)
    {
        if (pos < 1 || pos > vertices.size())
        {
            return nullptr;
        }
        return &vertices[pos - 1];
    }

    void Swap(Vertex *v1, Vertex *v2)
    {
        if (v1 && v2)
        {
            char temp = v1->vertexName;
            v1->vertexName = v2->vertexName;
            v2->vertexName = temp;
        }
    }

    char opreate()
    {
        int zeroIndex = searchZeroIndex();
        Vertex *zeroAddress = indexAddress(zeroIndex);

        // If space (the zero marker) is not found, return 'q'.
        if (zeroIndex == -1)
        {
            cout << "Space is Not Found.\n";
            return 'q';
        }

        char input = '\0';
        Vertex *swapNode = nullptr;

        gotoXY(17, 11);
        cout << "Move Input: ";
        input = getch();

        bool undoOp = false;
        bool redoOp = false;

        if (input == 'u')
        {
            if (!s1.isEmpty())
            {
                input = s1.peek();
                undoOp = true;
                undo();
                s1.pop();
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
        }

        if (input == upMove || input == downMove || input == leftMove || input == rightMove)
        {

            // Move Down
            if (input == downMove)
            {
                if (!undoOp)
                {
                    s1.push(upMove);
                }
                if (zeroIndex > 3)
                {
                    swapNode = indexAddress(zeroIndex - 3);
                    Swap(zeroAddress, swapNode);
                }
                else
                {
                    cout << "Move not allowed." << endl;
                    this_thread::sleep_for(chrono::milliseconds(300));
                }
            }
            // Move Up
            else if (input == upMove)
            {
                if (!undoOp)
                {
                    s1.push(downMove);
                }
                if (zeroIndex <= 6)
                {
                    swapNode = indexAddress(zeroIndex + 3);
                    Swap(zeroAddress, swapNode);
                }
                else
                {
                    cout << "Move not allowed." << endl;
                    this_thread::sleep_for(chrono::milliseconds(300));
                }
            }
            // Move Left
            else if (input == leftMove)
            {
                if (!undoOp)
                {
                    s1.push(rightMove);
                }
                if (zeroIndex == 9 || zeroIndex == 8 ||
                    zeroIndex == 6 || zeroIndex == 5 ||
                    zeroIndex == 3 || zeroIndex == 2)
                {
                    swapNode = indexAddress(zeroIndex - 1);
                    Swap(zeroAddress, swapNode);
                }
                else if (zeroIndex == 1 || zeroIndex == 4 || zeroIndex == 7)
                {
                    cout << "Move not allowed." << endl;
                    this_thread::sleep_for(chrono::milliseconds(300));
                }
                else
                {
                    cout << "ERROR!.\n";
                }
            }
            // Move Right
            else if (input == rightMove)
            {
                if (!undoOp)
                {
                    s1.push(leftMove);
                }
                if (zeroIndex == 1 || zeroIndex == 2 ||
                    zeroIndex == 4 || zeroIndex == 5 ||
                    zeroIndex == 7 || zeroIndex == 8)
                {
                    swapNode = indexAddress(zeroIndex + 1);
                    Swap(zeroAddress, swapNode);
                }
                else if (zeroIndex == 3 || zeroIndex == 6 || zeroIndex == 9)
                {
                    cout << "Move not allowed." << endl;
                    this_thread::sleep_for(chrono::milliseconds(300));
                }
                else
                {
                    cout << "ERROR!.\n";
                }
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
};

class GameLogics : private Graph
{
private:
    void wellCome()
    {
        showCursor(false);
        // left line
        for (int i = 4; i < 16; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 2);
            cout << "│";
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
            else
            {
                cout << "─";
            }
            gotoXY(6, i);
            if (i == 2)
            {
                cout << "├";
            }
            else if (i == 29)
            {
                cout << "┤";
            }
            else
            {
                cout << "─";
            }
        }
        // Right line
        for (int i = 5; i < 16; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 29);
            if (i == 6)
            {
                continue;
            }
            else
            {
                cout << "│";
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
            else
            {
                cout << "─";
            }
        }

        gotoXY(5, 11);
        cout << "WELL COME" << endl;
        gotoXY(9, 7);
        string name;
        cout << "Enter Name: ";
        getline(cin, name);
        name = toUpperCase(name);

        gotoXY(9, 7);
        cout << "                    ";
        gotoXY(10, 7);

        cout << "Loading ";
        for (int i = 0; i < 3; i++)
        {
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(500));
        }

        showCursor(false);
    }

public:
    void Play()
    {
        wellCome();

        do
        {
            char input = '\0';
            player.Score = 5000;

            while (true)
            {
                system("clear");
                Box();

                input = opreate();
                if (checkSequence())
                {
                    system("clear");
                    Win();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    gotoXY(17, 3);
                    cout << "Press enter to continue...";
                    cin.ignore();
                    break;
                }

                if (player.Score > 0)
                {
                    player.Score -= 100;
                }
                else
                {
                    system("clear");
                    Lose();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    gotoXY(17, 3);
                    cout << "Press enter to continue...";
                    cin.ignore();
                    break;
                }
            }

            if (player.Score > Higest_Score)
            {
                Higest_Score_Name = player.Name;
                Higest_Score = player.Score;
            }

            gotoXY(18, 2);
            cout << "Do you want to play again? (Y/N): ";
            cin >> input;
            input = toupper(input);

            if (input != 'Y')
            {
                break;
            }

        } while (true);
        gotoXY(9, 5);
        cout << "Thank you for playing!" << endl;
    }
};

int main()
{
    GameLogics Picture_Puzzal;
    Picture_Puzzal.Play();

    cout << endl;
    return 0;
}
