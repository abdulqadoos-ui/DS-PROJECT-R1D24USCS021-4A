#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct CarRental
{
    int rentalID;
    string customerName;
    string carName;
    int days;
    float rentPerDay;
};

CarRental st[MAX];
int top = -1;

// Check if stack is full
bool isFull()
{
    return top == MAX - 1;
}

// Check if stack is empty
bool isEmpty()
{
    return top == -1;
}

// Add a new rental (Push)
void pushRental()
{
    if (isFull())
    {
        cout << "Stack Overflow!\n";
        return;
    }

    top++;

    cout << "Rental ID: ";
    cin >> st[top].rentalID;

    cin.ignore();

    cout << "Customer Name: ";
    getline(cin, st[top].customerName);

    cout << "Car Name: ";
    getline(cin, st[top].carName);

    cout << "Days: ";
    cin >> st[top].days;

    cout << "Rent Per Day: ";
    cin >> st[top].rentPerDay;

    cout << "Rental Added Successfully!\n";
}

// Return a car (Pop)
void popRental()
{
    if (isEmpty())
    {
        cout << "No rentals available.\n";
        return;
    }

    cout << "Returning " << st[top].carName
         << " rented by " << st[top].customerName << endl;

    top--;

    cout << "Car Returned Successfully!\n";
}

// View latest rental (Peek)
void peekRental()
{
    if (isEmpty())
    {
        cout << "No rentals.\n";
        return;
    }

    cout << "\nLatest Rental\n";
    cout << "Rental ID: " << st[top].rentalID << endl;
    cout << "Customer : " << st[top].customerName << endl;
    cout << "Car : " << st[top].carName << endl;
    cout << "Days : " << st[top].days << endl;
    cout << "Rent Per Day : " << st[top].rentPerDay << endl;
}

// Display all rentals
void displayRentals()
{
    if (isEmpty())
    {
        cout << "No rentals available.\n";
        return;
    }

    cout << "\n========== ALL RENTALS ==========\n";

    for (int i = top; i >= 0; i--)
    {
        cout << "Rental ID : " << st[i].rentalID << endl;
        cout << "Customer : " << st[i].customerName << endl;
        cout << "Car : " << st[i].carName << endl;
        cout << "Days : " << st[i].days << endl;
        cout << "Rent/Day : " << st[i].rentPerDay << endl;
        cout << "Total Rent : " << st[i].days * st[i].rentPerDay << endl;
        cout << "-----------------------------" << endl;
    }
}

// Search rental by ID
void searchRental()
{
    if (isEmpty())
    {
        cout << "No rentals available.\n";
        return;
    }

    int id;

    cout << "Enter Rental ID: ";
    cin >> id;

    for (int i = top; i >= 0; i--)
    {
        if (st[i].rentalID == id)
        {
            cout << "\nRental Found!\n";
            cout << "Customer : " << st[i].customerName << endl;
            cout << "Car : " << st[i].carName << endl;
            cout << "Days : " << st[i].days << endl;
            cout << "Rent Per Day : " << st[i].rentPerDay << endl;
            return;
        }
    }

    cout << "Rental Not Found!\n";
}

// Update rental
void updateRental()
{
    if (isEmpty())
    {
        cout << "No rentals available.\n";
        return;
    }

    int id;

    cout << "Enter Rental ID to Update: ";
    cin >> id;

    cin.ignore();

    for (int i = top; i >= 0; i--)
    {
        if (st[i].rentalID == id)
        {
            cout << "New Customer Name: ";
            getline(cin, st[i].customerName);

            cout << "New Car Name: ";
            getline(cin, st[i].carName);

            cout << "New Days: ";
            cin >> st[i].days;

            cout << "New Rent Per Day: ";
            cin >> st[i].rentPerDay;

            cout << "Rental Updated Successfully!\n";
            return;
        }
    }

    cout << "Rental Not Found!\n";
}

// Calculate total revenue
void calculateRevenue()
{
    float total = 0;

    for (int i = 0; i <= top; i++)
    {
        total += st[i].days * st[i].rentPerDay;
    }

    cout << "\nTotal Revenue = " << total << endl;
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== CAR RENTAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Rental\n";
        cout << "2. Return Car\n";
        cout << "3. View Latest Rental\n";
        cout << "4. Display All Rentals\n";
        cout << "5. Search Rental\n";
        cout << "6. Update Rental\n";
        cout << "7. Total Revenue\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pushRental();
            break;

        case 2:
            popRental();
            break;

        case 3:
            peekRental();
            break;

        case 4:
            displayRentals();
            break;

        case 5:
            searchRental();
            break;

        case 6:
            updateRental();
            break;

        case 7:
            calculateRevenue();
            break;

        case 8:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 8);

    return 0;
}
