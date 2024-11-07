#include "hero.h"




int main()
{

    std::shared_ptr<BaseHero> hero = std::make_shared<BaseHero>();
    std::shared_ptr<BaseHero> hero_kzf = std::make_shared<KuangZhanFu>(hero);
    std::shared_ptr<BaseHero> hero_ssr = std::make_shared<SanShiZhiRen>(hero_kzf);

    std::cout << "-------------------------------------------" << std::endl;
    hero->attack();
    hero->show();

    std::cout << "-------------------------------------------" << std::endl;
    hero_ssr->attack();
    hero_ssr->show();

    return 0;
}








