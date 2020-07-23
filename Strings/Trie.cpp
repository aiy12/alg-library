int trie[MAXN][26];
bool endOfWord[MAXN];
int cnt = 1;

void insert(string s) {
    int pos = 0;
    
    for (char c : s) {
        if (trie[pos][c - 'a'] == 0) 
            trie[pos][c - 'a'] = cnt++;
        pos = trie[pos][c - 'a'];
    }
    
    endOfWord[pos] = true;
}

bool search(string s) {
    int pos = 0;
    
    for (char c : s) {
        if (trie[pos][c - 'a'] == 0) 
            return false;
        pos = trie[pos][c - 'a'];
    }
    
    return endOfWord[pos];
}
