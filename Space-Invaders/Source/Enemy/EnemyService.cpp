#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"

#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"



namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	EnemyService::EnemyService() {
	
		std::srand(static_cast<unsigned>(std::time(nullptr))); 

	}

	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			delete(enemy_list[i]);

			enemy_list[i] = nullptr;
		}
	}

	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->update();
	}


	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); // increase timer
	}


	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy(); //spawn 
			spawn_timer = 0.0f; // reset

		}
	}


	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->render();
	}



	

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		/*	case::Enemy::EnemyType::THUNDER_SNAKE:
				return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);*/

		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO);

			/*case::Enemy::EnemyType::UFO:
				return new UFOController(Enemy::EnemyType::UFO);*/
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		// The base class pointer will be pointing to a child class object
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());

		enemy_controller->initialize();
		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}



	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() %2; //will change later from 3 to 4, cuz we have 4 types of enemies

		return static_cast<EnemyType>(randomType);  //cast int to EnemyType enum class
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		// Erase the enemy_controller object from the enemy_list vector.
		// std::remove rearranges the elements in the vector so that all elements 
		// that are equal to enemy_controller are moved to the end of the vector,
		// then it returns an iterator pointing to the start of the removed elements.
		// The erase function then removes those elements from the vector.
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());

		delete(enemy_controller);
	}

	//void EnemyService::destroy()
	//{
	//	for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]); //delete all enemi
	//}

}