#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10;

struct slmhh{
    ll x1,y1,x2,y2;
}nums[15];
ll window[3000][1500];

void print(int idx){ //画画
    ll a = nums[idx].x1,b = nums[idx].y1;
    ll c = nums[idx].x2,d = nums[idx].y2;
    for(int i = a;i <= c;i++){
        for(int j = b;j <= d;j++){
            window[i][j] = idx;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,a,b,c,d;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a >> b >> c >> d;
        nums[i] = {a,b,c,d};
        print(i);
    }
    while(m--){
        cin >> a >> b;
        if(window[a][b] != 0){
            cout << window[a][b] << "\n";
            print(window[a][b]);
        }
        else cout << "IGNORED\n";
    }
    return 0; 
}