#pragma once


#include <iostream>
#include <memory>


class BaseHero
{
public:

    virtual void attack() {
        std::cout << "normal attack" << std::endl;
    }

    virtual void show() {
        std::cout << "display base icons" << std::endl;
    }
};

class GameEquipment : public BaseHero
{
public:
    GameEquipment(std::shared_ptr<BaseHero> hero) :  hero_(hero) {}
    virtual void attack() {
        hero_->attack();
    }

    virtual void show() {
        hero_->show();
    }
    

private:
    std::shared_ptr<BaseHero> hero_;
};

//狂战斧
class KuangZhanFu : public GameEquipment 
{
public:
    KuangZhanFu(std::shared_ptr<BaseHero> hero) : GameEquipment(hero) {
        std::cout << "Put On KuangZhanFu" << std::endl;
    }


    virtual void attack() {
        splash_attack();
        GameEquipment::attack();
    }

    virtual void show() {
        fuzi_show();
        GameEquipment::show();
    }

    void splash_attack() {
        std::cout << "splash_attack" << std::endl;
    }

    void fuzi_show() {
        std::cout << "display fuzi icons" << std::endl;
    }
 
};

//散失之刃
class SanShiZhiRen : public GameEquipment
{
public:
    SanShiZhiRen(std::shared_ptr<BaseHero> hero) : GameEquipment(hero) {
        std::cout << "Put On SanShiZhiRen" << std::endl;
    }

    virtual void attack() {
        feedback_attack();
        GameEquipment::attack();
    }

    virtual void show() {
        dadao_show();
        GameEquipment::show();
    }

    void feedback_attack() {
        std::cout << "feedback_attack" << std::endl;
    }

    void dadao_show() {
        std::cout << "display dadao icons" << std::endl;
    }
};











