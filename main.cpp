//Kenny Vu, CS162, kennyvu@pdx.edu, 11/24
// This is a menu for the program
#include "memorabilia.h"
#include <iostream>
using namespace std;

int main()
{
    Memorabilia inventory;

    int choice;
    do
    {
        cout << "\nMemorabilia Inventory Management\n";
        cout << "1. Add Item\n";
        cout << "2. Display All Items\n";
        cout << "3. Filter Items by Field\n";
        cout << "4. Delete Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            inventory.addItem();
        }
        else if (choice == 2)
        {
            inventory.displayAllItems();
        }
        else if (choice == 3)
        {
            string field;
            cout << "Enter field to filter by (name/category): ";
            getline(cin, field);
            inventory.filterByField(field);
        }
        else if (choice == 4)
        {
            string productID;
            cout << "Enter Product ID to delete: ";
            getline(cin, productID);
            inventory.deleteItem(productID);
        }
        else if (choice == 5)
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice != 5);

    return 0;
}
