#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int MAX_VISITORS = 100;

// Function to accept valid integer input
int readInteger(string message)
{
    string input;
    int value;
    char extra;

    while (true)
    {
        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> value && !(ss >> extra))
        {
            return value;
        }

        cout << "Invalid input! Please enter a valid number.\n";
    }
}

// Visitor Class
class Visitor
{
private:
    int ticketID;
    string visitorName;
    int age;
    string rideName;

    static int totalVisitors;

public:

    // Function to enter visitor details
    void setDetails()
    {
        ticketID = readInteger("Enter Ticket ID: ");

        cout << "Enter Visitor Name: ";
        getline(cin, this->visitorName);

        age = readInteger("Enter Age: ");

        cout << "Enter Ride Name: ";
        getline(cin, this->rideName);
    }

    // Function to validate visitor details
    bool isValid() const
    {
        if (ticketID <= 0)
            return false;

        if (visitorName.find_first_not_of(" \t") == string::npos)
            return false;

        if (age <= 0 || age > 120)
            return false;

        if (rideName.find_first_not_of(" \t") == string::npos)
            return false;

        return true;
    }

    // Getter function
    int getTicketID() const
    {
        return ticketID;
    }

    // Inline function to display visitor details
    inline void displayDetails()
    {
        cout << "\nTicket ID: " << ticketID << endl;
        cout << "Visitor Name: " << visitorName << endl;
        cout << "Age: " << age << endl;
        cout << "Ride Name: " << rideName << endl;
    }

    // Static function to increase visitor count
    static void incrementTotalVisitors()
    {
        totalVisitors++;
    }

    // Static function to get total visitors
    static int getTotalVisitors()
    {
        return totalVisitors;
    }

    // Friend function declaration+
    friend void displayVisitorDetails(Visitor *v);
};

// Define static data member
int Visitor::totalVisitors = 0;

// Friend function definition
void displayVisitorDetails(Visitor *v)
{
    cout << "\n----- Visitor Details -----" << endl;

    cout << "Ticket ID: " << v->ticketID << endl;
    cout << "Visitor Name: " << v->visitorName << endl;
    cout << "Age: " << v->age << endl;
    cout << "Ride Name: " << v->rideName << endl;
}

// Function to check duplicate Ticket ID
bool isDuplicate(Visitor visitors[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (visitors[i].getTicketID() == id)
        {
            return true;
        }
    }

    return false;
}

// Function to register a visitor
void addVisitor(Visitor visitors[], int &count)
{
    if (count >= MAX_VISITORS)
    {
        cout << "\nVisitor storage is full!\n";
        return;
    }

    Visitor newVisitor;

    cout << "\n----- Visitor Registration -----\n";

    newVisitor.setDetails();

    if (!newVisitor.isValid())
    {
        cout << "\nInvalid visitor details! Registration failed.\n";
        return;
    }

    if (isDuplicate(visitors, count, newVisitor.getTicketID()))
    {
        cout << "\nTicket ID already exists! Registration failed.\n";
        return;
    }

    visitors[count] = newVisitor;

    count++;

    Visitor::incrementTotalVisitors();

    cout << "\nVisitor registered successfully!\n";
}

// Function to display all visitors
void displayVisitors(Visitor visitors[], int count)
{
    if (count == 0)
    {
        cout << "\nNo visitor records available.\n";
        return;
    }

    cout << "\n===== ALL REGISTERED VISITORS =====\n";

    // Pointer to Visitor objects
    Visitor *ptr = visitors;

    for (int i = 0; i < count; i++)
    {
        displayVisitorDetails(ptr + i);
    }

    cout << "\nTotal Visitors: "
         << Visitor::getTotalVisitors() << endl;
}

// Main function
int main()
{
    Visitor visitors[MAX_VISITORS];

    int count = 0;
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << " AMUSEMENT PARK RIDE QUEUE SIMULATOR\n";
        cout << "====================================\n";

        cout << "1. Add Visitor\n";
        cout << "2. Display Visitors\n";
        cout << "3. Total Visitors\n";
        cout << "4. Exit\n";

        choice = readInteger("\nEnter your choice: ");

        switch (choice)
        {
            case 1:
                addVisitor(visitors, count);
                break;

            case 2:
                displayVisitors(visitors, count);
                break;

            case 3:
                cout << "\nTotal Registered Visitors: "
                     << Visitor::getTotalVisitors() << endl;
                break;

            case 4:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}