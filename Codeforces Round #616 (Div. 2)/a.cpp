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
       string s;
       cin>>s;
       int sum = 0;
       pii odd = {-1,-1};
       int oddn = 0;
       for(int i=0;i<n;i++){
           int k =s[i] - '0';
           sum += k;
           if(k&1){
               oddn++;
               if(odd.fi == -1){
                   odd.fi = i;
               }else if(odd.se == -1){
                   odd.se = i;
               }
           } 
       }
       if(sum&1){
           if(oddn < 2){
               cout<<-1<<endl;
           }else{
               cout<<s[odd.fi]<<s[odd.se]<<endl;
           }
       }else{
           int p = s[n-1] - '0';
            if(p&1){
                cout<<s<<endl;
            }else{
                if(oddn >= 2){
                    cout<<s[odd.fi]<<s[odd.se]<<endl;
                }else{
                    cout<<-1<<endl;
                }
            }
       }
   }
   return 0;
}