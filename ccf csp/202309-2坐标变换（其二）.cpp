#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

double k[N],th[N];
int main(){
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     ll n,m,op,l,r;
     cin >> n >> m;
     double t,x,y,ax,ay;
     k[0] = 1;
     for(int i = 1;i <= n;i++){
          cin >> op >> t;
          if(op == 1){
               k[i] = k[i - 1] * t;
               th[i] = th[i - 1];
          }else{
               k[i] = k[i - 1];
               th[i] = th[i - 1] + t;
          }
     }
     while(m--){
          cin >> l >> r >> x >> y;
          double ak = k[r] / k[l - 1],mth = th[r] - th[l - 1];
          x = ak * x;
          y = ak * y;
          ax = cos(mth) * x - sin(mth) * y;
          ay = sin(mth) * x + cos(mth) * y;
          cout << fixed << setprecision(3) << ax << " " << ay << "\n";
     }
     return 0;
}


/*暴力解法 80pts*/
/*#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

pair<double,double> o[N];
int main(){
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     ll n,m,op,l,r;
     cin >> n >> m;
     double t,x,y,ax,ay;
     for(int i = 1;i <= n;i++)
          cin >> o[i].first >> o[i].second;
     while(m--){
          cin >> l >> r >> x >> y;
          for(int i = l;i <= r;i++){
               t = o[i].second;
               if(o[i].first == 1){
                    ax = t * x;
                    ay = t * y;
               }else{
                    ax = cos(t) * x - sin(t) * y;
                    ay = sin(t) * x + cos(t) * y;
               }
               x = ax,y = ay;
          }
          cout << fixed << setprecision(3) << ax << " " << ay << "\n";
     }
     return 0;
}*/

/*矩阵求法 80pts*/
/*#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
typedef vector<double> vd;
typedef vector<vd> vvd;

vvd mul(vvd a,vvd b){
     vvd ans(2,vd(2));
     ans[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
     ans[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
     ans[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
     ans[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
     return ans;
}

vvd inv(vvd a){
     vvd ans(2,vd(2));
     double as = a[0][0] * a[1][1] - a[1][0] * a[0][1];
     ans[0][0] = a[1][1] / as;
     ans[1][1] = a[0][0] / as;
     ans[0][1] = -a[0][1] / as;
     ans[1][0] = -a[1][0] / as;
     return ans;
}

vvd o[N],oni[N];
int main(){
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     ll n,m,op,l,r;
     cin >> n >> m;
     double t,x,y,ax,ay;
     vvd temp(2,vd(2));
     temp[0][0] = 1;temp[1][1] = 1;
     temp[1][0] = 0;temp[0][1] = 0;
     o[0] = temp,oni[0] = temp;
     for(int i = 1;i <= n;i++){
          cin >> op >> t;
          if(op == 1){
               temp[0][0] = t;
               temp[1][1] = t;
               temp[0][1] = 0;
               temp[1][0] = 0;
          }
          else{
               temp[0][0] = cos(t);
               temp[1][1] = cos(t);
               temp[0][1] = -sin(t);
               temp[1][0] = sin(t);
          }
          o[i] = mul(o[i - 1],temp);
          oni[i] = mul(oni[i - 1],inv(temp));
     }
     while(m--){
          cin >> l >> r >> x >> y;
          temp = mul(o[r] , oni[l - 1]);
          ax = temp[0][0] * x + temp[0][1] * y;
          ay = temp[1][0] * x + temp[1][1] * y;
          cout << fixed << setprecision(3) << ax << " " << ay << "\n";
     }
     return 0;
}*/