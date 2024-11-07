#pragma once




class WeatherData
{
public:
    std::map<std::string, Value> sensor_data_map_;
};


class WeatherStation
{
public:
    WeatherStation() {

        std::shared_ptr<WeatherTopic> > all_data_topic = 
    }

    void add_sensor(const std::string& sensor_name, Sensor* sensor) {

    }

    void process() {
        
        TotalTopicMessage total_message(wendu_, qiya_, shidu_);
        StringTopicMessage hot_message("It's too hot!");
        StringTopicMessage cold_message("It's too cold!");

        weather_topic_map_["total_topic"]->notify(total_message);

        if (wendu_ > 38) {
            weather_topic_map_["cold_topic"]->notify(total_message);
        }

        if (wendu_ < -10) {
            weather_topic_map_["cold_topic"]->notify(total_message);
        }
    }


    int subscribe_topic(const std::string& topic_name, std::shared_ptr<Subscriber> > subscriber) {
        auto weather_topic = weather_topic_map_.find(topic_name);
        if (weather_topic == weather_topic_map_.end()) {
            return -1;
        }

        weather_topic->add_subscriber(subscriber);

        return 0;
    }

    void unsubscribe_topic(const std::string& topic_name, std::shared_ptr<Subscriber> > subscriber) {
        auto weather_topic = weather_topic_map_.find(topic_name);
        if (weather_topic == weather_topic_map_.end()) {
            return;
        }

        weather_topic->del_subscriber(subscriber);
    }


protected: 

    std::map<std::string, std::shared_ptr<WeatherTopic> > weather_topic_map_;

    float wendu_;
    float qiya_;
    float shidu_;
};


class 














