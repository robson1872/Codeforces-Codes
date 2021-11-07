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
vi adj[MAXN];
map<pii,int> ans;
int vst[MAXN];
int minn = INF;
bool dfs(int b, int e, int val){
    if(b == e){
        return true;
    }
    bool find = false;
    for(auto v :adj[b]){
        if(vst[v]) continue;
        vst[v]++;
        if(dfs(v,e,val)){
            find = true;
            pii curr = {min(v,b),max(v,b)};
            ans[curr] = max(ans[curr],val);
        }
    }
    return find;
}
bool dfs2(int b, int e){
    if(b == e){
        return true;
    }
    bool find = false;
    for(auto v :adj[b]){
        if(vst[v]) continue;
        vst[v]++;
        if(dfs2(v,e)){
            find = true;
            pii curr = {min(v,b),max(v,b)};
            if(ans[curr] != 0){
                minn = min(minn,ans[curr]);
            }
        }
    }
    return find;
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   t = 1;
   while(t--){
       int n;
       cin>>n;
       vector<pii>edges;
       for(int i=0;i<n-1;i++){
           int x,y;
           cin>>x>>y;
           adj[x].pb(y); adj[y].pb(x);
           pii curr = {min(x,y),max(x,y)};
           edges.pb(curr);
           ans[curr] = 0;
       }
       int m;
       cin>>m;
       vector<pair<pii,int>> q;
       for(int i=0;i<m;i++){
           int x,y,z;
           cin>>x>>y>>z;
           q.pb({{x,y},z});
       }
       sort(q.begin(), q.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second < b.second;
       });
       for(auto k : q){
           memset(vst,0,sizeof(vst));
           vst[k.fi.fi]++;
           dfs(k.fi.fi,k.fi.se,k.se);
       }
       bool valid = true;
       for(auto k : q){
           memset(vst,0,sizeof(vst));
           minn = INF;
           dfs2(k.fi.fi,k.fi.se);
           if(k.se != minn){
               valid = false;
           }
       }
       if(!valid){
           cout<<-1<<endl;
       }else{
           for(auto k : edges){
               cout<<(ans[k] > 0 ? ans[k] : 1000000)<<" ";
           }
           cout<<endl;
       }
   }
   return 0;
}