#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct Question {
    string question;
    vector<string> choices;
    char correctAnswer;
};

// Ask one question, return true if answered correctly
bool askQuestion(Question q) {
    cout << "\n" << q.question << "\n";

    for (int i = 0; i < q.choices.size(); i++) {
        cout << q.choices[i] << "\n";
    }

    cout << "Your answer: ";

    char userAnswer;
    cin >> userAnswer;

    userAnswer = toupper(userAnswer);

    if (userAnswer == q.correctAnswer) {
        cout << "Correct!\n";
        return true;
    } else {
        cout << "Incorrect.\n";
        cout << "Correct answer: " << q.correctAnswer << "\n";
        return false;
    }
}

void runQuiz(vector<Question> questions) {
    int score = 0;
    int total = questions.size();

    cout << "\n===== C++ Quiz Game =====\n";

    for (int i = 0; i < total; i++) {
        if (askQuestion(questions[i])) {
            score++;
        }
    }

    cout << "\n===== Quiz Finished =====\n";
    cout << "Your score: " << score << "/" << total << "\n";

    if (score == total) {
        cout << "Excellent work!\n";
    } else if (score >= (total + 1) / 2) {
        cout << "Good job!\n";
    } else {
        cout << "Keep practicing!\n";
    }
}

int main() {
    vector<Question> questions;

    questions.push_back({
        "What is 2 + 2?",
        { "A. 3", "B. 4", "C. 5", "D. 6" },
        'B'
    });

    questions.push_back({
        "Which language are we using?",
        { "A. Python", "B. Java", "C. C++", "D. HTML" },
        'C'
    });

    questions.push_back({
        "Which symbol ends most C++ statements?",
        { "A. .", "B. :", "C. ;", "D. ," },
        'C'
    });

    questions.push_back({
        "Which of these is a correct C++ data type?",
        { "A. string", "B. text", "C. word", "D. letter" },
        'A'
    });

    questions.push_back({
        "Which keyword returns a value from a function?",
        { "A. make", "B. function", "C. int", "D. return" },
        'D'
    });

    runQuiz(questions);

    return 0;
}