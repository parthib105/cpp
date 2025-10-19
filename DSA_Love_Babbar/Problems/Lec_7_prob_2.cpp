// Complement of a base 10 integer

/*  Using 32 bit representation

    Idea : 5               -> 0 0 0 ... 0 0 1 0 1
          ~5               -> 1 1 1 ... 1 1 0 1 0
           mask            -> 0 0 0 ... 0 0 1 1 1
           (~5) & mask = 2 -> 0 0 0 ... 0 0 0 1 0 (answer)  
*/

#include <iostream>
using namespace std;

int no_bits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count ++;
        n = n >> 1;
    }
    return count;
}

int bitwiseComplement(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int k = no_bits(n);
    int mask = (1 << k) - 1;

    return ((~n) & mask);
}

int bitwiseComplement_lb(int n)
{
    // edge case
    if (n == 0)
    {
        return 1;
    }

    int m = n;
    int mask = 0;

    while (m != 0)
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }

    return ((~n) & mask);
}

int main()
{
    cout << bitwiseComplement_lb(10) << endl;
    return 0;
}