#ifndef KVZ_MOVEOBJ_HPP
#define KVZ_MOVEOBJ_HPP

#include <sstream>

#include "PublicRule.hpp"
#include "World.h"

namespace KVZ {

class MoveObj : public PublicRule
{

    typedef World::ObjectList ObjList;

    int objType;

    World::FERRY_STATE from;

    World::FERRY_STATE to;

    ObjList::const_iterator findObj(const ObjList &objList);

public:
    MoveObj();

    MoveObj(int objType, World::FERRY_STATE from, World::FERRY_STATE to);

    MoveObj(const MoveObj &original);

    virtual ~MoveObj();

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
