#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

template<class ItemType>
class BagInterface
{
public:	
	// Gets the current number of entries in this bag.
	// Returns the integer number of entries currently in the bag
	virtual int getCurrentSize() const = 0;
   
	// Sees whether this bag is empty.
	// Returns True if the bag is empty, or false if not
	virtual bool isEmpty() const = 0;
   
	// Adds a new entry to this bag.
	// If successful, newEntry is stored in the bag and
	// the count of items in the bag has increased by 1.
	// Input: newEntry  The object to be added as a new entry.
	// Returns True if addition was successful, or false if not
	virtual bool add(const ItemType& newEntry) = 0;
   
	// Removes one occurrence of a given entry from this bag,
	// if possible.
	// If successful, anEntry has been removed from the bag
	// and the count of items in the bag has decreased by 1.
	// Input: anEntry  The entry to be removed.
	// Returns: True if removal was successful, or false if not
	virtual bool remove(const ItemType& anEntry) = 0;
   
	// Removes all entries from this bag.
	// Result: Bag contains no items, and the count of items is 0
	virtual void clear() = 0;
   
	// Counts the number of times a given entry appears in bag.
	// Input: anEntry  The entry to be counted
	// Returns: The number of times anEntry appears in the bag
	virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
   
	// Tests whether this bag contains a given entry.
	// Input: anEntry  The entry to locate
	// Returns: True if bag contains anEntry, or false otherwise
	virtual bool contains(const ItemType& anEntry) const = 0;
   
	// Empties and then fills a given vector with all entries that
	// are in this bag.
	// Returns: A vector containing all the entries in the bag
	virtual std::vector<ItemType> toVector() const = 0;

	// Sorts the items in an array
	// Result: Array is sorted in ascending order
	virtual void bubbleSort() = 0;

	// Performs an interary binary search for a specific element.
	// Input: User input for element to search for
	// Returns: True if element is found in array, false if not.
	virtual bool binarySearchIterative(ItemType& target) = 0;
	
	// Initiates recursive search allowing client code to only require
	// input from user to search.
	// Input: User input for element to search for.
	// Requests: Calls binarySearchRecursive to return search result.
	// Returns: True if element is found, false if not found.
	virtual bool startRecursiveSearch(ItemType& target) = 0;

	// Performs an recursive binary search for a specific element.
	// Input: First element in an array, last element in an array, value to search for in array.
	// Returns: True if element is found in array, false if not.
	virtual bool binarySearchRecursive(int startIndex, int lastIndex, ItemType& target) const = 0;
  
	// Destroys object and frees memory allocated by object.
	virtual ~BagInterface () { }
   
}; // end BagInterface
#endif
