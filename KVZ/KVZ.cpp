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

void addMoveFerryRule(World &world, MoveFerry::SideDict sideNames)
{
    allocator<MoveFerry> alloc;
    MoveFerry *rule = alloc.allocate(1);
    alloc.construct(rule);

    rule->setSideNames(sideNames);

    world.addPublicRule(rule);
}

void addMoveObjRule(World &world, int objType,
                    MoveObj::SideDict sideNames, MoveObj::ObjDict objectNames)
{
    allocator<MoveObj> alloc;
    MoveObj *rule1 = alloc.allocate(1),
            *rule2 = alloc.allocate(1);

    alloc.construct(rule1, objType, World::FERRY_LEFT, World::FERRY_RIGHT);
    alloc.construct(rule2, objType, World::FERRY_RIGHT, World::FERRY_LEFT);

    rule1->setSideNames(sideNames);
    rule1->setObjectNames(objectNames);

    rule2->setSideNames(sideNames);
    rule2->setObjectNames(objectNames);

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

void addWinRule(World &world, World::FERRY_STATE targetState)
{
    allocator<WinRule> alloc;
    WinRule *rule = alloc.allocate(1);
    alloc.construct(rule, targetState);

    world.addInternalRule(rule);
}

size_t selectRule(const World::PublicRuleList &rules)
{
    cout << "What you want to do?" << endl;

    for (size_t i = 0; i < rules.size(); ++i)
    {
        cout << (i + 1) << ": " << rules[i]->getName() << endl;
    }

    size_t selectedRule;
    cout << "Select your rule: ";
    cin >> selectedRule;

    return selectedRule - 1;
}

void printWorldStatus(const World &world, MoveFerry::SideDict sideNames,
                      MoveObj::ObjDict objectNames)
{
    cout << "Ferry is on " << sideNames[world.getFerryState()] << endl;

    World::Map map = world.getObjects();

    cout << "Left side: " << endl;

    for (GameItem item : map[World::FERRY_LEFT])
    {
        cout << objectNames[item.getItemType()] << endl;
    }

    cout << endl;
    cout << "Right side: " << endl;

    for (GameItem item : map[World::FERRY_RIGHT])
    {
        cout << objectNames[item.getItemType()] << endl;
    }

    cout << endl;
}

int main(int argc, char** argv)
{
    // create dictionaries
    MoveObj::ObjDict objectNames;
    objectNames[1] = "Wolf";
    objectNames[2] = "Goat";
    objectNames[3] = "Salad";

    MoveObj::SideDict sideNames;
    sideNames[World::FERRY_LEFT] = "left";
    sideNames[World::FERRY_RIGHT] = "right";

    // setup world and objects
    World world;

    world.addObject(GameItem(1), World::FERRY_LEFT); // wolf
    world.addObject(GameItem(2), World::FERRY_LEFT); // goat
    world.addObject(GameItem(3), World::FERRY_LEFT); // salad

    world.setFerryState(World::FERRY_LEFT);

    // add rules
    addMoveFerryRule(world, sideNames);
    addMoveObjRule(world, 1, sideNames, objectNames);
    addMoveObjRule(world, 2, sideNames, objectNames);
    addMoveObjRule(world, 3, sideNames, objectNames);

    addEatRule(world, 1, 2);
    addEatRule(world, 2, 3);
    addWinRule(world, World::FERRY_RIGHT);

    // start game
    world.applyInternalRules(); // initial test of rules

    while (world.getGameState() == World::GAME_RUNNING)
    {
        printWorldStatus(world, sideNames, objectNames);

        // get available rules
        World::PublicRuleList rules = world.filterAvailableRules();
        size_t selectedRule = selectRule(rules);

        rules[selectedRule]->apply(world);

        world.applyInternalRules();
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

