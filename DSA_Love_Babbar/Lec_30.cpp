#include<bits/stdc++.h>
using namespace std;

#define PI 3.14     // <-- macros

int score = 15;

void a(int& i) 
{

    cout << score << " in a" << endl;
    score++;
    char ch = 'a';
    cout << i << endl;
}

void b(int& i) 
{
    cout << score << " in b" << endl;
    cout << i << endl;
}

inline int getMax(int& a, int& b) 
{
    return (a>b) ? a : b;
}

// default argument
void print(int arr[], int end, int start = 0)
{
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
}

int main() 
{
    /******************** macros *******************/
    
    // int r = 5;
    // //double pi = 3.14;

    // double area = PI * r * r;

    // cout << "Area is " << area << endl;

    /***********************************************/


    /******************** Global variable *******************/

    // cout << score << " in main" << endl;
    // int i = 5;
    // a(i);
    // b(i);

    /********************************************************/


    /******************** Inline Function *******************/

    // int a = 1, b = 2;
    // int ans = 0; 

    // ans = getMax(a,b);
    // cout << ans << endl;

    // a = a + 3;
    // b = b + 1;

    // ans = getMax(a,b);
    // cout << ans << endl;

    /********************************************************/


    /******************** Default argument *******************/
    
    int arr[5] = {1, 4, 7, 8, 9};
    int size = 5;
    print(arr, 3);
    
    /*********************************************************/
    return 0;
}