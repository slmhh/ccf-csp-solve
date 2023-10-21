#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10,B = 30;

ll nums[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,maxs = 0,mins = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> nums[i];
        maxs += nums[i];
        if(i == 0 || nums[i] != nums[i - 1]) mins += nums[i];
    }
    cout << maxs << "\n" << mins << "\n";
    return 0;
}