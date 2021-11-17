#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using vi = vector<int>;
using vll = vector<ll>;
const int MAXN = 1e5+7;
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
int frq[MAXN];
bool nLeaf[MAXN];
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>n;
   vi ans(n-1,-1);
   vector<pii> edge;
   for(int i=0;i<n-1;i++){
       int x,y;
       cin>>x>>y;
       edge.pb({x,y});
       frq[x]++; frq[y]++;
       if(frq[x]>1)nLeaf[x] = true;
       if(frq[y]>1)nLeaf[y] = true;
   }
   int cnt = 0;
   for(int i=0;i<n-1;i++){
       if(!nLeaf[edge[i].fi] || !nLeaf[edge[i].se]){
           ans[i] = cnt;
           cnt++;
       }
   }
   for(int i=0;i<n-1;i++){
       if(ans[i] == -1){
           ans[i] = cnt;
           cnt++;
       } 
   }
   for(auto u : ans){
       cout<<u<<endl;
   }
   return 0;
}