#include "subject.h"
#include "subscriber.h"




void Subject::subscribe(std::shared_ptr<Subscriber> subscriber) 
{
    subscribers_.push_back(subscriber);
}

void Subject::unsubscribe(std::shared_ptr<Subscriber> subscriber) 
{

    int id = -1;
    for (size_t i = 0; i < subscribers_.size(); i++) {
        if (subscribers_[i] == subscriber) {
            id = i;
            break;
        }
    }
    if (id >= 0) {
        subscribers_.erase(subscribers_.begin() + id);
    }
    
}

void Subject::notify(std::shared_ptr<SubjectMessage> message) 
{
    for (const auto it : subscribers_) {
        it->update(message);
    }
}












