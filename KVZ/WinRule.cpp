#include "WinRule.h"

namespace KVZ
{

	WinRule::WinRule()
	{
	}

	WinRule::WinRule(World::FERRY_STATE target)
	{
		targetSide = target;
	}

	WinRule::~WinRule()
	{
	}

	World::FERRY_STATE WinRule::getTarget() const
	{
		return targetSide;
	}

	void WinRule::setTarget(World::FERRY_STATE val)
	{
		targetSide = val;
	}

	bool WinRule::canApply(const World &world) const
	{
		size_t objCnt = 0;
		World::Map objects = world.getObjects();

		for (World::Map::const_iterator pos = objects.cbegin(); pos != objects.cend() && !objCnt; ++pos)
		{
			if (pos->first != targetSide)
			{
				objCnt += pos->second.size();
			}
		}

		return objCnt == 0;
	}

	void WinRule::apply(World &world)
	{
		world.setGameState(World::GAME_SUCCESS);
	}

}