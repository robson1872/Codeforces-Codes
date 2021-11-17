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
       string s;
       cin>>s;
       bool ok = false;
       int k = 0;
       vi ans;
       string aux = s;
       string black = "";
       string white = "";
       for(int i=0;i<n;i++){
           black += "B"; white += "W";
       }
       // first black
       for(int i=0;i<n-1;i++){
           if(s[i] == 'B'){
               continue;
           }else{
               ans.pb(i+1);
               s[i] = 'B';
               s[i+1] = (s[i+1] == 'B' ? 'W' : 'B');
           }
       }
       if(s == black){
           ok = true;
       }else{
           ans.clear();
           s = aux;
           for(int i=0;i<n-1;i++){
                if(s[i] == 'W'){
                    continue;
                }else{
                    ans.pb(i+1);
                    s[i] = 'W';
                    s[i+1] = (s[i+1] == 'B' ? 'W' : 'B');
                }
           }
           if(s == white){
               ok = true;
           }
       }
       if(ok){
           cout<<sz(ans)<<endl;
           for(auto u : ans){
               cout<<u<<" ";
           }
           cout<<endl;
       }else{
           cout<<-1<<endl;
       }
   }
   return 0;
}