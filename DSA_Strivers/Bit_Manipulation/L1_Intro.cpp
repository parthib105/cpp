/*
    Introduction to Bit Manipulation

    # Right shift : n >> k = (n / (2^k))
    # Left shift : n << k = n * (2^k)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// T.C. : O(log(n)), S.C. : O(log(n))
string convertToBinary(int n)
{
    string ans = "";
    while (n != 1)
    {
        ans += to_string(n % 2);
        n = n / 2;
    }
    ans += to_string(n);

    reverse(ans.begin(), ans.end());
    return ans;
}

int convertToDecimal(string bin)
{
    int num = 0;
    int p = 1;
    for (int i = bin.length() - 1; i >= 0; i--)
    {
        if (bin[i] == '1')
        {
            num = num + p;
        }
        p = p * 2;
    }
    return num;
}

int main()
{
    cout << convertToBinary(13) << endl;
    cout << convertToDecimal("1101") << endl;
    return 0;
}