// STL 
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //********** Vectors **********
    // #include<vector>

    vector<int> v;
    cout << "Capacity -> " << v.capacity() << endl;      // capacity => memory allocated, size => no. of elements stored

    v.push_back(1);
    cout << "push_back(1), Capacity -> " << v.capacity() << endl;
    
    v.push_back(2);
    cout << "push_back(2), Capacity -> " << v.capacity() << endl;

    v.push_back(3);
    cout << "push_back(3), Capacity -> " << v.capacity() << endl;
    cout << "push_back(3), Size -> " << v.size() << endl;

    cout << "Element at 1st index " << v.at(1) << endl;

    cout << "Front -> " << v.front() << endl;
    cout << "Back -> " << v.back() << endl;

    cout << "Before pop :" << endl;

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout <<  "After pop :" << endl;

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    // initilize with size
    vector<int> a(5, 1);       // means vector of size 5 with all elements as 1
    cout << "print a" << endl;
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    // copy vector 'a' to vector 'v'

    vector<int> A(a);
    cout << "print A" << endl;
    for (auto i : A)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}