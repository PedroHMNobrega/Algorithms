#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loobBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 20
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int n, x, y;
vector<int> xs, ys;
double dist[17][17], dp[17][1 << 17];

double distancia(int x1, int y1, int x2, int y2) {
    return hypot(x1 - x2, y1 - y2);
}

double solve(int id, int bitmask) {
    if(bitmask == (1 << n) - 1) return dist[id][0];
    if(dp[id][bitmask] != -1) return dp[id][bitmask];
    double ans = DINF;
    loop(i, 0, n) {
        if(!(bitmask & (1 << i))) {
            ans = min(ans, dist[id][i] + solve(i, bitmask | (1 << i)));
        }
    }
    return dp[id][bitmask] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (cin >> n and n) {
        n++;
        loop(i, 0, n) {
            cin >> x >> y;
            xs.pb(x); ys.pb(y);
        }
        loop(i, 0, n) 
            loop(j, i, n) 
                dist[i][j] = dist[j][i] = distancia(xs[i], ys[i], xs[j], ys[j]);
        loop(i, 0, n)
            loop(j, 0, (1 << n)) 
                dp[i][j] = -1;

        printf("%.2f\n", solve(0, 1));
        xs.clear(); ys.clear();
    }
}