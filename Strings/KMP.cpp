#include <bits/stdc++.h>
using namespace std;

vector<int> criaAuxArr(string s) {
    int i = 0, j = 1;
    vector<int> arr(s.size());
    arr[0] = 0;
    
    while(j < s.size()) {
        while(i > 0 and s[i] != s[j]) i = arr[i-1];
        if(s[i] == s[j]) {
            arr[j] = i+1;
            i++;
        } else arr[j] = i;
        j++;
    }
    return arr;
}

int kmp(string s, string sub, vector<int> auxArr) {
    int i = 0, j = 0;
    while(i < s.size()) {
        if(s[i] == sub[j]) {
            if(j == sub.size()-1) return i - j;
            i++; j++;
        } else {
            if(j != 0) j = auxArr[j-1];
            else i++;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = criaAuxArr("ABACABA");
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << '\n';
    cout << kmp("abxabcabcaby", "abcabc", arr) << '\n';
}