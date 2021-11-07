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
vi edges[MAXN];
int dist[3][MAXN], visit[3][MAXN], p[3][MAXN];
int ans[3];
int ignor[MAXN];
void bfs(int i, int x){
    queue<int> q;
    q.push(x);
    visit[i][x]++;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : edges[u]){
            if(visit[i][v]){
                continue;
            }else{
                visit[i][v]++;
                p[i][v] = u;
                if(!ignor[v]){
                    dist[i][v] = dist[i][u] + 1;
                }
                if(dist[i][v] > dist[i][ans[i]]){
                    ans[i] = v;
                }
                q.push(v);
            }
        }
    }
    if(i == 1){
        int u = ans[1], v = ans[0];
        for(int j = u ; j != v ; j = p[i][j]){
            ignor[j]++;
        }
        ignor[v]++;
    }
}
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>n;
   for(int i=0;i<n;i++){
       int x,y;
       cin>>x>>y;
       edges[x].pb(y); edges[y].pb(x);
   }
   bfs(0,1);
   bfs(1,ans[0]);
   bfs(2,ans[1]);
   int sum = dist[1][ans[1]] + dist[2][ans[2]];
   cout<<sum<<endl;
   if(ans[2] == 0){
       for(int i=1;i<=n;i++){
           if(i != ans[0]  && ans[1] != i){
               ans[2] = i;
               break;
           }
       }
   }
   for(auto u : ans){
       cout<<u<<" ";
   }
   cout<<endl;
   return 0;
}