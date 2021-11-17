#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using vi = vector<int>;
using vll = vector<ll>;
const int MAXN = 2e5+7;
const int MOD = 1e9 + 7;
    
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define DBG(x) cout << "[" << #x << "] : "<<x<<endl
#define add(a, b) (a + b >= MOD ? a + b - MOD : a + b)
#define yep(a) cout<<(a ? "YES" : "NO")<<endl;
    
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
    
#define fi first
#define se second
#define mp make_pair
    
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
    
//interactive problems use *fflush(stdout);* at the end of the function; and delete the first line of the main fuction
int t;
ll count(ll n, ll x) {
    ll cnt = 1;
    if(x > n) return 0;
    if(x % 2 == 1) {
        x *= 2;
        ll aux = 2;
        while(x <= n) {
            cnt += min(aux, n - x + 1);
            x *= 2;
            aux *= 2;
        }
    }
    else {
        cnt = 2;
        x *= 2;
        ll aux = 4;
        while(x <= n) {
            cnt += min(aux, n - x + 1);
            aux *= 2;
            x *= 2;
        }
    }
    return cnt;
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   t = 1;
   while(t--){
       ll n,k;
       cin>>n>>k;
       ll ans = 1;
       // testar os pares:
       ll l = 0, r = n;
       while(l < r - 1){
           ll m = (l+r)/2;
           ll att = 2*m;
           ll curr = count(n,att);
           if(att <= n && curr >= k){
               ans = max(ans,att);
               l = m;
           }else{
               r = m;
           }
       }
       // testar os impares:
       l = 0, r = n;
       while(l < r - 1){
           ll m = (l+r)/2;
           ll att = 2*m + 1;
           ll curr = count(n,att);
           if(att <= n && curr >= k){
               ans = max(ans,att);
               l = m;
           }else{
               r = m;
           }
       }
       cout<<ans<<endl;
   }
   return 0;
}