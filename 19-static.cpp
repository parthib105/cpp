#include<iostream>
using namespace std;

class Employee
{
    int id;
    static int count;

    public:
        void setData(void)
        {
            cout << "Enter the id: " << endl;
            cin >> id;
            count ++;
        }
        void getData(void)
        {
            cout << "The id of this employee is " << id << " and this is employee no. " << count << endl;
        }
        static void getCount(void)    // usinf static functions, we can only access static variables
        {
            // cout << id; // throws an error
            cout << "The value of count is " << count << endl;
        }
};

int Employee :: count;

int main()
{
    Employee parthib, anu, subho;
    parthib.setData();
    parthib.getData();
    parthib.getCount();

    anu.setData();
    anu.getData();
    anu.getCount();

    subho.setData();
    subho.getData();
    subho.getCount();
    return 0;
}