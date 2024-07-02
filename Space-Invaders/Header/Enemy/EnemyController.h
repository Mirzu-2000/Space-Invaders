#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    class EnemyController
    {
    private:

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

    public:
        EnemyController();
        ~EnemyController();

        void initialize();
        void update();
        void render();

        //manage movement methods
        void move();
        void moveLeft();
        void moveRight();
        void moveDown();

        sf::Vector2f getEnemyPosition();
    };
}
