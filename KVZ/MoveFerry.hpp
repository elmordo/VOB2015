#ifndef KVZ_MOVEFERRY_HPP
#define KVZ_MOVEFERRY_HPP

#include "PublicRule.hpp"

namespace KVZ
{

class MoveFerry : public PublicRule
{
public:

    MoveFerry();

    MoveFerry(const MoveFerry &);

    virtual ~MoveFerry();


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