#include "MoveFerry.hpp"
#include "World.h"

namespace KVZ
{


MoveFerry::SideDict MoveFerry::getSideNames() const
{
    return sideNames;
}

void MoveFerry::setSideNames(const SideDict &value)
{
    sideNames = value;
}
MoveFerry::MoveFerry()
{
}

MoveFerry::MoveFerry(const MoveFerry &)
{

}

MoveFerry::~MoveFerry()
{

}

bool MoveFerry::canApply(const World &world) const
{
    return true;
}

void MoveFerry::apply(World &world)
{
    if (world.getFerryState() == World::FERRY_LEFT)
    {
        world.setFerryState(World::FERRY_RIGHT);
    }
    else
    {
        world.setFerryState(World::FERRY_LEFT);
    }
}

string MoveFerry::getName() const
{
    return "Move ferry to the other side";
}

} // namespace KVZ
