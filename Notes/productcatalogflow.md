### Project Documentation: Architecture, Flow, and Best Practices


#### **1. Project Architecture**

The project follows a layered architecture, which ensures separation of concerns and modularity. Below is an overview of the architecture:

1. **Entity Layer**:
   - Contains core data models such as `Product` and `Customer`.
   - These classes encapsulate the attributes and behaviors of the application's domain objects.

2. **Repository Layer**:
   - Example: `ProductRepository`
   - Acts as an in-memory storage for entities.
   - Provides methods to add, retrieve, and manage entities.

3. **Service Layer**:
   - Example: `ProductService`
   - Contains business logic, such as applying discounts, calculating total prices, and searching for products.
   - Acts as an intermediary between the repository and controller layers.

4. **Controller Layer**:
   - Example: `ProductsController`, `CustomersController`
   - Handles user requests and delegates them to the appropriate service methods.
   - Acts as a mediator between the UI and service layers.

5. **UI Layer**:
   - Example: `UIManager`
   - Manages user interaction, such as displaying menus and handling input.
   - Delegates user actions to the controller layer.

6. **Helper Layer**:
   - Example: `ProductIOManager`
   - Provides utility functions, such as reading and writing data to files.

---

#### **2. Application Flow**

The flow of the application is as follows:

1. **Initialization**:
   - The application starts in `Main.cpp`.
   - `ProductIOManager` loads product data from a file (`products.txt`) into a vector of `Product` objects.

2. **Repository Setup**:
   - The loaded products are added to the `ProductRepository`, which acts as the in-memory storage.

3. **Service and Controller Setup**:
   - The `ProductService` is initialized with the repository to provide business logic.
   - The `ProductsController` is initialized with the repository and service to handle user requests.

4. **User Interaction**:
   - The `UIManager` displays a menu and handles user input.
   - User actions are passed to the `ProductsController`, which invokes the appropriate service methods.

5. **Business Logic Execution**:
   - The `ProductService` performs operations such as applying discounts, searching for products, and calculating totals.

6. **Output**:
   - Results are displayed to the user via the `UIManager`.

---

#### **3. Best Practices Followed**

1. **Separation of Concerns**:
   - Each layer has a distinct responsibility, ensuring modularity and maintainability.

2. **Single Responsibility Principle**:
   - Each class is responsible for a single aspect of the application, e.g., `ProductRepository` handles data storage, and `ProductService` handles business logic.

3. **Encapsulation**:
   - Data members in entity classes like `Product` and `Customer` are private, with public getter and setter methods.

4. **Reusability**:
   - Utility classes like `ProductIOManager` are reusable across different parts of the application.

5. **Scalability**:
   - The layered architecture allows for easy addition of new features, such as additional services or UI components.

6. **Code Readability**:
   - The code is well-structured, with meaningful class and method names.

7. **Error Handling**:
   - File operations and other critical sections include error handling to ensure robustness.

---

#### **4. Example Class Roles**

- **`Product`**:
  - Represents a product with attributes like ID, title, description, category, quantity, and price.

- **`Customer`**:
  - Represents a customer with attributes like ID, name, email, phone number, and address.

- **`ProductRepository`**:
  - Stores and manages `Product` objects in memory.

- **`ProductService`**:
  - Provides business logic for managing products, such as applying discounts and searching.

- **`ProductsController`**:
  - Handles user requests related to products and delegates them to the service layer.

- **`UIManager`**:
  - Manages user interaction, such as displaying menus and handling input.

- **`ProductIOManager`**:
  - Handles file I/O operations for loading and saving product data.

---

#### **5. Diagram**


```plaintext
+-------------------+       +-------------------+       +-------------------+
|                   |       |                   |       |                   |
|  ProductIOManager | ----> | ProductRepository | ----> | ProductService     |
|  (File Handling)  |       | (Data Storage)    |       | (Business Logic)  |
|                   |       |                   |       |                   |
+-------------------+       +-------------------+       +-------------------+
        |                           |                           |
        v                           v                           v
+-------------------+       +-------------------+       +-------------------+
|                   |       |                   |       |                   |
|  ProductsController | <---|       UIManager   |       |     Customer      |
|  (Controller Layer) |       | (User Interface)|       | (Entity Layer)    |
|                   |       |                   |       |                   |
+-------------------+       +-------------------+       +-------------------+

```

---

Let me know if you need further details or specific examples!
