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


	ll ans = 0;
	int n; cin >> n;

	vector<ll> v(n);

	fr(i,n) {
		cin>> v[i];
	}
	
	int r=n-1;

	ll pref=0;
	ll suf=0;


	for(int i=0;i<n;i++){
		pref+=v[i];
		while(r>i && suf<pref) {
			suf+=v[r];
			r--;
		}
		if(pref==suf)	ans=pref;
	}
	

	cout << ans << endl;

}
