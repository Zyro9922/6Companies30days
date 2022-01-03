/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define fi              first
#define se              second
#define ll              long long
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define min3(x,y,z)      (x < y ? (x < z ? x : z) : (y < z ? y : z))
#define mod             1000000007

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)  os << " ";
    }
    return os;
}
map<int, int> dp;
//Recursive
int CountWaysRecursive(string str, int len) {
    int idx = len - 1;
    if (dp.count(len)) {
        return dp[len];
    }
    if (len == 0) {
        return dp[len] = 1;
    }
    else if (len == 1) {
        if (str[idx] == '0')
            return dp[len] = 0;
        return CountWaysRecursive(str, len - 1);
    } else {
        int a = str[idx - 1] - '0';
        int b = str[idx] - '0';
        int number = a * 10 + b;
        int result = 0;

        if (b != 0) {
            result += CountWaysRecursive(str, len - 1) % mod;
        }
        if (number >= 10 && number <= 26) {
            result += CountWaysRecursive(str, len - 2) % mod;
        }
        return dp[len] = result % mod;
    }
}

int CountWays(string str) {
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    dp[n - 1] = str[n - 1] == '0' ? 0 : 1;
    for (int idx = n - 2; idx >= 0; idx--) {
        int a = str[idx] - '0';
        int b = str[idx + 1] - '0';
        int number = a * 10 + b;

        if (a != 0) {
            dp[idx] += dp[idx + 1] % mod;
        }

        if (number >= 10 && number <= 26) {
            dp[idx] += dp[idx + 2] % mod;
        }

        dp[idx] %= mod;
    }
    return dp[0];
}

int main()
{
    string str;
    cin >> str;
    cout << CountWays(str);
}