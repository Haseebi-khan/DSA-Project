#include <iostream>
#include <cmath>

using namespace std;

void sort(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // Define the array of values
    double values[] = {

        3.79, 2.99, 2.77, 2.91, 3.10, 1.84, 2.52, 3.22,
        2.45, 2.14, 2.67, 2.52, 2.71, 2.75, 3.57, 3.85,
        3.36, 2.05, 2.89, 2.83, 3.13, 2.44, 2.10, 3.71,
        3.14, 3.54, 2.37, 2.68, 3.51, 3.37

    };

    // Calculate the total number of elements in the array
    int totalElements = sizeof(values) / sizeof(values[0]);

    // Sorting arr
    sort(values,totalElements);

    // Calculate the mean
    double mean = 0.0;
    for (int i = 0; i < totalElements; i++)
    {
        mean += values[i];
    }
    mean /= totalElements;

    // Calculate the variance using Bessel's correction
    double variance = 0.0;

    for (int i = 0; i < totalElements; i++)
    {
        double difference = values[i] - mean;
        variance += difference * difference;
        cout << values[i] << "         " << variance << endl;
    }
    variance /= (totalElements - 1);

    // Calculate the standard deviation
    double stdDev = sqrt(variance);

    // Print the results
    cout << "Statistics:" << endl;
    cout << "---------" << endl;
    cout << "Mean: " << mean << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard Deviation: " << stdDev << endl;
    int median = totalElements / 2;
    cout << "Median: " << values[median] << endl;

    return 0;
}