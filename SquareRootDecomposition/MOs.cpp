#include <bits/stdc++.h>
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
#define MAX 100050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct Query {
    int L, R;
};

int blockSize;

bool compare(Query x, Query y) {
    if(x.L / blockSize != y.L / blockSize)
        return x.L / blockSize < y.L / blockSize;
    return x.R < y.R;
}

void solveQuery(vector<int> a, vector<Query> q) {
    int n = a.size(), m = q.size();
    blockSize = ceil(sqrt(n));
    sort(all(q), compare);

    int currL = 0, currR = 0, currSum = 0;
    loop(i, 0, m) {
        int L = q[i].L, R = q[i].R;
        
        while(currL < L) {
            currSum -= a[currL];
            currL++;
        }
        while(currR > R+1) {
            currSum -= a[currR-1];
            currR--;
        }
        
        while(currL > L) {
            currSum += a[currL - 1];
            currL--;
        }
        while(currR <= R) {
            currSum += a[currR];
            currR++;
        }

        cout << currSum << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, q, type, x, y;

    cin >> n;
    vector<int> nums(n);
    loop(i, 0, n) cin >> nums[i];

    cin >> q;
    vector<Query> queries(q);
    loop(i, 0, q) {
        cin >> x >> y;
        queries[i] = {x, y};
    }

    solveQuery(nums, queries);
}