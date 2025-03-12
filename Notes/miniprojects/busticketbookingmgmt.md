### **Problem Definition for Bus Ticket Booking System Using C**

A **Bus Ticket Booking System** is a software application designed to help users search, book, and manage bus tickets for travel. The system should allow users to view available buses, choose seats, book tickets, and cancel them if needed. The system will be built using the **C programming language** and provide a simple command-line interface (CLI) for the users to interact with.

---

### **Problem Objective:**

To design and implement a **Bus Ticket Booking System in C** that enables users to:
1. **View available buses** with details such as bus name, source, destination, and available seats.
2. **Book tickets** by selecting a bus and specifying the number of tickets.
3. **Cancel tickets** that were previously booked.
4. **View booking details** to show current bookings for a specific bus or a list of all bookings.
5. **Exit** the system when finished.

---

### **System Features and Requirements:**

1. **Bus Information:**
   - Each bus has the following details:
     - **Bus ID**: A unique identifier for each bus.
     - **Bus Name**: The name of the bus company (e.g., "CityExpress").
     - **Source**: The city where the bus departs from.
     - **Destination**: The city where the bus is traveling to.
     - **Available Seats**: The number of available seats on the bus.
     - **Total Seats**: The total number of seats on the bus.

2. **User Input:**
   - Users will input their desired travel details (e.g., source and destination) to search for available buses.
   - Users will specify how many tickets they wish to book for a particular bus.
   - Users will be able to cancel their booking by providing the bus ID and booking details.

3. **Booking Operations:**
   - **View Available Buses**: The user should be able to see a list of buses available for their journey, including bus ID, name, source, destination, and available seats.
   - **Book Tickets**: The user can select a bus by ID, specify the number of tickets they want, and then the system should update the number of available seats accordingly.
   - **Cancel Tickets**: The user can cancel a booking by providing their booking ID or bus ID and the number of tickets they want to cancel. The available seats should be updated accordingly.
   - **View Booked Tickets**: Users should be able to view a list of their current bookings with details such as the bus name, source, destination, and the number of seats booked.

4. **Data Storage:**
   - The buses and bookings will be stored in arrays of structures. Each structure will hold the details of either a bus or a booking.
   - The system will use **static arrays** with a fixed size to manage buses and bookings.

5. **User Interface:**
   - The system will operate through a **command-line interface** (CLI) with text-based menus.
   - Users will choose different options to view buses, book tickets, cancel bookings, or exit.

---

### **Data Structures:**

1. **Bus Structure:**
   Each bus is represented by a structure containing information about the bus, such as the bus ID, name, source, destination, and available seats.

   ```c
   #define MAX_BUSES 50
   #define MAX_BOOKINGS 100

   struct Bus {
       int busID;           // Unique identifier for the bus
       char busName[100];    // Name of the bus company
       char source[50];      // Source city
       char destination[50]; // Destination city
       int totalSeats;       // Total number of seats in the bus
       int availableSeats;   // Seats available for booking
   };

   struct Bus buses[MAX_BUSES];
   int busCount = 0;  // Total number of buses available

   struct Booking {
       int busID;         // Bus ID for the booked bus
       int numSeats;      // Number of seats booked
   };

   struct Booking bookings[MAX_BOOKINGS];
   int bookingCount = 0;  // Total number of bookings
   ```

---

### **Functional Requirements:**

1. **View Available Buses:**
   - Display a list of buses with details:
     - Bus ID
     - Bus Name
     - Source and Destination
     - Available Seats
   - The system should show only buses that have available seats for the chosen route.

2. **Book Tickets:**
   - The user selects a bus from the available list and enters the number of tickets they want to book.
   - The system should check if there are enough available seats on the bus.
   - If enough seats are available, the system should update the number of available seats and record the booking.
   - The system should show a confirmation message with booking details.

3. **Cancel Tickets:**
   - The user provides the bus ID and the number of tickets they want to cancel.
   - The system should update the available seats for the bus accordingly and remove the booking details for the canceled tickets.

4. **View Booking Details:**
   - The user can see their booking history, including the bus ID, bus name, source, destination, and number of seats booked.

5. **Exit:**
   - The user can choose to exit the system, and the program should terminate gracefully.

---

### **Constraints and Assumptions:**

1. **Fixed Capacity:**
   - The system can handle a maximum of `MAX_BUSES` buses and `MAX_BOOKINGS` bookings at a time. These values are predefined at the start of the program.
   - If the number of buses or bookings exceeds this limit, the system will notify the user and not allow further operations.

