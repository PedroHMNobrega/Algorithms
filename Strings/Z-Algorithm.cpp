#include <bits/stdc++.h>
using namespace std;

vector<int> calculaZ(string s) {
    vector<int> z(s.size());
    int l = 0, r = 0;
	for(int i = 1; i < s.size(); i++){
		z[i] = max(0, min(z[i-l], r-i+1));
		while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]){
			l = i; r = i+z[i]; z[i]++;
		}
	}
	
    z[0] = 0;
    return  z;
}

vector<int> matchPattern(string iniS, string pattern) {
    string s = pattern + '$' + iniS;
    vector<int> ans;
    vector<int> Z = calculaZ(s);
    for(int i = 0; i < Z.size(); i++) {
        if(Z[i] == pattern.size()) 
            ans.push_back(i - pattern.size() - 1);
    }
    return ans;
}

int main() {
    string text = "aaabcxyzaaaabczaaczabbaaaaaabc";
    string pattern = "aaabc";
    vector<int> ans = matchPattern(text, pattern);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << '\n';
}