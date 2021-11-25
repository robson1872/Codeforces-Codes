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
       vi ans(n+1);
       vi aux(n+1,0);
       vi aux2;
       queue<int>aux3;
       for(int i=1;i<=n;i++){
           cin>>ans[i];
           aux[ans[i]]++;
       }
       for(int i=1;i<=n;i++){
           if(!aux[i] && !ans[i]){
               aux3.push(i);
               aux[i]++;
               aux2.pb(i); // dont send
               ans[i] = -1;
           }
       }
       for(int i=1;i<=n;i++){
           if(ans[i] == 0){
               aux2.pb(i); // dont send
           }
       }
       for(int i=1;i<=n;i++){
           if(!aux[i]) aux3.push(i);// dont receive
       }
       int k  = sz(aux2);
       for(int i = 0;i<k;i++){
            while(true){
                int p = aux2[i] , w = aux3.front(); 
                aux3.pop();
                if(p == w){
                    aux3.push(w);
                    continue;
                }else{
                    ans[p] = w; 
                    break;
                }
            }
        }
       for(int i=1;i<=n;i++){
           cout<<ans[i]<<" ";
       }
       cout<<"\n";
   }
   return 0;
}