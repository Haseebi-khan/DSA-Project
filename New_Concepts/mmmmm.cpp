#include <iostream>
#include <string>
using namespace std;

// Node structure for Binary Tree (Course Tree)
struct TreeNode
{
    string name;
    TreeNode *children[10]; // Fixed array for child nodes
    int childCount;

    TreeNode(string name) : name(name), childCount(0)
    {
        for (int i = 0; i < 10; i++)
            children[i] = nullptr;
    }
};
struct NodeQ
{
    string data;
    NodeQ *next;
    NodeQ(string data) : data(data), next(nullptr) {}
};

class MyQueue
{
public:
    NodeQ *front = nullptr;
    NodeQ *rear = nullptr;

    void push(const string &value)
    {
        NodeQ *newNode = new NodeQ(value);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string pop()
    {
        if (front == nullptr)
        {
            throw runtime_error("Queue is empty");
        }
        string value = front->data;
        NodeQ *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return value;
    }

    bool empty() const
    {
        return front == nullptr;
    }

    int size() const
    {
        int count = 0;
        NodeQ *current = front;
        while (current)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Structure to hold course details
struct Course
{
    string name;
    int capacity = 50;
    int enrolled = 0;
    MyQueue waitlist;
};

// Linked list for student records
struct StudentNode
{
    string courseName;
    StudentNode *next;

    StudentNode(string courseName) : courseName(courseName), next(nullptr) {}
};

struct StudentRecord
{
    string name;
    StudentNode *head;
};

struct NodeS
{
    pair<string, string> data;
    NodeS *next;
    NodeS(pair<string, string> data) : data(data), next(nullptr) {}
};

// Stack class
class MyStack
{
public:
    NodeS *top = nullptr;

    void push(const pair<string, string> &action)
    {
        NodeS *newNode = new NodeS(action);
        newNode->next = top;
        top = newNode;
    }

    pair<string, string> pop()
    {
        if (top == nullptr)
        {
            throw runtime_error("Stack is empty");
        }
        pair<string, string> value = top->data;
        NodeS *temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool empty() const
    {
        return top == nullptr;
    }
};
// ActionHistory structure
struct ActionHistory
{
    string name;
    MyStack actions; // Stack for storing action history
};

// Class to manage the University Course Registration System
class UniversityCourseRegistration
{
private:
    TreeNode *root;
    Course courses[100];          // Array for storing courses
    StudentRecord students[100];  // Array for student records
    ActionHistory histories[100]; // Array for action histories
    int studentCount;
    int courseCount;
    int historyCount;

    int findStudent(string name)
    {
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].name == name)
                return i;
        }
        return -1;
    }

    int findActionHistory(string name)
    {
        for (int i = 0; i < historyCount; i++)
        {
            if (histories[i].name == name)
                return i;
        }
        return -1;
    }

    void addActionHistory(string studentName, pair<string, string> action)
    {
        int index = findActionHistory(studentName);
        if (index == -1)
        {
            // Initialize a new history entry for the student
            histories[historyCount].name = studentName;
            index = historyCount++;
        }
        histories[index].actions.push(action); // Push the action to the student's action stack
    }

    void displayStudentRecords(string studentName)
    {
        int index = findStudent(studentName);
        if (index == -1)
        {
            cout << "Student not found!\n";
            return;
        }

        cout << "Student: " << studentName << "\nEnrolled Courses:\n";
        StudentNode *current = students[index].head;
        while (current)
        {
            cout << " - " << current->courseName << "\n";
            current = current->next;
        }
    }

public:
    UniversityCourseRegistration()
    {
        root = new TreeNode("University");
        courseCount = 0;
        studentCount = 0;
        historyCount = 0;
    }

    // Add department to the tree
    void addDepartment(string department)
    {
        if (root->childCount < 10)
        {
            root->children[root->childCount++] = new TreeNode(department);
        }
        else
        {
            cout << "Cannot add more departments!\n";
        }
    }

    // Add course to a department
    void addCourse(string department, string courseName)
    {
        for (int i = 0; i < root->childCount; i++)
        {
            if (root->children[i]->name == department)
            {
                TreeNode *dept = root->children[i];
                if (dept->childCount < 10)
                {
                    dept->children[dept->childCount++] = new TreeNode(courseName);
                    courses[courseCount++] = {courseName};
                }
                else
                {
                    cout << "Cannot add more courses to this department!\n";
                }
                return;
            }
        }
        cout << "Department not found!\n";
    }

    // Search for a course
    void searchCourse(string courseName)
    {
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i].name == courseName)
            {
                Course &course = courses[i];
                cout << "Course: " << courseName << "\nAvailable Seats: " << (course.capacity - course.enrolled)
                     << "\nWaitlist: " << course.waitlist.size() << "\n";
                return;
            }
        }
        cout << "Course not found!\n";
    }

    // Register a student for a course
    void registerCourse(string studentName, string courseName)
    {
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i].name == courseName)
            {
                Course &course = courses[i];
                if (course.enrolled < course.capacity)
                {
                    course.enrolled++;
                    addStudentRecord(studentName, courseName);
                    addActionHistory(studentName, {"register", courseName});
                    cout << "Student " << studentName << " enrolled in " << courseName << "\n";
                }
                else
                {
                    course.waitlist.push(studentName);
                    addActionHistory(studentName, {"waitlist", courseName});
                    cout << "Course full! Student " << studentName << " added to waitlist for " << courseName << "\n";
                }
                return;
            }
        }
        cout << "Course not found!\n";
    }

    // Drop a course for a student
    void dropCourse(string studentName, string courseName)
    {
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i].name == courseName)
            {
                Course &course = courses[i];
                if (removeStudentRecord(studentName, courseName))
                {
                    course.enrolled--;
                    if (!course.waitlist.empty())
                    {
                        string nextStudent = course.waitlist.pop();
                        registerCourse(nextStudent, courseName);
                    }
                    addActionHistory(studentName, {"drop", courseName});
                    cout << "Student " << studentName << " dropped from " << courseName << "\n";
                }
                else
                {
                    cout << "Student not enrolled in this course!\n";
                }
                return;
            }
        }
        cout << "Course not found!\n";
    }

    // Undo last action for a student
    void undo(string studentName)
    {
        int index = findActionHistory(studentName);
        if (index == -1 || histories[index].actions.empty())
        {
            cout << "No actions to undo!\n";
            return;
        }

        auto lastAction = histories[index].actions.pop();
        string action = lastAction.first;
        string courseName = lastAction.second;

        if (action == "register")
        {
            dropCourse(studentName, courseName);
        }
        else if (action == "drop")
        {
            registerCourse(studentName, courseName);
        }
        else if (action == "waitlist")
        {
            // Undo waitlist addition
            for (int i = 0; i < courseCount; i++)
            {
                if (courses[i].name == courseName)
                {
                    Course &course = courses[i];
                    // Remove student from waitlist
                    string waitlistStudent = course.waitlist.pop();
                    cout << "Student " << waitlistStudent << " removed from waitlist for " << courseName << "\n";
                    return;
                }
            }
        }
    }

    // Add student record for course
    void addStudentRecord(string studentName, string courseName)
    {
        int index = findStudent(studentName);
        if (index == -1)
        {
            students[studentCount].name = studentName;
            students[studentCount].head = new StudentNode(courseName);
            studentCount++;
        }
        else
        {
            StudentNode *newNode = new StudentNode(courseName);
            newNode->next = students[index].head;
            students[index].head = newNode;
        }
    }

    // Remove student record from course
    bool removeStudentRecord(string studentName, string courseName)
    {
        int index = findStudent(studentName);
        if (index == -1)
        {
            return false;
        }
        StudentNode *current = students[index].head;
        StudentNode *prev = nullptr;
        while (current)
        {
            if (current->courseName == courseName)
            {
                if (prev)
                    prev->next = current->next;
                else
                    students[index].head = current->next;
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    void displayMenu()
    {
        char choice;
        do
        {
            cout << "\n=== University Course Registration System ===\n";
            cout << "1. Add Department\n";
            cout << "2. Add Course\n";
            cout << "3. Search Course\n";
            cout << "4. Register for Course\n";
            cout << "5. Drop Course\n";
            cout << "6. Undo Last Action\n";
            cout << "7. Display Student Records\n";
            cout << "z. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == '1')
            {
                string department;
                cout << "Enter department name: ";
                cin >> department;
                addDepartment(department);
            }
            else if (choice == '2')
            {
                string department, course;
                cout << "Enter department name: ";
                cin >> department;
                cout << "Enter course name: ";
                cin >> course;
                addCourse(department, course);
            }
            else if (choice == '3')
            {
                string course;
                cout << "Enter course name: ";
                cin >> course;
                searchCourse(course);
            }
            else if (choice == '4')
            {
                string student, course;
                cout << "Enter student name: ";
                cin >> student;
                cout << "Enter course name: ";
                cin >> course;
                registerCourse(student, course);
            }
            else if (choice == '5')
            {
                string student, course;
                cout << "Enter student name: ";
                cin >> student;
                cout << "Enter course name: ";
                cin >> course;
                dropCourse(student, course);
            }
            else if (choice == '6')
            {
                string student;
                cout << "Enter student name: ";
                cin >> student;
                undo(student);
            }
            else if (choice == '7')
            {
                string student;
                cout << "Enter student name: ";
                cin >> student;
                displayStudentRecords(student);
            }
            else if (choice != '8')
            {
                cout << "Invalid choice! Please try again.\n";
            }

            cin.ignore();
        } while (choice != '8');

        cout << "Thanks For using Goodbye!\n";
    }
};

// Main driver to display the menu
int main()
{
    UniversityCourseRegistration system;
    system.displayMenu();
    return 0;
}
