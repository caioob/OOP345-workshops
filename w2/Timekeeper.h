#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <chrono>

namespace sict{
    const int MAX_RECS = 10;
    class Timekeeper{
        int noOfRecord;
        std::chrono::steady_clock::time_point startWatch;
        std::chrono::steady_clock::time_point stopWatch;
        struct{
            char* eventDescription;
            char* unit;
            std::chrono::steady_clock::duration durationWatch;
        } rec[MAX_RECS];
    public:
        Timekeeper();
        void start();// call the now fuction from chrono at respective object
        void stop();
        void recordEvent(char*); // duration = stopWatch - startWatch
        void report(std::ostream&);
    };
}

#endif // SICT_TIMEKEEPER_H
