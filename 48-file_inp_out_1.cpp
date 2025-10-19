/*
USEFUL CLASSES FOR WORKING WITH FILES IN C++
 1. fstreambase
 2. ifstream --> derived from fstreambase
 3. ofstream --> derived from fstreambase

In order to work with files in C++, you will have to open it.
Primarily, there are 2 ways to open a file

1. Using the constructor
2. Usinf the member function open() of the class
*/

#include<iostream>
#include<fstream>
using namespace std;



int main()
{
    string st1 = "Indian Institute of Technology Hyderabad";
    string st2;

    // opening files using constructor and reading it
    
    ifstream in("48-sample_r.txt");
    // in >> st2;
    getline(in, st2);
    cout << st2 << endl;
    getline(in, st2);
    cout << st2;

    // opening files using constructor and writing it
    
    ofstream out("48-sample_w.txt");
    out << st1;
    return 0;
}