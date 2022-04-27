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
int n,m;
int cost[26];
string s,t;
int memo[2020][2020];

int dp(int i, int j) {
	if(i==n || j==m)	return 0;
	int &pdm=memo[i][j];
	if(pdm!=-1)	return pdm;

	pdm = 0;
	if(s[i]==t[j])	pdm = max(pdm, cost[s[i]-'a'] + dp(i+1,j+1));
	pdm = max(pdm, dp(i+1,j));
	pdm = max(pdm, dp(i,j+1));

	return pdm;

}

int main(){

	fastio;

	cin >> n >> m;
	fr(i,26) cin >> cost[i];

	cin >> s >> t;
	ms(memo,-1);

	cout << dp(0,0) << endl;


}
