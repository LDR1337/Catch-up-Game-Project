#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H
#include <SFML/Graphics.hpp>


class Object {
public:
    enum { left,right,up,down,stay } state;
    double dx, dy, x, y,moveTimer;
    double speed;
    int w,h,health,PlayerHealth;
    bool life;
    bool isMove;
    bool lifeEnemyOne;
    bool lifeEnemyTwo;
    sf::String File;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::String name;
    Object(sf::Image image, double X, double Y, int W, int H, double w1, double h1, sf::String Name){
        x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
        life = true; isMove = false;
        image.loadFromFile("images/" + File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.scale(w1, h1);
    }

    virtual  void update(float time) = 0;

    sf::FloatRect getRect(){
        return sf::FloatRect(x, y, w, h);
    }

};


#endif //UNTITLED_OBJECT_H
