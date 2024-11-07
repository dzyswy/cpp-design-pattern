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

    test();

    // Drink naicha;

    // naicha.add_peiliao("MikeMix");
    // naicha.add_peiliao("MikeMix");
    // naicha.add_peiliao("MikeMix");

    // std::cout << "naicha: cost=" << naicha.cost() << std::endl;



    return 0;
}


void test()
{
    std::shared_ptr<PeiFang> p0 = std::make_shared<PeiFang>();

    std::shared_ptr<PeiFang> p1 = std::make_shared<MikeMix>(p0);
    std::shared_ptr<PeiFang> p2 = std::make_shared<MikeMix>(p1);
    std::shared_ptr<PeiFang> p3 = std::make_shared<MikeMix>(p2);

    std::cout << "p3: cost=" << p3->cost() << std::endl;

}



