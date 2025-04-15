#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std;

void  producer( promise<int> & p){  
    //produce data 
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"Producer is processing"<<endl;
    p.set_value(56);
}
void consumer( future<int> p){
    //consume data
    cout<<"Consumer is processing"<<endl;
    int result=p.get();
    cout<<"Result="<<result<<endl;
}
//entry point
int main() {
    cout<<"Main processing started"<<endl;
    promise<int> p;
    future<int> f=p.get_future();

    thread  thProducer(producer,ref(p));
    thread  thConsumer(consumer,move(f));

    thProducer.join();
    thConsumer.join();

    cout<<"Main processing is getting over"<<endl;

}