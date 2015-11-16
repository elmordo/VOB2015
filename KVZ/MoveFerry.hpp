#ifndef KVZ_MOVEFERRY_HPP
#define KVZ_MOVEFERRY_HPP

#include "PublicRule.hpp"
#include "World.h"

namespace KVZ
{

class MoveFerry : public PublicRule
{
public:

    typedef map<World::FERRY_STATE, string> SideDict;

private:

    SideDict sideNames;

public:

    MoveFerry();

    MoveFerry(const MoveFerry &);

    virtual ~MoveFerry();

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

#endif // KVZ_MOVEFERRY_HPP
