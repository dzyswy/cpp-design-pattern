#pragma once

#include "peifang_factory.h"


class PeiLiao : public PeiFang
{
public:
    PeiLiao(std::shared_ptr<PeiFang> peifang) : peifang_(peifang) {

    }

    virtual float cost() {
        return peifang_->cost() + price();
    }

    virtual std::string info() {
        return peifang_->info() + " + " + raw();
    }

    virtual float price() {
        return 2.0;
    }

    virtual std::string raw() {
        return "water + sugar";
    }

public:
    std::shared_ptr<PeiFang> peifang_;
};

class MikeMix : public PeiLiao
{
public:
    MikeMix(std::shared_ptr<PeiFang> peifang) : PeiLiao(peifang), peifang_(peifang) {
        std::cout << "create MikeMix" <<std::endl;
    }

    virtual float cost() {
        return peifang_->cost() + price();
    }

    virtual std::string info() {
        return PeiLiao::info() + " + " + raw();
    }

    float price() {
        std::cout << "get MikeMix price" << std::endl;
        return 2.0;
    }

    std::string raw() {
        std::cout << "get MikeMix raw" << std::endl;
        return "mike";
    }

public:
    std::shared_ptr<PeiFang> peifang_;

};





