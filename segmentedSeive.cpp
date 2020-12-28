#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

vector<int> *seive()
{
    bool isPrime[MAX];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i < MAX; i++)
    {

        if (isPrime[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> *primes = new vector<int>();
    primes->push_back(2);

    // rest primes are odd
    for (int i = 3; i < MAX; i += 2)
    {
        if (isPrime[i])
        {
            primes->push_back(i);
        }
    }

    return primes;
}

void segmentedSeive(long long l, long long r, vector<int> *&primes)
{
    bool isPrime[r - l + 1];

    memset(isPrime, true, sizeof(isPrime));

    for (int i = 0; primes->at(i) * (long long)primes->at(i) <= r; i++)
    {
        int currPrime = primes->at(i);

        // lust smaller or equal to l
        long long base = (l / (currPrime)) * currPrime;
        if (base < l)
        {
            base = base + currPrime;
        }

        // mark all multiples within l to r as false
        for (long long j = base; j <= r; j += currPrime)
        {
            isPrime[j - l] = false;
        }
        // there may be a case where base itsef is prime number
        if (base == currPrime)
        {
            isPrime[base - l] = true;
        }
    }

    for (int i = 0; i <= r - l; i++)
    {
        if (isPrime[i] == true)
        {
            cout << i + l << " ";
        }
    }
}

int main()
{
    vector<int> *primes = seive();
    long long l, r;
    cin >> l >> r;
    segmentedSeive(l, r, primes);
}