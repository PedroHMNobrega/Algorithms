#include<bits/stdc++.h>
#define loop(i, a, b) for(int i = a; i < b; i++)
using namespace std;

struct TrieNode {
    struct TrieNode* children[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        loop(i, 0, 26) children[i] = NULL;
    }
};

void trieAdd(string word, struct TrieNode *root) {
    loop(i, 0, word.size()) {
        int index = word[i]-'a';
        if(root->children[index]==NULL)
            root->children[index] = new TrieNode();
        root=root->children[index];
    }
    root->isWord = true;
}

bool isEmpty(TrieNode* node) {
    loop(i, 0, 26) {
        if(node->children[i]) return false;
    }
    return true;
}

TrieNode* remove(TrieNode *root, string num, int depth) {
    if(!root) return NULL;

    if(depth == num.size()) {
        if(root->isWord)
            root->isWord = false;
        if(isEmpty(root)) {
            delete(root);
            root = NULL;
        }
        return root;
    }

    int index = num[depth] - 'a';
    root->children[index] = remove(root->children[index], num, depth+1);
    if(isEmpty(root) and root->isWord == false) {
        delete(root);
        root = NULL;
    }
    return root;
}

bool solve(string word, struct TrieNode *root) {
    loop(i, 0, word.size()) {
        int index = word[i] - 'a';
        if(root->children[index] == NULL)
            return false;
        root = root->children[index];
    }
    if(root->isWord) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("in.txt", "r", stdin);
    struct TrieNode *trie = new TrieNode();  
}