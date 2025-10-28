#include "my_timer.hpp"
void myTimer::count_time(double &time, int &time_box, const int &iterationAmount) {
    while (time >= iterationAmount) {
        time -= iterationAmount;
        time_box++;
    }
}
void myTimer::populate_stringstream(std::stringstream &ss, const int &box_to_count, int &and_con) {
    if (box_to_count > 1) {
        ss << "s";
    }
    if (and_con == 2) {
        ss << " and ";
    } else if (and_con == 1 && box_to_count == 1) {
        ss << " has ";
    } else if (and_con == 1) {
        ss << " have ";
    } else {
        ss << ", ";
    }
    and_con--;
}

myTimer::myTimer() {
    timestamp_a = time(nullptr);
    timestamp_b = time(nullptr);
    gotNewFirstVal = false;
    gotNewSecondVal = false;
}
void myTimer::start() {
    time(&timestamp_a);
    gotNewFirstVal = true;
    gotNewSecondVal = false;
}
void myTimer::stop() {
    if (!gotNewSecondVal) {
        time(&timestamp_b);
        gotNewSecondVal = true;
    }
}
std::string myTimer::start_with_message() {
    start();
    return "Timer has been started";
}
std::string myTimer::stop_with_message() {
    stop();
    return "Timer has been stopped";
}
std::string myTimer::elapsed() {
    if (!gotNewFirstVal || !gotNewSecondVal) {
        return "Clock has not been started/stopped, start/stop it then check for elapsed time.";
    }
    if (timestamp_b <= timestamp_a) {
        return "Clock has not been started/stopped, start/stop it then check for elapsed time.";
    }
    gotNewFirstVal = false;
    gotNewSecondVal = false;
    return (std::to_string(difftime(timestamp_b, timestamp_a)) + " seconds have passed.");
}

std::string myTimer::prettyprint_elapsed() {
    if (!gotNewFirstVal || !gotNewSecondVal) {
        return "Clock has not been started/stopped, start/stop it then check for elapsed time.";
    }
    if (timestamp_b <= timestamp_a) {
        return "Clock has not been started/stopped, start/stop it then check for elapsed time.";
    }
    gotNewFirstVal = false;
    gotNewSecondVal = false;
    double time_passed = difftime(timestamp_b, timestamp_a);

    if (time_passed <= 0) {
        return "No time has passed.";
    }
    std::stringstream output;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int and_condition = 0;
    if (time_passed >= 86400) {
        and_condition++;
        count_time(time_passed, days, 86400);
    }
    if (time_passed >= 3600) {
        and_condition++;
        count_time(time_passed, hours, 3600);
    }
    if (time_passed >= 60) {
        and_condition++;
        count_time(time_passed, minutes, 60);
    }
    if (time_passed > 0) {
        and_condition++;
        count_time(time_passed, seconds, 1);
    }
    if (days > 0) {
        output << std::to_string(days) + " day";
        populate_stringstream(output, days, and_condition);
    }
    if (hours > 0) {
        output << std::to_string(hours) + " hour";
        populate_stringstream(output, hours, and_condition);
    }
    if (minutes > 0) {
        output << std::to_string(minutes) + " minute";
        populate_stringstream(output, minutes, and_condition);
    }
    if (seconds > 0) {
        output << std::to_string(seconds) + " second";
        populate_stringstream(output, seconds, and_condition);
    }
    output << "passed.";
    return output.str();
}
