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

ll fastxp(ll a, ll b) {
	ll mod = 1e9+7;
	if(b==0)	return 1;
	if(b==1)	return a;

	if (b%2)	return (a*fastxp(a,b-1))%mod;
	ll ans = fastxp(a, b/2);
	return (ans*ans)%mod;
}

int main(){

	fastio;

	ll mod = 1e9+7;
	ll fat[330];

	fat[0]=1;
	for(int i=1;i<330;i++) {
		fat[i]=(i*fat[i-1])%mod;
	}

	ll n,a,b,c;cin>>n>>a>>b>>c;
	ll ans = fat[n];

	ans = (ans*fastxp(fat[a],mod-2))%mod;
	ans = (ans*fastxp(fat[b],mod-2))%mod; 
	ans = (ans*fastxp(fat[c],mod-2))%mod;

	cout << ans << endl;




}
