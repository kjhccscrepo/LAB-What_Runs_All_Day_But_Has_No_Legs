#include "my_time_logic.hpp"
void my_wait(const int &seconds_whole) {
    time_t initial_time = time(nullptr);
    time_t current_time;
    while (true) {
        current_time = time(nullptr);
        if (current_time >= initial_time + seconds_whole) {
            break;
        }
    }
}