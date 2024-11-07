#pragma once



class Subscriber
{
public:
    virtual void receive_message(TopicMessage msg) = 0;
};











