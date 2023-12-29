#ifndef LOGDURATION_H
#define LOGDURATION_H

#include <iostream>
#include <string>
#include <chrono>
using namespace std;

class LogDuration {
private:
    chrono::steady_clock::time_point start;
    string message;

public:
    explicit LogDuration(const string& msg);
    ~LogDuration();

};

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};
#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#endif // LOGDURATION_H
