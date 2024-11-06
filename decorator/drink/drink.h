#pragma once


#include <iostream>
#include <memory>

class Drink
{
public:
    virtual float cost() {
        return 5.0;
    }

    virtual std::string peifang() {
        return "tea + water + sugar";
    }

};


class PeiLiao : public Drink
{
public:
    PeiLiao(std::shared_ptr<Drink> drink) : drink_(drink) {

    }

    virtual float cost() {
        return drink_->cost();
    }

    virtual std::string peifang() {
        return drink_->peifang();
    }

private:
    std::shared_ptr<Drink> drink_;
};


class MikeMix : public PeiLiao
{
public:
    MikeMix(std::shared_ptr<Drink> drink) : PeiLiao(drink) {

    }

    virtual float price() {
        return 3.0;
    }

    virtual std::string element() {
        return "mike";
    }

    virtual float cost() {
        float money = price() + PeiLiao::cost();
        return money;
    }

    virtual std::string peifang() {
        std::string str = element() + " + " + PeiLiao::peifang();
        return str;
    }

};


class ZhenZhuMix : public PeiLiao
{
public:
    ZhenZhuMix(std::shared_ptr<Drink> drink) : PeiLiao(drink) {

    }

    virtual float price() {
        return 2.0;
    }

    virtual std::string element() {
        return "zhenzhu";
    }

    virtual float cost() {
        float money = price() + PeiLiao::cost();
        return money;
    }

    virtual std::string peifang() {
        std::string str = element() + " + " + PeiLiao::peifang();
        return str;
    }

};


class CaoMeiMix : public PeiLiao
{
public:
    CaoMeiMix(std::shared_ptr<Drink> drink) : PeiLiao(drink) {

    }

    virtual float price() {
        return 2.5;
    }

    virtual std::string element() {
        return "caomei";
    }

    virtual float cost() {
        float money = price() + PeiLiao::cost();
        return money;
    }

    virtual std::string peifang() {
        std::string str = element() + " + " + PeiLiao::peifang();
        return str;
    }

};

class BingKuaiMix : public PeiLiao
{
public:
    BingKuaiMix(std::shared_ptr<Drink> drink) : PeiLiao(drink) {

    }

    virtual float price() {
        return 1.0;
    }

    virtual std::string element() {
        return "bingkuai";
    }

    virtual float cost() {
        float money = price() + PeiLiao::cost();
        return money;
    }

    virtual std::string peifang() {
        std::string str = element() + " + " + PeiLiao::peifang();
        return str;
    }

};

