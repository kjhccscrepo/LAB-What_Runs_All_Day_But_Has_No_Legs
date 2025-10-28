#ifndef MYCLOCK_H
#define MYCLOCK_H
#include <ctime>
#include <string>
#include <sstream>
class myTimer {
    private:
    time_t timestamp_a;
    time_t timestamp_b;
    bool gotNewFirstVal;
    bool gotNewSecondVal;
    static void count_time(double &time, int &time_box, const int &iterationAmount);
    static void populate_stringstream(std::stringstream &ss, const int &box_to_count, int &and_con);
    public:
    myTimer();
    void start();
    void stop();
    std::string start_with_message();
    std::string stop_with_message();
    std::string elapsed();
    std::string prettyprint_elapsed();
};
#endif