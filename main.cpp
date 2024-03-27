#include <iostream>
#include <chrono>
#include <string>
#include <cstring>

using namespace std;

int main() {
    cout << "Welcome! Type out the following text:\n";
    cout << " ";
    
    // Sample text
    string sampleText = "BYU-Idaho's spiritual environment is characterized by a weekly campus-wide devotional, immersive student wards, a temple within walking distance, prayers in class, and numerous leadership opportunities. Your personal growth, well-being, and success are the focal point at BYU-Idaho. With a student-focused mission to help students achieve, BYU-Idaho offers you a valuable educational experience found nowhere else.\n";
    cout << sampleText << endl;
    
    cout << "When you are done, press Enter:\n";

    string input;
    int wordCount = 0;
    auto start = chrono::steady_clock::now();

    getline(cin, input);

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);

    cout << "You entered the text in " << duration.count() << " seconds.\n";
    
    char* cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());
    char* word = strtok(cInput, " ");
    while (word != nullptr) {
        ++wordCount;
        word = strtok(nullptr, " ");
    }
    delete[] cInput;

    cout << "You entered " << wordCount << " words.\n";

    double wordsPerMinute = (wordCount * 60.0) / duration.count();
    cout << "Ваша скорость печати составляет примерно " << wordsPerMinute << " слов в минуту.\n";

    return 0;
}
