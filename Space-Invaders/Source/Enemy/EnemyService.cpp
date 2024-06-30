#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;


	EnemyService::EnemyService() { enemy = nullptr; }

	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize()
	{
		//Spawn Enemy
		spawnEnemy();
	}

	void EnemyService::update()
	{
	}

	void EnemyService::render()
	{
		enemy->render();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		//creates and intis an enemy controller
		enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}

	void EnemyService::destroy()
	{
		//deallocate memory 
		delete(enemy);
	}
}