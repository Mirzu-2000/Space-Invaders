#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UI/UIService.h"


// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

namespace Global {
    class ServiceLocator
    {
    private:

        // Private Attributes:
        // - event_service: Manages event-related functionalities.
        Event::EventService* event_service;
        // - graphic_service: Handles graphics-related tasks.
        Graphic::GraphicService* graphic_service;
        // - player_service: Handles graphics-related tasks.
        Player::PlayerService* player_service;
        // - time_service: Handles graphics-related tasks.
        Time::TimeService* time_service;
        UI::UIService* ui_service;
        // Private Constructor and Destructor:

        // Constructor for initializing the ServiceLocator.
        ServiceLocator();

        // Destructor for cleaning up resources upon object deletion.
        ~ServiceLocator();

        // Private Methods:
        void createServices(); 	// Creates instances of all services.
        void clearAllServices();  //	Deletes and deallocates memory for all services.

    public:
        // Public Methods:
        static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

        void initialize();            //	Initializes the ServiceLocator.
        void update(); 				//	Updates all services.
        void render(); 				//	Renders using the services.

        // Methods to Get Specific Services: 
        Event::EventService* getEventService();   // Retrieve the EventService instance.
        Graphic::GraphicService* getGraphicService();   // Retrieve the GraphicService instance.
        Player::PlayerService* getPlayerService();    // Retrieve the PlayerService instance.
        Time::TimeService* getTimeService();       //// Retrieve the TimeService instance.
        UI::UIService* getUIService();
    };
}