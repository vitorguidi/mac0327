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

int memo[4040];
	int n,a,b,c; 

int dp(int i) {
	if(i<0)
		return -1e9;
	if(i==0)	return 0;

	int &pdm = memo[i];
	if(pdm!=-1)	
		return pdm;
	
	pdm=-1e9;

	pdm = max(pdm, 1+dp(i-a));
	pdm = max(pdm, 1+dp(i-b));
	pdm = max(pdm, 1+dp(i-c));
	return pdm;
}

int main(){

	fastio;
	ms(memo,-1);

	cin >> n >> a >> b >> c;

	cout << dp(n) << endl;

}