2. **No Persistent Data Storage:**
   - The system does not save data permanently (e.g., to a file). All data will be lost when the program ends.

3. **Input Validation:**
   - The system should validate user input to ensure correct data entry (e.g., ensuring the number of seats booked does not exceed the available seats).
   - The system should notify the user if they attempt to cancel more tickets than they have booked.

4. **Simple User Interface:**
   - The system will be operated through a command-line interface (CLI) with clear menu options.

---

### **Sample Menu Options:**

```
Bus Ticket Booking System
==========================
1. View Available Buses
2. Book Tickets
3. Cancel Tickets
4. View Bookings
5. Exit
Enter your choice (1-5): 
```

---

### **Sample Code Outline:**

Here’s an outline of how the code for the bus ticket booking system might look:

```c
#include <stdio.h>
#include <string.h>

#define MAX_BUSES 50
#define MAX_BOOKINGS 100

struct Bus {
    int busID;
    char busName[100];
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
};

struct Bus buses[MAX_BUSES];
int busCount = 0;

struct Booking {
    int busID;
    int numSeats;
};

struct Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;

void addBus() {
    if (busCount < MAX_BUSES) {
        struct Bus newBus;
        printf("Enter Bus ID: ");
        scanf("%d", &newBus.busID);
        getchar();  // Consume the newline
        printf("Enter Bus Name: ");
        fgets(newBus.busName, 100, stdin);
        newBus.busName[strcspn(newBus.busName, "\n")] = '\0';
        printf("Enter Source: ");
        fgets(newBus.source, 50, stdin);
        newBus.source[strcspn(newBus.source, "\n")] = '\0';
        printf("Enter Destination: ");
        fgets(newBus.destination, 50, stdin);
        newBus.destination[strcspn(newBus.destination, "\n")] = '\0';
        printf("Enter Total Seats: ");
        scanf("%d", &newBus.totalSeats);
        newBus.availableSeats = newBus.totalSeats;

        buses[busCount] = newBus;
        busCount++;
    } else {
        printf("Bus list is full!\n");
    }
}

void viewBuses() {
    printf("Available Buses:\n");
    for (int i = 0; i < busCount; i++) {
        printf("Bus ID: %d, Bus Name: %s, Source: %s, Destination: %s, Available Seats: %d\n",
               buses[i].busID, buses[i].busName, buses[i].source, buses[i].destination, buses[i].availableSeats);
    }
}

void bookTicket() {
    int busID, numSeats;
    printf("Enter Bus ID: ");
    scanf("%d", &busID);
    printf("Enter Number of Seats: ");
    scanf("%d", &numSeats);

    // Find the bus
    int found = 0;
    for (int i = 0; i < busCount; i++) {
        if (buses[i].busID == busID) {
            found = 1;
            if (buses[i].availableSeats >= numSeats) {
                buses[i].availableSeats -= numSeats;
                printf("Booking successful! %d seats booked on bus %d\n", numSeats, busID);
                struct Booking newBooking = {busID, numSeats};
                bookings[bookingCount++] = newBooking;
            } else {
                printf("Not enough available seats!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Bus ID not found.\n");
    }
}

void cancelTicket() {
    int busID, numSeats;
    printf("Enter Bus ID: ");
    scanf("%d", &busID);
    printf("Enter Number of Seats to Cancel: ");
    scanf("%d", &numSeats);

    // Find the booking
    int found = 0;
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].busID == busID && bookings[i].numSeats >= numSeats) {
            found = 1;
            buses[busID].availableSeats += numSeats;
            printf("Booking cancelled. %d seats refunded.\n", numSeats);
            bookings[i].numSeats -= numSeats;
            break;
        }
    }
    if (!found) {
        printf("Booking not found or invalid number of seats to cancel.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nBus Ticket Booking System\n");
        printf("==========================\n");
        printf("1. View Available Buses\n");
        printf("2. Book Tickets\n");
        printf("3. Cancel Tickets\n");
        printf("4. View Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewBuses(); break;
            case 2: bookTicket(); break;
            case 3: cancelTicket(); break;
            case 4: viewBookings(); break;
            case 5: return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
```

---

### **Conclusion:**

The **Bus Ticket Booking System** allows users to view available buses, book tickets, cancel bookings, and view their booking details. Using C programming, the system simulates a simple, text-based CLI interface that manages bus ticket operations efficiently. It could be expanded with features like persistent data storage, more advanced search functionality, and a user-friendly GUI in the future.