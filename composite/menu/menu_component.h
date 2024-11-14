#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <typeinfo>
#include <iomanip>
#include <vector>
#include <list>

#include <glog/logging.h>


class MenuComponent
{
public:
    MenuComponent(const std::string& name) : name_(name), level_(0), parent_(this) {}

    virtual void set_parent(MenuComponent* parent) {
        parent_ = parent;
    }



    virtual void set_level(int level) {
        level_ = level;
    }

    virtual void inc_level() = 0;

    MenuComponent* parent() {
        return parent_;
    }

    

    virtual int level() {
        return level_;
    }

    virtual std::string name() {
        return name_;
    }
    virtual bool is_leaf() {return true;}
    virtual void inc() = 0;
    virtual void dec() = 0;
    virtual MenuComponent* move_left() = 0;
    virtual MenuComponent* move_right() = 0;
    virtual void show() = 0;

protected:
    std::string name_;
    int level_;
    MenuComponent* parent_;
};


class MenuBar;
class MenuItem : public MenuComponent
{
public:
    MenuItem(const std::string& name) : MenuComponent(name) {}

    void inc() {
        std::cout << name() << " param inc !" << std::endl;
    }

    void dec() {
        std::cout << name() << " param dec !" << std::endl;
    }

    MenuComponent* move_left();

    MenuComponent* move_right();


    virtual void inc_level() {
        level_++;
    }

    void show() { 
        std::stringstream ss;
        for (int i = 0; i < level(); i++) {
            ss << "\t";
        }
        ss << "├── " << name() << ", parent=" << parent()->name();
        std::cout << ss.str() << std::endl;
    }


};

class MenuBar : public MenuComponent
{
public:
    MenuBar(const std::string& name) : MenuComponent(name) {}

    bool is_leaf() {return false;}

    void add_child(MenuComponent* child) {
        child->set_parent(this);
        child->inc_level();
        child_list_.push_back(child);
    }

    MenuComponent* head_child() {
        return *child_list_.begin();
    }

    MenuComponent* tail_child() {
        return *child_list_.end();
    }

    MenuComponent* find_left_child(MenuComponent* child) {

        MenuComponent* next_child = child;
        for (auto it = child_list_.begin(); it != child_list_.end(); ++it) {
            if (((*it) == child) && ((*it) != child_list_.front()))
            {
                next_child = *std::prev(it);
                break;
            }
        } 
        return next_child;
    }

    MenuComponent* find_right_child(MenuComponent* child) {

        MenuComponent* next_child = child;
        for (auto it = child_list_.begin(); it != child_list_.end(); ++it) { 
            if (((*it) == child) && ((*it) != child_list_.back()))
            {
                next_child = *std::next(it);
                break;
            }
        } 
        return next_child;
    }


    void inc() {
        std::cout << name() << " is composite, can't inc !" << std::endl;
    }

    void dec() {
        std::cout << name() << " is composite, can't dec !" << std::endl;
    }

    MenuComponent* move_left() {
        MenuBar* bar = (MenuBar*)parent();
        return bar->find_left_child(this);
    }

    MenuComponent* move_right() {
        MenuBar* bar = (MenuBar*)parent();
        return bar->find_right_child(this);
    }

    virtual void inc_level() {
        level_++;
        for (const auto child : child_list_) {
            child->inc_level();
        }
    }

    void show() {  
        std::stringstream ss;
        for (int i = 0; i < level(); i++) {
            ss << "\t";
        }
        ss << "├── " << name() << ", parent=" << parent()->name();
        std::cout << ss.str() << std::endl;
        for (const auto child : child_list_) { 
            child->show();
        }
    }

protected:
    std::list<MenuComponent* > child_list_;
};



class MenuManager
{
public:
    MenuManager(MenuBar* root) : root_(root), hot_ptr_(root->head_child()) {}

    void menu_left() { 
        hot_ptr_ = hot_ptr_->move_left();  
    }

    void menu_right() { 
        hot_ptr_ = hot_ptr_->move_right(); 
    }

    std::string hot_item_name() {
        return hot_ptr_->name();
    }

    void menu_inc() {
        hot_ptr_->inc();
    }

    void menu_dec() {
        hot_ptr_->dec();
    }

    void menu_ok() {
        if (!hot_ptr_->is_leaf()) {
            MenuBar* bar = (MenuBar*)hot_ptr_;
            hot_ptr_ = bar->head_child();
        } 
    }

    void menu_cancel() {
        hot_ptr_ = hot_ptr_->parent();
    }

protected:
    MenuBar* root_;
    MenuComponent* hot_ptr_;
};









