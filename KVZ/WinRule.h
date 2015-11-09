#pragma once
#include "IRule.h"
#include "World.h"

namespace KVZ
{

	class WinRule :
		public IRule
	{

		World::FERRY_STATE targetSide;

	public:

		WinRule();

		WinRule(World::FERRY_STATE target);

		virtual ~WinRule();

		World::FERRY_STATE getTarget() const;

		void setTarget(World::FERRY_STATE val);

		virtual bool canApply(const World &world) const;

		virtual void apply(World &world);
	};

}