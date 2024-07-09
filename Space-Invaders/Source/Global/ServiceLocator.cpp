#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global 
{

	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Element;


	// Constructor: Initializes the graphic_service pointer to null and creates services.
	ServiceLocator::ServiceLocator() {
		graphic_service = nullptr; // Initialize graphic_service to null.
		event_service = nullptr; // Initialize event_service to null.
		player_service = nullptr; //Initialize player_service to null.
		time_service = nullptr;  //Initialize time_service to null.
		ui_service = nullptr;    //Initialize ui_service to null
		enemy_service = nullptr; //Initialize enemy_service to null
		gameplay_service = nullptr; //Initialize gameplay_service to null
		element_service = nullptr; // Initialize element_service to null
		createServices(); // Call createServices to instantiate services
	}

	// Destructor: Cleans up resources by clearing all services.
	ServiceLocator::~ServiceLocator() {
		clearAllServices(); // Call clearAllServices to delete any allocated services	
	}

	// Creates service instances, specifically the graphic service in this case.
	void ServiceLocator::createServices() {
		graphic_service = new GraphicService();// Dynamically create a GraphicService instance
		event_service = new EventService();// Dynamically create a EventService instance
		player_service = new PlayerService();// Dynamically create a PlayerService instance
		time_service = new TimeService(); // Dynamically create a TimeService instance
		ui_service = new UIService();    // Dynamically create a UIService instance
		enemy_service = new EnemyService(); // Dynamically create a EnemyService instance
		gameplay_service = new GameplayService();// Dynamically create a GameplayService instance
		element_service = new ElementService(); // Dynamically create a ElementService instance
	}

	// Deletes allocated services to prevent memory leaks, specifically the graphic service.
	void ServiceLocator::clearAllServices() {
		delete(graphic_service);// Delete the graphic_service instance
		delete(event_service); // Delete the event_service instance
		delete(player_service);  //Delete the player_service instance
		delete(time_service);   //Delete the time_service instance
		delete(ui_service);    //Delete the ui_service instance
		delete(enemy_service); //Delete the enemy_service instance
		delete(gameplay_service); //Delete the Gameplay_service instance
		delete(element_service); //Delete the element_service instance
	}

	// Returns a pointer to ServiceLocator.
	ServiceLocator* ServiceLocator::getInstance() {
		static ServiceLocator instance; // we will discuss what 'static' means at a later time.
		return &instance; // Return address of the instance
	}

	// Calls initialize on the graphic service, readying it for use.
	void ServiceLocator::initialize() {
		graphic_service->initialize();// Initialize graphic service.
		event_service->initialize();// Initialize event service.
		player_service->initialize();// Initialize player service.
		time_service->initialize(); // Initialize time_service.
		ui_service->initialize();  // Initialize ui_service.
		enemy_service->initialize();// Initialize enemy_service.
		gameplay_service->initialize(); // Initialize gameplay_service.
		element_service->initialize();  // Initialize element_service.

	}

	// Updates the state of the graphic service.
	void ServiceLocator::update() 
	{
		graphic_service->update();// Update graphic service
		time_service->update(); // Update time service'
		event_service->update();// Update event service.
		
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
		
			player_service->update();
			enemy_service->update();
			gameplay_service->update();
			element_service->update();
			
		}

		ui_service->update();

	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			element_service->render();
			
			
		}

		ui_service->render();


	}


	// Returns a pointer to the currently set graphic service.
	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
	EventService* ServiceLocator::getEventService() { return event_service; }
	PlayerService* ServiceLocator::getPlayerService() { return player_service; }
	TimeService* ServiceLocator::getTimeService() { return time_service; }
	UIService* ServiceLocator::getUIService() { return ui_service; }
	EnemyService* ServiceLocator::getEnemyServices() { return enemy_service; }
	GameplayService* ServiceLocator::getGameplayServices() { return gameplay_service; }
	ElementService* ServiceLocator::getElemrntService() { return element_service; }
}