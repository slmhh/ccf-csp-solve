#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

struct what{
    ll x,y;
    char typ;
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,flaga = 0,flagb = 0,flag = 1;
    cin >> n >> m;
    vector<what> num(n + 10);
    what a,b;
    for(ll i = 0;i < n;i++){
        cin >> num[i].x >> num[i].y >> num[i].typ;
        if(num[i].typ == 'A' && flaga == 0) a = num[i],flaga = 1;
        if(num[i].typ == 'B' && flagb == 0) b = num[i],flagb = 1;
    }
    ll s0,s1,s2;
    for(ll i = 0;i < m;i++){
        flag = 1;
        cin >> s0 >> s1 >> s2;
        if(s0 + s1 * a.x + s2 * a.y > 0) flaga = 1;
        else flaga = 0;
        if(s0 + s1 * b.x + s2 * b.y > 0) flagb = 1;
        else flagb = 0;
        if(flaga == flagb){
            cout << "No\n"; 
            continue;
        }
        for(ll j = 0;j < n;j++){
            if(num[j].typ == 'A'){
                if((s0 + s1 * num[j].x + s2 * num[j].y > 0) ^ (flaga)){
                    flag = 0;
                    break;
                }
            }
            else{
                if((s0 + s1 * num[j].x + s2 * num[j].y > 0) ^ (flagb)){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}