#ifndef MENU
#define MENU

#include "main.hpp"

//Redefinition of class so compiler wont complain
class MyButton;

class Menu{
    public:
        //functions
        Menu();
        void handleInput(sf::Event event);
        void Render();

        //variables
        sf::RenderWindow *app;

    private:
        std::vector<MyButton> buttonArray;
        std::string age_result{" "};
};




#endif