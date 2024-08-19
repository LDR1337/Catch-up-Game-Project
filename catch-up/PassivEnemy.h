#ifndef UNTITLED_PASSIVENEMY_H
#define UNTITLED_PASSIVENEMY_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class PassivEnemy : public Object{
public:
    PassivEnemy(sf::Image &image, double X, double Y,int W,int H,double w1,double h1,sf::String Name):Object(image,X,Y,W,H,w1,h1,Name){
        if (name == "1"){
            texture.loadFromImage(image);
            sprite.setTexture(texture);
            sprite.scale(w1, h1);
            sprite.setTextureRect(sf::IntRect(0, 0, w, h));
            dx = -0.25;
            health = 1;
            lifeEnemyOne = true;
        }
        if (name == "2"){
            texture.loadFromImage(image);
            sprite.setTexture(texture);
            sprite.scale(w1, h1);
            sprite.setTextureRect(sf::IntRect(0, 0, w, h));
            dx = 0.35;
            health = 1;
            lifeEnemyTwo = true;
        }
    }

    void update(float time);

};


#endif //UNTITLED_PASSIVENEMY_H
