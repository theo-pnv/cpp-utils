//  Created by Theo Penavaire on 05/20/2018
//  Last Update on 06/07/2018 

#pragma once

#include "AGObject.h"
#include "Text.h"

namespace neon_engine
{

	/**
	 * \brief Button class
	 * Triggers an event on click
	 */
	class Button : public AGObject
	{

	public: 
		Button() = default;
		/**
		 * \brief Constructor for Button
		 * \param text Text to display
		 * \param pos Position of the button
		 * \param onClick Callback to trigger when the button is clicked
		 * \param isEnabled Activation of the button
		 */
		Button(const Text& text, const Vector2<int>& pos, Event<void()> onClick, bool isEnabled = true);
		~Button() = default;

		bool	update(NEvent& event) override;
		void	draw(RendererSptr& renderer) override;

	private:
		Event<void()>	_onClick;

		Text			_text;
		Vector2<int>	_size;
	};

}
