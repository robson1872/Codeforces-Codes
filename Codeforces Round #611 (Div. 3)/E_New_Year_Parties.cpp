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
const int d[] = {-1,0,1};
    
//interactive problems use *fflush(stdout);* at the end of the function; and delete the first line of the main fuction
int n;
int dp[2][MAXN][3];
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>n;
   vi a(n);
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   sort(all(a));
   int mx = 0, mn = INF;
   // calculando dp para menor
   for(int i=0;i<3;i++){
       dp[0][0][i] = 1; 
   }
   for(int i=1;i<n;i++){
       for(int j=0;j<3;j++){
           for(int k = 0; k<3; k++){
               
           }
       }
   }

   // encontrando melhor
   for(int i=0;i<3;i++){
       mx = max(mx,dp[0][n-1][i]);
   }
   for(int i=0;i<3;i++){
       mn = min(mn,dp[1][n-1][i]);
   }
   cout<<mn<<" "<<mx<<endl;
   return 0;
}