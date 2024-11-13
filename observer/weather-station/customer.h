#pragma once


#include "subscriber.h"

class Customer
{
public:
    Customer(const std::string& name) : name_(name) {}
    
    virtual void subscribe(std::shared_ptr<Subject> subject, const std::string& subscriber_name) {

        if (subscriber_name == "TotalWeatherSubscriber") {
            std::shared_ptr<Subscriber> subscriber = std::make_shared<TotalWeatherSubscriber>(this);
            subscriber_map_["TotalWeatherSubscriber"] = subscriber;
            subject->subscribe(subscriber);
        }
        if (subscriber_name == "WarningWeatherSubscriber") {
            std::shared_ptr<Subscriber> subscriber = std::make_shared<WarningWeatherSubscriber>(this);
            subscriber_map_["WarningWeatherSubscriber"] = subscriber;
            subject->subscribe(subscriber);
        }
        
    }

    std::string name() {
        return name_;
    }

protected:
    std::string name_;
    std::map<std::string, std::shared_ptr<Subscriber> > subscriber_map_;
};












