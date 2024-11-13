#include "publisher.h"






Publisher::Publisher() 
{

    total_message_ = std::make_shared<TotalWeatherMessage>();
    warning_message_ = std::make_shared<WarningWeatherMessage>();

    std::shared_ptr<Subject> total_subject = std::make_shared<Subject>();
    std::shared_ptr<Subject> warning_subject = std::make_shared<Subject>();

    subject_map_["TotalWeatherSubject"] = total_subject;
    subject_map_["WarningWeatherSubject"] = warning_subject;
}


void Publisher::process(float wendu, float shidu, float qiya) 
{

    total_message_->set_wendu(wendu);
    total_message_->set_shidu(shidu);
    total_message_->set_qiya(qiya);
    subject_map_["TotalWeatherSubject"]->notify(total_message_);

    if (wendu > 38.0) {
        warning_message_->set_info("Hot weather warning!");
        subject_map_["WarningWeatherSubject"]->notify(warning_message_);
    }
    else if (wendu < -20.0) {
        warning_message_->set_info("Cold weather warning!");
        subject_map_["WarningWeatherSubject"]->notify(warning_message_);
    }

}

std::shared_ptr<Subject> Publisher::get_subject(const std::string& subject_name) 
{
    return subject_map_[subject_name];
}





