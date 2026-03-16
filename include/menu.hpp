#ifndef _MENU_
#define _MENU_
#include <exception>
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
    }

   public:
    void AddItem(const MenuItem& item) { items_.push_back(item); }

    void Run() {
        std::string input = "";
        bool should_exit = false;

        MenuItem exit =
            MenuItem("Выйти", [&should_exit]() { should_exit = true; });
        AddItem(exit);

        while (!should_exit) {
            PrintMenu();
            std::cout << "Перейти в пункт: ";
            std::getline(std::cin, input);
            size_t choice = 0;
            try {
                choice = std::stoul(input);
            } catch (const std::exception& _) {
                std::cerr << "Номер не распознан. Попробуйте ещё раз."
                          << std::endl;
                continue;
            }
            if (choice > items_.size()) {
                std::cerr << "Некорректный номер. Попробуйте ещё раз."
                          << std::endl;
                continue;
            }
            items_[choice - 1].Execute();
            std::cout << std::endl;
        };
    }
};

#endif
