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
vi adj[MAXN];
int a[MAXN],ans[MAXN];
int n;
bool f(int i, int j){
    return (i&1) != (j&1);
}
void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++){
       if(ans[i]==1) q.push(i);
   }
   while(!q.empty()){
       int curr = q.front(); q.pop();
       for(auto u: adj[curr]){
           if(ans[u] == -1){
               ans[u] = ans[curr] + 1;
               q.push(u);
           }
       }
   }
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>n;
   memset(ans,-1,sizeof(ans));
   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   for(int i=1;i<=n;i++){
       int p = i + a[i], w = i - a[i];
       if(p <= n){
           adj[p].pb(i);
           if( f(a[p], a[i]) )ans[i] = 1;
       } 
       if(w >= 1){
           adj[w].pb(i);
           if( f(a[w], a[i]) ) ans[i] = 1;
       } 
   }
   bfs();
   for(int i=1;i<=n;i++){
       cout<<ans[i]<<" ";
   }
   cout<<endl;
   return 0;
}