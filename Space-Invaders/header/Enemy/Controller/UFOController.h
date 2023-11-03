#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:
            void moveLeft() override;
            void moveRight() override;
            void moveDown() override;
            void moveDiagonalLeft() override;
            void moveDiagonalRight() override;

            void fireBullet() override;
            Powerup::PowerupType getRandomPowerupType();

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void initialize() override;
            void onCollision(ICollider* other_collider) override;
        };
    }
}