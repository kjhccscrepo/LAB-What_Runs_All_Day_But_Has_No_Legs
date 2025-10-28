#include "my_clock.hpp"
myClock::myClock() {
    timestamp_a = time(nullptr);
    timestamp_b = time(nullptr);
    gotNewFirstVal = false;
    gotNewSecondVal = false;
}
void myClock::start() {
    time(&timestamp_a);
    gotNewFirstVal = true;
    gotNewSecondVal = false;
}
void myClock::stop() {
    if (!gotNewSecondVal) {
        time(&timestamp_b);
        gotNewSecondVal = true;
    }
}
std::string myClock::start_with_message() {
    start();
    return "Timer has been started";
}
std::string myClock::stop_with_message() {
    stop();
    return "Timer has been stopped";
}
std::string myClock::elapsed() {
    if (!gotNewFirstVal || !gotNewSecondVal) {
        return "Clock has not been started/stopped, start/stop it then check for elapsed time.";
    }
    if (timestamp_b <= timestamp_a) {
        return "Clock has not been started/stopped, start/stop it then check for elapsed time.";
    }
    gotNewFirstVal = false;
    gotNewSecondVal = false;
    return (std::to_string(difftime(timestamp_b, timestamp_a)) + " seconds have passed between the last called time intervals.");
}