#include <iostream>
#include <future>
#include <thread>
#include <memory>
#include <chrono>

using namespace std;

// Base View (Consumer)
class View {
public:
    virtual void render(shared_future<string> dataFuture) = 0;
    virtual ~View() {}
};

// Concrete Views
class TopView : public View {
public:
    void render(shared_future<string> dataFuture) override {
        thread([dataFuture]() {
            string data = dataFuture.get();
            cout << "[TopView] Rendering data: " << data << "\n";
        }).detach();
    }
};

class FrontView : public View {
public:
    void render(shared_future<string> dataFuture) override {
        thread([dataFuture]() {
            string data = dataFuture.get();
            cout << "[FrontView] Rendering data: " << data << "\n";
        }).detach();
    }
};

class SideView : public View {
public:
    void render(shared_future<string> dataFuture) override {
        thread([dataFuture]() {
            string data = dataFuture.get();
            cout << "[SideView] Rendering data: " << data << "\n";
        }).detach();
    }
};

// Data Provider (Producer)
class DataModelProvider {
public:
    shared_future<string> provideDataAsync() {
        promise<string> dataPromise;
        shared_future<string> dataFuture = dataPromise.get_future();

        thread([promise = move(dataPromise)]() mutable {
            this_thread::sleep_for(chrono::seconds(1)); // simulate delay
            promise.set_value("Data Points of  Object");
        }).detach();

        return dataFuture;
    }
};

// --- Main Application ---
int main() {
    DataModelProvider provider;

    TopView top;
    FrontView front;
    SideView side;

    auto futureData = provider.provideDataAsync();

    top.render(futureData);
    front.render(futureData);
    side.render(futureData);

    // Give all threads time to finish before exiting main
    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}
