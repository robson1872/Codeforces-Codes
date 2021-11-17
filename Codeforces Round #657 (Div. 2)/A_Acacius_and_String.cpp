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
#define yep(a) cout<<(a ? "Yes" : "No")<<endl;
    
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
       string ans = "abacaba";
       cin>>s;
       vi a;
       string aux = s;
       for(int i=0;i<n;i++){
           if((s[i] == 'a' || s[i] == '?') && i + 6 < n) a.pb(i);
       }
       int exist = 0;
       int fazendo = 0;
       int first = -1;
       for(auto u : a){
           string curr = "";
           for(int i=u;i<=u+6;i++){
               curr += s[i];
           }
           if(curr == ans){
               exist++;
           }else{
               bool find = true;
               for(int i=0;i<=6;i++){
                   if(curr[i] != '?' && curr[i] != ans[i]){ 
                       find = false;
                   }
               }
               if(find && !fazendo){
                   first = u;
               }
               fazendo += find;
           }
       }
       if(!exist && !fazendo){
           cout<<"No"<<endl;
           continue;
       }else{
           if(exist > 1){
               cout<<"No"<<endl;
               continue;
           }
       }
       if(exist == 1){
           cout<<"Yes"<<endl;
           for(int i=0;i<n;i++){
               if(s[i] == '?') s[i] = 'd';
           }
           cout<<s<<endl;
       }else{
           bool find = false;
           for(auto u : a){
                int k = 0;
                string curr = s;
                for(int i=0;i<=6;i++){
                    if(curr[i+u] == '?') curr[i+u] = ans[i];
                }
                for(int i=0;i<n;i++){
                    if(curr[i] == '?') curr[i] = 'd';
                    if(curr[i] == 'a'){
                        string aux = "";
                        for(int j=0;j<=6;j++){
                            aux+=curr[j+i];
                        }
                        if(aux == ans){
                            k++;
                        }
                    }
                }
                if(k == 1){
                    s = curr;
                    find = true;
                    break;
                } 
            }
           if(find){
               cout<<"Yes"<<endl;
               cout<<s<<endl;
           }else{
               cout<<"No"<<endl;
           }
       }    
   }
   return 0;
}