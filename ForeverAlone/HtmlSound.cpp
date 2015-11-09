#include "HtmlSound.h"


HtmlSound::HtmlSound()
{
}


HtmlSound::~HtmlSound()
{
}

string HtmlSound::makeSound() const
{
	return "<strong>" + getParent()->makeSound()
		+ "</strong>";
}
