// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

// For n-th person there are two choices:
// 1) n-th person remains single, we recur
// for f(n – 1)
// 2) n-th person pairs up with any of the
// remaining n – 1 persons. We get (n – 1) * f(n – 2)

// Therefore we can recursively write f(n) as:
// f(n) = f(n – 1) + (n – 1) * f(n – 2)
class Solution
{
public:
    int countFriendsPairings(int n)
    {
        int m = 1e9 + 7;
        int t[n + 1];
        t[0] = 1;    // we have set two states manually;
        t[1] = 1;       // because t[i] depends on 2 previous states

        for (long long int i = 2; i <= n; i++)
        {
            t[i] = ((t[i - 1]) + ((i - 1) * t[i - 2])) % m;
        }

        return (t[n] % m + m) % m;
    }
};