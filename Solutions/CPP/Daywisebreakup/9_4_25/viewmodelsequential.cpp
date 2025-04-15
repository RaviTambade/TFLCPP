#include <iostream>
using namespace std;

// Base View (Consumer)
class View {
public:
    virtual void render(string  data) = 0;
    virtual ~View() {}
};

// Concrete Views
class TopView : public View {
public:
    void render(string data) override {
        cout<<"Rendering Top View "<<data<<endl;
    }
};

class FrontView : public View {
public:
    void render(string data) override {
        cout<<"Rendering Front View "<<data<<endl;
    }
};

class SideView : public View {
public:
    void render(string data) override {
         cout<<"Rendering Side View "<<data<<endl;
    }
};

class DataProvider {
public:
    string  provideData () {
        return "Model";
    }
};

int main() {
    //One Provider object, Multiple View
    //Sequential View Rendering
    DataProvider provider;
    TopView top;
    FrontView front;
    SideView side;

    string model = provider.provideData();
    top.render(model);
    front.render(model);
    side.render(model);
    return 0;
}