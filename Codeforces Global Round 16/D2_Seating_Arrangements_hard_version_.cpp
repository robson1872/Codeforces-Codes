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
bool comp(pii a, pii b){
    if(a.fi == b.fi){
        return a.se > b.se; 
    }
    return a.fi < b.fi;
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>t;
   while(t--){
       int n,m;
       cin>>n>>m;
       vector<pii> a(n*m+1);
       for(int i=1;i<=n*m;i++){
           cin>>a[i].fi;
           a[i].se = i;
       }
       sort(all(a));
       ll ans = 0;
       for(int i=0;i<n;i++){
           vi aux;
           sort(a.begin() + i*m+1,a.begin() + i*m + m + 1,comp);
           for(int j=1;j<=m;j++){
               aux.pb(a[i*m + j].se);
           }
           ll curr = 0;
           for(int j=0;j<m;j++){
               for(int k = j - 1; k >= 0 ; k--){
                   if(aux[k] < aux[j]){
                       curr++;
                   }
               }
           }
           ans += curr;
       }
       cout<<ans<<endl;
   }
   return 0;
}