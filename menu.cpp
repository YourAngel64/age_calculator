#include "menu.hpp"

#include "buttonFunctions.hpp"

using namespace std::string_view_literals;


Menu::Menu(){
    
}


// [/*args*/]() { testFunction(/*args*/); });
MyButton calculate;

void Menu::Render(){
    sf::Font font;
    font.loadFromFile("C:\\Users\\angel\\Documents\\coding\\age_calculator\\Arial.ttf");

    std::string_view dob{"08/04/2006"};

    calculate.app = app;
    calculate.font = font;
    calculate.createButton(sf::Vector2f(100.f, 120.f), sf::Color::Black, renderAge, dob);
    calculate.setButtonPosition(sf::Vector2f(10.f, 20.f));
    calculate.setButtonText("Calculate Age"sv, sf::Color::White);
    buttonArray.push_back(calculate);

    //cast result for age
    if(calculate.results.has_value()){
       age_result = std::any_cast<std::string>(calculate.results);
    }

    sf::Text age;
    age.setFont(font);
    age.setString(age_result);
    age.setFillColor(sf::Color::Black);
    age.move(sf::Vector2f(500.f, 100.f));
    

    for(MyButton button: buttonArray){
        button.drawButton(app);
        app->draw(age);
    }
}

void Menu::handleInput(sf::Event event){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
    }    
}

