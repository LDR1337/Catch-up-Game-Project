#include "menu.h"

void menu :: _menu(sf::RenderWindow &window) {

    sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
    menuTexture1.loadFromFile("images/111.png");
    menuTexture2.loadFromFile("images/333.png");
    menuBackground.loadFromFile("images/123.jpg");
    sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(750, 300);
    menu2.setPosition(750, 500);
    menuBg.setPosition(0, 0);

    while (isMenu) {
        menu1.setColor(sf::Color::White);
        menu2.setColor(sf::Color::White);
        menuNum = 0;
        window.clear(sf::Color(129, 181, 221));

        if (sf::IntRect(750, 300, 770, 310).contains(sf::Mouse::getPosition(window))) {
            menu1.setColor(sf::Color::Blue);
            menuNum = 1;
        }
        if (sf::IntRect(750, 500, 770, 450).contains(sf::Mouse::getPosition(window))) {
            menu2.setColor(sf::Color::Blue);
            menuNum = 2;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (menuNum == 1) isMenu = false;
            if (menuNum == 2) {
                window.close();
                isMenu = false;
            }

        }

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);

        window.display();
    }

};