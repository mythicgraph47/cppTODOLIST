#include<iostream>
#include<random>
#include<string>
#include<vector>

using namespace std;

//Declarations
int choice = 0;
string strChoice;
vector<string> tasks;
string pendTasks;
int removeNum;
int highlight;

int getRandomNumber() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100);

    int random_Num = distribution(generator);
    return random_Num;
}
//Display Menu
void displayMenu() {
    cout << "1. View Tasks" << endl;
    cout << "2. Add Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Highlight a task" << endl;
    cout << "5. Random" << endl;
    cout << "6. Exit" << endl;

    cout << "Enter choice: ";
    cin >> choice;
    cin >> strChoice;

} 

//Main 

int main() {
    cout << "=== MythicGraph's TODO List ===" << endl;
    while (choice != 6) {
        displayMenu();

        if (choice == 1) {
            if (tasks.empty()) {
                cout << "Your task list is empty. Add Something! " << endl;
                //return 0;
            } else {
                for (size_t x = 0; x < tasks.size(); ++x) {
                    cout << x + 1 << ". " << tasks[x] << endl;
                }
            }
        } else if (choice == 2) {
            cin.ignore(10000, '\n');
            cout << "Enter your pending task: " << endl;
            getline(cin, pendTasks);

            if (pendTasks.empty()) {
                cout << "Input cannot be empty" << endl;
            } else {
                tasks.push_back(pendTasks);
            }


        } else if (choice == 3) {
            if (tasks.empty()) {
                cout << "Empty list..." << endl;
            } else {
                for (size_t x = 0; x < tasks.size(); ++x) {
                cout << x + 1 << ". " << tasks[x] << endl;
            }
                cout << "Which task do you want to delete? " << endl;
                cin >> removeNum;
                tasks.erase(tasks.begin() + (removeNum - 1));
                cout << "Tasks Terminated" << endl;
                cout << "--------------------------" << endl;

            }
        } else if (choice == 4) {
            for (size_t x = 0; x < tasks.size(); ++x) {
                cout << x + 1 << ". " << tasks[x] << endl;
            }
            cout << "Enter Task Number: " << endl;
            cin >> highlight;

    if (highlight < 1 || highlight > (int)tasks.size()) {
    cout << "Invalid task number." << endl;

    } else {

    tasks[highlight - 1] = "* " + tasks[highlight - 1];
    cout << "Task highlighted!" << endl;

    }
            
        } else if (choice == 5) {
            cout << "getrandomnum() <<=" << getRandomNumber() << endl << "testFILE-s.c" << endl;
        } else if (choice == 6 || strChoice == "clear") {
            cout << "GoodBye!" << endl;
            break;
        }
    }


    return 0;
    
}
