#include <string>
#include <iostream>
#include "LogDuration.h"
#include <chrono>

using namespace std;

LogDuration::LogDuration(const string& msg) : message(msg + ": "), start(chrono::steady_clock::now()) {};

LogDuration::~LogDuration() {
    auto finish = chrono::steady_clock::now();
    auto dur = finish - start;
    cerr << message
         << chrono::duration_cast<chrono::milliseconds>(dur).count()
         << " ms" << endl;
};
