//  Created by Theo Penavaire on 08/01/2018
//  Last Update on 08/01/2018 

#pragma once

#include "tp_ecs.h"

namespace tp_ecs
{
	class Entity;

	class AComponent
	{

	public:
		Sptr<Entity>	_entity;

	public:
		virtual		~AComponent() = default;

		virtual void	init() {}	// override if needed
		virtual void	update() {}	// override if needed

	};
}
