#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int main(){

	fastio;

	int n; 
	cin >> n;


	vector<vector<int>> memo(n+1, vector<int>(3,0));
	vector<int> a(n+1, 0);
	vector<int> b(n+1, 0);
	vector<int> c(n+1, 0);

	for(int i=1;i<=n;i++) {
		cin >> a[i]>>b[i]>>c[i];
	}

	for(int i=1;i<=n;i++) {
		memo[i][0] = a[i] + max( memo[i-1][1], memo[i-1][2]);
		memo[i][1] = b[i] + max( memo[i-1][0], memo[i-1][2]);
		memo[i][2] = c[i] + max( memo[i-1][0], memo[i-1][1]);
	}

	int ans = max(memo[n][0], memo[n][1]);
	ans = max(memo[n][2], ans);
	cout << ans << endl;

}
