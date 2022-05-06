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

    int q; cin >> q;
    while(q--) {
        ll a,b; cin >> a >> b;
        ll eva = a/2;
        ll odda = a -eva;
        ll evb = b/2;
        ll oddb = b-evb;
        ll den = a*b; 
        ll num = eva*oddb + evb*odda;
        ll gcd = __gcd(den, num);
        num/=gcd;
        den/=gcd;
        cout << num <<"/"<<den<<endl;
    }

}
