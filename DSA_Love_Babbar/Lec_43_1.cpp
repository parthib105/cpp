#include <bits/stdc++.h>
using namespace std;

// Encapsulation : Wrapping up data members and functions
class Student
{
private:
    string name;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
};

// Inheritance
class Human
{
public:
    int height;
    int weight;
    int age;

    void setData(int height, int weight, int age)
    {
        this->height = height;
        this->weight = weight;
        this->age = age;
    }

    vector<int> getData()
    {
        vector<int> ans = {this->height, this->weight, this->age};
        return ans;
    }
};

// inherited class
class Male : public Human
{
public:
    string color;

    void setMaleData(string color)
    {
        this->color = color;
    }

    void getMaleData()
    {
        cout << "Color -> " << this->color << endl;
    }

    void sleeping()
    {
        cout << "Male is sleeping" << endl;
    }
};

int main()
{
    /******************** Inheritance ********************/

    Male obj1;      // obj1 contains all properties of Human which can be accessed publically
    obj1.setData(150, 45, 15);

    cout << "Direct access : " << endl;
    cout << "Height : " << obj1.height << endl;
    cout << "Weight : " << obj1.weight << endl;
    cout << "Age : " << obj1.age << endl;

    vector<int> data = obj1.getData();

    cout << endl << "Access using getData function : " << endl;
    cout << "Height : " << data[0] << endl;
    cout << "Weight : " << data[1] << endl;
    cout << "Age : " << data[2] << endl << endl;

    obj1.setMaleData("Brown");

    cout << "Getting male data : " << endl;
    obj1.getMaleData();

    obj1.sleeping();
    /*****************************************************/
    return 0;
}