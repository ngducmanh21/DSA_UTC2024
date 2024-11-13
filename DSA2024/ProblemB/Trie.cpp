#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef TRIE_CPP
#define TRIE_CPP

// Dinh nghia cau truc TrieNode
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

// Tao lop Trie
class Trie {
private:
    TrieNode* root;

    // Ham de quy luu tu dien vao file
    void saveDictionary(TrieNode* node, string& currentWord, ofstream& outFile) {
        if (node->isEndOfWord) {
            outFile << currentWord << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                currentWord.push_back('a' + i);
                saveDictionary(node->children[i], currentWord, outFile);
                currentWord.pop_back();
            }
        }
    }

    // Ham de quy lay tat ca cac tu tu Trie
    void getAllWordsHelper(TrieNode* node, string& currentWord, vector<string>& words) {
        if (node->isEndOfWord) {
            words.push_back(currentWord);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                currentWord.push_back('a' + i);
                getAllWordsHelper(node->children[i], currentWord, words);
                currentWord.pop_back();
            }
        }
    }

public:
    Trie() { root = new TrieNode(); }

    // Ham them tu vao Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index])
                current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // Ham kiem tra tu co ton tai trong Trie hay khong
    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index])
                return false;
            current = current->children[index];
        }
        return current->isEndOfWord;
    }

    // Ham nap tu dien tu file vao Trie
    bool loadDictionary(const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cerr << "Loi: Khong the mo file " << filename << endl;
            return false;
        }
        string word;
        while (inFile >> word) {
            insert(word);
        }
        inFile.close();
        return true;
    }

    // Ham lay tat ca cac tu trong Trie
    vector<string> getAllWords() {
        vector<string> words;
        string currentWord;
        getAllWordsHelper(root, currentWord, words);
        return words;
    }

    // Ham ghi tu dien vao file
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            string currentWord;
            saveDictionary(root, currentWord, outFile);
            outFile.close();
        }
    }

    // Ham tinh khoang cach Levenshtein
    int levenshteinDistance(const string& s1, const string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        return dp[m][n];
    }

    // Ham tim tu gan dung nhat
    string findClosestWord(const string& misspelledWord) {
        vector<string> candidates = getAllWords();
        string bestMatch;
        int minDistance = INT_MAX;

        for (const auto& word : candidates) {
            int distance = levenshteinDistance(misspelledWord, word);
            if (distance < minDistance) {
                minDistance = distance;
                bestMatch = word;
            }
        }
        return bestMatch;
    }

    // Ham tach tu tu doan van
    vector<string> splitWords(const string& text) {
        vector<string> words;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!word.empty())
                words.push_back(word);
        }
        return words;
    }
};

#endif // TRIE_CPP
