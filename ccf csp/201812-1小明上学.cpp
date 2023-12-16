#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int r,y,g,n,sum = 0;
    cin >> r >> y >> g;
    cin >> n;
    while(n--){
        int k,t;
        cin >> k >> t;
        if(k == 0 || k == 1) sum += t;
        else if(k == 2) sum += t + r;
    }
    cout << sum << "\n";
    return 0;
}