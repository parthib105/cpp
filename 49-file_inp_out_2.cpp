#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string name;
    ofstream pout("49-sample_w.txt"); // connecting our file with hout stream
    cout << "Enter your name: ";
    cin >> name;
    pout << "My name is " + name;
    pout.close();

    string content;
    ifstream pin("49-sample_w.txt");
    pin >> content;
    cout << "The content of this file is: " << content;
    pin.close();
    return 0;
}