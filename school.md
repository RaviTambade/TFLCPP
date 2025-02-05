

To create a table named `students` in MySQL, you can use the following SQL statement. This example includes common fields such as `id`, `first_name`, `last_name`, `date_of_birth`, and `email`.

```sql
CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    date_of_birth DATE,
    email VARCHAR(100) UNIQUE
);
```

### Explanation of the columns:

- **id**: An integer that auto-increments with each new entry, serving as the primary key.
- **first_name**: A string for the student's first name, with a maximum length of 50 characters.
- **last_name**: A string for the student's last name, also up to 50 characters.
- **date_of_birth**: A date field to store the student's date of birth.
- **email**: A string for the student's email address, which must be unique across the table.

You can modify the fields and data types based on your requirements!


To insert sample data into the `students` table you created, you can use the following SQL `INSERT` statements:

```sql
INSERT INTO students (first_name, last_name, date_of_birth, email) VALUES
('John', 'Doe', '2000-01-15', 'john.doe@example.com'),
('Jane', 'Smith', '1999-05-22', 'jane.smith@example.com'),
('Alice', 'Johnson', '2001-09-30', 'alice.johnson@example.com'),
('Bob', 'Brown', '1998-12-10', 'bob.brown@example.com');
```

### Explanation:
- Each `INSERT` statement adds a new row to the `students` table.
- The `id` column is not included in the insert statement because it auto-increments.
- Dates are formatted as `YYYY-MM-DD`.

Feel free to adjust the names, dates, and emails as needed!


Here are some additional `INSERT` statements to add more sample data into the `students` table:

```sql
INSERT INTO students (first_name, last_name, date_of_birth, email) VALUES
('Charlie', 'Davis', '2002-03-05', 'charlie.davis@example.com'),
('Emma', 'Wilson', '1997-07-14', 'emma.wilson@example.com'),
('Liam', 'Garcia', '2001-11-20', 'liam.garcia@example.com'),
('Olivia', 'Martinez', '2000-06-25', 'olivia.martinez@example.com'),
('Noah', 'Hernandez', '1999-02-17', 'noah.hernandez@example.com'),
('Sophia', 'Lopez', '2003-04-12', 'sophia.lopez@example.com'),
('Mason', 'Taylor', '1998-10-30', 'mason.taylor@example.com'),
('Isabella', 'Anderson', '2002-08-01', 'isabella.anderson@example.com');
```

### Summary of Data:
- These entries include a variety of names, birth dates, and email addresses.
- You can continue adding more records by following the same format!



To update records in the `students` table in MySQL, you can use the `UPDATE` statement. Here’s the general syntax:

```sql
UPDATE students
SET column_name = new_value
WHERE condition;
```

### Example Updates

Here are a few examples of how to use the `UPDATE` command for the `students` table:

1. **Update a Student's Email:**

```sql
UPDATE students
SET email = 'john.newemail@example.com'
WHERE first_name = 'John' AND last_name = 'Doe';
```

2. **Update a Student's Last Name:**

```sql
UPDATE students
SET last_name = 'Smithson'
WHERE id = 2;  -- Assuming the ID of Jane Smith is 2
```

3. **Update a Student's Date of Birth:**

```sql
UPDATE students
SET date_of_birth = '1998-12-25'
WHERE first_name = 'Bob' AND last_name = 'Brown';
```

### Important Note:
- Always include a `WHERE` clause to specify which records to update. If you omit it, all records in the table will be updated!

 


To delete records from the `students` table in MySQL, you can use the `DELETE` statement. Here’s the general syntax:

```sql
DELETE FROM students
WHERE condition;
```

### Example Deletes

Here are a few examples of how to use the `DELETE` command for the `students` table:

1. **Delete a Student by ID:**

```sql
DELETE FROM students
WHERE id = 3;  -- Assuming the ID of the student to delete is 3
```

2. **Delete a Student by Name:**

```sql
DELETE FROM students
WHERE first_name = 'Alice' AND last_name = 'Johnson';
```

3. **Delete All Students Born After a Certain Date:**

```sql
DELETE FROM students
WHERE date_of_birth > '2000-01-01';
```

### Important Note:
- Always include a `WHERE` clause to specify which records to delete. If you omit it, all records in the table will be deleted!

Make sure to use these commands carefully, especially in a production environment!



## SELECT Commands tryouts

