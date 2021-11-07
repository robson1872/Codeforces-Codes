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
set<int> trial_division1(int n) {
    set<int> factorization;
    int k = 0;
    for (int d = 2; d * d <= n && k < 2; d++) {
        if(n % d == 0) {
            k++;
            factorization.insert(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.insert(n);
    return factorization;
}
int t;
int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       set<int> a = trial_division1(n);
       if(sz(a) >= 3){
           cout<<"YES"<<endl;
           int p = 0;
           for(auto x : a){
               p++;
               if(p>3) break;
               cout<<x<<" ";
           }
           cout<<endl;
       }else{   
           cout<<"NO"<<endl;
       }
   }
   return 0;
}