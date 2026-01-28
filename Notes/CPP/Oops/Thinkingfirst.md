# 🧠*Thinking Behind the Healthcare Mini Project*

> **Important:** These are **mentor-only notes**.
> They explain *why decisions are made*, not *how to write code*.

Use these notes while reviewing student submissions, conducting design discussions, or correcting misconceptions.

#### 1️⃣ Patient Object – Identity & Lifecycle

* A **Patient is an identity**, not just data
* Once admitted, the *patientId must never change*

###### Why this design

* `final patientId` enforces **immutability**
* Prevents accidental reassignment (very common student bug)
* Models real hospitals: patient ID is permanent

###### What students often do wrong

* Allow patientId setters
* Generate ID lazily

👉 **Mentor correction**: “If identity changes, is it still the same patient?”


#### 2️⃣ MedicalRecord – Ownership & Copy Semantics

* Medical records are **sensitive**
* Copying must be intentional

###### Why cloning exists here

* Audit teams need snapshots
* Live treatment must not be affected

###### Deep vs Shallow Copy (Mental Model)

* Shallow → two doctors editing same file
* Deep → photocopy for audit

###### What students often do wrong

* Share same record reference everywhere

👉 **Mentor correction**: “Who owns this data right now?”


#### 3️⃣ Static Members – System-Wide State

* Some data belongs to the **hospital**, not patients

###### Why admittedCount is static

* Tracks total admissions
* Should not reset per object

###### Static Block reasoning

* System-level bootstrapping
* Runs once, predictably

###### Common mistake

* Using static as global variable bag

👉 **Mentor correction**: “Does this belong to one patient or the whole hospital?”


#### 4️⃣ Doctor Design – Capabilities, Not Hierarchy

* Doctors have **capabilities**, not inheritance chains

###### Why interfaces

* A doctor can treat, bill, consult, audit
* Roles evolve

###### Why NOT base class explosion

* `SeniorDoctor → InsuranceDoctor → EmergencyDoctor` is fragile

👉 **Mentor correction**: “Are we modeling *what it is* or *what it can do*?”


## 5️⃣ Billing – Compile-Time Polymorphism

* Billing rules are known at design time

###### Why overloading

* Same intent, different inputs
* Cleaner API

###### What students often do wrong

* One method with many flags

👉 **Mentor correction**: “Can the compiler help us here?”


#### 6️⃣ HospitalPolicy – Rules Must Be Untouchable

* Policies are **law**, not suggestions

###### Why static + final

* No instantiation
* No inheritance
* No modification



* Like government regulations

👉 **Mentor correction**: “Should a developer be allowed to override this?”


#### 7️⃣ Encapsulation – Patient Privacy

* Healthcare systems fail due to **data leaks**, not crashes

###### Why private fields

* Prevent uncontrolled access
* Enforce validation

###### Common student mistake

* Public fields for convenience

👉 **Mentor correction**: “Who is allowed to see this information?”


#### 8️⃣ Persistence – Memory Is Not Reality

* If the system crashes, patients still exist

### Why repository abstraction

* Storage may change
* Business logic must not care

###### Common mistake

* Logic tightly coupled to file/db

👉 **Mentor correction**: “What survives after program ends?”


#### 9️⃣ Object References – Aliasing Danger

* Two references ≠ two objects

###### Why this matters

* Accidental shared state
* Invisible bugs

### Mental model

* Two doctors holding same file

👉 **Mentor correction**: “How many *real* objects exist here?”


#### 🔟 Concurrency – Emergency Ward Reality

* Patients don’t arrive sequentially

###### Why concurrency example

* Introduces race conditions naturally
* Forces synchronization discussion

###### Common mistake

* Ignoring thread safety

👉 **Mentor correction**: “What happens if two emergencies arrive together?”


#### 1️⃣1️⃣ Destructor / Cleanup – End of Care

* Cleanup ≠ business logic

###### Why destructor is minimal

* Release resources only
* No state changes

###### Java comparison

* GC handles memory
* Developers handle resources

👉 **Mentor correction**: “Is this cleanup or business behavior?”


#### 1️⃣2️⃣ Typing – Safety Over Speed

* Healthcare prefers **correctness** over flexibility

###### Why static typing

* Catch errors early
* Prevent silent bugs

👉 **Mentor correction**: “Would you trust a dynamic dosage?”

> Code is temporary.
> **Design thinking stays forever.**