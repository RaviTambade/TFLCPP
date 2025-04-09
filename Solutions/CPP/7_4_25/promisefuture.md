# promise  and future  in C++ thread communication

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

---

### 🧠 Summary:
- **Producer thread**: uses `promise.set_value(value)` to send data.
- **Consumer thread**: uses `future.get()` to receive the data.
- **`get()` blocks** until `set_value()` is called.

---
Absolutely! Let’s walk through the diagram step-by-step so you can fully understand how `std::promise` and `std::future` work together across threads:

---

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


Perfect! Let’s explain `std::promise` and `std::future` using a **pizza delivery analogy** 🍕 — simple, fun, and super relatable!

---

### 🍕 The Promise-Future Analogy: Pizza Edition

#### 🎭 Characters:
- **Main Thread** = The person placing the order (organizer).
- **Producer Thread** = The pizza chef 🧑‍🍳 (prepares the pizza).
- **Consumer Thread** = The hungry customer 😋 (waiting for the pizza).
- **`std::promise`** = The chef’s guarantee: “I’ll deliver your pizza soon.”
- **`std::future`** = The receipt/ticket the customer uses to track the order and wait for it.

---

### 🔧 Step-by-Step, Pizza Style:

#### 🧾 1. Main Thread places an order:
- The organizer (main thread) creates a **promise** with the pizza chef:
  > “Here’s a ticket (future) for the customer. You’ll make the pizza (promise).”

```cpp
std::promise<Pizza> promise;
std::future<Pizza> future = promise.get_future();
```

---

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