#include <iostream>
#include <fstream>
#include <cctype>
#include "AVLTree.h"

using namespace std;

bool isValidChar(char c) {
    return isalpha(c);
}

string normalize(const string& s) {
    string out;
    for (char c : s)
        if (isalpha(c))
            out += tolower(c);
    return out;
}

int main() {
    AVLTree dict[26];

    ifstream dictFile("random_dictionary.txt");
    if (!dictFile) {
        cout << "Failed to open dictionary file\n";
        return 1;
    }

    string word;
    while (dictFile >> word) {
        int idx = word[0] - 'a';
        if (idx >= 0 && idx < 26)
            dict[idx].insert(word);
    }
    dictFile.close();

    ifstream book("oliver.txt");
    if (!book) {
        cout << "Failed to open book file\n";
        return 1;
    }

    int wdFound = 0, wdNotFound = 0;
    int compsFound = 0, compsNotFound = 0;

    string token;
    char c;
    while (book.get(c)) {
        if (isValidChar(c)) {
            token += tolower(c);
        } else if (!token.empty()) {
            int idx = token[0] - 'a';
            if (idx >= 0 && idx < 26) {
                int comps = dict[idx].search(token);
                if (comps > 0) {
                    wdFound++;
                    compsFound += comps;
                } else {
                    wdNotFound++;
                    compsNotFound += -comps;
                }
            }
            token.clear();
        }
    }
    book.close();

    cout << "Words Found: " << wdFound << endl;
    cout << "Words Not Found: " << wdNotFound << endl;
    cout << "Comparisons (Found): " << compsFound << endl;
    cout << "Comparisons (Not Found): " << compsNotFound << endl;

    if (wdFound > 0)
        cout << "Average Comparisons (Found): "
             << (double)compsFound / wdFound << endl;

    if (wdNotFound > 0)
        cout << "Average Comparisons (Not Found): "
             << (double)compsNotFound / wdNotFound << endl;

    return 0;
}
