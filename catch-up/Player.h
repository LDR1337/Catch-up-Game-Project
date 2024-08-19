#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class Player : public Object {
public:
    Player(sf::Image image, double X, double Y, int W, int H,double w1, double h1, sf::String Name) : Object(image, X, Y, W, H, w1, h1, Name) {
        life = true; isMove = false;
        speed = 0;
        PlayerHealth = 3;
        if (name == "Cat") {
            texture.loadFromImage(image);
            sprite.setTexture(texture);
            sprite.scale(w1, h1);
            sprite.setTextureRect(sf::IntRect(231, 0, 249, 18));
        }
    }

    float getplayercoordinateX(){
        return x;
    }
    float getplayercoordinateY(){
        return y;
    }


    void control();
    void update(float time);
    void interactionWithMap(double Dx,double Dy);

};


#endif //UNTITLED_PLAYER_H
