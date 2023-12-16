#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,sum = 0,last = 0;
    while(true){
        cin >> n;
        if(n == 0) break;
        if(n == 1){
            last = 0;
            sum += 1;
        }
        else{
            last += 2;
            sum += last;
        }
    }
    cout << sum << "\n";
    return 0;
}