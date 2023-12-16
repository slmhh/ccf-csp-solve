#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10,B = 30;

struct temp{
    ll idx,num;
};

bool cmp(temp a,temp b){
    if(a.num != b.num) return a.num < b.num;
    return a.idx < b.idx;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,X,Y,x,y;
    vector<temp> nums;
    cin >> n >> X >> Y;
    for(int i = 1;i <= n;i++){
        cin >> x >> y;
        temp t;
        t.idx = i;
        t.num = (x - X) * (x - X) + (y - Y) * (y - Y);
        nums.push_back(t);
    }
    sort(nums.begin(),nums.end(),cmp);
    cout << nums[0].idx << "\n" << nums[1].idx << "\n" << nums[2].idx << "\n";
    return 0;
}