//  Created by Theo Penavaire on 05/29/2018
//  Last Update on 06/07/2018 

#pragma once

#include "neon_engine.h"
#include "event.h"

namespace neon_engine
{
	class Core;

	/**
	 * \brief Interface for game state
	 * A state is like a separated program within the game.
	 * It handles its rendering, and its events.
	 * It is very useful to implement different logic for menus, games...
	 */
	class IState
	{
		
		public:

			/**
			 * \brief Destruction and cleanup of the state must happen here
			 */
			virtual void	cleanup() = 0;

			/**
			 * \brief Pause the state for a short amount of time
			 */
			virtual void	pause() = 0;

			/**
			 * \brief Resume the state
			 */
			virtual void	resume() = 0;

			/**
			 * \brief Called once per loop.
			 * \param event Current event's data
			 * Handle the events.
			 */
			virtual void	update(NEvent& event) = 0;

			/**
			 * \brief Render the state on screen.
			 * For example, call the draw method of concerned game objects.
			 */
			virtual void	draw() = 0;

			/**
			 * \brief Give the order to the game engine to change state
			 * \param state the new state
			 */
			virtual void	changeState(Sptr<IState> state) = 0;

		protected:
			virtual ~IState() = default;
	};

}
