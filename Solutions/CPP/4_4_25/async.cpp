#include <iostream>
#include <string>
#include <future>
#include <thread> 
#include <chrono>

using namespace std;

// A function to simulate a time-consuming task
string printing_task() {
    std::this_thread::sleep_for(std::chrono::seconds(10)); // Simulate a 10-second task
    return "Printing is done";
}

string scanning_task() {
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulate a 5-second task
    return "Scanning is done";;
}

int main() {
    // Launch the task asynchronously
    std::future<string> printing_result = std::async(std::launch::async, printing_task);
    std::future<string> scanning_result = std::async(std::launch::async, scanning_task);

    // Perform other work while the long task is running
    std::cout << "Doing other work..." << std::endl;

    // Get the result from the asynchronous task (this will block if the task hasn't completed yet)
    string result_printing_value = printing_result.get(); // Get the result of long_task
    string result_scanning_value = scanning_result.get(); // Get the result of long_task

    std::cout << " Printing Task completed. The result is: " << result_printing_value << std::endl;
    std::cout << "Scanning Task completed. The result is: " << result_scanning_value << std::endl;

    return 0;
}