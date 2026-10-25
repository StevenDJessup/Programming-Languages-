
#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

int main() {
    GroceryTracker tracker;
    int choice = 0;

    // Loads grocery items and create the backup file
    tracker.loadItems();
    tracker.createBackupFile();

    // Continue displaying the menu until the user leaves
    while (choice != 4) {
        cout << "\n********************************" << endl;
        cout << "          CORNER GROCER         " << endl;
        cout << "********************************" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit program" << endl;
        cout << "********************************" << endl;
        cout << "Enter your choice: ";

        // Checks for invalid input from user
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Performs the action chosen by the user
        switch (choice) {
        case 1:
            tracker.searchItem();
            break;

        case 2:
            tracker.displayFrequencies();
            break;

        case 3:
            tracker.displayHistogram();
            break;

        case 4:
            cout << "Thank you for using Corner Grocer!" << endl;
            break;

        default:
            cout << "Invalid choice. Please select 1-4." << endl;
            break;
        }
    }

    return 0;
}
