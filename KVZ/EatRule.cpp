#include "EatRule.h"
#include "World.h"

namespace KVZ
{
	EatRule::EatRule()
	{
		gourmet = -1;
		food = -1;
	}

	EatRule::EatRule(int gourmet, int food)
	{
		this->gourmet = gourmet;
		this->food = food;
	}

	EatRule::~EatRule()
	{
	}

	bool EatRule::searchForObjects(const World::ObjectList &objects) const
	{
		bool gourmetFound = false, foodFound = false;

		for (auto obj : objects)
		{
			if (obj.getItemType() == gourmet) gourmetFound = true;
			if (obj.getItemType() == food) foodFound = true;

			if (gourmetFound && foodFound) return true;
		}

		return false;
	}

	bool EatRule::canApply(const World &world) const
	{
		World::Map map = world.getObjects();

		for (World::Map::const_iterator side = map.cbegin(); side != map.cend(); ++side)
		{
			if (side->first != world.getFerryState() && searchForObjects(side->second))
			{
				return true;
			}
		}

		return false;
	}

	void EatRule::apply(World &world)
	{
		world.setGameState(World::GAME_FAIL);
	}

}