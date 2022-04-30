#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

// tire node

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndofWord;
};

struct TrieNode *
getNode() {
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndofWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndofWord = true;
}

bool search(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            return false;
        }
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->isEndofWord;
}

int main() {
    string keys[] = { "the",
                      "a",
                      "there",
                      "answer",
                      "any",
                      "by",
                      "lettuce",
                      "rhinoceros" };
    int n = sizeof(keys)/sizeof(keys[0]);
    
    // construct trie
    struct TrieNode *root = getNode();
    for (int i=0; i<n; i++){
        insert(root, keys[i]);
    }
    search(root, "the") ? cout<<"yes\n" : cout<<"no\n";
    search(root, "theh") ? cout<<"yes\n" : cout<<"no\n";

}