To retrieve data from the `students` table in MySQL, you can use the `SELECT` statement. Here are some simple examples:

### 1. **Select All Columns from the Table**

```sql
SELECT * FROM students;
```

### 2. **Select Specific Columns**

```sql
SELECT first_name, last_name FROM students;
```

### 3. **Select Students with a Specific Condition**

For example, to find students with the first name "John":

```sql
SELECT * FROM students
WHERE first_name = 'John';
```

### 4. **Select Students Born After a Certain Date**

```sql
SELECT * FROM students
WHERE date_of_birth > '2000-01-01';
```

### 5. **Select Students and Order by Last Name**

```sql
SELECT * FROM students
ORDER BY last_name ASC;  -- Use DESC for descending order
```

### 6. **Select a Limited Number of Records**

To limit the results to, say, 5 records:

```sql
SELECT * FROM students
LIMIT 5;
```

These simple `SELECT` commands can help you retrieve the data you need from the `students` table! Feel free to modify the queries based on your requirements.


Here are some additional `SELECT` commands to further explore the data in the `students` table:

### 7. **Select Students with a Specific Email Domain**

To find students with an email address from a specific domain (e.g., `example.com`):

```sql
SELECT * FROM students
WHERE email LIKE '%@example.com';
```

### 8. **Count the Total Number of Students**

To count how many students are in the table:

```sql
SELECT COUNT(*) AS total_students FROM students;
```

### 9. **Select Students with a Date of Birth in a Specific Range**

To find students born between two dates:

```sql
SELECT * FROM students
WHERE date_of_birth BETWEEN '1999-01-01' AND '2001-12-31';
```

### 10. **Select Distinct Last Names**

To find unique last names of students:

```sql
SELECT DISTINCT last_name FROM students;
```

### 11. **Select Students and Sort by Date of Birth**

To sort students by their date of birth:

```sql
SELECT * FROM students
ORDER BY date_of_birth ASC;  -- Use DESC for descending order
```

### 12. **Select Students with a Conditional Statement**

To find students whose first name is "Emma" or who were born after January 1, 2000:

```sql
SELECT * FROM students
WHERE first_name = 'Emma' OR date_of_birth > '2000-01-01';
```

### 13. **Select Students with a Specific Condition and Limit Results**

To limit results to the first 3 students who have the last name "Smith":

```sql
SELECT * FROM students
WHERE last_name = 'Smith'
LIMIT 3;
```

### 14. **Select Students and Group by Last Name**

To group students by their last names and count how many students share each last name:

```sql
SELECT last_name, COUNT(*) AS count
FROM students
GROUP BY last_name;
```

These additional `SELECT` commands allow you to perform a variety of queries to retrieve and analyze your data more effectively! Adjust the queries as needed based on your requirements.



Here are more advanced `SELECT` commands and variations that you can use with the `students` table:

### 15. **Select Students with a Specific Pattern in Their First Name**

To find students whose first names start with "A":

```sql
SELECT * FROM students
WHERE first_name LIKE 'A%';
```

### 16. **Select Students and Limit Results with Offset**

To select 5 students starting from the 10th record:

```sql
SELECT * FROM students
LIMIT 5 OFFSET 10;  -- This skips the first 10 records and then selects the next 5
```

### 17. **Select Students with Aggregate Functions**

To find the oldest student:

```sql
SELECT MAX(date_of_birth) AS oldest_student_birthdate FROM students;
```

### 18. **Select Students Using Subqueries**

To select students who have the earliest date of birth:

```sql
SELECT * FROM students
WHERE date_of_birth = (SELECT MIN(date_of_birth) FROM students);
```

### 19. **Select Students and Calculate Average Age**

First, you may want to create a new column for age calculation:

```sql
SELECT AVG(TIMESTAMPDIFF(YEAR, date_of_birth, CURDATE())) AS average_age FROM students;
```

### 20. **Select Students with Multiple Conditions**

To find students whose last name is "Smith" and were born after January 1, 2000:

```sql
SELECT * FROM students
WHERE last_name = 'Smith' AND date_of_birth > '2000-01-01';
```

### 21. **Select Students and Group by First Name with Count**

To count how many students have the same first name:

```sql
SELECT first_name, COUNT(*) AS count
FROM students
GROUP BY first_name;
```

### 22. **Select Students with Conditional Sorting**

