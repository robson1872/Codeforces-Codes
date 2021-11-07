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
int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> maxdp(26);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int c = 25; c > s[i] - 'a'; --c) {
			dp[i] = max(dp[i], maxdp[c] + 1);
		}
		maxdp[s[i] - 'a'] =  max(maxdp[s[i] - 'a'], dp[i]);
	}
	int k = *max_element(maxdp.begin(), maxdp.end());
   if(k > 2){
      cout<<"NO"<<endl;
      return 0;
   }else{
      cout<<"YES"<<endl;
   }
	for (int i = 0; i < n; ++i) cout << --dp[i];
	cout << endl;
	
	return 0;
}