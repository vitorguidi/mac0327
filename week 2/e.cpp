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


bool verify(vector<ll> &v, ll rad, ll l) {
	ll x=0;
	ll y=0;

	for(auto val : v) {
		ll new_x = val-rad;
		ll new_y = val+rad;
		if(new_x<=y && y<=new_y) {
			x=min(x,new_x);
			y=max(y,new_y);
		}
		else
			return false;
	}

	x = max(x,0ll);
	y = min(y,l);

	if(x==0 && y==l)	return true;
	return false;
	
}

int main(){

	fastio;

	int n,l;
	cin >> n >> l;
	vector<ll> v(n);
	fr(i,n) {
		cin >> v[i];
		v[i]*=2;
	}

	sort(v.begin(),v.end());

	ll ini=0;
	ll end=2*1e9;

	while(ini<=end){
		ll mid = (ini+end)/2;
		if(verify(v,	mid, 2*l)) {
			end=mid-1;
		}
		else{
			ini=mid+1;
		}
	}
	cout << setprecision(10) << fixed;
	cout << double(end+1)/2.0 << endl;

}
