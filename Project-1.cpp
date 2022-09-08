// Project-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <map>
using namespace std;

int FiboR(int n) // array of size n
{
    if (n == 0 || n == 1)
        return (n);
    else return (FiboR(n - 1) + FiboR(n - 2));
}

int MODFiboR(int n) {
    static map<int, int> values;
    if (n == 0 || n == 1)
        return n;
    map<int, int>::iterator iter = values.find(n);

    if (iter == values.end())
        return values[n] = MODFiboR(n - 1) + MODFiboR(n - 2);
    
    else
        return iter->second;
}

int FiboNR(int n) // array of size n
{
    int F[60];
    F[0] = 0; F[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        F[n] = F[n - 1] + F[n - 2];
    }
    return (F[n]);
}

int main()
{
    clock_t startFR = clock();
    clock_t startFNR = clock();
    clock_t startMODFR = clock();
    int arr[60];

    cout << "Integer\t\tFiboR(seconds)\t\tMODFibR\t\tFiboNR(seconds)\t\tFibo-value\n";

    for (int i = 0; i < 60; i++) {
        arr[i] = i + 1;
    }
    
    for (int i = 0; i < 60; i++) {
        int fibValue = 0;
        cout << arr[i] << "\t\t";

        fibValue = FiboR(i);
        clock_t endFR = clock();
        cout << double(endFR - startFR) / CLOCKS_PER_SEC << "\t\t\t";

        MODFiboR(i);
        clock_t endMODFR = clock();
        cout << double(endMODFR - startMODFR) / CLOCKS_PER_SEC << "\t\t";

        FiboNR(i);       
        clock_t endFNR = clock();
        cout << double(endFNR - startFNR) / CLOCKS_PER_SEC << "\t\t\t";

        cout << fibValue << "\n";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
