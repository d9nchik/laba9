#include <iostream>
#include <string>

using namespace std;

string userInput();

int create_words(string data, string *words);

int chooseWords(string *words, int size);


int main() {
    const int maxWords = 20;
    string data = userInput();
    string words[maxWords];
    int size = create_words(data, words);
    int found = chooseWords(words, size);
    cout << "Знайдених слів: " << found;
}

string userInput() {
    cout << "Введіть строку: ";
    string text;
    getline(cin, text);

    return text;
}

int create_words(string data, string *words) {
    string dirtyWords[30];
    int dirtWordCounter = 0;
    int positionStart = 0;
    cout << "Список слів: " << endl;
    int position = 0;
    while (data[position] != '\0') {
        if (data[position] == ',' || data[position] == '.' || data[position] == ' ') {
            string a;
            for (int i = positionStart; i < position; ++i) {
                a+=data[i];
            }
            positionStart = position + 1;
            dirtyWords[dirtWordCounter] = a;
            dirtWordCounter++;
        }
        position++;
    }
    string a;
    for (int i = positionStart; i < position; ++i) {
        a += data[i];
    }
    dirtyWords[dirtWordCounter] = a;
    dirtWordCounter++;
    int counter = 0;
    for (int j = 0; j < dirtWordCounter; ++j) {
        if (!dirtyWords[j].empty()) {
            cout << dirtyWords[j] << endl;
            words[counter] = dirtyWords[j];
            counter++;
        }

    }
    cout << "Кількість слів:" << counter << endl;
    return counter;
}

int chooseWords(string *words, int size) {
    cout << "Введіть групу символів з яких мають починатися слова: ";
    string symbols;
    cin >> symbols;
    int counter = 0;
    int width = symbols.size();
    cout << "Співпадіння: " << endl;
    for (int i = 0; i < size; ++i) {
        int partCorrect = 0;
        for (int j = 0; j < width; ++j) {

            if (words[i][j] == symbols[j])
                partCorrect++;

        }
        if (partCorrect == width) {
            cout << words[i] << endl;
            counter++;
        }

    }
    return counter;
}
