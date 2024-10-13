#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

ll a1[N],a2[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,k,t = 0,temp,last,ans,cnt = 0;
    cin >> n >> k;
    queue<ll> a,b;
    for(int i = 1;i <= n;i++){
        a.push(i);
    }
    while(a.size() > 1){
        last = a.size();
        while(a.size() != 0){
            cnt++;
            temp = a.front();
            a.pop();
            if(cnt % k == 0 || cnt % 10 == k){
                ans = temp;
                continue;
            }
            else b.push(temp);
        }
        while(!b.empty()){
            a.push(b.front());
            b.pop();
        }
    }
    if(a.size() == 1) cout << a.front();
    else cout << ans << "\n";
    return 0; 
}