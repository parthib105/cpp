#include <bits/stdc++.h>
using namespace std;

__global__ void kernel(int* inp)
{
    inp[0] = inp[0] * 100;
}

int main()
{
    int val = 2;
    printf("%d,", val);
    kernel<<<1 ,1>>>(&val);
    printf("%d\n", val);
    return 0;
}