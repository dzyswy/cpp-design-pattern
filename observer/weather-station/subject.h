#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <vector>

class SubjectMessage
{

};


class TotalWeatherMessage : public SubjectMessage
{
public:
    TotalWeatherMessage() {}
    TotalWeatherMessage(float wendu, float qiya, float shidu) : wendu_(wendu), qiya_(qiya), shidu_(shidu) {}
    void set_wendu(float value) {wendu_ = value;}
    void set_shidu(float value) {shidu_ = value;}
    void set_qiya(float value) {qiya_ = value;}

    float wendu() {return wendu_;}
    float shidu() {return shidu_;}
    float qiya() {return qiya_;}
protected:
    float wendu_;
    float qiya_;
    float shidu_;
};


class WarningWeatherMessage : public SubjectMessage
{
public:
    void set_info(const std::string& value) {
        warning_info_ = value;
    }

    std::string info() {
        return warning_info_;
    }

protected:
    std::string warning_info_;
};


class Subscriber;
class Subject
{
public:
    virtual void subscribe(std::shared_ptr<Subscriber> subscriber);
    virtual void unsubscribe(std::shared_ptr<Subscriber> subscriber);
    virtual void notify(std::shared_ptr<SubjectMessage> message);


protected:
    std::vector<std::shared_ptr<Subscriber> > subscribers_;
};











