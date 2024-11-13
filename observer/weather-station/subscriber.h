#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "subject.h"

class Customer;

class Subscriber
{
public:
    Subscriber(Customer* customer) : customer_(customer) {}
    virtual void update(std::shared_ptr<SubjectMessage> message) = 0;

protected:
    Customer* customer_;
};




class TotalWeatherSubscriber : public Subscriber
{
public:
    TotalWeatherSubscriber(Customer* customer) : Subscriber(customer) {}
    virtual void update(std::shared_ptr<SubjectMessage> message);
};

class WarningWeatherSubscriber : public Subscriber
{
public:
    WarningWeatherSubscriber(Customer* customer) : Subscriber(customer) {}
    virtual void update(std::shared_ptr<SubjectMessage> message);
};





