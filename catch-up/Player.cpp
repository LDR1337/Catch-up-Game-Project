#include "Player.h"


void Player :: control() {
    if (life == true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            state = left;
            speed = 0.25;
            sprite.setTextureRect(sf::IntRect(0, 0, 23, 18));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            state = right;
            speed = 0.25;
            sprite.setTextureRect(sf::IntRect(23, 0, -23, 18));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            state = up;
            speed = 0.25;
            sprite.setTextureRect(sf::IntRect(0, 0, 23, 18));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            state = down;
            speed = 0.25;
            sprite.setTextureRect(sf::IntRect(23, 0, -23, 18));
        }
    }
}

void Player :: update(float time) {

    control();
    switch (state) {
        case right: dx = speed; dy = 0; break;
        case left: dx = -speed; dy = 0; break;
        case down: dx = 0; dy = speed; break;
        case up: dx = 0; dy = -speed; break;
        case stay: dx = 0; dy = 0;
    }

    x += dx*time;
    interactionWithMap(dx, 0);
    y += dy*time;
    interactionWithMap(0, dy);
    if (!isMove) speed = 0;
    sprite.setPosition(x+w/2, y+h/2);
    if (PlayerHealth <= 0){life = false;}
    speed = 0;
    sprite.setPosition(x, y);
}


