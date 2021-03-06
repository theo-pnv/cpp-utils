//  Created by Theo Penavaire on 05/31/2018
//  Last Update on 06/08/2018 

#pragma once

#include <memory>

namespace tp_singleton
{

	template <class T>
	using Sptr = std::shared_ptr<T>;

	/**
	 * \brief Singleton
	 * \tparam T templated object
	 */
	template <class T>
	class Singleton
	{

	private:
		static Sptr<T>	_instance;

	public:
		Singleton() = default;

		virtual ~Singleton() = default;

		static Sptr<T> getInstance()
		{
			if (!_instance) {
				_instance = std::make_shared<T>();
			}

			return _instance;
		}

	};

	template <class T>
	Sptr<T> Singleton<T>::_instance = nullptr;

}