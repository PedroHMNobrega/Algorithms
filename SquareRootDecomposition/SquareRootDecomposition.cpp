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

vector<int> blocks;
int blockSize;

vector<int> build(vector<int> a) {
    blockSize = ceil(sqrt(a.size()));
    vector<int> auxBlocks(blockSize, 0);
    loop(i, 0, a.size()) 
        auxBlocks[i / blockSize] += a[i];
    return auxBlocks;
}

void update(vector<int> &a, int idx, int newValue) {
    int oldValue = a[idx];
    blocks[idx/blockSize] += newValue - oldValue;
    a[idx] = newValue;
}

ll query(vector<int> &a, int l, int r) {
    if(l == r) return a[l];
    ll sum = 0;
    int startBlock = l / blockSize;
    int endBlock = r / blockSize;
    
    loop(i, startBlock+1, endBlock)
        sum += blocks[i];

    int startIndex = l % blockSize;
    int endIndex = r % blockSize;
    
    loop(i, startIndex, blockSize)
        sum += a[(startBlock * blockSize) + i];
    
    loop(i, 0, endIndex+1)
        sum += a[(endBlock * blockSize) + i];

    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q, type, x, y;

    cin >> n;
    vector<int> nums(n);
    loop(i, 0, n) cin >> nums[i];

    blocks = build(nums);

    cin >> q;
    while(q--) {
        cin >> type >> x >> y;
        if(type == 0) 
            update(nums, x, y);
        else 
            cout << query(nums, x, y) << '\n';
    }
}