#include "drink.h"
#include "peiliao.h"



void test();

int main(int argc, char* argv[])
{
    google::InstallFailureSignalHandler();
    google::InitGoogleLogging(argv[0]);

    FLAGS_stderrthreshold = 0;
    FLAGS_minloglevel = 0;

    PeiFangFactory* factory = PeiFangFactory::instance();
    factory->peiliao_info();

    //test();

    Drink naicha;

    naicha.add_peiliao("MikeMix"); 
    naicha.add_peiliao("MikeMix"); 
    naicha.add_peiliao("ZhenZhuMix");

    naicha.shouyao(); 

    std::cout << "naicha: cost = " << naicha.cost() << ", info = " << naicha.info() << std::endl;

    Drink shuiguocha;

    shuiguocha.add_peiliao("CaoMeiMix"); 
    shuiguocha.add_peiliao("BingKuaiMix");

    shuiguocha.shouyao(); 

    std::cout << "shuiguocha: cost = " << shuiguocha.cost() << ", info = " << shuiguocha.info() << std::endl;

    return 0;
}


void test()
{
    std::shared_ptr<PeiFang> p0 = std::make_shared<PeiFang>();
    std::cout << "p0: cost=" << p0->cost() << std::endl;

    std::shared_ptr<PeiFang> p1 = std::make_shared<MikeMix>(p0);
    std::shared_ptr<PeiFang> p2 = std::make_shared<MikeMix>(p1);
    std::shared_ptr<PeiFang> p3 = std::make_shared<MikeMix>(p2);

    std::cout << "p3: cost=" << p3->cost() << std::endl;

}



