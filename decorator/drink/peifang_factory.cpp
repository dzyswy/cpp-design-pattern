#include "peifang_factory.h"

#include "peiliao.h"


void PeiFangFactory::peiliao_info() 
{
    std::cout << std::left << std::setw(40) << std::setfill('-')<< "peiliao list begin"  << std::setfill(' ') << std::endl;  
    std::cout << std::left << std::setw(20) << "peiliao_name" << std::setw(20) << "price" << std::setw(20) << "raw" << std::endl; 
    for (const auto &pair : peiliao_map_) { 
        std::string name = pair.first;
        std::shared_ptr<PeiFang> peifang = pair.second(std::make_shared<PeiFang>());
        std::shared_ptr<PeiLiao> peiliao = std::dynamic_pointer_cast<PeiLiao>(peifang);
        float price = peiliao->price();
        std::string raw = peiliao->raw();
        std::cout << std::left << std::setw(20) <<  pair.first << std::setw(20) << price << std::setw(20) << raw << std::endl;
    } 
    std::cout << std::left << std::setw(40) << std::setfill('-')<< "peiliao list end"  << std::setfill(' ') << std::endl;  
    std::cout << std::endl;
}

