#pragma once

#include "peifang_factory.h"


class PeiLiao : public PeiFang
{
public:
    virtual float price() = 0;
    virtual std::string raw() = 0;
 
};

class MikeMix : public PeiLiao
{
public:
    MikeMix(std::shared_ptr<PeiFang> peifang) : peifang_(peifang) { 
    }

    virtual float cost() {
        return peifang_->cost() + price();
    }

    virtual std::string info() {
        return peifang_->info() + " + " + raw();
    }

    float price() { 
        return 2.0;
    }

    std::string raw() { 
        return "mike";
    }

protected:
    std::shared_ptr<PeiFang> peifang_;
};

class ZhenZhuMix : public PeiLiao
{
public:
    ZhenZhuMix(std::shared_ptr<PeiFang> peifang) : peifang_(peifang) { 
    }

    virtual float cost() {
        return peifang_->cost() + price();
    }

    virtual std::string info() {
        return peifang_->info() + " + " + raw();
    }

    float price() { 
        return 1.2;
    }

    std::string raw() { 
        return "zhenzhu";
    }

protected:
    std::shared_ptr<PeiFang> peifang_;
};


class CaoMeiMix : public PeiLiao
{
public:
    CaoMeiMix(std::shared_ptr<PeiFang> peifang) : peifang_(peifang) { 
    }

    virtual float cost() {
        return peifang_->cost() + price();
    }

    virtual std::string info() {
        return peifang_->info() + " + " + raw();
    }

    float price() { 
        return 3.0;
    }

    std::string raw() { 
        return "caomei";
    }

protected:
    std::shared_ptr<PeiFang> peifang_;
};

class BingKuaiMix : public PeiLiao
{
public:
    BingKuaiMix(std::shared_ptr<PeiFang> peifang) : peifang_(peifang) { 
    }

    virtual float cost() {
        return peifang_->cost() + price();
    }

    virtual std::string info() {
        return peifang_->info() + " + " + raw();
    }

    float price() { 
        return 1.0;
    }

    std::string raw() { 
        return "bingkuai";
    }

protected:
    std::shared_ptr<PeiFang> peifang_;
};
