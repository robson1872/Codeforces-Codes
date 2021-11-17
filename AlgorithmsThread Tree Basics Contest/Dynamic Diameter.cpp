#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using vi = vector<int>;
using vll = vector<ll>;
const int MAXN = 3e5+7;
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
int n;
int vst[4][MAXN],dst[4][MAXN],ans[4]={1,1,1,1};
vi adj[MAXN];
void dfs(int i, int v){
    for(auto u : adj[v]){
        if(vst[i][u]){
            continue;
        }
        vst[i][u]++;
        dst[i][u] = dst[i][v] + 1;
        if(dst[i][u] >= dst[i][ans[i]]){
            ans[i] = u;
        }
        dfs(i,u);
    }
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>n;
   for(int i=0;i<n-1;i++){
       int x, y;
       cin>>x>>y;
       adj[x].pb(y);
       adj[y].pb(x);
   }
   for(int i=1;i<=3;i++){
       dfs(i,ans[i-1]);
   }
   int act = dst[2][ans[2]];
   for(int i=1;i<=n;i++){
       int curr = max(dst[2][i] + 1, dst[3][i] + 1);
       cout<<max(curr , act)<<"\n";
   }
   return 0;
}
