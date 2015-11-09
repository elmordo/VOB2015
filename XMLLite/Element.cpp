#include "Element.h"

const uint Element::TYPE_ID = AbstractXML::generateId();

Element::Element()
{
}

Element::Element(Node *parent, const string &name) 
	: AbstractXML(parent)
{
	tagName = name;
}

Element::~Element()
{
}

string Element::getTagName() const
{
	return tagName;
}

Element::AttributeList &Element::getAttrs()
{
	return attributes;
}

Element::AttributeList Element::getAttrs() const
{
	return attributes;
}

uint Element::getType() const
{
	return TYPE_ID;
}

string Element::toXML() const
{
	// open tag
	string xml = "<" + tagName;

	for (AttributeList::const_iterator pos = attributes.cbegin();
		pos != attributes.cend(); ++pos)
	{
		xml += " " + pos->first + "=\"" + pos->second + "\"";
	}

	// close tag
	xml += "/>";

	return xml;
}
