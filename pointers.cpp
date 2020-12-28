#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    int *ptr{&x};

    cout << ptr << " \n";
    cout << *ptr << endl;

    ptr++;

    cout << ptr << endl;

    cout << endl;
    int scores[]{100, 95, 85, 75, -1};
    int *score_ptr{scores};

    while (*score_ptr != -1)
    {
        cout << *score_ptr << endl;
        score_ptr++;
    }

    cout << "\n-----------------------------------" << endl;
    score_ptr = scores;
    while (*score_ptr != -1)
    {
        cout << *score_ptr++ << endl;
    }

    cout << "\n-----------------------------------" << endl;
    char name[]{"Frank"};
    char *char1{&name[0]}; //pointinfg to F
    char *char2{&name[3]}; //pointing to n

    cout << "In the string " << name << ", " << *char2 << " is " << (char2 - char1) << " characters away from " << *char1 << endl;

    cout << "\n-----------------------------------" << endl;

    //pointer to constants

    int high_Score{100};
    int low_Score{65};

    const int *scoreptr{&high_Score};

    //*score_ptr = 86; //error //you cannot change the data pointed by pointer

    high_Score = 101;
    cout << *scoreptr;

    //or
    cout << endl;
    scoreptr = &low_Score;
    cout << *scoreptr;

    //constant pointers
    cout << "\n-----------------------------------" << endl;

    int h{100};
    int l{60};
    int *const hl_ptr{&h};

    cout << *hl_ptr << endl;

    //hl_ptr = &l; //error

    *hl_ptr = 80; //ok
    cout << *hl_ptr << endl;

    //constant pointers to constants
    // the data pointed by pointer cannot be change
    // the pointer itself cannot change and point somewhere else
}