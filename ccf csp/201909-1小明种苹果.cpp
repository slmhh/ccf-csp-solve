#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,T = 0,k = 0,p = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int sum,t,cnt = 0;
        cin >> sum; 
        for(int j = 0;j < m;j++){
            cin >> t;
            cnt += t;
        }
        if(-cnt > p){
            p = -cnt;
            k = i + 1;
        }
        T += sum + cnt;
    }
    cout << T << " " <<  k << " " << p << "\n";
    return 0;
}