#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include "Trie.cpp"
using namespace std;

int main() {
    Trie trie;
    string dictionaryFile = "C:\\Users\\OS\\CLionProjects\\ProblemB\\dictionary.txt";

    if (trie.loadDictionary(dictionaryFile)) {
        cout << "Tu dien da duoc nap tu file: " << dictionaryFile << endl;
    } else {
        cerr << "Khong the nap tu dien tu file: " << dictionaryFile << endl;
        return 1;
    }

    cout << "Nhap doan van ban can kiem tra loi chinh ta: ";
    string inputText;
    getline(cin, inputText);

    vector<string> words = trie.splitWords(inputText);
    unordered_set<string> misspelledWords;

    for (const string& word : words) {
        if (!trie.search(word)) {
            misspelledWords.insert(word);
        }
    }

    if (misspelledWords.empty()) {
        cout << "Khong co loi chinh ta nao duoc phat hien." << endl;
    } else {
        cout << "Cac tu sai chinh ta va goi y tu dung:" << endl;
        for (const string& word : misspelledWords) {
            string suggestion = trie.findClosestWord(word);
            cout << "Sai: " << word << " -> Goi y: " << suggestion << endl;
        }
    }

    string outputDictionaryFile = "C:\\Users\\OS\\CLionProjects\\ProblemB\\output_dictionary.txt";
    trie.saveToFile(outputDictionaryFile);
    cout << "Tu dien da duoc ghi vao file: " << outputDictionaryFile << endl;

    return 0;
}
