#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cctype> // for toupper

using namespace std;

// --- Globals ---
int choice = 0;
vector<string> inventory;

// --- Helper Functions ---
int getRandomNum(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void displayMenu() {
    cout << "\n=== INVENTORY MANAGER ===" << endl;
    cout << "1. View Inventory" << endl;
    cout << "2. Add Custom Item" << endl;
    cout << "3. Drop (Delete) Item" << endl;
    cout << "4. Open Loot Box (Random)" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter (1-5): ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        choice = -1;
    }
}

void viewInventory() {
    if (inventory.empty()) {
        cout << "Your inventory is empty. Go find some loot!" << endl;
        return;
    }
    
    cout << "\n--- Your Items ---" << endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << i + 1 << ". " << inventory[i] << endl;
    }
    cout << "Total items: " << inventory.size() << endl;
}

void addItem() {
    string newItem;
    cin.ignore(10000, '\n'); // Clear menu buffer
    cout << "Enter item name: ";
    getline(cin, newItem);

    if (newItem.empty()) {
        cout << "Item name cannot be blank!" << endl;
        return;
    }

    inventory.push_back(newItem);
    cout << "Success! '" << newItem << "' added to inventory." << endl;
}

void deleteItem() {
    if (inventory.empty()) {
        cout << "Nothing to drop!" << endl;
        return;
    }

    viewInventory(); // Show them what they have first
    
    cout << "Enter item number to drop: ";
    int itemNum;
    
    // Input validation for the delete number
    if (!(cin >> itemNum)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    if (itemNum < 1 || itemNum > (int)inventory.size()) {
        cout << "Invalid item number." << endl;
    } else {
        // The classic erase pattern
        cout << "'" << inventory[itemNum - 1] << "' was dropped." << endl;
        inventory.erase(inventory.begin() + (itemNum - 1));
    }
}

void openLootBox() {
    // Array of possible loot
    string lootTable[5] = { "Rusty Sword", "Health Potion", "Gold Coin", "Magic Scroll", "Trash" };
    
    // Generate a random index between 0 and 4
    int randomIndex = getRandomNum(0, 4);
    string prize = lootTable[randomIndex];

    cout << "\nYou open the box..." << endl;
    cout << "You found: " << prize << "!" << endl;

    // Ask to keep it
    cout << "Keep it? (Y/N): ";
    char answer;
    cin >> answer;
    answer = toupper(answer);

    if (answer == 'Y') {
        inventory.push_back(prize);
        cout << "Added to inventory." << endl;
    } else {
        cout << "You threw it away." << endl;
    }
}

// --- Main Loop ---
int main() {
    cout << "Welcome to the Inventory Manager!" << endl;

    while (choice != 5) {
        displayMenu();

        if (choice == 1) {
            viewInventory();
        }
        else if (choice == 2) {
            addItem();
        }
        else if (choice == 3) {
            deleteItem();
        }
        else if (choice == 4) {
            openLootBox();
        }
        else if (choice == 5) {
            cout << "Closing inventory. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}