#include <iostream>
#include "src/my_clock.hpp"
#include "src/my_time_logic.hpp"
int main() {
    myClock timer;
    timer.start();
    my_wait(5);
    timer.stop();
    std::cout << timer.elapsed() << std::endl;
    timer.start();
    my_wait(1);
    std::cout << timer.elapsed() << std::endl;      // this displays my error message
    my_wait(2);
    timer.stop();
    std::cout << timer.elapsed() << std::endl;
    return 0;
}
