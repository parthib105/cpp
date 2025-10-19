// Array of Objects using pointers

#include<iostream>
using namespace std;

class Shop
{
private:
    int id;
    float price;

public:
    void setData(int a, float b)
    {
        id = a;
        price = b;
    }

    void getData(void)
    {
        cout << "Code of this item is " << id << endl;
        cout << "Price of this item is " << price << endl;
    }
};

int main()
{
    int size = 3;
    Shop *ptr = new Shop[size];

    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Id and price of item " << i+1 << ": ";
        cin >> p >> q;
        (ptr + i) -> setData(p, q);
    }
    
    for (int i = 0; i < size; i++)
    {
        (ptr + i) -> getData();
    }
    
    return 0;
}