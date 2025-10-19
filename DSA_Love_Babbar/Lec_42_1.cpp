/*
    Object Oriented Programming (OOP)
*/
#include<bits/stdc++.h>
using namespace std;

/*For empty class, size = 1*/

/******************** Basics ********************/

// class Hero
// {
// public:
//     // properties
//     int health;
//     char level;

// };

/************************************************/

class Hero
{
private : 
    int health;
    char level;

public : 
    // setter function (to set values of private members)
    void setVals(int h, char l)
    {
        health = h;
        level = l;
    }

    //getter function (to get the values of private members)
    int gethealth()
    {
        return health;
    }

    char getlevel()
    {
        return level;
    }
};

int main()
{
    /******************** Basics ********************/
    // Hero h1;

    // // what is the size of class
    // cout << "Size of object h1 : " << sizeof(h1) << endl;

    // // accessing properties
    // h1.health = 70;
    // h1.level = 'A';

    // cout << "Health : " << h1.health << endl << "Level : " << h1.level << endl;
    /************************************************/



    /******************** How to access private members ********************/
    // Hero h1;

    // // set the values
    // h1.setVals(60, 'B');

    // // get the values
    // cout << "Health of Hero h1 : " << h1.gethealth() << endl;
    // cout << "Level of Hero h1 : " << h1.getlevel() << endl;
    /***********************************************************************/



    /******************** Static vs Dynamic ********************/  

    // static
    Hero h1;
    h1.setVals(60, 'C');

    cout << "Statically allocated : " << endl;
    cout << "Health : " << h1.gethealth() << "\nLevel : " << h1.getlevel() << endl << endl;

    // Dynamic
    Hero* h2 = new Hero;

    (*h2).setVals(65, 'B');
    cout << "Dynamically allocated (access using dereference operator (*)) : " << endl;
    cout << "Health : " << (*h2).gethealth() << "\nLevel : " << (*h2).getlevel() << endl << endl;

    h2->setVals(70, 'A');
    cout << "Dynamically allocated (access using ->) : " << endl;
    cout << "Health : " << h2->gethealth() << "\nLevel : " << h2->getlevel() << endl << endl;
    /***********************************************************/  

    return 0;
}