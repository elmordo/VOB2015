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
}

string MoveObj::getName() const
{
    stringstream buffer;
    buffer << "Move " << objType << " from " << from << " to " << to << endl;

    return buffer.str();
}

} // namespace KVZ
