#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using vi = vector<int>;
using vll = vector<ll>;
const int MAXN = 5e3+7;
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
int dp[MAXN][MAXN];
int cst[MAXN], pnts[MAXN], ncr[MAXN], hrs[MAXN];
vi adj[MAXN];
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   t = 1;
   while(t--){
       int n,m,p;
       cin>>n>>m>>p;
       int ans = -1;
       memset(dp,-1,sizeof(dp));
       for(int i=1;i<=n;i++){
           cin>>ncr[i]>>hrs[i]>>pnts[i];
       }
       for(int i = 1; i<= n; i++){
           cst[i] = i;
       }
       for(int i=1;i<=m;i++){
           int u,v;
           cin>>u>>v;
           cst[v] = max(cst[v],u);
       }
       for(int i=1;i<=n;i++){
           adj[cst[i]].pb(pnts[i]);
       }
       for(int i=1;i<=n;i++){
           sort(all(adj[i]));
           reverse(all(adj[i]));
       }
       int sum  = p;
       dp[1][p] = 0;
       for(int i=1;i<=n;i++){
           for(int j = max(0,sum - i); j<= sum; j++){
               if(dp[i][j] == -1 || j < ncr[i]) continue;
               int u = 0, acm = 0;
               dp[i+1][j + hrs[i]] = dp[i][j];
               for(auto k : adj[i]){
                   u++;
                   acm += k;
                   if(j - u + hrs[i] >= 0){
                       dp[i+1][j-u + hrs[i]] = max(dp[i+1][j-u+hrs[i]],acm + dp[i][j]);
                       //cout<<i+1<<" "<<j-u + hrs[i]<<" "<<dp[i+1][j-u + hrs[i]]<<endl;
                   }else{
                       break;
                   }
               }
           }
           sum += hrs[i];
       }
       for(int i = 0; i <= sum; i++){
           ans = max(dp[n+1][i],ans);
       }
       cout<<ans<<endl;
   }
   return 0;
}