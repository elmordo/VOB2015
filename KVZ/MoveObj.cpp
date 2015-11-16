#include "MoveObj.hpp"

namespace KVZ
{

MoveObj::ObjList::const_iterator MoveObj::findObj(const World::ObjectList &objList)
{
    for (ObjList::const_iterator pos = objList.cbegin(); pos != objList.cend(); ++pos)
    {
        if (pos->getItemType() == objType)
        {
            return pos;
        }
    }

    return objList.cend();
}


MoveObj::ObjDict MoveObj::getObjectNames() const
{
    return objectNames;
}

void MoveObj::setObjectNames(const ObjDict &value)
{
    objectNames = value;
}

MoveObj::SideDict MoveObj::getSideNames() const
{
    return sideNames;
}

void MoveObj::setSideNames(const SideDict &value)
{
    sideNames = value;
}
MoveObj::MoveObj()
{
    objType = -1;
    from = World::FERRY_LEFT;
    to = World::FERRY_RIGHT;
}

MoveObj::MoveObj(int objType, World::FERRY_STATE from, World::FERRY_STATE to)
{
    this->objType = objType;
    this->from = from;
    this->to = to;
}

MoveObj::MoveObj(const MoveObj &original)
{
    objType = original.objType;
    from = original.from;
    to = original.to;
}

MoveObj::~MoveObj()
{

}

bool MoveObj::canApply(const World &world) const
{
    if (from != world.getFerryState())
    {
        return false;
    }

    // search for object on side
   World::Map map = world.getObjects();
   ObjList objects = map[from];

    for (ObjList::const_iterator pos = objects.cbegin(); pos != objects.cend(); ++pos)
    {
        if (pos->getItemType() == objType)
        {
            return true;
        }
    }

    return false;
}

void MoveObj::apply(World &world)
{
    world.removeObject(objType, from);
    world.addObject(GameItem(objType), to);
    world.setFerryState(to);
}

string MoveObj::getName() const
{
    stringstream buffer;
    string objName = objectNames.find(objType)->second,
            fromName = sideNames.find(from)->second,
            toName = sideNames.find(to)->second;

    buffer << "Move " << objName << " from "
           << fromName << " to " << toName;

    return buffer.str();
}

} // namespace KVZ
