#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Creating 2-d array dynamically
    int m, n;
    cout << "Enter rows and columns of arr : ";
    cin >> m >> n;

    int** arr_2d = new int*[m];
    for (int i = 0; i < m; i++)
    {
        arr_2d[i] = new int[n];
    }

    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr_2d[i][j];
        }
    }

    cout << "Printing array : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr_2d[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < m; i++)
    {
        delete[] arr_2d[i];
    }

    delete[] arr_2d;

    cout << " > Done freeing memory\n";
    
    return 0;
}