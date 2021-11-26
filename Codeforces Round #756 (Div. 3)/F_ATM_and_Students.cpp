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
       ll n,s;
       cin>>n>>s;
       vll a(n+5);
       vll pfx(n+5);
       vll sfx(n+5);
       ll sum = 0;
       for(int i=1;i<=n;i++){
           cin>>a[i];
           sum += a[i];
           pfx[i] = pfx[i-1] + a[i];
       }
       for(int i = n ; i>= 1; i--){
           sfx[i] = sfx[i+1] + a[i];
       }
       ll ans1=-1,ans2=-1;
       ll l=1,r=MAXN;
       bool found = false;
       while(l<=r){
           ll m = (l+r)/2;
           bool ok = false;
           for(ll i = 1; i+m-1<=n;i++){
               ll aux = sum + s - pfx[i-1] - sfx[i+m];
               if(aux >= 0){
                   ans1 = i;
                   ans2 = i+m-1;
                   ok = true;
                   found = true;
                   break;
               } 
           }
           if(ok){
               l = m + 1;
           }else{
               r = m - 1;
           }
       }
       if(!found){
           cout<<-1<<endl;
       }else{
           cout<<ans1<<" "<<ans2<<endl;
       }
   }
   return 0;
}