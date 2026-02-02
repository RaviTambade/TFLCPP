
## Lab Problem: Media Player Design using Virtual Base Classes in C++

## 🧠 Learning Context (Why this lab?)

As software systems grow, **inheritance hierarchies become complex**.

In multimedia applications:

* A **video** contains both **visual** and **audio** components
* These components share **common media properties**
* Poor inheritance design leads to **duplication and ambiguity**

This lab introduces a real-world problem known as the **Diamond Inheritance Problem** and demonstrates how **virtual base classes** solve it.

This concept is widely used in:

* Multimedia frameworks
* Game engines
* Device drivers
* Large-scale system architectures


## 🎯 Learning Objectives

By completing this lab, learners will be able to:

* Understand **diamond inheritance** in C++
* Identify problems caused by multiple inheritance
* Apply **virtual inheritance** correctly
* Design clean and unambiguous class hierarchies
* Model real-world multimedia systems using OOP principles


## 🧩 Problem Statement

Design and implement a **Media Player system** in C++ that supports different types of media content such as **images, audio, and videos**.

All media types share common properties such as title, duration, and size.
A video consists of **both visual and audio components**, requiring it to inherit from both `Image` and `Audio`.

The design must ensure that the base class `Media` exists **only once** within the `Video` object.

## 🏗️ System Design Requirements

### 1️⃣ Base Class: `Media`

* Common media attributes:

  * Title
  * Duration
  * Size
* Common behaviors:

  * Display media information
  * Load media

### 2️⃣ Derived Class: `Image`

* Inherits from `Media`
* Adds image-specific attributes:

  * Resolution
  * Format
* Provides image display functionality

### 3️⃣ Derived Class: `Audio`

* Inherits from `Media`
* Adds audio-specific attributes:

  * Bitrate
  * Channels
* Provides audio playback functionality

### 4️⃣ Derived Class: `Video`

* Inherits from both `Image` and `Audio`
* Combines visual and audio behavior
* Must share **only one instance of `Media`**

⚠️ **Constraint:**
`Media` must be inherited **virtually** by `Image` and `Audio`.

## ⚙️ Technical Constraints

* Programming Language: **C++**
* Inheritance Type: **Multiple inheritance with virtual base class**
* No external libraries
* Console-based output
* Proper constructor chaining must be demonstrated

## 🧪 Expected Behaviour

* Media properties must not be duplicated inside `Video`
* Access to `Media` attributes from `Video` must be unambiguous
* Constructors must initialize the `Media` class exactly once
* Program output must clearly show correct object behavior

## 📦 Deliverables

1. C++ source file implementing:

   * `Media`, `Image`, `Audio`, and `Video` classes
2. Demonstration of:

   * Diamond inheritance problem
   * Virtual inheritance solution
3. Clean, well-documented code
4. Sample output showing correct behavior

## 🧠 Concept Mapping (TLF Insight)

| Concept              | Media Player Mapping         |
| -------------------- | ---------------------------- |
| Base Class           | Media                        |
| Shared Resource      | Media properties             |
| Diamond Problem      | Video inherits Image + Audio |
| Virtual Inheritance  | Single Media instance        |
| Ambiguity Resolution | Clean access to base class   |


## 📊 Evaluation Criteria

| Criteria                           | Weight |
| ---------------------------------- | ------ |
| Correct use of virtual inheritance | 30%    |
| Class hierarchy design             | 25%    |
| Constructor chaining               | 20%    |
| Code clarity                       | 15%    |
| Concept explanation                | 10%    |

## 🚀 Extension Tasks (Next TLF Level)

* Add `play()` and `pause()` virtual functions
* Introduce polymorphic media playback
* Add a `MediaPlayer` controller class
* Visualize memory layout using ASCII diagrams
* Compare with **interface-based design (Java / C#)**

## 🧬 Mentor Insight (Transflower Signature)

> “Bad inheritance creates confusion.
> Virtual inheritance creates clarity.”

Once students understand this lab, **diamond inheritance stops being scary** and becomes a **design tool**.


### Code Example:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Base class: Media
class Media {
public:
    string title;
    double size; // in MB

    Media(string t, double s) : title(t), size(s) {}
    virtual void play() = 0; // Pure virtual function to play media
    virtual void displayInfo() {
        cout << "Title: " << title << ", Size: " << size << " MB" << endl;
    }
};

// Derived class: Image (inherits Media)
class Image : virtual public Media {
public:
    Image(string t, double s) : Media(t, s) {}

    void play() override {
        cout << "Displaying Image: " << title << endl;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Type: Image" << endl;
    }
};

// Derived class: Audio (inherits Media)
class Audio : virtual public Media {
public:
    Audio(string t, double s) : Media(t, s) {}

    void play() override {
        cout << "Playing Audio: " << title << endl;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Type: Audio" << endl;
    }
};

// Derived class: Video (inherits both Image and Audio, using virtual inheritance)
class Video : public Image, public Audio {
public:
    double duration; // in minutes

    Video(string t, double s, double d) : Media(t, s), Image(t, s), Audio(t, s), duration(d) {}

    void play() override {
        cout << "Playing Video: " << title << " (" << duration << " minutes)" << endl;
    }

    void displayInfo() override {
        Media::displayInfo(); // Calling base class Media display
        cout << "Type: Video, Duration: " << duration << " minutes" << endl;
    }
};

int main() {
    // Create an image, an audio, and a video
    Image img("Landscape", 3.5);
    Audio aud("Song", 5.0);
    Video vid("Movie", 700.0, 120.0);

    // Display info and play each media
    img.displayInfo();
    img.play();

    cout << endl;

    aud.displayInfo();
    aud.play();

    cout << endl;

    vid.displayInfo();
    vid.play();

    return 0;
}
```

### Output:

```
Title: Landscape, Size: 3.5 MB
Type: Image
Displaying Image: Landscape

Title: Song, Size: 5 MB
Type: Audio
Playing Audio: Song

Title: Movie, Size: 700 MB
Type: Video, Duration: 120 minutes
Playing Video: Movie (120 minutes)
```

### Explanation:

1. **Base Class (`Media`)**:
   - The `Media` class is a **virtual base class** for all media types (`Image`, `Audio`, `Video`).
   - It contains common properties such as `title` and `size`, and a pure virtual function `play()` to be overridden by derived classes.

2. **Derived Classes (`Image` and `Audio`)**:
   - Both `Image` and `Audio` inherit from `Media` virtually. This means that `Media` is **not duplicated** when `Video` inherits from both `Image` and `Audio`.

3. **Derived Class (`Video`)**:
   - The `Video` class inherits both `Image` and `Audio` using **virtual inheritance**, which means it contains only **one instance** of the `Media` base class, even though it inherits from both `Image` and `Audio`.

4. **Avoiding Multiple Instances of `Media`**:
   - If `Media` were inherited **non-virtually** (i.e., without the `virtual` keyword), `Video` would contain **two copies** of the `Media` class (one from `Image` and one from `Audio`).
   - By making `Image` and `Audio` inherit from `Media` virtually, `Video` inherits just **one copy** of the `Media` base class.

### Why Virtual Base Class is Needed Here:

In the `Video` class, if the `Media` class were not virtual, the `Media` class would be duplicated through both `Image` and `Audio` inheritance. This could cause:
- **Multiple copies** of the same data (e.g., `title` and `size`) in the `Video` object.
- **Confusion** or errors when trying to access the shared `Media` properties, as there would be two different `Media` sub-objects in `Video`.

Using **virtual inheritance** ensures that `Video` only has **one instance** of the `Media` base class, thus resolving the **diamond problem** and ensuring a cleaner, more efficient design.