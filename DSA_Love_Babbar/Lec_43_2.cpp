// Inheritance

#include<bits/stdc++.h>
using namespace std;

class Animal
{
public:
    int age;
    int weight;

    Animal(int a, int w)
    {
        this->age = a;
        this->weight = w;
    }

    void speak(string str)
    {
        cout << "speaking : " << str << endl;
    }

    void printAnimalFeatures()
    {
        cout << "Age : " << this->age << " years" << endl;
        cout << "Weight : " << this->weight << " kg" << endl;
    }
};

class Dog : public Animal
{
public:

    string words;

    Dog(int ag, int wg, string w) : Animal(ag, wg)
    {
        this->words = w;
    }

    void printDogFeatures()
    {
        this->printAnimalFeatures();
        cout << "Dog speaks : " << this->words << endl;
    }

};

class GermanShepherd : public Dog
{
public:
    string aka;

    GermanShepherd(int ag, int wg, string w, string aka) : Dog(ag, wg, w)
    {
        this->aka = aka;
    }

    void printGSFeatures()
    {
        this->printDogFeatures();
        cout << "This is German Sheperd species, also known as : " << aka << endl;
    }
};

class B
{
public:
    int a;
    int b;

    B(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    int add()
    {
        return this->a + this->b;
    }

    void operator+(B &obj)
    {
        cout << "Output : " << this->a - obj.a << endl;
    }

    void operator() ()
    {
        cout << "Main bracket hoon : " << this->a << endl;
    }
};
int main()
{
    /******************** Inheritance ********************/
    
    // Dog d(7, 60, "Bhaw");
    // d.speak(d.words);
    // d.printDogFeatures();

    // GermanShepherd gs(8, 70, "Bhawwww", "Alsatian");
    // gs.speak(gs.words);
    // gs.printGSFeatures();

    /*****************************************************/



    /******************** Operator Overloading (Runtime polymorphism) ********************/

    B obj1(3, 6), obj2(1, 5);

    cout << "Adding a and b of obj1 : " << obj1.add() <<  endl;
    cout << "Adding a and b of obj2 : " << obj2.add() <<  endl;

    obj1 + obj2;
    obj1();
    obj2();

    /*************************************************************************************/
    return 0;
}