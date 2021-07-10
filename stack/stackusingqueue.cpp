//implement stack using queue
#include <bits/stdc++.h>
using namespace std;
queue<int> q1;
queue<int> q2;

void pop()
{
    cout << q1.front() << " ";
    q1.pop();
}

void push(int el)
{
    while (q1.empty() == false)
    {
        int curr = q1.front();
        q1.pop();
        q2.push(curr);
    }

    q1.push(el);

    while (q2.empty() == false)
    {
        int curr = q2.front();
        q2.pop();
        q1.push(curr);
    }
}

int main()
{
    push(1);
    push(3);
    push(5);
    pop();
    pop();
    push(2);
    pop();
}