//  Created by Theo Penavaire on 05/20/2018
//  Last Update on 06/08/2018 

#include "Core.h"
#include "SDL_image.h"

namespace neon_engine
{

	Core::Core(
		const std::string& winTitle,
		const int width,
		const int height) :
		_title(winTitle),
		_width(width),
		_height(height)
	{
	}

	Core::~Core()
	{
		if (_isInitialized) {
			SDL_Quit();
			TTF_Quit();
			IMG_Quit();
		}
	}

	bool Core::start()
	{
		// General
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			throw NeonException("Initialization error");
		}
		_isInitialized = true;

		// Window
		_mainWindow = WindowSptr(SDL_CreateWindow(
			_title.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			_width,
			_height,
			SDL_WINDOW_SHOWN));
		if (!_mainWindow) {
			throw NeonException("Can't create the main window");
			return false;
		}

		// Renderer
		_renderer = RendererSptr(SDL_CreateRenderer(
			_mainWindow.get(),
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
		SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
		if (!_renderer) {
			throw NeonException("Can't create the graphic renderer");
		}
		
		// SDL_ttf
		if (TTF_Init() < 0) {
			throw NeonException("Can't initialize TTF_Font");
		}

		// SDL_Image
		const auto flags = IMG_INIT_JPG | IMG_INIT_PNG;
		const auto initted = IMG_Init(flags);

		if ((initted & flags) != flags) {
			throw NeonException("Can't initialize SDL_Image");
		}

		return true;
	}

	void Core::setEventFuncMapper(NEventFuncMapper& evFm)
	{
		buildEventMapper();
		_eventFuncMapper = evFm;
	}

}