#include<iostream>
using namespace std;

class shop
{
private:
    int itemId[100];
    int itemPrice[100];
    unsigned int counter;

public:
    void initCounter(void) 
    {
        counter = 0;
    }

    void setPrice(void)
    {
        cout << "Enter Id of your item no " << counter + 1 << " ";
        cin >> itemId[counter];
        cout << "Enter price of your item ";
        cin >> itemPrice[counter];
        counter ++; 
    }

    void displayPrice(void)
    {
        for (int i=0; i<counter; ++i)
        {
            cout << "The price of item " << itemId[i] << " is " << itemPrice[i] << endl;
        }
    }

    void totalPrice(void)
    {
        int sum = 0;
        for (int i = 0; i < counter; ++i)
        {
            sum += itemPrice[i];
        }
        cout << "Total price of your items is " << sum << endl;
    }
};

int main()
{
    int items;
    shop dukan;
    cout << "How many items do you want to buy? ";
    cin >> items;
    dukan.initCounter();
    for (int j=0; j<items; ++j)
    {
        dukan.setPrice();
    }
    dukan.displayPrice();
    dukan.totalPrice();
    return 0;
}