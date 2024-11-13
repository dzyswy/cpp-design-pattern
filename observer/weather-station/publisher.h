#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <list>

#include "subject.h"




class Publisher
{
public:
    Publisher();


    void process(float wendu, float shidu, float qiya);

    std::shared_ptr<Subject> get_subject(const std::string& subject_name);
protected:
    std::map<std::string, std::shared_ptr<Subject> > subject_map_;

    std::shared_ptr<TotalWeatherMessage> total_message_;
    std::shared_ptr<WarningWeatherMessage> warning_message_;
};









