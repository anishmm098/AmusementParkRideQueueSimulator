#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_VISITORS = 100;
const char DATA_FILE[] = "../data/visitors.dat";

// Fixed-size record for binary file storage
struct VisitorRecord
{
    int ticketID;
    char visitorName[50];
    int age;
    char rideName[50];
};

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

// Function to select a ride from available options
string selectRide()
{
    cout << "\nAvailable Rides:\n";
    cout << "1. Roller Coaster\n";
    cout << "2. Ferris Wheel\n";
    cout << "3. Bumper Cars\n";
    cout << "4. Water Splash\n";
    cout << "5. Haunted House\n";

    int choice;

    while (true)
    {
        choice = readInteger("Select Ride: ");

        switch (choice)
        {
            case 1:
                return "Roller Coaster";

            case 2:
                return "Ferris Wheel";

            case 3:
                return "Bumper Cars";

            case 4:
                return "Water Splash";

            case 5:
                return "Haunted House";

            default:
                cout << "Invalid ride selection! Please select 1-5.\n";
        }
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

    // Default Constructor
    Visitor()
    {
        ticketID = 0;
        visitorName = "";
        age = 0;
        rideName = "";
    }

    // Parameterized Constructor
    Visitor(int id, string name, int visitorAge, string ride)
    {
        ticketID = id;
        visitorName = name;
        age = visitorAge;
        rideName = ride;
    }

    // Copy Constructor
    Visitor(const Visitor &v)
    {
        ticketID = v.ticketID;
        visitorName = v.visitorName;
        age = v.age;
        rideName = v.rideName;
    }

    // Destructor
    ~Visitor()
    {
        // Destructor called when Visitor object is destroyed
    }

    // Function to enter visitor details
    void setDetails()
    {
        ticketID = readInteger("Enter Ticket ID: ");

        cout << "Enter Visitor Name: ";
        getline(cin, this->visitorName);

        age = readInteger("Enter Age: ");

        // Select ride from available options
        this->rideName = selectRide();
    }

    // Function to validate visitor details
    bool isValid() const
    {
        if (ticketID <= 0)
            return false;

        if (visitorName.find_first_not_of(" \t") == string::npos)
            return false;

        // Age must be between 1 and 70
        if (age <= 0 || age > 70)
            return false;

        if (rideName.find_first_not_of(" \t") == string::npos)
            return false;

        return true;
    }

    // Getter function for Ticket ID
    int getTicketID() const
    {
        return ticketID;
    }

    // Getter function for Visitor Name
    string getVisitorName() const
    {
        return visitorName;
    }

    // Getter function for Age
    int getAge() const
    {
        return age;
    }

    // Getter function for Ride Name
    string getRideName() const
    {
        return rideName;
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

    // Static function to set total visitors
    static void setTotalVisitors(int count)
    {
        totalVisitors = count;
    }

    // Friend function declaration
    friend void displayVisitorDetails(Visitor *v);
};

// Define static data member
int Visitor::totalVisitors = 0;

// Convert Visitor object to fixed-size binary record
VisitorRecord createRecord(const Visitor &visitor)
{
    VisitorRecord record{};

    record.ticketID = visitor.getTicketID();
    record.age = visitor.getAge();

    strncpy(record.visitorName,
            visitor.getVisitorName().c_str(),
            sizeof(record.visitorName) - 1);

    strncpy(record.rideName,
            visitor.getRideName().c_str(),
            sizeof(record.rideName) - 1);

    return record;
}

// Convert fixed-size binary record to Visitor object
Visitor createVisitor(const VisitorRecord &record)
{
    return Visitor(
        record.ticketID,
        string(record.visitorName),
        record.age,
        string(record.rideName)
    );
}

// Friend function definition
void displayVisitorDetails(Visitor *v)
{
    cout << "\n----- Visitor Details -----" << endl;

    cout << "Ticket ID: " << v->ticketID << endl;
    cout << "Visitor Name: " << v->visitorName << endl;
    cout << "Age: " << v->age << endl;
    cout << "Ride Name: " << v->rideName << endl;
}

// Function to load visitor records from binary file
int loadVisitors(Visitor visitors[])
{
    fstream file(DATA_FILE, ios::in | ios::binary);

    if (!file)
    {
        // File does not exist yet
        return 0;
    }

    VisitorRecord record;
    int count = 0;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(record)))
    {
        if (count >= MAX_VISITORS)
        {
            break;
        }

        visitors[count] = createVisitor(record);
        count++;
    }

    file.close();

    return count;
}

