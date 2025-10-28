#ifndef MYCLOCK_H
#define MYCLOCK_H
#include <ctime>
#include <string>
class myClock {
    private:
    time_t timestamp_a;
    time_t timestamp_b;
    bool gotNewFirstVal;
    bool gotNewSecondVal;
    public:
    myClock();
    void start();
    void stop();
    std::string start_with_message();
    std::string stop_with_message();
    std::string elapsed();
};
#endif