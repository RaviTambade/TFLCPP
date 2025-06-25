#include <iostream>
#include <mysql.h>

//Object Oriented Programming (OOP) approach to manage topics in a MySQL database
//Natural way of thinking to manage topics in a MySQL database

class DBManager {
    //Access specifiers
    private:
      //data members
        MYSQL *conn;  // MySQL connection object

    public:

        //constructors and destructors
        DBManager() {
            // Initialize MySQL connection
            conn = mysql_init(NULL);
            if (conn == NULL) {
                std::cerr << "mysql_init() failed\n";
                exit(EXIT_FAILURE);
            }
    
            if (mysql_real_connect(conn, "localhost", "root", "password", "tflmentoringdb", 0, NULL, 0) == NULL) {
                std::cerr << "mysql_real_connect() failed\n";
                mysql_close(conn);
                exit(EXIT_FAILURE);
            }
        }
    
        ~DBManager() {
            mysql_close(conn);
        }
    
        //methods
        void displayTopics(){
            MYSQL_RES *res;
            MYSQL_ROW row;

            // Execute SQL query to select all topics
            if (mysql_query(conn, "SELECT * FROM topics")) {
                std::cerr << "SELECT * FROM topics failed. Error: " << mysql_error(conn) << "\n";
                return;
            }

            // Store the result set
            res = mysql_store_result(conn);
            if (res == NULL) {
                std::cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << "\n";
                return;
            }

            // Fetch and display each row
            while ((row = mysql_fetch_row(res)) != NULL) {
                std::cout << "ID: " << row[0] << ", Title: " << row[1] << ", URL: " << row[2] << "\n";
            }

            // Clean up
            mysql_free_result(res);

        }
        void displayTopic(int id)
        {
            MYSQL_RES *res;
            MYSQL_ROW row;
            char query[256];

            // Prepare the SQL statement
            snprintf(query, sizeof(query), "SELECT * FROM topics WHERE id = %d", id);

            // Execute the SQL query
            if (mysql_query(conn, query)) {
                std::cerr << "SELECT * FROM topics failed. Error: " << mysql_error(conn) << "\n";
                return;
            }

            // Store the result set
            res = mysql_store_result(conn);
            if (res == NULL) {
                std::cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << "\n";
                return;
            }

            // Fetch and display the row
            if ((row = mysql_fetch_row(res)) != NULL) {
                std::cout << "ID: " << row[0] << ", Title: " << row[1] << ", URL: " << row[2] << "\n";
            } else {
                std::cout << "No topic found with ID: " << id << "\n";
            }

            // Clean up
            mysql_free_result(res);

        }


        bool insertTopic(const std::string& title, const std::string& url){

            return false; // Placeholder for the actual implementation
        }
       
        bool updateTopic(int id, const std::string& title, const std::string& url){

            char query[256];

            // Prepare the SQL statement
            snprintf(query, sizeof(query), "UPDATE topics SET title = '%s', url = '%s' WHERE id = %d", title.c_str(), url.c_str(), id);

            // Execute the SQL query
            if (mysql_query(conn, query)) {
                std::cerr << "UPDATE topics failed. Error: " << mysql_error(conn) << "\n";
                return false;
            }

            return true;

       }
       
       bool deleteTopic(int id){
            char query[256];

            // Prepare the SQL statement
            snprintf(query, sizeof(query), "DELETE FROM topics WHERE id = %d", id);

            // Execute the SQL query
            if (mysql_query(conn, query)) {
                std::cerr << "DELETE FROM topics failed. Error: " << mysql_error(conn) << "\n";
                return false;
            }

            return true;

        }

};


int main(){

    // Create an instance of DBManager
    DBManager *ptrDbManager=NULL;
    ptrDbManager = new DBManager();


    // Display menu options
    std::cout << "Menu:\n";
    std::cout << "1. Display all topics\n";
    std::cout << "2. Display a specific topic\n";
    std::cout << "3. Insert a new topic\n";
    std::cout << "4. Update a topic\n";
    std::cout << "5. Delete a topic\n";
    std::cout << "6. Exit\n";

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    // Handle user input and call appropriate methods on dbManager
    switch(choice) {
        case 1:
             ptrDbManager->displayTopics();
            break;
        case 2: {
            int id;
            std::cout << "Enter topic ID to display: ";
            std::cin >> id;
            ptrDbManager->displayTopic(id);
            break;
        }
        case 3: {
            std::string title, url;
            std::cout << "Enter title: ";
            std::cin >> title;
            std::cout << "Enter URL: ";
            std::cin >> url;
            if (ptrDbManager->insertTopic(title, url)) {
                    std::cout << "Topic inserted successfully.\n";
            } else {
                    std::cout << "Failed to insert topic.\n";
            }
            break;
        }
        case 4: {
            int id;
            std::string title, url;
            std::cout << "Enter topic ID to update: ";
            std::cin >> id;
            std::cout << "Enter new title: ";
            std::cin >> title;
            std::cout << "Enter new URL: ";
            std::cin >> url;
            if (ptrDbManager->updateTopic(id, title, url)) {
            std::cout << "Topic updated successfully.\n";
            } else {
                 std::cout << "Failed to update topic.\n";
            }
            break;
        }
        case 5: {
            int id;
            std::cout << "Enter topic ID to delete: ";
            std::cin >> id;
            if (ptrDbManager->deleteTopic(id)) {
                std::cout << "Topic deleted successfully.\n";
            } else {
               std::cout << "Failed to delete topic.\n";
            }
            break;
        }
        case 6:
            return 0;  // Exit the program
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
    // Implement the logic to handle user input and call appropriate methods on dbManager

    return 0;
}