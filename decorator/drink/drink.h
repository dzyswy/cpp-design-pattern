#pragma once


#include "peifang_factory.h"


class Drink
{
public:

    void add_peiliao(const std::string& peiliao_name) {
        peiliao_name_vec_.push_back(peiliao_name);
    }

    void shouyao() {
        peifang_vec_.clear();
        peifang_vec_.push_back(std::make_shared<PeiFang>());
        for (size_t i = 0; i < peiliao_name_vec_.size(); i++) {
            PeiFangFactory* factory = PeiFangFactory::instance();
            std::shared_ptr<PeiFang> peifang = factory->add_peiliao(peiliao_name_vec_[i], peifang_vec_[i]);
            peifang_vec_.push_back(peifang);
        }
    }

    float cost() {
        if (peifang_vec_.size() == 0) {
            return 0;
        }

        return peifang_vec_[peifang_vec_.size() - 1]->cost(); 
    }

    std::string info() {
        if (peifang_vec_.size() == 0) {
            return std::string();
        }

        return peifang_vec_[peifang_vec_.size() - 1]->info(); 
    }


protected:
    std::vector<std::string> peiliao_name_vec_; 
    std::vector<std::shared_ptr<PeiFang> > peifang_vec_;
};












