#include "../../header/Bullet/BulletController.h"
#include "../../header/Bullet/BulletView.h"
#include "../../header/Bullet/BulletModel.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Elements/Bunker/BunkerController.h"

namespace Bullet
{
	using namespace Global;
	using namespace Entity;
	using namespace Player;
	using namespace Enemy;
	using namespace Element::Bunker;

	BulletController::BulletController(BulletType bullet_type, EntityType owner_type)
	{
		bullet_view = new BulletView();
		bullet_model = new BulletModel(bullet_type, owner_type);
	}

	BulletController::~BulletController()
	{
		delete (bullet_view);
		delete (bullet_model);
	}

	void BulletController::initialize(sf::Vector2f position, MovementDirection direction)
	{
		bullet_view->initialize(this);
		bullet_model->initialize(position, direction);
	}

	void BulletController::update()
	{
		updateBulletPosition();
		bullet_view->update();
	}

	void BulletController::render()
	{
		bullet_view->render();
	}

	void BulletController::updateBulletPosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case::Bullet::MovementDirection::UP:
			moveUp();
			break;

		case::Bullet::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y -= bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y += bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	sf::Vector2f BulletController::getBulletPosition()
	{
		return bullet_model->getBulletPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}

	Entity::EntityType BulletController::getOwnerEntityType()
	{
		return bullet_model->getOwnerEntityType();
	}

	const sf::Sprite& BulletController::getColliderSprite()
	{
		return bullet_view->getBulletSprite();
	}

	void BulletController::onCollision(ICollider* other_collider)
	{
		processPlayerCollision(other_collider);
		processEnemyCollision(other_collider);
		processBunkerCollision(other_collider);
		processBulletCollision(other_collider);
	}

	void BulletController::processBulletCollision(ICollider* other_collider)
	{
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

		if (bullet_controller) 
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
	}

	void BulletController::processEnemyCollision(ICollider* other_collider)
	{
		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);

		if (enemy_controller && getOwnerEntityType() != EntityType::ENEMY)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processPlayerCollision(ICollider* other_collider)
	{
		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);

		if (player_controller && getOwnerEntityType() != EntityType::PLAYER)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processBunkerCollision(ICollider* other_collider)
	{
		BunkerController* bunker_controller = dynamic_cast<BunkerController*>(other_collider);

		if (bunker_controller) 
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
	}
}