
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end() 
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define all(x) x.begin(), x.end() 
const int N = 1000000;

bool prime[N + 9]; // use bitset<100000000> prime for large numbers

void sieve(int N){
	prime[0] = true ; // Make it false if you want but make sure you fill the array with memset(arr, arr+1000000, true)
	prime[0] = true ; // you can also use vector it is the same but array is faster
	for(int i = 2 ; i < N ; i++){
		if( !prime[i] ){ // if you fill the array with false delete the not ( !prime[i] ) => (prime[i]) 
			for (int j = i + i; j < N; j += i)
			{
				prime[j] = true;
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve(N);
    for (int i = 2; i < N; ++i)
    {
    	if(!prime[i]) cout<< i << " ";
    }

}
