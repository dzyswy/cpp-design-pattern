#pragma once

#include <iostream>
#include <memory>


class Car
{
public:
    void set_body(const std::string& value) {
        body_ = value;
        std::cout << "set_body: " << value << std::endl;
    }

    void set_engine(const std::string& value) {
        engine_ = value;
        std::cout << "set_engine: " << value << std::endl;
    }

    void set_whell(const std::string& value) {
        whell_ = value;
        std::cout << "set_whell: " << value << std::endl;
    }

    void set_type(const std::string& value) {
        type_ = value;
        std::cout << "set_type: " << value << std::endl;
    }

    void info() {
        std::cout << type_ << ": " << body_ << ", " << engine_ << ", " << whell_ << std::endl;
    }

private:
    std::string body_;
    std::string engine_;
    std::string whell_;
    std::string type_;
};


class CarBom
{
public:
    virtual std::shared_ptr<Car> build() {
        std::shared_ptr<Car> car = std::make_shared<Car>();
        install_body(car);
        install_engine(car);
        install_whell(car);
        set_type(car);
        return car;
    }

    virtual void install_body(std::shared_ptr<Car> car) = 0;
    virtual void install_engine(std::shared_ptr<Car> car) = 0;
    virtual void install_whell(std::shared_ptr<Car> car) = 0;
    virtual void set_type(std::shared_ptr<Car> car) = 0;

};

class MotoCarBom : public CarBom
{
public:
    void install_body(std::shared_ptr<Car> car) {
        car->set_body("small body");
    }

    void install_engine(std::shared_ptr<Car> car) {
        car->set_engine("small engine");
    }

    void install_whell(std::shared_ptr<Car> car) {
        car->set_whell("small whell");
    }

    void set_type(std::shared_ptr<Car> car) {
        car->set_type("motocar");
    }

};

class SUVBom : public CarBom
{
public:
    void install_body(std::shared_ptr<Car> car) {
        car->set_body("medium body");
    }

    void install_engine(std::shared_ptr<Car> car) {
        car->set_engine("medium engine");
    }

    void install_whell(std::shared_ptr<Car> car) {
        car->set_whell("medium whell");
    }

    void set_type(std::shared_ptr<Car> car) {
        car->set_type("SUV");
    }

};



class BUSBom : public CarBom
{
public:
    void install_body(std::shared_ptr<Car> car) {
        car->set_body("big body");
    }

    void install_engine(std::shared_ptr<Car> car) {
        car->set_engine("big engine");
    }

    void install_whell(std::shared_ptr<Car> car) {
        car->set_whell("big whell");
    }

    void set_type(std::shared_ptr<Car> car) {
        car->set_type("BUS");
    }

};


class CarProcess
{
public:
    CarProcess(CarBom* bom) : bom_(bom) {

    }
    virtual std::shared_ptr<Car> process() = 0;

protected:
    CarBom* bom_;
};


class MotoCarProcess : public CarProcess
{
public:
    MotoCarProcess(CarBom* bom) : CarProcess(bom) {

    }

    virtual std::shared_ptr<Car> process() {
        std::shared_ptr<Car> car = std::make_shared<Car>();
        std::cout << "product motocar ..." << std::endl;
        bom_->install_body(car);
        bom_->install_engine(car);
        bom_->install_whell(car);
        bom_->set_type(car);
        std::cout << "product motocar ok!" << std::endl;
        std::cout << std::endl;
        return car;
    }
};

class SUVProcess : public CarProcess
{
public:
    SUVProcess(CarBom* bom) : CarProcess(bom) {

    }
    
    virtual std::shared_ptr<Car> process() {
        std::shared_ptr<Car> car = std::make_shared<Car>();
        std::cout << "product suv ..." << std::endl;
        bom_->install_engine(car);
        bom_->install_whell(car);
        bom_->install_body(car);
        bom_->set_type(car);
        std::cout << "product suv ok!" << std::endl;
        std::cout << std::endl;
        return car;
    }
};

class BUSProcess : public CarProcess
{
public:
    BUSProcess(CarBom* bom) : CarProcess(bom) {

    }
    
    virtual std::shared_ptr<Car> process() {
        std::shared_ptr<Car> car = std::make_shared<Car>();
        std::cout << "product bus ..." << std::endl;
        bom_->install_engine(car);
        bom_->install_whell(car);
        bom_->install_body(car);
        bom_->set_type(car);
        std::cout << "product bus ok!" << std::endl;
        std::cout << std::endl;
        return car;
    }
};


