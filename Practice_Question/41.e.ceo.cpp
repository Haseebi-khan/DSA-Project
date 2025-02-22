// An organization is structured as a hierarchy with the CEO at the top. Each employee may have several subordinates, but each subordinate reports to only one manager.
// Scenario: You need to design a system that allows you to perform the following operations:
//     • Add an employee under a specific manager.
//     • Display all employees under a specific manager.
//     • Find the total number of employees in the organization.

#include <iostream>
using namespace std;
class Employee
{
public:
    int id;
    string name;
    Employee *manager;
    Employee *firstSubordinate;
    Employee *nextSubordinate;

    Employee(int id, string name) : id(id), name(name), manager(nullptr), firstSubordinate(nullptr), nextSubordinate(nullptr) {}

    void addSubordinate(Employee *subordinate)
    {
        if (firstSubordinate == nullptr)
        {
            firstSubordinate = subordinate;
        }
        else
        {
            Employee *current = firstSubordinate;
            while (current->nextSubordinate != nullptr)
            {
                current = current->nextSubordinate;
            }
            current->nextSubordinate = subordinate;
        }
        subordinate->manager = this;
    }

    void printSubordinates()
    {
        cout << "Subordinates of " << name << ":" << endl;
        Employee *current = firstSubordinate;
        while (current != nullptr)
        {
            cout << "  - " << current->name << endl;
            current = current->nextSubordinate;
        }
    }

    int countEmployees()
    {
        int count = 1;
        Employee *current = firstSubordinate;
        while (current != nullptr)
        {
            count += current->countEmployees();
            current = current->nextSubordinate;
        }
        return count;
    }
};

int main()
{
    Employee *ceo = new Employee(1, "CEO");
    Employee *manager1 = new Employee(2, "Manager 1");
    Employee *manager2 = new Employee(3, "Manager 2");
    Employee *employee1 = new Employee(4, "Employee 1");
    Employee *employee2 = new Employee(5, "Employee 2");
    Employee *employee3 = new Employee(6, "Employee 3");
    Employee *employee4 = new Employee(7, "Employee 4");

    ceo->addSubordinate(manager1);
    ceo->addSubordinate(manager2);
    manager1->addSubordinate(employee1);
    manager1->addSubordinate(employee2);
    manager2->addSubordinate(employee3);
    manager2->addSubordinate(employee4);

    manager1->printSubordinates();

    int totalEmployees = ceo->countEmployees();
    cout << "Total number of employees: " << totalEmployees << endl;

    return 0;
}