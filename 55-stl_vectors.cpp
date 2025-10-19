// For more reference, visit 
// cplusplus.com/reference/vector/vector/

#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    // ways to create vector
    vector<int> vec1; // zero length vector
    vector<char> vec2(4); // 4-element character vector
    vector<char> vec3(vec2); // 4-element character vector from vec2
    vector<int> vec4(6, 3); // 6-element vector with 3s

    int elm, size;
    cout << "Enter the size of vector: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element to add to this vector ";
        cin >> elm;
        vec1.push_back(elm);
    }
    display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter /*+ 1*/, 54);
    display(vec1);

    return 0;
}