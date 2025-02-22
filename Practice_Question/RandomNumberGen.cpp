#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;

int main()
{
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

    cout << endl;

    return 0;
}
