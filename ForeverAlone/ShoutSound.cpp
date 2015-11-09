#include "ShoutSound.h"


ShoutSound::ShoutSound()
{
}


ShoutSound::~ShoutSound()
{
}

string ShoutSound::makeSound() const
{
	return getParent()->makeSound() + "!!!";
}
