#include <iostream>
#include <chrono>
#include <string>
#include <cctype>

using namespace std;

bool isValidCharacter(char c) {
    return isalnum(c) || c == ',' || c == '.' || c == '-';
}

int main() {
    cout << "Welcome! Type out the following text:\n";
    cout << " ";
    
    // sample text (from byui.com)
    string sampleText = "BYU-Idaho's spiritual environment is characterized by a weekly campus-wide devotional, immersive student wards, a temple within walking distance, prayers in class, and numerous leadership opportunities. Your personal growth, well-being, and success are the focal point at BYU-Idaho. With a student-focused mission to help students achieve, BYU-Idaho offers you a valuable educational experience found nowhere else.\n";
    cout << sampleText << endl;
    
    cout << "When you are done, press Enter:\n";

    string input;
    int wordCount = 0;
    int sentenceCount = 0;
    int charCount = 0;
    auto start = chrono::steady_clock::now();

    getline(cin, input);

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);

    cout << "You entered the text in " << duration.count() << " seconds.\n";
    
    // Counting words
    size_t pos = 0;
    while ((pos = input.find(' ', pos)) != string::npos) {
        ++wordCount;
        ++pos;
    }
    ++wordCount; // count the last word after the final space

    // count sentences
    for (char c : input) {
        if (c == '.' || c == '?' || c == '!') {
            ++sentenceCount;
        }
    }

    // how many characters
    charCount = input.size();

    cout << "You entered " << wordCount << " words.\n";
    cout << "You entered " << sentenceCount << " sentences.\n";
    cout << "You entered " << charCount << " characters.\n";

    double wordsPerMinute = (wordCount * 60.0) / duration.count();
    cout << "Your typing speed is approximately " << wordsPerMinute << " words a minute.\n";

    // display input summary
    cout << "\nSummary of your input:\n";
    cout << "-----------------------\n";
    cout << "Words: " << wordCount << endl;
    cout << "Sentences: " << sentenceCount << endl;
    cout << "Characters: " << charCount << endl;
    cout << "Typing speed: " << wordsPerMinute << " words per minute\n";

    // search for specific words
    char searchChoice;
    do {
        string searchWord;
        cout << "\nDo you want to search for specific words in your text? (y/n): ";
        cin >> searchChoice;
        if (tolower(searchChoice) == 'y') {
            cout << "Enter the word you want to search for: ";
            cin >> searchWord;
            size_t found = input.find(searchWord);
            int count = 0;
            size_t pos = 0;
            while ((pos = input.find(searchWord, pos)) != string::npos) {
                ++count;
                ++pos;
            }
            cout << "The word '" << searchWord << "' was found " << count << " time(s) in the text.\n";
        }
    } while (tolower(searchChoice) == 'y');

    // replace specific word (whynot)
 
    return 0;
}
