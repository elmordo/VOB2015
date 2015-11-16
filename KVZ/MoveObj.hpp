#ifndef KVZ_MOVEOBJ_HPP
#define KVZ_MOVEOBJ_HPP

#include <sstream>

#include "PublicRule.hpp"
#include "World.h"

namespace KVZ {

class MoveObj : public PublicRule
{

public:

    typedef map<World::FERRY_STATE, string> SideDict;

    typedef map<int, string> ObjDict;

private:

    typedef World::ObjectList ObjList;

    int objType;

    World::FERRY_STATE from;

    World::FERRY_STATE to;

    ObjList::const_iterator findObj(const ObjList &objList);

    ObjDict objectNames;

    SideDict sideNames;

public:
    MoveObj();

    MoveObj(int objType, World::FERRY_STATE from, World::FERRY_STATE to);

    MoveObj(const MoveObj &original);

    virtual ~MoveObj();

    ObjDict getObjectNames() const;
    void setObjectNames(const ObjDict &value);
    SideDict getSideNames() const;
    void setSideNames(const SideDict &value);

    // IRule interface
public:
    virtual bool canApply(const World &world) const;
    virtual void apply(World &world);

    // PublicRule interface
public:
    virtual string getName() const;
};

} // namespace KVZ

#endif // KVZ_MOVEOBJ_HPP
