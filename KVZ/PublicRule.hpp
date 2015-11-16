#ifndef KVZ_PUBLICRULE_HPP
#define KVZ_PUBLICRULE_HPP

#include <string>

#include "IRule.h"

using namespace std;


namespace KVZ
{

class PublicRule : public IRule
{

public:
    PublicRule();

    virtual ~PublicRule();

    virtual string getName() const = 0;

};

} // namespace KVZ

#endif // KVZ_PUBLICRULE_HPP
