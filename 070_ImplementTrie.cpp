// Topic: Design / Trie
// Implement Trie (Prefix tree) with insert, search, startsWith
// Time Complexity: insert/search O(L) where L is word length
// Space Complexity: O(total chars)

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    bool end = false;
    array<TrieNode*, 26> nxt{};
    TrieNode() { nxt.fill(nullptr); }
};

class Trie
{
    TrieNode* root;

   public:
    Trie() : root(new TrieNode()) {}
    void insert(const string& w)
    {
        TrieNode* p = root;
        for (char c : w)
        {
            int i = c - 'a';
            if (!p->nxt[i])
                p->nxt[i] = new TrieNode();
            p = p->nxt[i];
        }
        p->end = true;
    }
    bool search(const string& w)
    {
        TrieNode* p = root;
        for (char c : w)
        {
            int i = c - 'a';
            if (!p->nxt[i])
                return false;
            p = p->nxt[i];
        }
        return p->end;
    }
    bool startsWith(const string& pref)
    {
        TrieNode* p = root;
        for (char c : pref)
        {
            int i = c - 'a';
            if (!p->nxt[i])
                return false;
            p = p->nxt[i];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << "\n";    // 1
    cout << trie.search("app") << "\n";      // 0
    cout << trie.startsWith("app") << "\n";  // 1
    trie.insert("app");
    cout << trie.search("app") << "\n";  // 1
    return 0;
}
