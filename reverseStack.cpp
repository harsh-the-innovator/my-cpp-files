#include <bits/stdc++.h>
using namespace std;

stack<char> st;
string str;

char insert_at_bottom(char x)
{

    if (st.size() == 0)
        st.push(x);

    else
    {

        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom

        char a = st.top();
        st.pop();
        insert_at_bottom(x);

        // push allthe items held in
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}

// Below is the function that
// reverses the given stack using
// insert_at_bottom()
char reverse()
{
    if (st.size() > 0)
    {

        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        char x = st.top();
        st.pop();
        reverse();

        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert_at_bottom(x);
    }
}
int main()
{
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');

    cout << "Original Stack" << endl;

    // print the elements
    // of original stack
    cout << "1"
         << " "
         << "2"
         << " "
         << "3"
         << " "
         << "4"
         << endl;

    // function to reverse
    // the stack
    reverse();
    cout << "Reversed Stack"
         << endl;

    // storing values of reversed
    // stack into a string for display
    while (!st.empty())
    {
        char p = st.top();
        st.pop();
        str += p;
    }

    //display of reversed stack
    cout << str[3] << " " << str[2] << " "
         << str[1] << " " << str[0] << endl;
    return 0;
}