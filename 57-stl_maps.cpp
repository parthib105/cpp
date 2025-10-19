// map is an associative array

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string, int> marksMap;
    marksMap["Parthib"] = 98;
    marksMap["Jack"] = 87;
    marksMap["Anu"] = 69;

    marksMap.insert({{"Kozume", 169}, {"Kuroo", 187}});
    map<string, int> :: iterator itr;

    for (itr = marksMap.begin(); itr != marksMap.end(); itr++)
    {
        cout << (*itr).first << " " << (*itr).second << endl;
    }
    
    return 0;
}