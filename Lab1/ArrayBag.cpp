#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY) {}  // end default constructor

template<class ItemType>
void ArrayBag<ItemType>::bubbleSort() {
    int size = getCurrentSize();

    for (int maxElement = size - 1; maxElement > 0; maxElement--) {
        for (int index = 0; index < maxElement; index++) {
			if (items[index] > items[index + 1]) {
				int temp = items[index];
				items[index] = items[index + 1];
				items[index + 1] = temp;
            }
        }
    }
}

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchIterative(ItemType& target) {
    bool itemFound = false;

	int first = 0;
	int middle;
	int last = itemCount - 1;
	int position = -1;

	while (!itemFound && first <= last) {
		middle = (first + last) / 2;

		if (items[middle] == target) {
			itemFound = true;
			position = middle;
		}
		else if (items[middle] > target) {
			last = middle - 1;
		}
		else { first = middle + 1; }
	}
	return itemFound;
}

template<class ItemType>
bool ArrayBag<ItemType>::startRecursiveSearch(ItemType& target) {
	int arrSize = getCurrentSize();
	bool found = binarySearchRecursive(0, arrSize, target);

	return found;
}

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursive(int startIndex, int lastIndex, ItemType& target) const {
	int first = startIndex;
	int last = lastIndex;
	int middle = (first + last) / 2;

	if (first > last) { return 0; }
	else if (items[middle] == target) { return 1; }
	else if (items[middle] < target) { return binarySearchRecursive(middle + 1, last, target); }
	else { return binarySearchRecursive(first, middle - 1, target); }
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const { return itemCount; }

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
	if (itemCount < DEFAULT_CAPACITY) { return true; }
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry) {
	bool hasRoomToAdd = (itemCount < maxItems);

	if (hasRoomToAdd) {
		items[itemCount] = newEntry;
		itemCount++;
	}
	return hasRoomToAdd;
}  

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry) {
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = locatedIndex > -1;

	if (canRemoveItem) {
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}
	return canRemoveItem;
}

template<class ItemType>
void ArrayBag<ItemType>::clear() {
	itemCount = 0;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
   int frequency = 0;
   int curIndex = 0;       // Current array index

   while (curIndex < itemCount) {
      if (items[curIndex] == anEntry) {
         frequency++;
      }
      curIndex++;          // Increment to next entry
   }
   return frequency;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const { return getIndexOf(anEntry) > -1; }

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {
	bool found = false;
	int result = -1;
	int searchIndex = 0;
   
	// If the bag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount)) {
		if (items[searchIndex] == target) {
			found = true;
			result = searchIndex;
		} 
		else {
			searchIndex++;
		}
	}
	return result;
}

