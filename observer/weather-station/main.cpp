#include <iostream>


#include "publisher.h"
#include "subscriber.h"
#include "customer.h"

int main(int argc, char* argv[])
{
 
    Publisher weather_station;
    std::shared_ptr<Subject> total_subject = weather_station.get_subject("TotalWeatherSubject");
    std::shared_ptr<Subject> warning_subject = weather_station.get_subject("WarningWeatherSubject");

    
    Customer tom("tom");
    tom.subscribe(total_subject, "TotalWeatherSubscriber");
    tom.subscribe(warning_subject, "WarningWeatherSubscriber");

    Customer jack("jack"); 
    jack.subscribe(warning_subject, "WarningWeatherSubscriber");

    weather_station.process(11, 22, 33);
    weather_station.process(50, 22, 33);
    weather_station.process(-34, 22, 33);

    return 0;
}




