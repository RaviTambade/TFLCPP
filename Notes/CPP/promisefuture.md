# Asynchronous Communication using promise and future  

In modern C++, we use **`std::promise`** and **`std::future`** to handle **asynchronous programming**, where one thread produces a value and another waits for it.

Let’s think in terms of **trade and currency**:

---

### 💱 **Analogy: Currency as a Promise**

Imagine you're in a market:

- A buyer wants to buy a product (the **value**).
- But the product isn't ready yet — the seller says:  
  *"I'll give it to you tomorrow."*

To confirm this, the seller gives the buyer a **currency note** — a **promise**.

> 💡 That currency doesn’t give you the product immediately,  
> but it **guarantees** you will get the value later.

---

### 🤝 How this relates to C++:

| Real-World Analogy     | C++ Concept                     |
|------------------------|--------------------------------------|
| Seller                 | The **thread producing** the value   |
| Currency (Note)        | A **`std::promise`**                 |
| Buyer                  | The **thread waiting** for the value |
| Future delivery        | A **`std::future`**                  |
| Product (actual item)  | The **result value**                 |

---

### 🧪 Code Snippet (Currency Example in C++)

```cpp
#include <iostream>
#include <thread>
#include <future>
using namespace std;

void makePayment(std::promise<int> paymentPromise) {
    // Simulate some delay (like product preparation)
    this_thread::sleep_for(chrono::seconds(2));
    paymentPromise.set_value(500);  // Set the promised value (currency)
}

int main() {
    std::promise<int> promiseObj;        // The currency note (promise)
    std::future<int> futureObj = promiseObj.get_future();  // Buyer holds the future

    std::thread seller(makePayment, std::move(promiseObj)); // Seller prepares the value

    cout << "Waiting for payment...\n";
    int payment = futureObj.get();  // Buyer waits until value is available
    cout << "Received payment: " << payment << " units.\n";

    seller.join();
    return 0;
}
```

 ### 📌 Key Takeaways:

- A **`promise`** is like a **guarantee** from one thread that it will deliver a value in the future.
- A **`future`** is like the **receipt** the other thread holds to wait for and receive that value.
- This model allows **asynchronous communication** between threads in a clean, safe way.


### 🔧 Step-by-Step, Pizza Style:

#### 🧾 1. Main Thread places an order:
- The organizer (main thread) creates a **promise** with the pizza chef:
  > “Here’s a ticket (future) for the customer. You’ll make the pizza (promise).”

```cpp
std::promise<Pizza> promise;
std::future<Pizza> future = promise.get_future();
```

#### 🍽️ 2. The customer waits with their pizza ticket:
- The customer (consumer thread) holds the `future` and says:
  > “I’ll wait until the pizza is ready.”

```cpp
Pizza myPizza = future.get(); // This blocks until pizza is delivered
```

---

#### 🍳 3. The chef starts preparing the pizza:
- The chef (producer thread) does some work — maybe dough tossing, sauce spreading.

```cpp
promise.set_value(Pizza("Margherita"));
```

---

#### 🛵 4. Once the pizza is ready, it's delivered!
- When the chef calls `set_value()`, the pizza is delivered instantly to the customer.
- The customer’s `.get()` call **unblocks**, and they eat the pizza.

---

### 💥 If something goes wrong…
- If the oven catches fire 🔥, the chef can call `promise.set_exception()` instead of `set_value()`.
- The customer’s `future.get()` will then throw an exception: “Pizza failed to arrive!”

---

### ✅ Summary Table:

| Real Thing           | Analogy Element         |
|----------------------|-------------------------|
| `std::promise<T>`     | Chef's commitment to deliver pizza |
| `std::future<T>`      | Pizza order receipt held by customer |
| `set_value(value)`   | Pizza is delivered |
| `get()`              | Customer waits and eats pizza |
| `set_exception()`    | Pizza delivery failed (exception thrown) |

---

# promise  and future  Concept Visualization

```
        [ Main Thread ]
               |
               |  create promise
               V
        +-----------------+
        | std::promise<T> |
        +-----------------+
               |
               | get_future()
               V
        +-----------------+
        | std::future<T>  | <---------------------------+
        +-----------------+                            |
               |                                        |
               | pass future to                         |
               | consumer thread                        |
               V                                        |
    [ Consumer Thread ]                                 |
        |                                               |
        | value = future.get();   // blocks until set   |
        V                                               |
     ( uses value )                                     |
                                                        |
                                                        |
    [ Producer Thread ]                                 |
        |                                               |
        | promise.set_value(42);  // sets the value ----+
        V
    ( done )
```

### 🔧 Step-by-step explanation:

#### **1. Main Thread creates a `std::promise`**
```cpp
std::promise<int> promise;
```
- This object is used to **set a value later**, from another thread.

---

#### **2. Main Thread gets a `std::future` from the `promise`**
```cpp
std::future<int> future = promise.get_future();
```
- This future is a **handle** to retrieve the value that will eventually be set by the promise.

---

#### **3. The Future is passed to a Consumer Thread**
```cpp
std::thread consumerThread(consumerFunction, std::move(future));
```
- Now, the consumer thread has the future, and it will **wait for the result** using `.get()`.

---

#### **4. The Promise is passed to a Producer Thread**
```cpp
std::thread producerThread(producerFunction, std::ref(promise));
```
- This thread will do some work and **send a result** using `promise.set_value(42)`.

---

#### **5. Inside the Consumer Thread:**
```cpp
int result = future.get(); // Blocks here
```
- The thread **waits** until the promise provides a value.
- `get()` is a **blocking call**—the thread sleeps here until the value is ready.

---

#### **6. Inside the Producer Thread:**
```cpp
promise.set_value(42);
```
- This call **unblocks the consumer thread**, delivering the value.
- Now, the consumer thread can continue its work using the received value.

---

### 🧵 Summary of Thread Roles:

| Thread | Role         | Function Used         |
|--------|--------------|------------------------|
| Main   | Setup        | Creates promise + future |
| Producer | Sets value  | `set_value()`         |
| Consumer | Gets value  | `get()` (waits if needed) |

---
### 🍕 The Promise-Future Analogy: Pizza Edition

#### 🎭 Characters:
- **Main Thread** = The person placing the order (organizer).
- **Producer Thread** = The pizza chef 🧑‍🍳 (prepares the pizza).
- **Consumer Thread** = The hungry customer 😋 (waiting for the pizza).
- **`std::promise`** = The chef’s guarantee: “I’ll deliver your pizza soon.”
- **`std::future`** = The receipt/ticket the customer uses to track the order and wait for it.

---

