# 👨‍🏫 The OTP That Thinks Before It Trusts

🧓 *“Once I was mentoring a batch of aspiring system programmers. One student asked, ‘Sir, how do banking apps validate OTPs so quickly and securely?’ I replied — by thinking like a **state machine**. OTP validation isn’t just a text check — it’s a process: you request → you receive → you validate → you’re in (or out). Every step… is a **state**.”*

Let’s simulate this logic like a real-world OTP validator:

## 🔐 OTP Validator State Machine Design

### 🔄 **States**

1. **Idle** – Waiting for OTP request
2. **OTPSent** – OTP generated and sent (simulated)
3. **OTPEntry** – User enters the OTP
4. **Verified** – OTP matched
5. **Failed** – OTP mismatch or expired


### 🎯 Use Case Flow:

```
Start in Idle ➝ Request OTP ➝ Simulate sending OTP ➝ User enters OTP ➝ Validate ➝ Either Verified or Failed
```

## 💡 OTP Validator Simulation in C (Mentor Style)

### 🧱 Setup: Include headers, declare state functions

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define function pointer type for states
typedef void (*StateFn)();

// Forward declarations
void stateIdle();
void stateOTPSent();
void stateOTPEntry();
void stateVerified();
void stateFailed();

// Shared variables
StateFn currentState = stateIdle;
char generatedOTP[6];
int attempts = 0;
const int maxAttempts = 3;
```

### 🔄 1. Idle State – Wait for OTP Request

```c
void stateIdle() {
    printf("\n📩 [IDLE] Press 'r' to request OTP or 'q' to quit: ");
    char input;
    scanf(" %c", &input);

    if (input == 'r' || input == 'R') {
        currentState = stateOTPSent;
    } else if (input == 'q' || input == 'Q') {
        printf("👋 Exiting system.\n");
        currentState = NULL;
    } else {
        printf("❗ Invalid option.\n");
    }
}
```

### 📤 2. OTPSent State – Generate and Simulate OTP

```c
void generateOTP() {
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        generatedOTP[i] = '0' + rand() % 10;
    }
    generatedOTP[5] = '\0'; // Null-terminate
}

void stateOTPSent() {
    generateOTP();
    printf("🔐 OTP Sent (Simulated): %s\n", generatedOTP); // In real-world, you wouldn't print it!
    currentState = stateOTPEntry;
}
```


### 🔢 3. OTP Entry State – Accept and Verify OTP

```c
void stateOTPEntry() {
    char userInput[10];
    printf("🔎 Enter the 5-digit OTP: ");
    scanf("%s", userInput);

    if (strcmp(userInput, generatedOTP) == 0) {
        currentState = stateVerified;
    } else {
        attempts++;
        if (attempts >= maxAttempts) {
            currentState = stateFailed;
        } else {
            printf("❌ Incorrect OTP. You have %d attempt(s) left.\n", maxAttempts - attempts);
            currentState = stateOTPEntry; // Try again
        }
    }
}
```


### ✅ 4. Verified State

```c
void stateVerified() {
    printf("✅ OTP Verified. Access granted.\n");
    currentState = NULL; // End session
}
```


### ❌ 5. Failed State

```c
void stateFailed() {
    printf("🚫 OTP verification failed. Too many incorrect attempts.\n");
    currentState = NULL;
}
```


### 🏁 Main Function

```c
int main() {
    printf("📲 Welcome to the OTP Validator System\n");

    while (currentState != NULL) {
        currentState();  // Execute current state
    }

    printf("🔒 Session ended.\n");
    return 0;
}
```

## ✅ Sample Output

```
📲 Welcome to the OTP Validator System

📩 [IDLE] Press 'r' to request OTP or 'q' to quit: r
🔐 OTP Sent (Simulated): 68245
🔎 Enter the 5-digit OTP: 12345
❌ Incorrect OTP. You have 2 attempt(s) left.
🔎 Enter the 5-digit OTP: 68245
✅ OTP Verified. Access granted.
🔒 Session ended.
```

## 🧓 Mentor Notes: Why This Is Elegant

* 💡 You cleanly separate **state logic**.
* 🔄 Each state handles its responsibility and moves forward.
* 🔐 You simulate **security logic** in a clean, testable way.


## 🧪 Bonus Ideas to Practice

* Add **expiry timer** (simulated with a countdown or sleep).
* Use `gettimeofday()` for **time-bound OTP**.
* Simulate **OTP resend** functionality.
* Write a `struct` for `OTPRequest` and make the machine more object-like.

## 🔚 Final Word from Mentor

🧓 *“Whether you’re designing an ATM, vending machine, or an OTP validator — remember, your code isn’t just logic. It’s a system of states responding to the world around it. And with function pointers… you control the brain of the machine.”*

Let me know if you'd like to upgrade this into a **multi-user login system with OTP + password + file-based persistence** — and we’ll take the journey together. Mentor-style. 🔐🚀
