#include<iostream>
#include<random>
#include<string>
#include<vector>

using namespace std;

//Declarations
int choice = 0;
vector<string> tasks;
string pendTasks;
int removeNum;
int highlight;

//Display Menu
void displayMenu() {
    cout << "View Tasks" << endl;
    cout << "Add Tasks" << endl;
    cout << "Delete Tasks" << endl;
    cout << "Highlight Task" << endl;
    cout << "Random (BETA TEST)" << endl;
    cout << "Exit Program" << endl;

    cout << "Enter (1-6): ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        choice = -1;
    }

}


//Main Body
int main() {
    while (true) {
    displayMenu();

    if (choice == 1) {

        if (tasks.empty()) {
            cout << "Nothing In the list. Add Something!" << endl;
            

        } else {
        for (size_t x = 0; x < tasks.size(); ++x) {
            cout << x + 1 << ". " << tasks[x] << endl; 
        }
    }

    } else if (choice == 2) {
        cin.clear();
        cout << "Enter Pending Task: ";
        getline(cin, pendTasks);

        if (pendTasks.empty()) {
            cout << "Please, Input cannot be Empty." << endl;
        } else {
            tasks.push_back(pendTasks);
            cout << "Task Added!" << endl;
        }
    } else if (choice == 3) {
        if (tasks.empty()) {
            cout << "List is empty. Add Something! ";
        } else {
            for (size_t x = 0; x < tasks.size(); ++x) {
                cout << x + 1 << ". " << tasks[x] << endl;

                cout << "Which task do you want to remove?";
                cin >> removeNum;

                if (removeNum < 1 || removeNum > tasks.size()) {
                    cout << "Invalid Input." << endl;
                } else {
                    tasks.erase((tasks.begin() + (removeNum - 1)));
                    cout << "Task has been terminated. " << endl;
                }
            }
        }
    } else if (choice == 4) {
        if (tasks.empty()) {
            cout << "Nothing in the list." << endl;

        } else {
            for (size_t x = 0; x < tasks.size(); ++x) {
                cout << x + 1 << ". " << endl;
            }

            cout << "Enter Task Number: " << endl;
            cin >> highlight;

            if (hightlight < 1 || highlight > (int)tasks.size()) {
                cout << "Invalid Task Number" << endl;
            }
        }
    }

}

}