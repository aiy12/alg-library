vector<int> precomp(string &pat) {
    vector<int> ret(pat.length());
    ret[0] = 0;
    int len = 0; // length of prev longest prefix suffix
    for (int i = 1; i < pat.length(); ) {
        if (pat[i] == pat[len]) {
            len++;
            ret[i] = len;
            i++;
        } else if (len != 0) {
            len = ret[len - 1];
        } else {
            ret[i] = 0; i++;
        }
    }
    return ret;
}

void KMP(string &text, string &pat) {
    vector<int> lps = precomp(pat);
    int i = 0, j = 0;
    while (i < text.length()) {
        if (text[i] == pat[j]) {
            i++; j++;
        }
        if (j == pat.length()) {
            // solution found
            cout << "sol at index: " << i-j << endl;
            j = lps[j - 1];
        } else if (i < text.length() && text[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return;
}
