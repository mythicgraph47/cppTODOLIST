#include<iostream>
#include<random>
#include<string>
#include<vector>

using namespace std;

int choice = 0;
vector<string> tasks;
string pendTasks;
int removeNum;
int highlight;

int getRandomNumber() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100);
    return distribution(generator);
}

void displayMenu() {
    cout << "\n1. View Tasks" << endl;
    cout << "2. Add Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Highlight a task" << endl;
    cout << "5. Random" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        choice = -1;
    }
}

int main() {
    cout << "=== MythicGraph's TODO List ===" << endl;

    while (choice != 6) {
        displayMenu();

        if (choice == 1) {
            if (tasks.empty()) {
                cout << "Your task list is empty. Add something!" << endl;
            } else {
                for (size_t x = 0; x < tasks.size(); ++x) {
                    cout << x + 1 << ". " << tasks[x] << endl;
                }
            }
        }
        else if (choice == 2) {
            cin.ignore(10000, '\n');
            cout << "Enter your pending task: ";
            getline(cin, pendTasks);

            if (pendTasks.empty()) {
                cout << "Input cannot be empty" << endl;
            } else {
                tasks.push_back(pendTasks);
                cout << "Task added!" << endl;
            }
        }
        else if (choice == 3) {
            if (tasks.empty()) {
                cout << "Empty list..." << endl;
            } else {
                for (size_t x = 0; x < tasks.size(); ++x) {
                    cout << x + 1 << ". " << tasks[x] << endl;
                }
                cout << "Which task do you want to delete? ";
                cin >> removeNum;

                if (removeNum < 1 || removeNum > (int)tasks.size()) {
                    cout << "Invalid task number." << endl;
                } else {
                    tasks.erase(tasks.begin() + (removeNum - 1));
                    cout << "Task terminated." << endl;
                }
            }
        }
        else if (choice == 4) {
            if (tasks.empty()) {
                cout << "Empty list..." << endl;
            } else {
                for (size_t x = 0; x < tasks.size(); ++x) {
                    cout << x + 1 << ". " << tasks[x] << endl;
                }
                cout << "Enter Task Number: ";
                cin >> highlight;

                if (highlight < 1 || highlight > (int)tasks.size()) {
                    cout << "Invalid task number." << endl;
                } else if (tasks[highlight - 1].rfind("* ", 0) == 0) {
                    cout << "Already highlighted!" << endl;
                } else {
                    tasks[highlight - 1] = "* " + tasks[highlight - 1];
                    cout << "Task highlighted!" << endl;
                }
            }
        }
        else if (choice == 5) {
            cout << "Random number: " << getRandomNumber() << endl;
        }
        else if (choice == 6) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}