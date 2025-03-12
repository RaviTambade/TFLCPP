### **Problem Definition for Library Management System Using C**

A **Library Management System (LMS)** is a software application designed to manage the operations of a library. This includes keeping track of books, issuing and returning books, managing member records, and more. The system allows the librarian and users to interact with the library's inventory, borrow books, return them, and maintain records efficiently.

This problem definition focuses on implementing a simple **Library Management System** using **C programming**, which will enable users to manage books, issue them to members, and track returns.

---

### **Problem Objective:**

To design and implement a **Library Management System in C** that allows the following functionalities:
1. **Add new books** to the library collection.
2. **View all available books** in the library.
3. **Issue books** to members and track issued books.
4. **Return books** and update the availability status.
5. **Search for books** by title, author, or genre.
6. **Exit** the system.

---

### **System Features and Requirements:**

1. **Book Information:**
   - Each book will have the following information:
     - **Book ID**: A unique identifier for the book.
     - **Title**: The title of the book.
     - **Author**: The author of the book.
     - **Genre**: The genre/category of the book (e.g., Fiction, Non-fiction, Mystery).
     - **Availability**: A status (e.g., Available or Issued).
   
2. **User Input:**
   - The system will accept user input for adding new books, issuing books, and returning books.
   - Users can search for books by title, author, or genre.
   
3. **Operations:**
   - **Add Book**: Allows the librarian to add a new book to the library.
   - **View Books**: Allows users to see the list of all available books in the library.
   - **Issue Book**: Allows members to issue a book. The system will check if the book is available and update its availability status.
   - **Return Book**: Allows members to return books, updating the system to reflect that the book is available again.
   - **Search Book**: Allows users to search for a book by its title, author, or genre.
   - **Exit**: Allows the user to exit the program.

4. **Book Storage:**
   - The books will be stored in an array of structures.
   - Each structure will represent a book, and the library will support a predefined maximum number of books (`MAX_BOOKS`).
   - Book data will be stored temporarily (in-memory storage only).

5. **User Interface:**
   - The system will operate through a **command-line interface** (CLI), allowing users to interact with the system through a series of options in the menu.

---

### **Data Structures:**

1. **Book Structure:**
   Each book is represented by a structure containing information about the book, such as the book ID, title, author, genre, and availability.

   ```c
   #define MAX_BOOKS 100

   struct Book {
       int bookID;             // Unique identifier for the book
       char title[100];        // Title of the book
       char author[50];        // Author of the book
       char genre[50];         // Genre/category of the book
       int available;          // Availability (1 for available, 0 for issued)
   };

   struct Book library[MAX_BOOKS];
   int totalBooks = 0;  // Total number of books in the library
   ```

2. **Member Structure (optional, for tracking issued books):**
   If the system is to track users, the member structure can store information about members who have issued books.

   ```c
   #define MAX_MEMBERS 50

   struct Member {
       int memberID;          // Unique identifier for the member
       char name[100];        // Name of the member
       int issuedBookID;      // ID of the book issued (if any)
   };

   struct Member members[MAX_MEMBERS];
   int totalMembers = 0;  // Total number of members
   ```

---

### **Functional Requirements:**

1. **Add Book:**
   - The librarian can add new books to the library by providing the book's ID, title, author, genre, and initial availability status (set to "Available").
   - The system should check if there is space in the library to add the book (up to `MAX_BOOKS`).

2. **View Available Books:**
   - The user can view all the books in the library, including their book ID, title, author, and genre.
   - Books that are currently issued should be marked as "Issued."

3. **Issue Book:**
   - A member can issue a book by selecting a book ID.
   - The system should check if the book is available (i.e., its availability status is "Available").
   - If the book is available, the system will mark it as "Issued" and store the member's ID with the issued book.
   - If the book is not available, the system will notify the member.

4. **Return Book:**
   - A member can return an issued book by providing the book ID.
   - The system will mark the book as "Available" again, and the member’s record will be updated to reflect the returned book.

5. **Search Book:**
   - The user can search for a book by entering part of the title, author, or genre.
   - The system will display all books matching the search criteria, including their book ID, title, and availability status.