To sort students by last name, but if their last name is "Smith," sort them by first name instead:

```sql
SELECT * FROM students
ORDER BY last_name, CASE WHEN last_name = 'Smith' THEN first_name END;
```

### 23. **Select Students Using a Join (if you had another table)**

If you have another table, such as `courses`, you could join it with the `students` table. For example:

```sql
SELECT s.first_name, s.last_name, c.course_name
FROM students s
JOIN courses c ON s.id = c.student_id;
```

### 24. **Select Students with a Count of Courses (if applicable)**

If you have a `courses` table and want to count how many courses each student is enrolled in:

```sql
SELECT s.first_name, s.last_name, COUNT(c.course_id) AS course_count
FROM students s
LEFT JOIN courses c ON s.id = c.student_id
GROUP BY s.id;
```

These commands provide a range of options for querying your `students` table and can be adapted to meet specific data retrieval needs! Feel free to experiment with them!


Sure! Here are even more `SELECT` commands and variations for working with the `students` table:

### 25. **Select Students with Email Containing a Specific String**

To find students whose email addresses contain "gmail":

```sql
SELECT * FROM students
WHERE email LIKE '%gmail%';
```

### 26. **Select Students with a Nested Subquery**

To select students who are younger than the average age:

```sql
SELECT * FROM students
WHERE date_of_birth > (SELECT DATE_SUB(CURDATE(), INTERVAL AVG(TIMESTAMPDIFF(YEAR, date_of_birth, CURDATE())) YEAR) FROM students);
```

### 27. **Select Students Using Case Statements**

To label students based on their age group:

```sql
SELECT first_name, last_name,
CASE 
    WHEN TIMESTAMPDIFF(YEAR, date_of_birth, CURDATE()) < 18 THEN 'Minor'
    WHEN TIMESTAMPDIFF(YEAR, date_of_birth, CURDATE()) BETWEEN 18 AND 24 THEN 'Young Adult'
    ELSE 'Adult'
END AS age_group
FROM students;
```

### 28. **Select Students with a Specific Last Name and Order by First Name**

To select students with the last name "Johnson" and order them by their first name:

```sql
SELECT * FROM students
WHERE last_name = 'Johnson'
ORDER BY first_name ASC;
```

### 29. **Select Students and Use HAVING Clause**

To count how many students share the same last name and only show those with more than one occurrence:

```sql
SELECT last_name, COUNT(*) AS count
FROM students
GROUP BY last_name
HAVING COUNT(*) > 1;
```

### 30. **Select Students with Date Formatting**

To display the date of birth in a specific format:

```sql
SELECT first_name, last_name, DATE_FORMAT(date_of_birth, '%M %d, %Y') AS formatted_dob
FROM students;
```

### 31. **Select Students and Use UNION**

If you have another table (e.g., `graduates`), you can combine results:

```sql
SELECT first_name, last_name FROM students
UNION
SELECT first_name, last_name FROM graduates;
```

### 32. **Select Students and Show Row Number (Using Variables)**

To display a row number for each student (not a standard SQL feature, but can be done with variables):

```sql
SET @row_number = 0;
SELECT (@row_number := @row_number + 1) AS row_num, first_name, last_name
FROM students;
```

### 33. **Select Students with Related Data (using LEFT JOIN)**

If you have a `grades` table that links to students:

```sql
SELECT s.first_name, s.last_name, g.grade
FROM students s
LEFT JOIN grades g ON s.id = g.student_id;
```

### 34. **Select Students and Calculate Total Years Since Enrollment**

Assuming you have an `enrollment_date` column, you could calculate years since they enrolled:

```sql
SELECT first_name, last_name, TIMESTAMPDIFF(YEAR, enrollment_date, CURDATE()) AS years_enrolled
FROM students;
```

### 35. **Select Students with Random Order**

To select students in a random order:

```sql
SELECT * FROM students
ORDER BY RAND();
```

### 36. **Select Students Using GROUP_CONCAT**

If you have multiple entries in another table related to students, you can concatenate them:

```sql
SELECT s.first_name, s.last_name, GROUP_CONCAT(c.course_name) AS courses
FROM students s
JOIN courses c ON s.id = c.student_id
GROUP BY s.id;
```

These commands cover a wide range of scenarios, allowing for comprehensive data retrieval and manipulation in your `students` table. Feel free to adjust and combine these queries based on your specific needs!
