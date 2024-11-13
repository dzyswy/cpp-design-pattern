#include "subscriber.h"
#include "customer.h"





void TotalWeatherSubscriber::update(std::shared_ptr<SubjectMessage> message)
{
    std::shared_ptr<TotalWeatherMessage> msg = std::static_pointer_cast<TotalWeatherMessage>(message);

    std::cout << customer_->name() << " TotalWeatherSubscriber update: wendu=" << msg->wendu() << ", shidu=" << msg->shidu() << ", qiya=" << msg->qiya() << std::endl; 
}



void WarningWeatherSubscriber::update(std::shared_ptr<SubjectMessage> message)
{
    std::shared_ptr<WarningWeatherMessage> msg = std::static_pointer_cast<WarningWeatherMessage>(message);

    std::cout << customer_->name() << " WarningWeatherSubscriber update: info=" << msg->info() << std::endl; 
}

