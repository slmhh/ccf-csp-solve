#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

bool check(ll n){
    if(n % 7 == 0) return true;
    while(n > 0){
        if(n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll cnt[5] = {0},n,s = 1;
    cin >> n;
    for(int i = 0;s <= n;i++){
        if(check(i + 1))
            cnt[i % 4]++;
        else s++;
    }
    for(int i = 0;i < 4;i++){
        cout << cnt[i] << "\n";
    }
    return 0;
}