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
typedef vector<vpl> vvpl;

#define all(x) x.begin(), x.end()

const int INF = INT_MAX;

void dijkastra(int s, vl &d, vvpl adj)
{
    int n = adj.size();
    d.resize(n, INF);
    // p.assign(n, -1);
    vector<bool> visit(n, false);

    d[s] = 0;
    priority_queue<pl, vpl, greater<pl>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u])
        {
            int v = x.F;
            int w = x.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    ll N, E, s; // N Node , E  Edge, s source 

    ll v, u, w; // u start , v - dest , w - weight


    cin >> N >> E;
    vvpl adj(N+1);

    for (int i = 0; i < E; i++)
    {
        cin >> v >> u >> w;
        
        adj[v].push_back({u, w});
        // adj[u].push_back({v, e}); // if the graph is undirected 
    }
    
    cin >> s; // Source

    vl d; // distance 

    // Run Dijkastra's Algorithm 
    dijkastra(s, d, adj);

    cout<< "The Distance \n" ;
    
    for (int i = 0; i <= N ; i++)
    {
        cout<< "from " << s << " to " <<  i << " is " << d[i] << " \n";
    }
       
}
