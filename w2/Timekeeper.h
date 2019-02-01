#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include<chrono>

namespace sict{
    const int MAX_RECS = 10;
    class Timekeeper{
        int noOfRecord = 0;
        std::chrono::steady_clock::time_point startWatch;
        std::chrono::steady_clock::time_point stopWatch;
        struct{
            char* structMessage;
            char* structUnit;
            std::chrono::steady_clock::duration durationWatch;
        } rec[MAX_RECS];
    public:
        Timekeeper();
        void start();// call the now fuction from chrono at respective object
        void stop();
        recordEvent(const char*); // duration = stopWatch - startWatch
        void report(std::ostream&);
    };
}

#endif // SICT_TIMEKEEPER_H
