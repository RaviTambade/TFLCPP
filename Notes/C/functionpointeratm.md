
👨‍🏫 The ATM That Thinks in States


🧓 *“One of my brightest students once said, ‘Sir, I want to simulate an ATM — just like the one near our college.’ I smiled and said, ‘Perfect. Because an ATM is the best real-world example of a **state machine**.’ You see, the ATM doesn’t just run code. It moves between **states** — Idle, Card Inserted, PIN Entry, and Transaction. Each state has its own behavior, and the transitions depend on **events**.”*

Let’s build this stateful ATM in C — using **function pointers** to model its flow.


## 🏧 ATM State Machine Overview

### 💡 **States:**

1. `Idle` – Waiting for card.
2. `CardInserted` – Card detected, asking for PIN.
3. `PinEntry` – User enters PIN.
4. `Transaction` – User chooses and performs action.
5. `Exit` – Ends the session.

We'll simulate this with console input and function pointers.


### 🧠 Step-by-Step Implementation

```c
#include <stdio.h>
#include <string.h>

// Define a function pointer type for state functions
typedef void (*ATMState)();

// Forward declarations
void stateIdle();
void stateCardInserted();
void statePinEntry();
void stateTransaction();

// Shared ATM variables
char correctPin[] = "1234";
char enteredPin[10];
int balance = 1000;
int sessionActive = 1;

// Current state pointer
ATMState currentState = stateIdle;
```

### 🟩 1. Idle State

```c
void stateIdle() {
    printf("\n🏧 [IDLE] Please insert your card (press 'i'): ");
    char input;
    scanf(" %c", &input);
    if (input == 'i' || input == 'I') {
        currentState = stateCardInserted;
    } else {
        printf("No card detected. Still idle...\n");
    }
}
```


### 🟨 2. Card Inserted State

```c
void stateCardInserted() {
    printf("\n💳 [CARD INSERTED] Please enter your 4-digit PIN: ");
    scanf("%s", enteredPin);
    currentState = statePinEntry;
}
```


### 🟧 3. PIN Entry State

```c
void statePinEntry() {
    if (strcmp(enteredPin, correctPin) == 0) {
        printf("✅ PIN correct.\n");
        currentState = stateTransaction;
    } else {
        printf("❌ Incorrect PIN. Ejecting card...\n");
        currentState = stateIdle;
    }
}
```


### 🟥 4. Transaction State

```c
void stateTransaction() {
    printf("\n💰 [TRANSACTION MENU]\n");
    printf("1. Check Balance\n2. Withdraw\n3. Exit\nChoose option: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Your current balance is Rs.%d\n", balance);
            break;
        case 2: {
            int amount;
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                printf("🤑 Please collect your cash. Remaining balance: Rs.%d\n", balance);
            } else {
                printf("⚠️ Insufficient balance.\n");
            }
            break;
        }
        case 3:
            printf("👋 Thank you for using the ATM. Card ejected.\n");
            sessionActive = 0;
            return;
        default:
            printf("❗ Invalid option.\n");
    }

    // Stay in transaction menu unless user exits
    currentState = stateTransaction;
}
```


### 🏁 Main Function – State Loop

```c
int main() {
    printf("🏦 Welcome to Transflower Bank ATM\n");

    while (sessionActive) {
        currentState();  // Execute the current state
    }

    printf("🔒 Session Ended.\n");
    return 0;
}
```

## ✅ Output Flow Example

```
🏦 Welcome to Transflower Bank ATM

🏧 [IDLE] Please insert your card (press 'i'): i

💳 [CARD INSERTED] Please enter your 4-digit PIN: 1234

✅ PIN correct.

💰 [TRANSACTION MENU]
1. Check Balance
2. Withdraw
3. Exit
Choose option: 2
Enter amount to withdraw: 500
🤑 Please collect your cash. Remaining balance: Rs.500
...
```


## 🧓 Mentor’s Insights

💡 **Why this design is beautiful**:

* Each state is modular and independent.
* The `main()` function becomes clean and focused — just looping through states.
* Adding new states (like “PIN blocked” or “Language Selection”) becomes easy.

🧓 *“You’re not just writing a program. You’re simulating behavior — like real-world systems do. That’s the power of state machines. And function pointers? They're your wiring between brains.”*


## 🔧 Bonus: Want More?

You can expand this by:

* Adding **PIN retry limits**
* Adding **language selection state**
* Logging each transaction using **file handling**
* Using **structs** to manage user sessions

Just say the word, and I’ll guide you through them — mentor-style.
Because building software isn’t just about code… it’s about modeling the real world.
And you, my dear learner, are doing just that — one state at a time. 🌟
