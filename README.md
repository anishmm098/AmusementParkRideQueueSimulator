# Amusement Park Ride Queue Simulator

## Project Information

Student Name: Anish Kumar
Registration / Roll Number: 12626434
Course: CAP455 – Object-Oriented Programming Using C++
Project: Amusement Park Ride Queue Simulator
Phase: CA2 – Phase 2
Language: C++

## Project Description

The Amusement Park Ride Queue Simulator is a C++ based console application designed to manage visitor registration and visitor records in an amusement park.

The CA2 implementation extends the CA1 system by introducing constructors, destructor, binary file handling, permanent data storage, visitor search, and basic record update functionality.

## Features

1. Add new visitors.
2. Store visitor Ticket ID, Name, Age and Ride Name.
3. Validate visitor information.
4. Prevent duplicate Ticket IDs.
5. Display all registered visitors.
6. Search visitor using Ticket ID.
7. Update visitor Age and Ride.
8. Store visitor records in a binary file.
9. Load saved records when the program starts.
10. Maintain visitor records after program restart.
11. Support multiple visitor records using an array of objects.
12. Select a ride from predefined ride options.
13. Maintain a fixed-size binary record structure.
14. Support file searching using seekg().
15. Support record updating using seekp().

## C++ Concepts Used

- Classes and Objects
- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Static Data Members and Functions
- Inline Functions
- Friend Functions
- Array of Objects
- Pointers
- This Pointer
- String
- Input Validation
- File Handling using fstream
- Binary File Handling
- Fixed-size Binary Records
- seekg() for file searching
- seekp() for updating records
- reinterpret_cast
- Character Array Handling using cstring

## Project Folder Structure

AmusementParkRideQueueSimulator/
|
├── .vscode/
│   ├── launch.json
│   └── tasks.json
|
├── docs/
│   └── Project_Report.docx
|
├── src/
│   └── 57_CAP455_CA2_AmusementParkRideQueueSimulator.cpp
|
├── data/
│   └── visitors.dat
|
├── tests/
└── README.md

## Source Code File

The main CA2 source code file is:

57_CAP455_CA2_AmusementParkRideQueueSimulator.cpp

The source code file is located inside the src folder.

## How to Compile

Open the project folder in the terminal and execute:

g++ src/57_CAP455_CA2_AmusementParkRideQueueSimulator.cpp -o main

## How to Run

For Windows:

.\main.exe

## Main Menu

1. Add Visitor
2. Display Visitors
3. Search Visitor
4. Update Visitor
5. Total Visitors
6. Exit

## Visitor Validation

The system validates visitor information before saving a record.

- Ticket ID must be greater than 0.
- Visitor Name cannot be empty.
- Age must be between 1 and 70.
- Ride must be selected from the available ride options.
- Duplicate Ticket IDs are not allowed.

## Available Rides

1. Roller Coaster
2. Ferris Wheel
3. Bumper Cars
4. Water Splash
5. Haunted House

## Storage Information

In CA1, visitor records were stored temporarily in memory and were lost when the program was closed.

In CA2, file handling and permanent data storage have been introduced. Visitor records are stored in a binary file named visitors.dat.

The file is located inside the data folder:

data/visitors.dat

The program automatically loads saved visitor records when it starts. Therefore, records remain available even after the program is closed and restarted.

## File Handling

The system uses fstream for binary file handling.

A fixed-size VisitorRecord structure is used to store visitor information in the binary file.

The program uses:

- write() to save visitor records.
- read() to load visitor records.
- seekg() for file searching.
- seekp() for updating records.
- tellg() to obtain the current file position.

## VisitorRecord Structure

The fixed-size binary record contains:

- ticketID – integer Ticket ID
- visitorName[50] – visitor name
- age – visitor age
- rideName[50] – selected ride

This fixed-size structure allows records to be stored consistently in the binary file and updated at their existing file position.

## Constructors and Destructor

The Visitor class contains:

- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor

These constructors are used to demonstrate object initialization and copying as required in CA2.

## Search and Update

The system allows the user to search for a visitor using the Ticket ID.

The search process uses binary file reading and seekg().

The system also allows basic updating of an existing visitor record. The visitor's Age and Ride can be updated using the Ticket ID.

The seekp() operation is used to move the file write pointer to the required record position before writing the updated record.

## Testing

The system was tested using different valid and invalid inputs, including:

- Valid visitor registration
- Duplicate Ticket ID
- Visitor search
- Non-existing Ticket ID search
- Visitor update
- Non-existing Ticket ID update
- Invalid age 0
- Boundary age 70
- Invalid age 71
- Data persistence after restarting the program
- Invalid menu choice

## CA2 Storage Behaviour

Unlike CA1, where records were stored only in memory, CA2 stores visitor records permanently in a binary file.

When the program is restarted, the saved visitor records are loaded from the binary file.

This ensures that visitor data is not lost when the program is closed.

## Current CA2 Scope

The current CA2 implementation includes:

- Visitor registration
- Visitor validation
- Duplicate Ticket ID checking
- Visitor display
- Visitor search
- Visitor update
- Binary file storage
- Persistent data loading
- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- seekg() based file searching
- seekp() based record updating

Delete functionality is not included in the current CA2 implementation.

## Future Development

CA3:
- Inheritance
- Operator Overloading
- Dynamic Memory
- Polymorphism
- Safe Delete Operations

CA4:
- Full CRUD Operations
- Exception Handling
- Templates
- STL
- Advanced Features

## Conclusion

The CA2 version of the Amusement Park Ride Queue Simulator extends the CA1 application by adding object constructors and destructor concepts, binary file handling, permanent storage, search functionality, and basic record update functionality.

The project demonstrates practical use of Object-Oriented Programming and file-handling concepts in C++.