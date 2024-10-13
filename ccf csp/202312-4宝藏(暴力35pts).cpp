#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int mod = 998244353;

struct matrix{
    vector<vector<ll>> a;
    matrix(){
        a.push_back({1,0});
        a.push_back({0,1});
    }
};

matrix operator+(matrix a,matrix b){
    matrix c;
    c.a[0][0] = ((a.a[0][0] * b.a[0][0]) % mod + (a.a[0][1] * b.a[1][0]) % mod) % mod;
    c.a[0][1] = ((a.a[0][0] * b.a[0][1]) % mod + (a.a[0][1] * b.a[1][1]) % mod) % mod;
    c.a[1][0] = ((a.a[1][0] * b.a[0][0]) % mod + (a.a[1][1] * b.a[1][0]) % mod) % mod;
    c.a[1][1] = ((a.a[1][0] * b.a[0][1]) % mod + (a.a[1][1] * b.a[1][1]) % mod) % mod;
    return c;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<array<ll,5>> op(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> op[i][0];
        if(op[i][0] != 3){
            cin >> op[i][1] >> op[i][2] >> op[i][3] >> op[i][4];
        }
    }
    for(int i = 1;i <= m;i++){
        ll v;
        cin >> v;
        if(v == 1){
            ll x;
            cin >> x;
            cin >> op[x][0];
            if(op[x][0] != 3){
                cin >> op[x][1] >> op[x][2] >> op[x][3] >> op[x][4];
            }
        }
        else{
            ll l,r;
            cin >> l >> r;
            deque<matrix> q;
            stack<ll> s;
            for(int j = l;j <= r;j++){
                if(op[j][0] == 1){
                    s.push(1);
                    matrix temp;
                    temp.a[0][0] = op[j][1],temp.a[0][1] = op[j][2];
                    temp.a[1][0] = op[j][3],temp.a[1][1] = op[j][4];
                    q.push_front(temp);
                }
                else if(op[j][0] == 2){
                    s.push(2);
                    matrix temp;
                    temp.a[0][0] = op[j][1],temp.a[0][1] = op[j][2];
                    temp.a[1][0] = op[j][3],temp.a[1][1] = op[j][4];
                    q.push_back(temp);
                }
                else{
                    if(!s.empty()){
                        ll idx = s.top();
                        s.pop();
                        if(idx == 1) q.pop_front();
                        else q.pop_back();
                    }
                }
            }
            matrix ans;
            while(!q.empty()){
                matrix temp = q.front();
                q.pop_front();
                ans = ans + temp;
            }
            cout << ans.a[0][0] << " " << ans.a[0][1] << " " << ans.a[1][0] << " " << ans.a[1][1] << "\n";
        }
    }
    return 0;
}   

// 01 2 74 93 66 52
// 02 1 75 47 74 79
// 03 2 28 38 47 23
// 04 1 33 50 86 64
// 05 2 29 82 70 18
// 06 2 9 6 73 86
// 07 2 73 29 58 33
// 08 2 61 39 72 4
// 09 3
// 10 2 96 71 87 5
// 11 1 95 96 8 58
// 12 1 19 65 11 66
// 13 1 34 38 63 66
// 14 2 90 12 18 76
// 15 1 67 19 7 20
// 16 3
// 17 1 76 62 30 8