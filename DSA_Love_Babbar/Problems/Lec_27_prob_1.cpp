// MCQs

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Question : 1
    int first_1 = 8;
    int second_1 = 18;
    int* ptr_1 = &second_1;
    *ptr_1 = 9;
    cout << "Answer for Q1 : " << first_1 << " " << second_1 << endl;

    // Question : 2
    int first_2 = 6;
    int* p_2 = &first_2;
    int* q_2 = p_2;
    (*q_2) ++;
    cout << "Answer for Q2 : " << first_2 << endl;

    // Question : 3
    int first_3 = 8;
    int* p_3 = &first_3;
    cout << "Answer for Q3 : " << (*p_3)++ << " ";
    cout << first_3 << endl;

    // Question : 4
    // segmentation fault
    // int* p_4 = 0;
    // int first_4 = 110;
    // *p_4 = first_4;
    // cout << "Answer for Q4 : " << *p_4 << endl;

    // Question : 5
    int first_5 = 8;
    int second_5 = 11;
    int* third_5 = &second_5;
    first_5 = *third_5;
    *third_5 = *third_5 + 2;
    cout << "Answer for Q5 : " << first_5 << " " << second_5 << endl;

    // Question : 6
    float f_6 = 12.5;
    float p_6 = 21.5;
    float* ptr_6 = &f_6;
    (*ptr_6) ++;
    *ptr_6 = p_6;
    cout << "Answer for Q6 : " << *ptr_6 << " " << f_6 << " " << p_6 << endl;
    
    return 0;
}