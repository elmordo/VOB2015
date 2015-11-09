#pragma once

#include <vector>
#include <map>

#include "GameItem.h"
#include "IRule.h"

using namespace std;


namespace KVZ
{

	class World
	{
	public:

		enum FERRY_STATE
		{
			FERRY_LEFT,
			FERRY_RIGHT
		};

		enum GAME_STATE
		{
			GAME_FAIL,
			GAME_RUNNING,
			GAME_SUCCESS
		};

		typedef vector<GameItem> ObjectList;

		typedef map<FERRY_STATE, ObjectList> Map;

		typedef vector<IRule *> InternalRuleList;

	private:

		FERRY_STATE ferry;

		Map objects;

		GAME_STATE gameState;

		InternalRuleList internalRules;

	public:

		World();

		World(FERRY_STATE ferry);

		virtual ~World();

		void addObject(const GameItem &item, FERRY_STATE side);

		const Map &getObjects() const;

		FERRY_STATE getFerryState() const;

		void setFerryState(FERRY_STATE val);

		GAME_STATE getGameState() const;

		void setGameState(GAME_STATE val);

	};

}

