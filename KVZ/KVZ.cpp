// KVZ.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "World.h"
#include "EatRule.h"
#include "MoveFerry.hpp"
#include "MoveObj.hpp"
#include "WinRule.h"

using namespace KVZ;
using namespace std;

void addMoveFerryRule(World &world)
{
    allocator<MoveFerry> alloc;
    MoveFerry *rule = alloc.allocate(1);
    alloc.construct(rule);

    world.addPublicRule(rule);
}

void addMoveObjRule(World &world, int objType)
{
    allocator<MoveObj> alloc;
    MoveObj *rule1 = alloc.allocate(1),
            *rule2 = alloc.allocate(1);

    alloc.construct(rule1, objType, World::FERRY_LEFT, World::FERRY_RIGHT);
    alloc.construct(rule1, objType, World::FERRY_RIGHT, World::FERRY_LEFT);

    world.addPublicRule(rule1);
    world.addPublicRule(rule2);
}

void addEatRule(World &world, int groumet, int food)
{
    allocator<EatRule> alloc;
    EatRule *rule = alloc.allocate(1);
    alloc.construct(rule, groumet, food);

    world.addInternalRule(rule);
}

void addWinRule(World &world)
{
    allocator<WinRule> alloc;
    WinRule *rule = alloc.allocate(1);
    alloc.construct(rule);

    world.addInternalRule(rule);
}

size_t selectRule(const World::PublicRuleList &rules)
{
    cout << "What you want to do?" << endl;


}

int main(int argc, char** argv)
{
    // setup world and objects
    World world;

    world.addObject(GameItem(1), World::FERRY_LEFT); // wolf
    world.addObject(GameItem(2), World::FERRY_LEFT); // goat
    world.addObject(GameItem(3), World::FERRY_LEFT); // salad

    world.setFerryState(World::FERRY_LEFT);

    // add rules
    addMoveFerryRule(world);
    addMoveObjRule(world, 1);
    addMoveObjRule(world, 2);
    addMoveObjRule(world, 3);

    addEatRule(world, 1, 2);
    addEatRule(world, 2, 3);

    // start game
    world.applyInternalRules(); // initial test of rules

    while (world.getGameState() == World::GAME_RUNNING)
    {
        // get available rules
        World::PublicRuleList rules = world.filterAvailableRules();

        world.applyInternalRules();
        break;
    }

    // resolve result
    if (world.getGameState() == World::GAME_SUCCESS)
    {
        cout << "Congratulation!! You beat this game!!!" << endl;
    }
    else if (world.getGameState() == World::GAME_RUNNING)
    {
        cout << "Oops, game is still running" << endl;
    }
    else
    {
        cout << "n00b!!!" << endl;
    }

	return 0;
}

