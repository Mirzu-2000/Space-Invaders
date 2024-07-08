#include "../../Header/Graphic/GraphicService.h"

namespace Graphic {

	//Constructor: initializes game window and vido mode pointers to null.
	GraphicService::GraphicService() {

		game_window = nullptr; //initializes game window pointers to null
		video_mode = nullptr; // initializes vido mode pointer to null
	};

	//Destructor:Clean up resources by calling on Destroy.
	GraphicService::~GraphicService() {
		onDestroy(); // Calls on Destroy method to clean up resources
	}

	//initialize the graphic service by creating a new game window
	void GraphicService::initialize() {
		game_window = creatGameWindow(); // assinged a  new game window to the game_window pointer
		game_window->setFramerateLimit(frame_rate);
	}

	//Created new SFML RenderWindow object with specified video mode and title.
	sf::RenderWindow* GraphicService::creatGameWindow() {
		setVideoMode(); // sets up the video mode for the window
		return new sf::RenderWindow(*video_mode, game_window_title,sf::Style::Fullscreen); // creates and returns a new RenderWindow object
	}

	// Sets up the video mode for the game window using specified dimensions and system's color depth.
	void GraphicService::setVideoMode() {
		video_mode = new sf::VideoMode(game_window_width, game_window_height,
			sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
	}

	// Cleans up allocated memory for video mode and game window to avoid memory leaks.
	void GraphicService::onDestroy() {
		delete(video_mode); // Deletes the video mode object
		delete(game_window); // Deletes the game window object
	}

	// Placeholder function for game update logic.
	void GraphicService::update() { }

	// Placeholder function for game rendering logic.
	void GraphicService::render() { }

	// Checks if the game window is currently open.
	bool GraphicService::isGameWindowOpen() {
		return game_window->isOpen(); // Returns the open status of the game window
	}

	// Returns a pointer to the game window object.
	sf::RenderWindow* GraphicService::getGameWindow() {
		return game_window;
	}

	// Returns the configured window background color.
	sf::Color GraphicService::getWindowColor() {
		return window_color;
	}

}