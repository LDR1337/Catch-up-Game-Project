//
// Created by LDR on 22.06.2021.
//

#include "PassivEnemy.h"

void PassivEnemy :: update(float time) {
    if (name == "1") {
        time += 1;
        moveTimer += time;
        if (moveTimer > 20000) {
            dx *= -1;
            moveTimer = 0;
            sprite.scale(-1, 1);
        }
        x += dx;
        sprite.setPosition(x + w / 2, y + h / 2);
        if (health <= 0) { lifeEnemyOne = false; }
    }
    if (name == "2") {
        time += 1;
        moveTimer += time;
        if (moveTimer > 7400) {
            dx *= -1;
            moveTimer = 0;
            sprite.scale(-1, 1);
        }
        x += dx;
        sprite.setPosition(x + w / 2, y + h / 2);
        if (health <= 0) { lifeEnemyTwo = false; }
    }}