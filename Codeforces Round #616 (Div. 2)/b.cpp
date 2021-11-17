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
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vi a(n+1);
       int cnt = 0;
       bool ok = false;
       int mx = 1;
       vi pfx(n+5);
       vi sfx(n+5);
       pfx[0] = 1; sfx[n+1] = 1;
       for(int i=1;i<=n;i++){
           cin>>a[i];
           if(a[i] >= i - 1){
               pfx[i] = pfx[i-1] & 1;
           }else{
               pfx[i] = 0;
           }
       }
       for(int i= n;i>=1 ; i--){
           if(a[i] >= n - i ){
               sfx[i] = sfx[i+1] & 1;
           }else{
               sfx[i] = 0;
           }
       }
       for(int i=1;i<=n;i++){
           if(pfx[i] && sfx[i]) ok  = true;
       }
       cout<<(ok ? "Yes" : "No")<<"\n";
   }
   return 0;
}