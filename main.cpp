#include <iostream>
#include "src/my_timer.hpp"
#include "src/my_time_logic.hpp"
int main() {
    myTimer timer;
    timer.start();
    my_wait(2);
    timer.stop();
    std::cout << timer.elapsed() << std::endl;
    timer.start();
    my_wait(1);
    std::cout << timer.elapsed() << std::endl; // this will throw the error message.
    my_wait(2);
    timer.stop();
    std::cout << timer.elapsed() << std::endl;
    timer.start();
    my_wait(1);
    timer.stop();
    std::cout << timer.prettyprint_elapsed() << std::endl;
    timer.start();
    my_wait(2);
    timer.stop();
    std::cout << timer.prettyprint_elapsed() << std::endl;
    timer.start();
    my_wait(5);
    timer.stop();
    std::cout << timer.prettyprint_elapsed() << std::endl;
    return 0;
}
