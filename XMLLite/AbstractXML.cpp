#include "AbstractXML.h"
#include "Node.h"

uint AbstractXML::nextId = 1;

AbstractXML::AbstractXML()
{
	parent = NULL;
}

AbstractXML::AbstractXML(Node *parent)
{
	this->parent = parent;
}


AbstractXML::~AbstractXML()
{
	parent->killChild(this);
}

Node *AbstractXML::getParent() const
{
	return parent;
}

uint AbstractXML::generateId()
{
	return nextId++;
}
