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
using piii = pair<int,pii>;
#define fi first
#define se second
#define mp make_pair
    
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
    
//interactive problems use *fflush(stdout);* at the end of the function; and delete the first line of the main fuction
int t;
struct seg{
    int tam, l, r;
};
bool comp(seg a,seg b){
    if(a.tam == b.tam){
        return (a.l < b.l);
    }
    return (a.tam < b.tam);
}

int main(){
   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vi a(n+1);
       set<pair<int,pii>> q;
       int cnt = 1;
       q.insert({-n,{1,n}});
       //set<pii> ra;
       while(!q.empty()){
           if(cnt > n) break;
           piii curr = *q.begin(); q.erase(q.begin());
           int r = curr.se.se, l = curr.se.fi;
           //if(ra.find({r,l}) != ra.end()) continue;
           int k = r - l + 1;
           if(k&1){
               a[(r+l)/2] = cnt;
               if(k > 1){
                   piii a = {-(k/2),{l,(r+l)/2 - 1}}; piii b = {-(k/2),{(r+l)/2+1,r}};
                   q.insert(a); q.insert(b);
               }
               cnt++;
           }else{
               a[(r+l-1)/2] = cnt;
               if(k > 1){
                   piii a = {-(k/2 - 1),{l,(r+l-1)/2 - 1}}; piii b = {-(k/2), {(r+l-1)/2 + 1,r}};
                   q.insert(a); q.insert(b);
               }
               cnt++;
           }
           //ra.insert({l,r});
       }
       for(int i=1;i<=n;i++){
           cout<<a[i]<<" ";
       }
       cout<<endl;
   }
   return 0;
}