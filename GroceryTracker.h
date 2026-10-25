#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Class to help track grocery purchases
class GroceryTracker {
public:
	// Reads items from the input
	void loadItems();

	// Creates the backup for frequency.dat
	void createBackupFile();

	// Searches for a specific item
	void searchItem() const;

	// Displays all of the item frequencies
	void displayFrequencies() const;

	// Displays a histogram for purchases
	void displayHistogram() const;

private:
	// Stores the grocery items and their frequencies
	map<string, int> itemFrequencies;
};

#endif