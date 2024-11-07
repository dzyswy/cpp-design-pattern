#pragma once


#include "peifang_factory.h"


class Drink
{
public:
    float cost() {

        std::vector<std::shared_ptr<PeiFang> > peifangs;
        peifangs.push_back(std::make_shared<PeiFang>());
        for (size_t i = 0; i < peiliao_name_vec_.size(); i++) {
            PeiFangFactory* factory = PeiFangFactory::instance();
            std::shared_ptr<PeiFang> peifang = factory->add_peiliao(peiliao_name_vec_[i], peifangs[i]);
            peifangs.push_back(peifang);
        }
        float money = peifangs[peifangs.size() - 1]->cost();
        return money;
    }

    void add_peiliao(const std::string& peiliao_name) {
        peiliao_name_vec_.push_back(peiliao_name);
    }

protected:
    std::vector<std::string> peiliao_name_vec_; 
     
};












