#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

ll day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isrun(ll y){
    if((y % 100 != 0 && y % 4 == 0) || y % 400 == 0) return true;
    return false;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll y,d;
    cin >> y >> d;
    if(isrun(y)) day[2]++;
    for(int i = 1;i <= 12;i++){
        if(d <= day[i]){
            cout << i << "\n" << d << "\n";
            break;
        }
        d -= day[i];
    }
    return 0;
}