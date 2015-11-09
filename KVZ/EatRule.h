#pragma once
#include "IRule.h"
#include "World.h"

namespace KVZ
{

	class EatRule :
		public IRule
	{

		/**
		 * @brief eats food
		 */
		int gourmet;

		/**
		* @brief eaten by gourmet
		*/
		int food;

		bool searchForObjects(const World::ObjectList &objects) const;

	public:
		EatRule();

		EatRule(int gourmet, int food);

		virtual ~EatRule();

		virtual bool canApply(const World &world) const;

		virtual void apply(World &world);

	};

}