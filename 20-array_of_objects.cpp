#include<iostream>
using namespace std;

class complex
{
    int re;
    int im;

    public:
        void setData(void)
        {
            cout << "Enter the real part: ";
            cin >> re;
            cout << "Enter the imafinary part: ";
            cin >> im;
        }

        void setDataByProduct(complex o1, complex o2)
        {
            re = o1.re * o2.re - o1.im * o2.im;
            im = o1.re * o2.im + o1.im * o2.re;
        }

        void printData()
        {
            cout << "Required complex number: " << re << " + " << im << " i" << endl;
        }
};

int main()
{
    // **********Passing objects as Function arguments**********
    
    complex c1, c2, c3;
    c1.setData();
    c2.setData();

    c3.setDataByProduct(c1, c2);
    c3.printData();

    // **********Array of objects********
    
    // complex arr[4];
    // for (int i = 0; i < 4; i++)
    // {
    //     arr[i].setData();
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     arr[i].printData();
    // }
    
    return 0;
}