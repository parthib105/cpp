#include<iostream>
#include<string>
using namespace std;

class binary
{
    private:
        string s;
        void chk_bin(void)
        {
            for(int i=0; i<s.length(); ++i)
            {
                if (s.at(i) != '0' && s.at(i) != '1')
                {
                    cout << "Invalid binary number" << endl;
                    exit(0);
                }
            }
        }

    public :
        void read(void)
        {
            cout << "Enter a binary number: ";
            cin >> s;
        }

        void ones_comp(void)
        {
            for(int i=0; i<s.length(); ++i)
            {
                if (s.at(i) == '0')
                {
                    s.at(i) = '1';
                }
                else
                {
                    s.at(i) = '0';
                }
            } 
        }

        void display(void)
        {
            cout << "Displaying your binary number: " << s << endl;
        }
};

int main()
{
    binary b;
    b.read();
    b.chk_bin();
    b.display();
    b.ones_comp();
    b.display();
    return 0;
}