#include "GroceryTracker.h"
#include <fstream>

using namespace std;

// Reads the grocery items and counts the frequency
void GroceryTracker::loadItems() {
	ifstream inputFile("CS210_Project_Three_Input_File.txt");
	string item;

	// Checks if the file has been opened
	if (!inputFile.is_open()) {
		cout << "Error: Could not open input file." << endl;
		return;
	}

	// Reads each item and increases the count
	while (inputFile >> item) {
		itemFrequencies[item]++;
	}

	// Closes the file
	inputFile.close();
}

	// Creates the backup file
void GroceryTracker::createBackupFile() {
	ofstream outputFile("frequency.dat");


	// Checks if the backup file has been opened
	if (!outputFile.is_open()) {
		cout << "Error: Could not create backup file." << endl;
		return;
	}

	// Writes each item and the frequency
	for (const auto& item : itemFrequencies) {
		outputFile << item.first << " " << item.second << endl;
	}

	// Closes the backup file
	outputFile.close();
}

// Searches for specific items
void GroceryTracker::searchItem() const {
	string item;


	cout << "Enter the item you want to search for: ";
	cin >> item;

	// Looks for the item in the map
	auto foundItem = itemFrequencies.find(item);

	if (foundItem != itemFrequencies.end()) {
		cout << item << " was purchased "
			<< foundItem->second << " times." << endl;
	}
	else {
		cout << item << " was purchased 0 times." << endl;
	}
}

// Displays the frequency for all items
void GroceryTracker::displayFrequencies() const {

	cout << "\nITEM PURCHASE FREQUENCIES" << endl;
	cout << "-------------------------" << endl;

	// Displays each item and how often it's purchased
	for (const auto& item : itemFrequencies) {
		cout << item.first << " " << item.second << endl;
	}
}

// Displays a histogram of grocery pruchases
void GroceryTracker::displayHistogram() const {

	cout << "\nITEM PURCHASE HISTOGRAM" << endl;
	cout << "-----------------------" << endl;

	// Displays each item for its frequency
	for (const auto& item : itemFrequencies) {
		cout << item.first << " ";

		// Prints an aterisk for each purchase
		for (int i = 0; i < item.second; i++) {
			cout << "*";
		}

		cout << endl;
	}
}