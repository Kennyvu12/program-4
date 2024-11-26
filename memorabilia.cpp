//Kenny Vu, CS162, kennyvu@pdx.edu, 11/24
// This is the code that  reads in the information from the user.

#include "memorabilia.h"
#include <iostream>
using namespace std;

// Constructor
Memorabilia::Memorabilia(int initialSize)
{
    arraySize = initialSize;
    itemCount = 0;
    items = new Item[arraySize];
}

// Destructor
Memorabilia::~Memorabilia()
{
    delete[] items;
    items = nullptr;
}

// Resize the array when full
void Memorabilia::resizeArray()
{
    int newSize = arraySize * 2;
    Item* newArray = new Item[newSize];
    for (int i = 0; i < itemCount; i++)
    {
        newArray[i] = items[i];
    }
    delete[] items;
    items = newArray;
    arraySize = newSize;
}

// Add a new item
void Memorabilia::addItem()
{
    if (itemCount == arraySize)
    {
        resizeArray();
    }

    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, items[itemCount].name);
    cout << "Enter product ID: ";
    getline(cin, items[itemCount].productID);
    cout << "Enter category: ";
    getline(cin, items[itemCount].category);
    cout << "Enter description: ";
    getline(cin, items[itemCount].description);
    cout << "Enter price: ";
    cin >> items[itemCount].price;
    cin.ignore();
    items[itemCount].sold = false;
    itemCount++;
    cout << "Item added successfully!" << endl;
}

// Display all items
void Memorabilia::displayAllItems() const
{
    if (itemCount == 0)
    {
        cout << "No items in inventory." << endl;
        return;
    }

    for (int i = 0; i < itemCount; i++)
    {
        cout << "\n---------------------------" << endl;
        cout << "Name: " << items[i].name << endl;
        cout << "Product ID: " << items[i].productID << endl;
        cout << "Category: " << items[i].category << endl;
        cout << "Description: " << items[i].description << endl;
        cout << "Price: $" << items[i].price << endl;
        cout << "Status: " << (items[i].sold ? "Sold" : "Available") << endl;
        cout << "---------------------------" << endl;
    }
}

// Filter and display items by field
void Memorabilia::filterByField(const string& field) const
{
    if (itemCount == 0)
    {
        cout << "No items in inventory." << endl;
        return;
    }

    string searchValue;
    cout << "Enter the value to search for: ";
    getline(cin, searchValue);

    bool found = false;
    for (int i = 0; i < itemCount; i++)
    {
        if ((field == "name" && items[i].name == searchValue) ||
            (field == "category" && items[i].category == searchValue))
        {
            cout << "\n---------------------------" << endl;
            cout << "Name: " << items[i].name << endl;
            cout << "Product ID: " << items[i].productID << endl;
            cout << "Category: " << items[i].category << endl;
            cout << "Description: " << items[i].description << endl;
            cout << "Price: $" << items[i].price << endl;
            cout << "Status: " << (items[i].sold ? "Sold" : "Available") << endl;
            cout << "---------------------------" << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No items found matching the given criteria." << endl;
    }
}

// Delete an item by ID
void Memorabilia::deleteItem(const string& productID)
{
    bool found = false;
    int i = 0;
    while (i < itemCount)
    {
        if (items[i].productID == productID)
        {
            found = true;
            for (int j = i; j < itemCount - 1; j++)
            {
                items[j] = items[j + 1];
            }
            itemCount--;
        }
        else
        {
            i++;
        }
    }

    if (found)
    {
        cout << "Item deleted successfully." << endl;
    }
    else
    {
        cout << "Item with Product ID " << productID << " not found." << endl;
    }
}
