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
   t = 1;
   while(t--){
       int n;
       cin>>n;
       vi a(n+2);
       vi pfx(n+2);
       vi sfx(n+2);
       int ans = 1;
       int aux = 1;
       for(int i = 1; i<= n; i++){
           cin>>a[i];
           if(i > 1 && a[i] > a[i-1]){
               aux++;
               ans = max(ans,aux);
               pfx[i] = aux;
           }else{
               aux = 1;
               pfx[i] = 1;
           }
       }
       aux = 1;
       for(int i = n; i >= 1;i--){
           if(i < n && a[i] < a[i+1]){
               aux++;
               sfx[i] = aux;
           }else{
               aux = 1;
               sfx[i] = aux;
           }
       }
       for(int i=2;i<=n-1;i++){
           int curr = 1;
           if(a[i-1] < a[i+1]){
               curr = pfx[i-1] + sfx[i+1];
           }
           ans = max(ans,curr);
       }
       cout<<ans<<endl;
   }
   return 0;
}