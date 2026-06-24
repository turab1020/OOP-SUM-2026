#include <iostream>
using namespace std;

bool areEqual(char first[], char second[]) {
    int i = 0;

    while (first[i] != '\0' && second[i] != '\0') {
        if (first[i] != second[i]) {
            return false;
        }

        i++;
    }

    if (first[i] == '\0' && second[i] == '\0') {
        return true;
    }

    return false;
}

void removeStopWords(char text[], char stop_words[][6], int size) {
    int i = 0;
    int j = 0;
    int len = 0;

    while (text[len] != '\0') {
        len++;
    }

    while (i < len) {
        char word[50] = { 0 };
        int wIdx = 0;

        while (i < len && text[i] != ' ' && text[i] != '\0') {
            word[wIdx] = text[i];
            wIdx++;
            i++;
        }

        word[wIdx] = '\0';

        bool isStop = false;

        for (int k = 0; k < size; k++) {
            if (areEqual(word, stop_words[k])) {
                isStop = true;
                break;
            }
        }

        if (!isStop && wIdx > 0) {
            if (j > 0) {
                text[j] = ' ';
                j++;
            }

            int m = 0;

            while (word[m] != '\0') {
                text[j] = word[m];
                j++;
                m++;
            }
        }

        while (i < len && text[i] == ' ') {
            i++;
        }
    }

    text[j] = '\0';
}

void display_word_frequency(char text[]) {
    char uniqueWords[100][50] = { 0 };
    int frequencies[100] = { 0 };
    int uniqueCount = 0;
    int i = 0;

    while (text[i] != '\0') {
        char word[50] = { 0 };
        int wIdx = 0;

        while (text[i] != ' ' && text[i] != '\0') {
            word[wIdx] = text[i];
            wIdx++;
            i++;
        }

        word[wIdx] = '\0';

        if (wIdx > 0) {
            int foundIndex = -1;

            for (int j = 0; j < uniqueCount; j++) {
                if (areEqual(uniqueWords[j], word)) {
                    foundIndex = j;
                    break;
                }
            }

            if (foundIndex == -1) {
                int k = 0;

                while (word[k] != '\0') {
                    uniqueWords[uniqueCount][k] = word[k];
                    k++;
                }

                uniqueWords[uniqueCount][k] = '\0';
                frequencies[uniqueCount] = 1;
                uniqueCount++;
            }

            else {
                frequencies[foundIndex]++;
            }
        }

        while (text[i] == ' ') {
            i++;
        }
    }

    for (int i = 0; i < uniqueCount; i++) {
        cout << uniqueWords[i] << " : " << frequencies[i] << endl;
    }
}

void find_longest_word(char text[]) {
    int maxLen = 0;
    char longest[50] = { 0 };
    int i = 0;

    while (text[i] != '\0') {
        char word[50] = { 0 };
        int wIdx = 0;

        while (text[i] != ' ' && text[i] != '\0') {
            word[wIdx] = text[i];
            wIdx++;
            i++;
        }

        word[wIdx] = '\0';

        if (wIdx > maxLen) {
            maxLen = wIdx;
            int k = 0;

            while (word[k] != '\0') {
                longest[k] = word[k];
                k++;
            }

            longest[k] = '\0';
        }

        while (text[i] == ' ') {
            i++;
        }
    }

    cout << "Longest word: " << longest << endl;
}

int main() {
    char text[501] = "learning programming in fast for fast students with passion";
    char stop_words[5][6] = { "to", "in", "on", "for", "with" };

    cout << "Original: " << text << endl;
    removeStopWords(text, stop_words, 5);
    cout << "After removing stop words: " << text << endl << endl;

    cout << "Word Frequencies:" << endl;
    display_word_frequency(text);
    cout << endl;

    find_longest_word(text);

    return 0;
}