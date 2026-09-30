#include <iostream>
#include <vector>
#include <string>
using namespace std;

int choice;
vector<string> tasks;

void displayMenu() {
    cout << "\n--- To-Do List ---" << endl;
    cout << "1. View Tasks" << endl;
    cout << "2. Add Task" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter Choice (1-3): ";
    cin >> choice;
}

int main() {
    while (choice != 3) {
        displayMenu();

        if (choice == 1) {
            if (tasks.empty()) {
                cout << "No tasks found." << endl;
            } else {
                cout << "\nYour tasks:" << endl;
                for (size_t x = 0; x < tasks.size(); ++x) {
                    cout << x + 1 << ". " << tasks[x] << endl;
                }
            }
        }
        else if (choice == 2) {
            cout << "Enter your pending task: ";
            cin.ignore(10000, '\n');
            string newTask;
            getline(cin, newTask);

            if (newTask.empty()) {
                cout << "Task cannot be empty." << endl;
            } else {
                tasks.push_back(newTask);
                cout << "Task added successfully." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}
