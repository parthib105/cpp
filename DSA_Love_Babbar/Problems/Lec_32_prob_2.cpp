/*
    Say digits

    You are given an integer number 'n' , you are asked to say its digits

    ex.: n = 412
        output : "four" "one" "two"
        separated by space
*/

#include<bits/stdc++.h>
using namespace std;

string* digits;

void sayDigits(int n)
{
    if (n == 0)
    {
        return;
    }
    sayDigits(n/10);
    cout << digits[n%10] << " ";
}

int main()
{
    digits = new string[10];
    digits[0] = "zero";
    digits[1] = "one";
    digits[2] = "two";
    digits[3] = "three";
    digits[4] = "four";
    digits[5] = "five";
    digits[6] = "six";
    digits[7] = "seven";
    digits[8] = "eight";
    digits[9] = "nine";

    int n;
    cout << "Enter the number : ";
    cin >> n;

    sayDigits(n);
    return 0;
}