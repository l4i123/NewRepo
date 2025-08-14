#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <cctype>
using namespace std;

class TextProcessor {
private:
    set<string> words;
public:
    void readLineExtractWords() {
        string line;
        getline(cin, line);

        int n = (int)line.size();
        for (int i = 0; i < n; i++) {
            while (i < n && !isalpha(line[i])) {
                i++;
            }
            if (i >= n) break;

            int start = i;
            while (i < n && isalpha(line[i])) {
                i++;
            }
            string word = line.substr(start, i - start);

            words.insert(word);
        }
    }

    const set<string>& getWords() const {
        return words;
    }
};

class AlphabetChecker {
private:
    vector<char> letters;   // запазваме буквите в реда на въвеждане, с оригиналния case
    set<char> alphabetSet;  // за бърза проверка на наличието (малки букви)
public:
    void readAlphabet() {
        string line;
        while (true) {
            getline(cin, line);
            if (line == ".") break;
            if (!line.empty()) {
                char c = line[0];
                char lower = tolower(c);
                if (alphabetSet.count(lower) == 0) {
                    letters.push_back(c);      // запазваме оригиналния символ
                    alphabetSet.insert(lower); // проверяваме по малка буква
                }
            }
        }
    }

    const vector<char>& getLetters() const {
        return letters;
    }

    const set<char>& getAlphabetSet() const {
        return alphabetSet;
    }
};

class TogetherMapped {
private:
    map<char, set<string>> letterToWords;
public:
    void buildIndex(const set<string>& words, const set<char>& alphabet) {
        letterToWords.clear();

        for (const auto& word : words) {
            set<char> uniqueLettersInWord;
            for (char c : word) {
                uniqueLettersInWord.insert(tolower(c));
            }

            for (char c : uniqueLettersInWord) {
                if (alphabet.count(c) > 0) {
                    letterToWords[c].insert(word);
                }
            }
        }
    }

    const set<string>& getWordsForLetter(char letter) const {
        static const set<string> emptySet;
        char lower = tolower(letter);
        auto it = letterToWords.find(lower);
        if (it != letterToWords.end()) {
            return it->second;
        }
        return emptySet;
    }
};

int main() {
    TextProcessor tp;
    tp.readLineExtractWords();

    AlphabetChecker ac;
    ac.readAlphabet();

    TogetherMapped tm;
    tm.buildIndex(tp.getWords(), ac.getAlphabetSet());

    for (char letter : ac.getLetters()) {
        const auto& wordsForLetter = tm.getWordsForLetter(letter);

        if (wordsForLetter.empty()) {
            cout << "---\n";
        }
        else {
            bool first = true;
            for (const auto& w : wordsForLetter) {
                if (!first) cout << " ";
                cout << w;
                first = false;
            }
            cout << "\n";
        }
    }

    return 0;
}
