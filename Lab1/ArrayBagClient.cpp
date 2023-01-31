// Check error handling
// document methods
// clean up code

#include <iostream>
#include <string>
#include "ArrayBag.h"
using namespace std;

// Prototypes
void viewBag(ArrayBag<int>&);
void addItem(ArrayBag<int>&);
void removeItem(ArrayBag<int>&);
void search(ArrayBag<int>&);

int main() {
	const int SIZE = 15;
	int items[SIZE] = { 1, 33, 6, 9, 2, 65, 4, 5, 17, 8, 63, 24, 7, 21, 19 };
	bool isSorted = false;        // Is bag sorted
	bool found = false;           // Was the number found in search;

	ArrayBag<int> bag;            // Create bag object

	// Populate bag with elements in items[].
	for (int i = 0; i < SIZE; i++) { bag.add(items[i]); }

	// Vector of elements in bag
	vector<int> bagContents = bag.toVector();

	cout << "--------------------------------------------\n";
	cout << "Lab 1: Arrays and Recursion - Rex Craft\n";

	// Run program while false;
	bool exitProgram = false;

	// Switch statement for menu selection, exit while loop when user chooses to exit.
	while (!exitProgram) {
		int userChoice;

		// Display capacity and sort status of bag
		cout << "--------------------------------------------\n";
		cout << "Bag Capacity: " << bag.getCurrentSize() << " / " << 20 << endl;
		cout << "Bag Status: ";
		if (isSorted) { cout << "Sorted\n"; }
		else { cout << "Unsorted\n"; }

		// Menu options
		cout << "--------------------------------------------\n";
		cout << "1. View bag contents.\n";
		cout << "2. Add to bag.\n";
		cout << "3. Remove from bag.\n";
		cout << "4. Sort your bag.\n";
		cout << "5. Search for something in the bag.\n";
		cout << "6. Empty Bag\n";
		cout << "0. Close Program.\n";
		cout << "--------------------------------------------\n";
		cout << "Choose an option: ";
		std::cin >> userChoice;


		// Handle user inputs that are out of range and prompt for another input.
		while (userChoice < 0 || userChoice > 6) {
			cout << userChoice << " is not a valid option, please try again: ";
			cin >> userChoice;
		}

		// Switch statement for menu options
		switch (userChoice) {
		case 1:                // View bag contents
			viewBag(bag);
			break;
		case 2:                // Add item to bag
			addItem(bag);
			isSorted = false;
			break;
		case 3:                // Remove item from bag
			removeItem(bag);
			break;
		case 4:                // Sort bag in ascending order
			bag.bubbleSort();
			isSorted = true;

			system("cls");
			cout << "--------------------------------------------\n";
			cout << "Your bag has been sorted successfully!\n";
			break;
		case 5:                // Search bag for a specific item
		{
			char input;
			bool isFound = false;
			system("cls");
			cout << "--------------------------------------------\n";
			cout << "Item Search\n";
			cout << "--------------------------------------------\n";

			if (!isSorted) {
				cout << "Your bag has not been sorted! Please sort before your search!\n";
				cout << "--------------------------------------------\n";
				cout << "Would you like to sort now? (y/n): ";
				cin >> input;

				if (tolower(input) == 'y') {
					bag.bubbleSort();
					isSorted = true;
					cout << "--------------------------------------------\n";
					search(bag);
				}
				else { system("cls"); }
			}
			else if (isSorted) {
				search(bag);
			}
			else { system("cls"); }
			break;
		}
		case 6:                // Remove all items in bag
			char confirm;

			cout << "--------------------------------------------\n";
			cout << "Are you sure you want to empty the entire bag? (y/n): ";
			cin >> confirm;

			if (tolower(confirm) == 'y') {
				system("cls");
				bag.clear();
				cout << "--------------------------------------------\n";
				cout << "Your bag is now empty!\n";
			}
			else { system("cls"); }
			break;
		case 0:                // Exit program
			exitProgram = true;
			bag.clear();
			system("cls");
			cout << "Goodbye!\n";
			break;
		}
	} // end switch statement
	return 0;
} // end main

