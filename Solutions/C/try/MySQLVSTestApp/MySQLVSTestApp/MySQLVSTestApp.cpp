#include <driver.h>
#include <exception.h>
#include <statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
using namespace std;
int main()
{
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306",
            "root", "password");

        con->setSchema("ecommerce"); // your database name

        sql::Statement* stmt;
        stmt = con->createStatement();

        // SQL query to create a table
        string createTableSQL
            = "CREATE TABLE IF NOT EXISTS GFGCourses ("
            "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,"
            "courses VARCHAR(255) NOT NULL"
            ")";

        stmt->execute(createTableSQL);

        string insertDataSQL
            = "INSERT INTO GFGCourses (courses) VALUES "
            "('DSA'),('C++'),('JAVA'),('PYTHON')";

        stmt->execute(insertDataSQL);

        // SQL query to retrieve data from the table
        string selectDataSQL = "SELECT * FROM GFGCourses";

        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        // Loop through the result set and display data
        int count = 0;
        while (res->next()) {
            cout << " Course " << ++count << ": "
                << res->getString("courses") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}
