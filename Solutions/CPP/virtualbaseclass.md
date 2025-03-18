Let's consider a **realistic application** where virtual base classes are necessary. A common example can be a **multimedia application** where multiple types of media elements (such as images, videos, and audio files) share common properties or behaviors but also have specific functionality that differs from one another. 

For this example, let's design a **media player** that has different types of media files (e.g., `Image`, `Audio`, and `Video`), all inheriting from a common base class `Media`. Since both `Image` and `Audio` might be used by the `Video` class (e.g., a video has an image frame and an audio track), the `Media` class must be shared only once.

### Problem Scenario:
- We have a common base class `Media`, which defines basic media properties such as `title`, `duration`, and `size`.
- Classes `Image`, `Audio`, and `Video` all inherit from `Media`. The `Video` class, in particular, will inherit both `Image` (for the visual part of the video) and `Audio` (for the audio part).
- Without **virtual inheritance**, the `Media` class would be inherited twice: once through `Image` and once through `Audio`, causing multiple instances of the `Media` class.
- We need **virtual inheritance** to ensure that `Video` only has one instance of the `Media` base class.

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