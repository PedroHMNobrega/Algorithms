#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loopBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 100
#define MOD 1000
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct FlowEdge {
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges; 
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    
    vector<int> level, ptr; 
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add(int v, int u, ll cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m+1);
        m += 2;
    }

    bool bfs() {
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int viz : adj[v]) {
                if(edges[viz].cap - edges[viz].flow < 1) continue; 
                if(level[edges[viz].u] != -1) continue; 
                level[edges[viz].u] = level[v] + 1;
                q.push(edges[viz].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed) {
        if(pushed == 0) return 0;
        if(v == t) return pushed;
        for(int &i = ptr[v]; i < (int)adj[v].size(); i++) { 
            int viz = adj[v][i];
            int u = edges[viz].u;
            
            if(level[v] + 1 != level[u] || edges[viz].cap - edges[viz].flow < 1) continue;
            
            ll tr = dfs(u, min(pushed, edges[viz].cap - edges[viz].flow));
            if(tr == 0) continue; 

            edges[viz].flow += tr;
            edges[viz ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while(true) {
            fill(all(level), -1);
            level[s] = 0;
            q.push(s);
            if(!bfs()) break;
            fill(all(ptr), 0);
            while(ll pushed = dfs(s, flow_inf))
                f += pushed;
        }
        return f;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("in.txt", "r", stdin);
    Dinic graph = Dinic(MAX, 'A'-'A', 'Z'-'A');
    int n, nA, nB, cap;
    char a, b;
    cin >> n;
    loop(i, 0, n) {
        cin >> a >> b >> cap;
        nA = a - 'A';
        nB = b - 'A';
        graph.add(nA, nB, cap);
    }
    ll ans = graph.flow();
    cout << ans << '\n';
}