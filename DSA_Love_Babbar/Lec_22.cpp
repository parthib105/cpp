// Character Arrays & Strings

/*
    char array : {'a', 'b', 'c'}
    string : "abc"  => 1-Dimentional character arrays
*/
#include<iostream>
using namespace std;

// calculating the length of the string
int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count ++;
    }
    return count;
}

// Reverse a string
void reverse(char name[])
{
    int n = getLength(name);
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        char temp = name[i];
        name[i] = name[j];
        name[j] = temp;
        i ++;
        j --;
    }
}

int main()
{
    char name[20];

    // cout << "Enter your name : ";
    // cin >> name;

    // cout << endl << "Your name is : " << name << endl;

    // cout << endl << "Length : " << getLength(name) << endl;

    // reverse(name);
    // cout << endl << "Reverse : " << name << endl;
    char c = 'Z';
    cout << c - 'A';
    return 0;
}