// Displays the contents of a vector of current items in the ArrayBag object
void viewBag(ArrayBag<int>& bag) {
	std::vector<int> bagContents = bag.toVector();

	system("cls");

	cout << "--------------------------------------------\n";
	for (int i = 0; i < bagContents.size(); i++) { cout << "[" << bagContents[i] << "] "; }
	cout << endl;
}
// Adds a new item into the bag specified by user
// Inputs: ArrayBag object to add element to
// Result: user element is appended to ArrayBag object if it does not exist and there is enough
// room inside of the array
void addItem(ArrayBag<int>& bag) {
	std::vector<int> bagContents;
	int n;
	bool goBack = false;

	system("cls");

	cout << "--------------------------------------------\n";
	cout << "Add an Item\n";
	cout << "--------------------------------------------\n";

	while (!goBack) {

		if (bag.getCurrentSize() == 20) {
			goBack = true;
			system("cls");
			cout << "--------------------------------------------\n";
			cout << "You're bag is full! You must remove something first.\n";
		}
		else if (bag.isEmpty()) {
			bagContents = bag.toVector();
			for (int i = 0; i < bagContents.size(); i++) { cout << "[" << bagContents[i] << "] "; }
			cout << endl;
			cout << "\nAvailable slots in bag: " << (20 - bag.getCurrentSize()) << endl;
			cout << "--------------------------------------------\n";
			cout << "Enter number to add to bag (-1 to return to menu): ";
			cin >> n;

			if (n == -1) {
				goBack = true;
				system("cls");
			}
			else {
				// Check if value already exists in bag and prompt for different value.
				while (bag.getFrequencyOf(n) > 0) {
					cout << "That number is already in the bag! Please choose a different number: ";
					cin >> n;
				}
				bag.add(n);
				system("cls");
				cout << "--------------------------------------------\n";
				cout << n << " has been added to the bag!\n";
				cout << "--------------------------------------------\n";
			}
		}
	}
}

// Removes item specified by user
// Inputs: ArrayBag object to remove item from
// Results: Removes item if item is present, and if the array size is > 0
void removeItem(ArrayBag<int>& bag) {
	std::vector<int> bagContents;

	system("cls");

	cout << "--------------------------------------------\n";
	cout << "Remove an Item\n";
	cout << "--------------------------------------------\n";

	int x;
	bool goBack = false;

	while (!goBack) {
		bagContents = bag.toVector();

		bool checkBag = true;

		for (int i = 0; i < bagContents.size(); i++) { cout << "[" << bagContents[i] << "] "; }

		cout << "\n--------------------------------------------\n";
		cout << "Enter a number to remove from bag (-1 to return to menu): ";
		cin >> x;

		if (x == -1) { 
			goBack = true;
			system("cls");
		}
		else {
			// Check if value is in the bag.
			while (bag.getFrequencyOf(x) == 0 && checkBag) {
				cout << "That number is not in the bag! Please try again (-1 to return to menu): ";
				cin >> x;

				if (x == -1) {
					checkBag = false;
					goBack = true;
				}
			}
			if (x == -1) { system("cls"); }
			else {
				bag.remove(x);

				system("cls");

				cout << "--------------------------------------------\n";
				cout << x << " has been removed successfully!\n";
				cout << "--------------------------------------------\n";
			}
		}
		bagContents.erase(bagContents.begin(), bagContents.end());
	}
}

// Allow the user to search for an element either iteratively or recursively
// Input: ArrayBag object
// Output: Calls either iterative or recursive search methods
// Result: Displays whether or not the element is inside the object
void search(ArrayBag<int>& bag) {
	int searchType, searchFor;
	bool found = false;

	cout << "How would you like to search?\n";
	cout << "1. Iterative Search\n";
	cout << "2. Recursive Search\n";
	cout << "Search option: ";
	std::cin >> searchType;

	while (searchType != 1 && searchType != 2) {
		cout << "That is not a valid choice, please try again: ";
		cin >> searchType;
	}

	cout << "--------------------------------------------\n";
	cout << "Enter number to search for: ";
	std::cin >> searchFor;

	// Set found = true if search returns true, else false
	switch (searchType) {
	case 1:
		found = bag.binarySearchIterative(searchFor);
		break;
	case 2:
		found = bag.startRecursiveSearch(searchFor);
		break;
	}
	system("cls");

	if (found) { cout << searchFor << " is in the bag!\n"; }
	else { cout << searchFor << " is NOT in the bag.\n"; }
}

