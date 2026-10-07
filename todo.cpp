#include<iostream>
#include<vector>
#include<random>
#include<string>

using namespace std;

//Declarations
int choice = 0;
vector<string> tasks;

int getRandomNum() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100); 

    int random_Num = distribution(generator);
    cout << random_Num << endl;
     
}

void menu() {
    cout << "1. View Task" << endl;
    cout << "2. Add Tasks" << endl;
    cout << "3. Remove Tasks" << endl;
    cout << "4. Random" << endl;
    cout << "5. Exit" << endl;
    
    cout << "Enter Choice: ";
    cin >> choice;
}


int main() {
    cout << " ==== TODO List ==== " << endl;

    while (choice != 5) {
        menu();

        if (choice == 1) {
            if (tasks.empty()) {
                cout << "Nothing in the list." << endl;
            } else {
                for (size_t z = 0; z < tasks.size(); ++z) {
                    cout << z + 1 << ". " << tasks[z] << endl;
                    
            }
        }
        

        } else if (choice == 2) {
            string newTask;
            cin.ignore(10000, '\n');

            cout << "Which Task do you relish the most?: ";
            getline(cin, newTask);

            if (newTask.empty()) {
                cout << "You didnt put anything? Re-enter: ";
            } else {
            cout << "Task Added" << endl;
            cout << "------------------------------" << endl;
            tasks.push_back(newTask);
            }

        } else if (choice == 3) {

            if (tasks.empty()) {
                cout << "Empty List" << endl;
            } else {
            for (size_t z = 0; z < tasks.size(); ++z) {
                cout << z + 1 << ". " << tasks[z] << endl;
            }
            
            int removeNum;
            cout << "----" << endl;
            cout << "Which task you want to remove?: " << endl; 
            cin >> removeNum;
            tasks.erase(tasks.begin() + (removeNum - 1));
            cout << "Task Terminated" << endl;
            cout << "---------------------" << endl;
            }
       } else if (choice == 4) {
        cout << "Tasks.gen " << getRandomNum() << endl;
       }
        
    }


    return 0;
}
