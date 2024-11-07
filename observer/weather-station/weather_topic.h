#pragma once


class TopicMessage
{
public:

};


class WeatherTopic
{
public:
    void add_subscriber(std::shared_ptr<Subscriber> subscriber) {
        subscriber_vec_.push_back(subscriber);
    }

    void del_subscriber(std::shared_ptr<Subscriber> subscriber) {
        int id = -1;
        for (size_t i = 0; i < subscriber_vec_.size(); i++) {
            if (subscriber == subscriber_vec_[i]) {
                id = i;
                break;
            }
        }
        if (id >= 0) {
            subscriber_vec_.erase(subscriber_vec_.begin() + id);
        }
    }

    void notify(TopicMessage msg) {
        for (size_t i = 0; i < subscriber_vec_.size(); i++) {
            subscriber_vec_[i]->receive_message(msg);
        }
    }

protected:
    std::vector<std::shared_ptr<Subscriber> > subscriber_vec_;

};



class AllDataTopic : public WeatherTopic
{

};














