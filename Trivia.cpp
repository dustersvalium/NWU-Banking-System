/*
Name: Your Name
Surname: Your Surname
Student Number: 12345678
CMPG121 – Structured Programming Test 2
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function prototypes
char getValidAnswer();
void askQuestionAndCheckAnswer(const string &question, char correctAnswer, int &correctCount);
void playGame(string questions[], char answers[], int size);
void displayQuestionsAndAnswers(string questions[], char answers[], int size);
void deleteQuestion(string questions[], char answers[], int &size);
void displayMenu();


// Reads and validates user input (A, B, or C)
char getValidAnswer() {
    char ans;
    do {
        cout << "Enter A, B, or C: ";
        cin >> ans;
        ans = toupper(ans);  // handle lowercase input
    } while (ans != 'A' && ans != 'B' && ans != 'C');
    return ans;
}

// Ask a single question and update score
void askQuestionAndCheckAnswer(const string &question, char correctAnswer, int &correctCount) {
    cout << question << endl;
    char ans = getValidAnswer();
    if (ans == correctAnswer) {
        cout << "Correct!\n\n";
        correctCount++;
    } else {
        cout << "Incorrect. Correct answer is " << correctAnswer << "\n\n";
    }
}

// Loop through all questions and play game
void playGame(string questions[], char answers[], int size) {
    int correctCount = 0;

    for (int i = 0; i < size; i++) {
        askQuestionAndCheckAnswer(questions[i], answers[i], correctCount);
    }

    cout << "Game over!\n";
    cout << "You got " << correctCount << " correct and " 
         << (size - correctCount) << " incorrect.\n\n";
}

// Display all questions and their answers
void displayQuestionsAndAnswers(string questions[], char answers[], int size) {
    cout << "\nList of Questions:\n";
    for (int i = 0; i < size; i++) {
        cout << (i+1) << ". " << questions[i] 
             << " (Correct Answer: " << answers[i] << ")\n";
    }
    cout << endl;
}

// Delete a question by index
void deleteQuestion(string questions[], char answers[], int &size) {
    int index;
    cout << "Enter the number of the question you want to delete (1-" << size << "): ";
    cin >> index;

    if (index < 1 || index > size) {
        cout << "Invalid question number.\n";
        return;
    }

    // Shift elements left
    for (int i = index - 1; i < size - 1; i++) {
        questions[i] = questions[i + 1];
        answers[i] = answers[i + 1];
    }
    size--;

    cout << "Question deleted.\n\n";
}

// Display menu
void displayMenu() {
    cout << "Basketball Trivia Game\n\n"
         << "Menu\n"
         << "1. Play game\n"
         << "2. Display questions\n"
         << "3. Delete question\n"
         << "4. Exit\n";
}


int main() {
    const int MAX = 10; // maximum capacity
    int size = 4;       // actual number of questions

    // Questions array
    string questions[MAX] = {
        "How many players on a basketball team?\n A. 5  B. 6  C. 7",
        "How many points for a basket?\n A. 1  B. 2  C. 3",
        "How many points for a free throw?\n A. 1  B. 2  C. 3",
        "What's the size of an NBA basketball?\n A. 5  B. 6  C. 7"
    };

    // Correct answers
    char answers[MAX] = {'A', 'B', 'A', 'C'};

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                playGame(questions, answers, size);
                break;
            case 2:
                displayQuestionsAndAnswers(questions, answers, size);
                break;
            case 3:
                deleteQuestion(questions, answers, size);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid entry. Please try again.\n\n";
        }
    } while (choice != 4);

    return 0;
}