6. **Exit:**
   - The program can be exited when the user selects the exit option in the menu.

---

### **Constraints and Assumptions:**

1. **Fixed Capacity:**
   - The system can store a maximum of `MAX_BOOKS` books. If the number of books exceeds this limit, the librarian will be notified, and no more books can be added.

2. **No Persistent Data Storage:**
   - The system does not save data permanently (e.g., to a file). When the program ends, all data is lost.
   - This could be extended to use file handling in the future to save and load data.

3. **Simple User Interface:**
   - The system will be operated through a text-based command-line interface (CLI), with easy-to-follow menu options.

4. **Basic Input Validation:**
   - The system should check for valid input when adding books (e.g., checking that the book ID is unique).
   - The system should ensure that members can only issue a book if it is available and can only return a book that they have issued.

---

### **Sample Menu Options:**

```
Library Management System
==========================
1. Add Book
2. View Available Books
3. Issue Book
4. Return Book
5. Search Book
6. Exit
Enter your choice (1-6):
```

---

### **Sample Code Outline:**

Here’s an outline of how the code for the library management system might look:

```c
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int bookID;
    char title[100];
    char author[50];
    char genre[50];
    int available; // 1 if available, 0 if issued
};

struct Book library[MAX_BOOKS];
int totalBooks = 0;

void addBook() {
    if (totalBooks < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter Book ID: ");
        scanf("%d", &newBook.bookID);
        getchar();  // Consume newline
        printf("Enter Book Title: ");
        fgets(newBook.title, 100, stdin);
        newBook.title[strcspn(newBook.title, "\n")] = '\0';  // Remove newline
        printf("Enter Author: ");
        fgets(newBook.author, 50, stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0';  // Remove newline
        printf("Enter Genre: ");
        fgets(newBook.genre, 50, stdin);
        newBook.genre[strcspn(newBook.genre, "\n")] = '\0';  // Remove newline
        newBook.available = 1;  // Initially available

        library[totalBooks++] = newBook;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void viewBooks() {
    printf("\nList of Books:\n");
    for (int i = 0; i < totalBooks; i++) {
        printf("Book ID: %d, Title: %s, Author: %s, Genre: %s, Status: %s\n",
               library[i].bookID, library[i].title, library[i].author,
               library[i].genre, library[i].available ? "Available" : "Issued");
    }
}

void issueBook() {
    int bookID;
    printf("Enter Book ID to issue: ");
    scanf("%d", &bookID);
    int found = 0;

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].bookID == bookID && library[i].available == 1) {
            library[i].available = 0;  // Mark as issued
            printf("Book issued successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not available or invalid Book ID.\n");
    }
}

void returnBook() {
    int bookID;
    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);
    int found = 0;

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].bookID == bookID && library[i].available == 0) {
            library[i].available = 1;  // Mark as available
            printf("Book returned successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not issued or invalid Book ID.\n");
    }
}

void searchBook() {
    char searchQuery[50];
    printf("Enter title, author, or genre to search: ");
    getchar();  // Consume newline
    fgets(searchQuery, 50, stdin);
    searchQuery[strcspn(searchQuery, "\n")] = '\0';  // Remove newline

    printf("Search Results:\n");
    for (int i = 0; i < totalBooks; i++) {
        if (strstr(library[i].title, searchQuery) || strstr(library[i].author, searchQuery) ||
            strstr(library[i].genre, searchQuery)) {
            printf("Book ID: %d, Title: %s, Author: %s, Genre: %s, Status: %s\n",
                   library[i].bookID, library[i].title, library[i].author,
                   library[i].genre, library[i].available ? "Available" : "Issued");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("==========================\n");
        printf("1. Add Book\n");
        printf("2. View Available Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: searchBook(); break;
            case 6: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
```

---

### **Conclusion:**

This **Library Management System** enables users to add books, view available books, issue books, return books, and search for books by title, author, or genre. It is a simple, text-based CLI program written in C that efficiently manages a library’s operations. Future enhancements could include adding member records, persistence (using files), and a more advanced user interface.