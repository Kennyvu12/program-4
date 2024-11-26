//Kenny Vu, CS162, kennyvu@pdx.edu, 11/24
// structs

#ifndef MEMORABILIA_H
#define MEMORABILIA_H

#include <string>
using namespace std;

// Struct to define a memorabilia item
struct Item
{
    string name;
    string productID;
    string category;
    string description;
    float price;
    bool sold;
};

// Class to manage memorabilia items
class Memorabilia
{
private:
    Item* items;       // Pointer to dynamically allocated array of items
    int arraySize;     // Total size of the array
    int itemCount;     // Current number of items in the array

    // Resize the array when full
    void resizeArray();

public:
    // Constructor
    Memorabilia(int initialSize = 10);

    // Destructor
    ~Memorabilia();

    // Add a new item
    void addItem();

    // Display all items
    void displayAllItems() const;

    // Filter and display items by field
    void filterByField(const string& field) const;

    // Delete an item by Product ID
    void deleteItem(const string& productID);
};

#endif

