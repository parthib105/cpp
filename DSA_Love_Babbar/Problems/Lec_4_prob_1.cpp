#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    // ********** Question 1 **********

    /*
        print the following pattern

        *
        * *
        * * *
        * * * *
    */

    // int row = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << "* ";
    //         col ++;
    //     }
    //     cout << endl;
    //     row ++;
    // } 

    // ********** Question 2 **********

    /*
        print the following pattern

        1
        2 3
        4 5 6
        7 8 9 10
    */

    // int row = 1;
    // int count = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << count << " ";
    //         count++;
    //         col ++;
    //     }
    //     cout << endl;
    //     row ++;
    // }

    // ********** Question 3 **********

    /*
        print the following pattern

        1
        2 1
        3 2 1
        4 3 2 1
    */

    // int row = 1;
    // while (row <= n)
    // {
    //     int col = row;
    //     while (col >= 1)
    //     {
    //         cout << col << " ";
    //         col --;
    //     }
    //     cout << endl;
    //     row ++;
    // }

    // ********** Question 4 **********

    /*
        print the following pattern

        A A A
        B B B
        C C C
    */

    // int row = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= n)
    //     {
    //         char ch = 'A' + row - 1;
    //         cout << ch << " ";
    //         col ++;
    //     }
    //     cout << endl;
    //     row ++;
    // }

    // ********** Question 5 **********

    /*
        print the following pattern

        A 
        B B 
        C C C
    */

    // int row = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << (char)('A' + row - 1) << " ";
    //         col ++;
    //     }
    //     cout << endl;
    //     row ++;
    // }

    // ********** Question 6 **********

    /*
        print the following pattern

        A 
        B C 
        C D E
        D E F G
    */

    // int row = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << (char)('A' + row + col - 2) << " ";
    //         col ++;
    //     }
    //     cout << endl;
    //     row ++;
    // }

    // ********** Question 7 **********

    /*
        print the following pattern

        A 
        B C 
        D E F
        G H I J
    */

    // int row = 1;
    // char count = 'A';
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << count << " ";
    //         count ++;
    //         col ++;
    //     }
    //     cout << endl;
    //     row ++;
    // }

    // ********** Question 8 **********

    /*
        print the following pattern

             1
           1 2 1
         1 2 3 2 1
       1 2 3 4 3 2 1
    */

    // int row = 1;
    // while (row <= n)
    // {
    //     int space = 2 * (n - row);
    //     while (space > 0)
    //     {
    //         cout << " ";
    //         space --;
    //     }
        
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << col << " ";
    //         col ++;
    //     }

    //     int c = row - 1;
    //     while (c >= 1)
    //     {
    //         cout << c << " ";
    //         c --;
    //     }
    //     cout << endl;
    //     row ++;
    // }

    // ********** Question 9 **********

    /*
        print the following pattern

        1 2 3 4 5 5 4 3 2 1
        1 2 3 4 * * 4 3 2 1
        1 2 3 * * * * 3 2 1
        1 2 * * * * * * 2 1
        1 * * * * * * * * 1
    */

    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= 2 * n)  // first triangle
        {
            if (col <= n - row + 1)
            {
                cout << col << " ";
            }
            if (col > n - row + 1 && col <= n + row - 1)
            {
                cout << '*' << " "; 
            }
            if (col > n + row - 1)
            {
                cout << 2 * n - col + 1 << " ";
            }
            col ++;
        }
        cout << endl;
        row++;
    }
    return 0;
}