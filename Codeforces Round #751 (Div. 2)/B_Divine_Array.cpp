#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using vi = vector<int>;
using vll = vector<ll>;
const int MAXN = 2e3+7;
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
int t,n;
int frq[MAXN][MAXN];
int a[MAXN][MAXN];
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>t;
   while(t--){
       cin>>n;
       //memset(frq,0,sizeof(frq)); memset(a,0,sizeof(a));
       for(int j=1;j<=n;j++){
            frq[0][j] = 0;
        }
       for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a[0][i] = x;
            frq[0][x]++;
        }
        for(int i=0;i<=n;i++){
            for(int j=1;j<=n;j++){
                frq[i+1][j] = 0;
            }
            for(int j=1;j<=n;j++){
                a[i+1][j] = frq[i][a[i][j]];
                frq[i+1][a[i+1][j]]++;
            }
        }
        int q;
        cin>>q;
        while(q--){
            int x,k;
            cin>>x>>k;
            if(k > n) k = n+1;
            cout<<a[k][x]<<"\n";
        }
   }
   
   return 0;
}