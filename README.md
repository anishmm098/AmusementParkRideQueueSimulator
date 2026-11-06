# Amusement Park Ride Queue Simulator

## Project Information

* **Course:** CAP455 – Object-Oriented Programming using C++
* **Project:** Amusement Park Ride Queue Simulator
* **Phase:** CA1
* **Language:** C++

## Project Description

The Amusement Park Ride Queue Simulator is a C++ based project designed to manage visitor registration and visitor records in an amusement park.

The CA1 implementation focuses on basic visitor management using Object-Oriented Programming concepts.

## Features

1. Add new visitors.
2. Store visitor Ticket ID, Name, Age and Ride Name.
3. Validate visitor information.
4. Prevent duplicate Ticket IDs.
5. Display all registered visitors.
6. Display total registered visitors.
7. Support multiple visitor records using an array of objects.

## C++ Concepts Used

* Classes and Objects
* Static Data Members and Functions
* Inline Functions
* Friend Functions
* Array of Objects
* Pointers
* This Pointer
* String
* Input Validation

## Project Folder Structure

```text
AmusementParkRideQueueSimulator/
│
├── docs/
│   └── Project_Report.docx
│
├── src/
│   └── main.cpp
│
├── data/
├── tests/
└── README.md
```

## How to Compile

Open the project folder in the terminal and execute:

```bash
g++ src/main.cpp -o main
```

## How to Run

For Windows:

```powershell
.\main.exe
```

## Main Menu

1. Add Visitor
2. Display Visitors
3. Total Visitors
4. Exit

## Storage Information

In CA1, visitor records are stored temporarily in memory. Records are lost when the program is closed.

File handling and permanent data storage will be introduced in a future project phase.

## Future Development

* CA2: File Handling and Constructors
* CA3: Inheritance, Operator Overloading and Polymorphism
* CA4: CRUD Operations, Exception Handling and STL
