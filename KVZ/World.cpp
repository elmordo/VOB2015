#include "World.h"
#include "IRule.h"
#include "PublicRule.hpp"

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

    for (PublicRule *rule : publicRules)
    {
        alloc.destroy(rule);
        alloc.deallocate(rule, 1);
    }
}

void World::addObject(const GameItem &item, World::FERRY_STATE side)
{
    objects[side].push_back(item);
}

void World::addInternalRule(IRule *rule)
{
    internalRules.push_back(rule);
}

void World::addPublicRule(PublicRule *rule)
{
    publicRules.push_back(rule);
}

void World::applyInternalRules()
{
    for (IRule *rule : internalRules)
    {
        if (rule->canApply(*this))
        {
            rule->apply(*this);
        }
    }
}

World::PublicRuleList World::filterAvailableRules()
{
    PublicRuleList rules;

    for (PublicRule *rule : publicRules)
    {
        if (rule->canApply(*this))
        {
            rules.push_back(rule);
        }
    }

    return rules;
}

void World::removeObject(int itemType, World::FERRY_STATE side)
{
    ObjectList &sideObjects = objects[side];

    for (ObjectList::iterator pos = sideObjects.begin(); pos != sideObjects.end(); ++pos)
    {
        if (pos->getItemType() == itemType)
        {
            sideObjects.erase(pos);
            break;
        }
    }
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
