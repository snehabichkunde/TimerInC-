#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

bool is_running = true;
bool is_stopped = false;

using namespace std;

void stopTimmer(){
    char input;
    //cin>>input;
    while(true){
        cin>>input;
        if(input == 'r'){
            is_running = true;
            is_stopped = false;
        }
        else if (input == 's')
        {
            is_running = false;
            is_stopped = true;
        }
        
    }
}

void timer(int hours, int minutes, int seconds)
{
    
    while (hours > 0 || minutes > 0 || seconds > 0) {
        while(is_stopped){
            this_thread:: sleep_for(chrono::seconds(1));
        }
        if(is_running)
        {cout << "\rTime remaining: " << setw(2) << setfill('0') << hours << "h "
             << setw(2) << setfill('0') << minutes << "m " 
             << setw(2) << setfill('0') << seconds << "s"<< flush;
             //cout << endl;

        this_thread::sleep_for(chrono::seconds(1));
        
        if (seconds > 0) {
            seconds--;
        } else {
            seconds = 59;
            if (minutes > 0) {
                minutes--;
            } else {
                minutes = 59;
                if (hours > 0) {
                    hours--;
                }
            }
        }
    }}
    cout << "\rTime's up!                            " << endl; 
}

bool isValidTime(int hours, int minutes, int seconds)
{
    return (hours >= 0 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
}

int main()
{
    int hours, minutes, seconds;
    cout << "Enter s to stop the timer and r to restart the timmer: " << endl;
    cout << "Enter time (hours minutes seconds): ";
    cin >> hours >> minutes >> seconds;

    if (!isValidTime(hours, minutes, seconds)) {
        cout << "Invalid time input. Please enter valid values." << endl;
        return 1; 
    }
    thread userInput(stopTimmer);
    timer(hours, minutes, seconds);

    return 0;
}
