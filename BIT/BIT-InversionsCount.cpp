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
#define MAX 10050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

ll maxNum;
int t, n; 

int sum(int k, vector<int> &bit) {
    int s = 0;
    while(k > 0) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}

void add(int k, int x, vector<int> &bit) {
    while(k <= maxNum) {
        bit[k] += x;
        k += k & -k;
    }
}

ll solve(vector<ll> &arr) {
    ll ans = 0;
    maxNum = 0;
    loop(i, 0, n) maxNum = max(maxNum, arr[i]);
    
    vector<int> bit(maxNum+1, 0);
    loopBack(i, n-1, 0) {
        ans += sum(arr[i]-1, bit);
        add(arr[i], 1, bit);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> arr(n);
        loop(i, 0, n) cin >> arr[i];
        cout << solve(arr) << "\n";
    }
}