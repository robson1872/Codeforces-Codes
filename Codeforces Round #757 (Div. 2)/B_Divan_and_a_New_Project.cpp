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
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>t;
   while(t--){
       ll n;
       cin>>n;
       vector<pll> a(n);
       for(ll i=0;i<n;i++){
           cin>>a[i].fi;
           a[i].se = i+1;
       }
       sort(all(a));
       reverse(all(a));
       ll ans = 0;
       vi b(n+1);
       ll cnt = 0;
       for(ll i=0;i<n;i++){
           if(i%2 ==0) cnt++;
           pii x = a[i];
           if(i%2 == 0){
               b[x.se] = cnt;
           }else{
               b[x.se] = -cnt;
           }
           ans += abs(b[x.se]*a[i].fi);
       }
       cout<<2*ans<<endl;
       for(auto u : b){
           cout<<u<<" ";
       }
       cout<<endl;
   }
   return 0;
}