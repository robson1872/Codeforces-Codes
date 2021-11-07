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
int t;
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vector<pii> q;
       for(int i=0;i<n;i++){
           int x,y;
           cin>>x>>y;
           q.pb({x,y});
       }
       bool ok = true;
       string s = "";
       sort(all(q)); reverse(all(q));
       int x = 0,y = 0;
       while(!q.empty() && ok){
           int x_curr = q.back().fi,y_curr = q.back().se;
           q.pop_back();
           if(x <= x_curr && y <= y_curr){
               int r = x_curr - x , u =  y_curr - y;
               x = x_curr;
               y = y_curr;
               for(int i=0;i<r;i++){
                   s+= "R";
               }
               for(int i=0;i<u;i++){
                   s+= "U";
               }
           }else{
               ok = false;
           }
       }
       if(q.empty() && ok){
           cout<<"YES"<<endl<<s<<endl;
       }else{
           cout<<"NO"<<endl;
       }
   }
   return 0;
}