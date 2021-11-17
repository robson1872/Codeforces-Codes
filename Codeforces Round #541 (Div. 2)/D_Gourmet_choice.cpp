#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using vi = vector<int>;
using vll = vector<ll>;
const int MAXN = 2e3+7;
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
int ans[MAXN], p[MAXN], siz[MAXN],vst[MAXN];
int n,m;
vi adj[MAXN];
bool ok = true;
char a[MAXN][MAXN];
int find(int x){
   return ( p[x] == x ? x : p[x] = find(p[x]));
}
void join(int x, int y){
   x = find(x); y = find(y);
   if(x != y){
      if(siz[x] < siz[y]){
         swap(x,y);
      }
      p[y] = x;
      siz[x] += siz[y];
   }
   return;
}
void dfs(int v){
   if(ok == false) return;
   ans[v] = 1;
   vst[v]++;
   for(auto u : adj[v]){
      if(vst[u] == 0){
         dfs(u);
      }else if(vst[u] == 1){
         ok = false;
         return;
      }
      ans[v] = max(ans[v], ans[u] + 1);
   }
   vst[v] = 2;
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   t = 1;
   while(t--){
      cin>>n>>m;
      int mi = - 1;
      for(int i=1;i<=n+m;i++){
         p[i] = i;
         siz[i] = 1;
      }
      for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j] == '=') join(i,j+n);
         }
      }
      for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            int k = find(i) , w = find(j+n);
            if(a[i][j] == '>'){// i < j
               adj[k].pb(w);
            }else if(a[i][j] == '<'){
               adj[w].pb(k);
            }
         }
      }
      for(int i=1;i<=n+m;i++){
         int curr = find(i);
         if(!vst[curr] && siz[i] == 1){
            dfs(curr);
         }
	   }
      for(int i=1;i<=n+m;i++){
         if(!vst[find(i)]){
            ok = false;
            break;
         }
	   }
      if(!ok){
         cout<<"No"<<endl;
         break;
      }
      cout<<"Yes"<<endl;
       for(int i=1;i<=n+m;i++){
          cout<<ans[find(i)]<<" ";
          if(i == n) cout<<endl;
       }
   }
   return 0;
}