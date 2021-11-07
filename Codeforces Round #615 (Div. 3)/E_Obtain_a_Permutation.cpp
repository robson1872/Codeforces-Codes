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
int n,m;

int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>n>>m;
   int mt[n+1][m+1];
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>mt[i][j];
           mt[i][j]--;
       }
   }
   int ans = 0;
   for(int j=0;j<m;j++){
       vi cnt(n,0);
       for(int i=0;i<n;i++){
           if(mt[i][j] % m == j){
               int p = mt[i][j]/m;
               if(p < n){
                   cnt[(i - p + n)%n]++;
               }
           }
       }
       int curr = n;
       for(int i=0;i<n;i++){
           curr = min(curr,n - cnt[i] + i);
       }
       ans += curr;
   }
   cout<<ans<<endl;
   return 0;
}