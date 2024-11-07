#pragma once


#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <iomanip>

#include <glog/logging.h>


class PeiFang
{
public:
    virtual float cost() {
        return 0.0;
    }

    virtual std::string info() {
        return "";
    }
};



typedef std::shared_ptr<PeiFang> (*func_add_peiliao)(std::shared_ptr<PeiFang>);

class PeiFangFactory
{
public:
    static PeiFangFactory* instance() {
        static PeiFangFactory instance;
        return &instance;
    }

    std::shared_ptr<PeiFang> add_peiliao(const std::string& peiliao_name, std::shared_ptr<PeiFang> peifang) {
        auto it = peiliao_map_.find(peiliao_name);
        if (it == peiliao_map_.end()) {
            return std::shared_ptr<PeiFang>();
        }
        return it->second(peifang);
    }

    void peiliao_info();

public:
    std::map<std::string, func_add_peiliao> peiliao_map_;

private:
    PeiFangFactory() {}
    ~PeiFangFactory() {}
    PeiFangFactory(const PeiFangFactory&) = delete;
    PeiFangFactory & operator = (const PeiFangFactory&) = delete;
};

class PeiFangFactoryHelper
{
public:
    PeiFangFactoryHelper(const std::string& peiliao_name, func_add_peiliao func) {
        PeiFangFactory* factory = PeiFangFactory::instance();
        factory->peiliao_map_[peiliao_name] = func;
    }
};




#define REGISTER_PEILIAO(name)                                                          \
    std::shared_ptr<PeiFang> add_##name_func(std::shared_ptr<PeiFang> peifang) {        \
        return std::make_shared<name>(peifang);                                         \
    }                                                                                   \
    PeiFangFactoryHelper helper_##name(#name, add_##name_func)


