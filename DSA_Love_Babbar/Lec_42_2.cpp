#include<bits/stdc++.h>
using namespace std;

class Hero
{
private : 
    int health;
    char level;

public : 
    char* name;
    static int timeToComplte;

    // default constructor 
    Hero()
    {
        name = new char[100];
        cout << "Default constructor called " << endl;
    }

    // parameterized constructor
    Hero(int health, char level)
    {
        cout << "Parameterized constructor called" << endl;
        this->health = health;
        this->level = level;
    }

    // copy constructor
    Hero(Hero& another)
    {
        cout << "Copy constructor called" << endl;
        char* ch = new char[strlen(another.name) + 1];
        strcpy(ch, another.name);
        this->name = ch;
        this->health = another.health;
        this->level = another.level;
    }

    // setter function (to set values of private members)
    void setVals(int h, char l, char* n)
    {
        health = h;
        level = l;
        this->name = n;
    }

    //getter function (to get the values of private members)
    pair<int, char> getVals()
    {
        return make_pair(health, level);
    }

    // Print data
    void printVals()
    {
        cout << "[ name : " << this->name;
        cout << ", health : " << this->health;
        cout << ", level : " << this->level << " ]";
        cout << endl << endl;
    }

    // static member function
    static void time()
    {
        cout << "Time taken to complete : " << timeToComplte << endl;
    }

    // destructor
    ~Hero()
    {
        cout << "Destructor is called " << endl;
    }
};

int Hero :: timeToComplte = 5;      // :: -> scope resolution operator

int main()
{
    /******************* Constructors ********************/

    // Hero parthib(90, 'A');
    // cout << "Address of parthib : " << &parthib << endl;
    // pair<int, char> params = parthib.getVals();
    // cout << "Health : " << params.first << endl << "Level : " << params.second << endl; 

    /*****************************************************/



    /******************* Copy Constructors ********************/

    // Hero h1(70, 'B');
    // pair<int, char> p1 = h1.getVals();
    // cout << "Health h1 : " << p1.first << endl;
    // cout << "Level h1 : " << p1.second << endl;

    // Hero h2(h1);
    // pair<int, char> p2 = h2.getVals();
    // cout << "Health h2 : " << p2.first << endl;
    // cout << "Level h2 : " << p2.second << endl;

    /**********************************************************/



    /******************* Shallow and Deep Copy ********************/

    // Hero hero1;
    // char name[8] = {'p', 'a', 'r', 't', 'h', 'i', 'b', '\0'};
    // hero1.setVals(16, 'C', name);
    // cout << "hero1 : " << endl;
    // hero1.printVals();

    // Hero hero2(hero1);
    // cout << "hero2 : " << endl;
    // hero2.printVals();

    // hero1.name[0] = 'g';

    // cout << "hero1 : " << endl;
    // hero1.printVals();

    // cout << "hero2 : " << endl;
    // hero2.printVals();

    /**************************************************************/



    /******************* Destructors (for de-allocating memory) ********************/

    // // statucally allocated
    // Hero h1;

    // // dynamically alocated
    // Hero* h2 = new Hero();

    // // manually destructor called for dynamically allocated object
    // delete h2;

    /*******************************************************************************/



    /******************* Static variables and functions ********************/
    
    // static variables
    cout << "Time to complete belongs class not object -> " << Hero::timeToComplte << endl;

    Hero a;
    cout << "For hero a : " << a.timeToComplte << endl;

    Hero b;
    b.timeToComplte = 20;

    cout << "For hero a : " << a.timeToComplte << endl;
    cout << "For hero b : " << b.timeToComplte << endl;

    // static functions 
    // -> Object creation is not required, -> do not have this keyword, -> can access only static members

    Hero::time();

    /***********************************************************************/
    return 0;
}