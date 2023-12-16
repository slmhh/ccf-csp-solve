#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    cin >> n;
    n /= 10;
    cout << n + n / 5 * 2 + (n - n / 5 * 5) / 3 << "\n";
    return 0;
}