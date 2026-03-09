#ifndef _MENU_
#define _MENU_
#include <functional>
#include <iostream>
#include <string>
#include <vector>

typedef std::function<void()> MenuAction;

class MenuItem {
    std::string label_;
    MenuAction menu_action_;

   public:
    MenuItem(const std::string& label, MenuAction menu_action)
        : label_(label), menu_action_(menu_action) {}

    void Execute() const {
        if (menu_action_) {
            menu_action_();
        }
    }

    const std::string& label() const { return label_; }
};

class Menu {
    std::vector<MenuItem> items_;
    void PrintMenu() const {
        std::cout << "ДЕЙСТВИЯ:\n";
        for (size_t i = 0; i < items_.size(); i++) {
            std::cout << i + 1 << ". " << items_[i].label() << "\n";
        }
        std::cout << std::endl;
    }

   public:
    void AddItem(const MenuItem& item) { items_.push_back(item); }

    void Run() {
        size_t choice;
        do {
            PrintMenu();
            std::cout << "Перейти в пункт: ";
            std::cin >> choice;
            std::cin.ignore();

            if (choice > 0 && choice <= items_.size()) {
                items_[choice - 1].Execute();
                std::cout << std::endl;
            } else if (choice != 0) {
                std::cout << "Некорректный номер. Попробуйте ещё раз."
                          << std::endl;
            }
        } while (choice != 0);
    }
};

#endif
