# 👨‍🏫 The Lock That Listens to Logic


🧓 *"One day, my student walked in with an idea: ‘Sir, I want to build a smart digital lock system.’ I asked, ‘Is it smart because it has buttons and a screen?’ He replied, ‘No. It’s smart because it **understands states**.’ I smiled. That’s when we started building our lock — from Locked → Entering Code → Unlocked — using function pointers and state transitions.”*

Let’s dive in. This simulation works like a real-world lock keypad where:

* The system starts in a **Locked** state.
* User begins **Entering Code**.
* If the code matches, it transitions to **Unlocked**.
* If the code is wrong, it resets.


## 🔐 Digital Lock – State Machine Design

### 🔄 **States**

1. `Locked`
2. `EnteringCode`
3. `Unlocked`

We’ll create each state as a function and use a function pointer to transition between them dynamically.


### 🧱 Step-by-Step Implementation in C

```c
#include <stdio.h>
#include <string.h>

// Define a function pointer type for states
typedef void (*StateFn)();

// Forward declarations
void stateLocked();
void stateEnteringCode();
void stateUnlocked();

// Global state variable
StateFn currentState = stateLocked;

// Lock configuration
const char correctCode[] = "4321";
char userInput[10];

// Retry limit (optional)
int retryCount = 0;
const int maxRetries = 3;
```


### 🔒 1. Locked State

```c
void stateLocked() {
    printf("\n🔒 [LOCKED] Press 'e' to enter code or 'q' to quit: ");
    char input;
    scanf(" %c", &input);

    if (input == 'e' || input == 'E') {
        currentState = stateEnteringCode;
    } else if (input == 'q' || input == 'Q') {
        printf("🔚 Exiting lock system.\n");
        currentState = NULL;  // Exit the loop
    } else {
        printf("Invalid option.\n");
    }
}
```


### 🧾 2. Entering Code State

```c
void stateEnteringCode() {
    printf("🔢 Enter 4-digit code: ");
    scanf("%s", userInput);

    if (strcmp(userInput, correctCode) == 0) {
        printf("✅ Code correct. Lock is now unlocked!\n");
        currentState = stateUnlocked;
    } else {
        printf("❌ Incorrect code.\n");
        retryCount++;
        if (retryCount >= maxRetries) {
            printf("🚫 Too many attempts. System locked down.\n");
            currentState = NULL;  // Optional: end system
        } else {
            currentState = stateLocked;
        }
    }
}
```


### 🔓 3. Unlocked State

```c
void stateUnlocked() {
    printf("🔓 [UNLOCKED] Press 'l' to lock again or 'q' to quit: ");
    char input;
    scanf(" %c", &input);

    if (input == 'l' || input == 'L') {
        retryCount = 0;  // reset retries
        currentState = stateLocked;
    } else if (input == 'q' || input == 'Q') {
        printf("🔚 Lock system shutting down.\n");
        currentState = NULL;
    } else {
        printf("Invalid input.\n");
    }
}
```

### 🏁 Main Function – State Runner

```c
int main() {
    printf("🔐 Welcome to the Digital Lock Simulator\n");

    while (currentState != NULL) {
        currentState();  // Call the current state's function
    }

    printf("🔒 System Terminated.\n");
    return 0;
}
```


## ✅ Sample Output

```
🔐 Welcome to the Digital Lock Simulator

🔒 [LOCKED] Press 'e' to enter code or 'q' to quit: e
🔢 Enter 4-digit code: 1234
❌ Incorrect code.

🔒 [LOCKED] Press 'e' to enter code or 'q' to quit: e
🔢 Enter 4-digit code: 4321
✅ Code correct. Lock is now unlocked!

🔓 [UNLOCKED] Press 'l' to lock again or 'q' to quit: l
...
```

## 🧓 Mentor’s Notes

* 🔄 **State-based logic** keeps your code clean and easy to extend.
* 🧩 Each function handles only its own logic — no tangled mess.
* 🔧 Want to make it fancier? Add:

  * Countdown timer
  * Timeout lockout
  * User code setup
  * File logging with timestamps

## 💡 Final Thought:

🧓 *“In life and in code, everything has a state — and transitions happen because of input. When you think like this, you don’t just write programs. You design intelligent systems.”*

You’ve just unlocked a powerful way of thinking. Want to try a **door access system**, **elevator panel**, or **OTP validator** next?

I’m right here. Mentor-style. Ready when you are. 🔑
