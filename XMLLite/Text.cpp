#include "Text.h"

const uint Text::NODE_ID = AbstractXML::generateId();

Text::Text()
{
}

Text::Text(Node *parent, const string &content) 
	: AbstractXML(parent)
{
	this->content = content;
}

Text::~Text()
{
}

void Text::setContent(const string &val)
{
	content = val;
}

string Text::getContent() const
{
	return content;
}

string Text::toXML() const
{
	return content;
}

uint Text::getType() const
{
	return NODE_ID;
}
