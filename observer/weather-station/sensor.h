#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <typeinfo>
#include <iomanip>

class Value
{
public:
    template<typename T>
    T get() {
        T res;
        std::istringstream iss(str_);
        iss >> res;
        return res;
    }


    template<typename T>
    void set(T value) {
        std::stringstream ss;
        ss << value;
        str_ = ss.str();
    }

    std::string str() {
        return str_;
    }

public:
    std::string str_;  
};


class Sensor
{
public:
    virtual Value get_data() = 0;

};

class TempSensor : public Sensor
{
public:
    Value get_data() {
        Value value;
        value.set<int>(rand() % 100);
        return value;
    }
};

class ShiDuSensor : public Sensor
{
public:
    Value get_data() {
        Value value;
        value.set<int>(rand() % 100);
        return value;
    }
};


class QiYaSensor : public Sensor
{
public:
    Value get_data() {
        Value value;
        value.set<int>(rand() % 100);
        return value;
    }
};






