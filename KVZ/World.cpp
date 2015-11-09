#include "World.h"

namespace KVZ
{

	World::World()
	{
		objects[FERRY_LEFT];
		objects[FERRY_RIGHT];

		ferry = FERRY_LEFT;
		gameState = GAME_RUNNING;
	}

	World::World(FERRY_STATE ferry)
	{
		objects[FERRY_LEFT];
		objects[FERRY_RIGHT];

		this->ferry = ferry;
		gameState = GAME_RUNNING;
	}


	World::~World()
	{
		// destroy rules
		allocator<IRule> alloc;

		for (IRule *rule : internalRules)
		{
			alloc.destroy(rule);
			alloc.deallocate(rule, 1);
		}
	}

	void World::addObject(const GameItem &item, World::FERRY_STATE side)
	{
		objects[side].push_back(item);
	}

	World::FERRY_STATE World::getFerryState() const
	{
		return ferry;
	}

	void World::setFerryState(FERRY_STATE val)
	{
		ferry = val;
	}

	const World::Map &World::getObjects() const
	{
		return objects;
	}

	World::GAME_STATE World::getGameState() const
	{
		return gameState;
	}

	void World::setGameState(GAME_STATE val)
	{
		gameState = val;
	}

}
