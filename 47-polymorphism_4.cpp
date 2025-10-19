// Abstract Base Class and Pure Virtual Class

// Abstruct base class is created to create other inherited classes
// and is should contain one pure virtual class

#include<iostream>
#include<cstring>
using namespace std;

class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string s, float r)
    {
        title = s;
        rating = r;
    }

    virtual void display()=0 ;  // do-nothing function --> pure virtual function
};

class CWHVideo: public CWH
{
private:
    float videolength;

public:
    CWHVideo(string s, float r, float vl) : CWH(s, r)
    {
        videolength = vl;
    }

    void display()
    {
        cout << "This is an amazing video with title " << title << endl;
        cout << "Ratings: " << rating << " out of 5 stars " << endl;
        cout << "Length of this video is: " << videolength << " minutes" << endl;
    }
};

class CWHText: public CWH
{
private:
    int words;

public:
    CWHText(string s, float r, int wc) : CWH(s, r)
    {
        words = wc;
    }

    void display()
    {
        cout << "This is an amazing text tutorial with title " << title << endl;
        cout << "Ratings of this text tutorial: " << rating << " out of 5 stars " << endl;
        cout << "No of words in this text tutorial is: " << words << " words" << endl;
    }
};

int main()
{
    string title;
    float rating, vlen;
    int words;

    // for code with harry video
    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    CWHVideo djvideo(title, rating, vlen);
    // djvideo.display();

    // for code with harry text
    title = "Django tutorial text";
    words = 456;
    rating = 4.19;
    CWHText djtext(title, rating, words);
    // djtext.display();

    CWH *tut[2];
    tut[0] = &djvideo;
    tut[1] = &djtext;

    tut[0] -> display();
    tut[1] -> display();

    return 0;
}