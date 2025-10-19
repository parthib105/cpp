#include<iostream>
#include<list>
using namespace std;

template <class T>
void display(list<T> &lst)
{
    list<int> :: iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> list1; // list of 0 length
    // list<int> list2(7); // empty list of size 7

    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);
    list1.push_back(12);
    display(list1);

    // removing elements from the list1

    list1.pop_front();
    list1.pop_back();
    list1.remove(12);
    display(list1);

    return 0;
}