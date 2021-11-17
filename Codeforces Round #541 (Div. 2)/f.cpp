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
int p[MAXN];
vi ans [MAXN];
int find(int x){
    if(p[x] == x){
        return x;
    }
    return p[x] = find(p[x]);
}
void join(int x, int y){
    x = find(x); y = find(y);
    if(sz(ans[x]) < sz(ans[y])){
        swap(x,y);
    }
    p[y] = x;
    ans[x].insert(ans[x].end(), ans[y].begin(), ans[y].end());
    return;
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   t = 1;
   while(t--){
       int n;
       cin>>n;
       for(int i=1;i<=n;i++){
           p[i] = i;
           ans[i] = {i};
       }
       for(int i=1;i<=n-1;i++){
           int x,y;
           cin>>x>>y;
           join(x,y);
       }
       for(int i=1;i<=n;i++){
           if(sz(ans[i]) == n){
               for(auto u : ans[i]){
                   cout<<u<<" ";
               }
               cout<<endl;
               break;
           }
       }
   }
   return 0;
}