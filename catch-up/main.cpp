#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "menu.h"
#include "timer.h"
#include "PassivEnemy.h"
#include "map.h"
#include <vector>
#include <list>
using namespace std;

void Player :: interactionWithMap(double Dx, double Dy){
    for (int i = y / 96; i < (y + h) / 96; i++)
        for (int j = x / 96; j < (x + w) / 96; j++)
        { if ((TileMap[i][j] == 'c') || (TileMap[i][j] =='z') || (TileMap[i][j] =='q')|| (TileMap[i][j] =='x')|| (TileMap[i][j] =='a'))
            {if (dy > 0)
                {y = i * 96 - h;
                }
                if (dy < 0) { y = i * 96 + 96;
                }
                if (dx > 0) { x = j * 96 - w;
                }
                if (dx < 0) { x = j * 96 + 96;
                }
            }
            if (TileMap[i][j] == 's') {
                TileMap[i][j] = ' ';
                PlayerHealth += 2;
            }
            if (TileMap[i][j] == 'v') {
                TileMap[i][j] = ' ';
                PlayerHealth -= 1;
            }
        }
};

int main() {


    //score
    sf ::Font font;
    font.loadFromFile("17838.ttf");
    sf ::Text text("", font, 20);
    text.setColor(sf ::Color::White);
    int score = 0;



    //timer
    int hour = 30;
    int min = 60;
    int sec = 0;
    sf ::Text hourText("", font, 40);sf ::Text minText("", font, 40);
    sf ::Text text1(":", font, 40); text1.setColor(sf ::Color::White);
    hourText.setColor(sf ::Color::White);minText.setColor(sf ::Color::White);
    hourText.setPosition(150, 100);minText.setPosition(200, 100);


    //map
    sf ::Image map_image;
    map_image.loadFromFile("images/map.png");
    sf ::Texture map;
    map.loadFromImage(map_image);
    sf ::Sprite s_map;
    s_map.setTexture(map);
    s_map.scale(3, 3);

    sf ::Image playerImage;
    playerImage.loadFromFile("images/kot12.png");

    sf ::Image PassivEnemyImageOne;
    PassivEnemyImageOne.loadFromFile("images/mouse1.png");
    sf ::Image PassivEnemyImageTwo;
    PassivEnemyImageTwo.loadFromFile("images/mouse2.png");


    Player cat(playerImage, 500, 200, 23, 18, 2, 2, "Cat");

    vector<string> eVector;
    eVector.push_back("1");
    eVector.push_back("2");
    eVector.push_back("3");

    std::list<Object*>  entities;
    std::list<Object*>::iterator it;

    for (int i = 0; i < eVector.size(); i++) {
        entities.push_back(new PassivEnemy(PassivEnemyImageOne, 1600, 95, 36, 22, 1.5, 1.5, "1"));
        entities.push_back(new PassivEnemy(PassivEnemyImageTwo, 400, 850, 36, 22, 1.5, 1.5, "2"));
    }



    //timer
    sf ::Clock clock;

    // window
    sf ::RenderWindow window(sf ::VideoMode(1920, 1000), "catch-up", sf ::Style::Fullscreen);
    menu start;
    start._menu(window);



    while (window.isOpen()) {

        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf ::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf ::Event::Closed)
                window.close();
        }

        if (cat.life) {(cat.getplayercoordinateX(), cat.getplayercoordinateY());
        }

        for (it = entities.begin(); it != entities.end(); it++) { (*it)->update(time);}


        cat.update(time);

        //eat mouse
        for (it = entities.begin(); it != entities.end();)
        {   Object *b = *it;
            b->update(time);
            if (b->lifeEnemyOne == false)	{ it = entities.erase(it); delete b;
                entities.push_back(new PassivEnemy(PassivEnemyImageOne, 1600, 95, 36, 22, 1.5, 1.5, "1"));
            }
            if (b->lifeEnemyTwo == false)	{ it = entities.erase(it); delete b;
                entities.push_back(new PassivEnemy(PassivEnemyImageTwo, 400, 850, 36, 22, 1.5, 1.5, "2"));
            }
            else it++;
        }



        for (it = entities.begin(); it != entities.end(); it++) {
            if ((*it)->getRect().intersects(cat.getRect())) {
                if (((*it)->name == "1")) {
                    if ((cat.dy > 0)) {
                        (*it)->dx = 0;
                        (*it)->health = 0;
                        score += 5;
                    }
                }
                if ((*it)->name == "2") {
                    if ((cat.dy > 0)) {
                        (*it)->dx = 0;
                        (*it)->health = 0;
                        score += 10;
                    }
                }
            }
        }

        window.clear();

        //map building
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++) {

                if (TileMap[i][j] == ' ') s_map.setTextureRect(sf ::IntRect(0, 0, 32, 32));
                if (TileMap[i][j] == 'p') s_map.setTextureRect(sf ::IntRect(0, 0, 32, 32));
                if (TileMap[i][j] == 's') s_map.setTextureRect(sf ::IntRect(32, 0, 62, 32));
                if ((TileMap[i][j] == 'f')) s_map.setTextureRect(sf ::IntRect(64, 0, 96, 32));
                if ((TileMap[i][j] == 'a')) s_map.setTextureRect(sf ::IntRect(96, 0, 128, 32));
                if ((TileMap[i][j] == 'c')) s_map.setTextureRect(sf ::IntRect(128, 0, 160, 32));
                if ((TileMap[i][j] == 'z')) s_map.setTextureRect(sf ::IntRect(160, 0, 192, 32));
                if ((TileMap[i][j] == 'x')) s_map.setTextureRect(sf ::IntRect(192, 0, 224, 32));
                if ((TileMap[i][j] == 'v')) s_map.setTextureRect(sf ::IntRect(224, 0, 256, 32));
                if ((TileMap[i][j] == 'n')) s_map.setTextureRect(sf ::IntRect(256, 0, 288, 32));
                if ((TileMap[i][j] == 'b')) s_map.setTextureRect(sf ::IntRect(288, 0, 310, 32));
                if ((TileMap[i][j] == 'q')) s_map.setTextureRect(sf ::IntRect(192, 0, -32, 32));
                s_map.setPosition(j * 96, i * 96);
                window.draw(s_map);
            }

        //score
        ostringstream ScoreString;
        ScoreString << score;
        text.setString("SCORE : " + ScoreString.str());
        text.setPosition(960, 100);
        window.draw(text);

        //HP
        ostringstream health;
        health << cat.PlayerHealth;
        text.setString("HP : " + health.str());
        text.setPosition(1160, 100);
        window.draw(text);

        //timer
        timer(hour, min, sec);
        hourText.setString(intToString(hour));minText.setString(intToString(min));

        // timer on screen
        text1.setPosition(190, 100); window.draw(text1);
        window.draw(hourText);
        window.draw(minText);

        for (it = entities.begin(); it != entities.end(); it++){
            window.draw((*it)->sprite);
        }
        window.draw(cat.sprite);
        window.display();
    }
    return 0;
}