#include "drink.h"



int main()
{

    std::shared_ptr<Drink> drink0 = std::make_shared<Drink>();
    std::shared_ptr<MikeMix> drik_mike = std::make_shared<MikeMix>(drink0);
    std::shared_ptr<ZhenZhuMix> naicha = std::make_shared<ZhenZhuMix>(drik_mike);

    std::shared_ptr<Drink> drink1 = std::make_shared<Drink>();
    std::shared_ptr<CaoMeiMix> drik_cm = std::make_shared<CaoMeiMix>(drink1);
    std::shared_ptr<BingKuaiMix> shuiguocha = std::make_shared<BingKuaiMix>(drik_cm);

    std::cout << "naicha peifang: " << naicha->peifang() << ", cost: " << naicha->cost() << std::endl;
    std::cout << "shuiguocha peifang: " << shuiguocha->peifang() << ", cost: " << shuiguocha->cost() << std::endl;

    return 0;
}




