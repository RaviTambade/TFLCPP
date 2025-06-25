#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

//Functional approach to manage topics in a MySQL database
//Procedural approach to create a MySQL database for topics
//Divide and conquer approach to manage topics in a MySQL database

//Reusable function to display topics from the MySQL database
void displayTopic(int id){
    MYSQL *conn;
    MYSQL_RES *res; 
    MYSQL_ROW row;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if(mysql_real_connect(conn, "localhost", "root","password","tflmentoringdb",0,NULL,0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    //SQL query to create a table
    //SELCT * from topics where id = id;
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM topics WHERE id = %d", id);
    
    if (mysql_query(conn, query)) {
        fprintf(stderr, "SELECT * FROM topics failed. Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    //retrive the result set
    res = mysql_store_result(conn);

    while((row = mysql_fetch_row(res)) != NULL) {
        printf("\n ID: %s, Title: %s, URL: %s\n", row[0], row[1], row[2]);
    }

    //clean up
    mysql_free_result(res);
    mysql_close(conn);
}

void displayTopics(){
        MYSQL *conn;
        MYSQL_RES *res; 
        MYSQL_ROW row;
        conn = mysql_init(NULL);
        if (conn == NULL) {
            fprintf(stderr, "mysql_init() failed\n");
            return EXIT_FAILURE;
        }

        if(mysql_real_connect(conn, "localhost", "root","password","tflmentoringdb",0,NULL,0) == NULL) {
            fprintf(stderr, "mysql_real_connect() failed\n");
            mysql_close(conn);
            return EXIT_FAILURE;
        }

        //SQL query to create a table
        //SELCT * from topics;
        if (mysql_query(conn, "SELECT * FROM topics")) {
            fprintf(stderr, "SELECT * FROM topics failed. Error: %s\n", mysql_error(conn));
            mysql_close(conn);
            return EXIT_FAILURE;
        }

        //retrive the result set
        res = mysql_store_result(conn);

        while((row = mysql_fetch_row(res)) != NULL) {
            printf("\n ID: %s, Title: %s, URL: %s\n", row[0], row[1], row[2]);
        }

        //clean up
        mysql_free_result(res);
        mysql_close(conn);

}

bool insertTopic(const char *title, const char *url) {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return false;
    }

    if (mysql_real_connect(conn, "localhost", "root", "password", "tflmentoringdb", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return false;
    }

    // Prepare the SQL statement
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO topics (title, url) VALUES ('%s', '%s')", title, url);

    // Execute the SQL statement
    if (mysql_query(conn, query)) {
        fprintf(stderr, "INSERT INTO topics failed. Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return false;
    }

    // Clean up
    mysql_close(conn);
    return true;
}

// Function to delete a topic by ID
bool deleteTopic(int id) {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return false;
    }

    if (mysql_real_connect(conn, "localhost", "root", "password", "tflmentoringdb", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return false;
    }

    // Prepare the SQL statement
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM topics WHERE id = %d", id);

    // Execute the SQL statement
    if (mysql_query(conn, query)) {
        fprintf(stderr, "DELETE FROM topics failed. Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return false;
    }

    // Clean up
    mysql_close(conn);
    return true;
}

// Function to update a topic by ID
bool updateTopic(int id, const char *title, const char *url) {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return false;
    }

    if (mysql_real_connect(conn, "localhost", "root", "password", "tflmentoringdb", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return false;
    }

    // Prepare the SQL statement
    char query[256];
    snprintf(query, sizeof(query), "UPDATE topics SET title = '%s', url = '%s' WHERE id = %d", title, url, id);

    // Execute the SQL statement
    if (mysql_query(conn, query)) {
        fprintf(stderr, "UPDATE topics failed. Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return false;
    }

    // Clean up
    mysql_close(conn);
    return true;
}
//Entry point of the program
int main(){

//structurs provided for mysql topics

    int choice, id;
    char title[100], url[200];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display all topics\n");
        printf("2. Display a specific topic\n");
        printf("3. Insert a new topic\n");
        printf("4. Update a topic\n");
        printf("5. Delete a topic\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTopics();
                break;
            case 2:
                printf("Enter topic ID to display: ");
                scanf("%d", &id);
                displayTopic(id);
                break;
            case 3:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter URL: ");
                scanf("%s", url);
                if (insertTopic(title, url)) {
                    printf("Topic inserted successfully.\n");
                } else {
                    printf("Failed to insert topic.\n");
                }
                break;
            case 4:
                printf("Enter topic ID to update: ");
                scanf("%d", &id);
                printf("Enter new title: ");
                scanf("%s", title);
                printf("Enter new URL: ");
                scanf("%s", url);
                if (updateTopic(id, title, url)) {
                    printf("Topic updated successfully.\n");
                } else {
                    printf("Failed to update topic.\n");
                }
                break;
            case 5:
                printf("Enter topic ID to delete: ");
                scanf("%d", &id);
                if (deleteTopic(id)) {
                    printf("Topic deleted successfully.\n");
                } else {
                    printf("Failed to delete topic.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


return EXIT_SUCCESS;
}


//gcc .\mysqltopicsdb.c -o db.exe -I "C:\Program Files\MySQL\MySQL Server 8.4\include" -L "C:\Program Files\MySQL\MySQL Server 8.4\lib" -l libmysql