// Function to search visitor using seekg()
bool searchVisitorByID(int ticketID)
{
    fstream file(DATA_FILE, ios::in | ios::binary);

    if (!file)
    {
        cout << "\nError opening data file!\n";
        return false;
    }

    VisitorRecord record;

    while (true)
    {
        streampos position = file.tellg();

        file.seekg(position);

        file.read(reinterpret_cast<char*>(&record), sizeof(record));

        if (!file)
        {
            break;
        }

        if (record.ticketID == ticketID)
        {
            cout << "\n----- Visitor Found -----\n";
            cout << "Ticket ID: " << record.ticketID << endl;
            cout << "Visitor Name: " << record.visitorName << endl;
            cout << "Age: " << record.age << endl;
            cout << "Ride Name: " << record.rideName << endl;

            file.close();
            return true;
        }
    }

    file.close();

    cout << "\nVisitor with Ticket ID "
         << ticketID
         << " not found.\n";

    return false;
}

// Function to update visitor record using seekp()
bool updateVisitor(int ticketID)
{
    fstream file(DATA_FILE, ios::in | ios::out | ios::binary);

    if (!file)
    {
        cout << "\nError opening data file!\n";
        return false;
    }

    VisitorRecord record;

    while (true)
    {
        streampos position = file.tellg();

        file.read(reinterpret_cast<char*>(&record), sizeof(record));

        if (!file)
        {
            break;
        }

        if (record.ticketID == ticketID)
        {
            cout << "\n----- Current Visitor Details -----\n";
            cout << "Ticket ID: " << record.ticketID << endl;
            cout << "Visitor Name: " << record.visitorName << endl;
            cout << "Age: " << record.age << endl;
            cout << "Ride Name: " << record.rideName << endl;

            int newAge = readInteger("\nEnter New Age: ");

            // Age must be between 1 and 70
            while (newAge <= 0 || newAge > 70)
            {
                cout << "Invalid age! Please enter age between 1 and 70.\n";
                newAge = readInteger("Enter New Age: ");
            }

            string newRide = selectRide();

            record.age = newAge;

            strncpy(record.rideName,
                    newRide.c_str(),
                    sizeof(record.rideName) - 1);

            record.rideName[sizeof(record.rideName) - 1] = '\0';

            // Move write pointer to the record position
            file.seekp(position);

            // Write updated record at the same position
            file.write(reinterpret_cast<char*>(&record), sizeof(record));

            if (!file)
            {
                cout << "\nError updating visitor record!\n";
                file.close();
                return false;
            }

            file.close();

            cout << "\nVisitor record updated successfully!\n";
            return true;
        }
    }

    file.close();

    cout << "\nVisitor with Ticket ID "
         << ticketID
         << " not found.\n";

    return false;
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

    // Create fixed-size binary record
    VisitorRecord record = createRecord(newVisitor);

    // Open binary file in append mode
    fstream file(DATA_FILE, ios::out | ios::app | ios::binary);

    if (!file)
    {
        cout << "\nError opening data file!\n";
        return;
    }

    // Write fixed-size record to binary file
    file.write(reinterpret_cast<char*>(&record), sizeof(record));

    file.close();

    count++;

    Visitor::incrementTotalVisitors();

    cout << "\nVisitor registered successfully!\n";
    cout << "Visitor record saved to file successfully!\n";
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

    int count = loadVisitors(visitors);

    Visitor::setTotalVisitors(count);

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << " AMUSEMENT PARK RIDE QUEUE SIMULATOR\n";
        cout << "====================================\n";

        cout << "1. Add Visitor\n";
        cout << "2. Display Visitors\n";
        cout << "3. Search Visitor\n";
        cout << "4. Update Visitor\n";
        cout << "5. Total Visitors\n";
        cout << "6. Exit\n";

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
            {
                int searchID = readInteger("\nEnter Ticket ID to search: ");
                searchVisitorByID(searchID);
                break;
            }

            case 4:
            {
                int updateID = readInteger("\nEnter Ticket ID to update: ");
                updateVisitor(updateID);
                break;
            }

            case 5:
                cout << "\nTotal Registered Visitors: "
                     << Visitor::getTotalVisitors() << endl;
                break;

            case 6:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}