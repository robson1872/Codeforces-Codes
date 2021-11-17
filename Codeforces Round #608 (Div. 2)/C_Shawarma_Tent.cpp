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
       int x,y;
       cin>>x>>y;
       int a1 = 0, a2 = 0, a3 =0, a4 = 0;// (x - 1) , (x + 1) , (y - 1) , (y + 1)
       for(int i=0;i<n;i++){
           int a,b;
           cin>>a>>b;
           if(a > x){
               a2++;
           }
           if(a < x){
               a1++;
           }
           if(b > y){
               a4++;
           }
           if(b < y){
               a3++;
           }
       }
       if(a4 >= a3 && a4 >= a2 && a4 >= a1){
           cout<<a4<<endl;
           cout<<x<<" "<<y+1<<endl;
           break;
       }
       if(a1 >= a3 && a1 >= a2 && a1 >= a4){
           cout<<a1<<endl;
           cout<<x-1<<" "<<y<<endl;
           break;
       }
       if(a3 >= a1 && a3 >= a2 && a3 >= a4){
           cout<<a3<<endl;
           cout<<x<<" "<<y-1<<endl;
           break;
       }
       if(a2 >= a1 && a2 >= a3 && a2 >= a4){
           cout<<a2<<endl;
           cout<<x+1<<" "<<y<<endl;
           break;
       }
   }
   return 0;
}