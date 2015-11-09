#include "Node.h"

const uint Node::TYPE_ID = AbstractXML::generateId();

Node::Node()
{
}

Node::Node(Node* parent, const string &name) 
	: Element(parent, name)
{
}

Node::~Node()
{
}

Node::ChildList &Node::getChildren()
{
	return children;
}

Node::ChildList Node::getChildren() const
{
	return children;
}

int Node::killChild(AbstractXML *child)
{
	bool notFound = true;

	for (ChildList::iterator pos = children.begin();
		pos != children.end() && notFound; ++pos)
	{
		if (*pos == child)
		{
			notFound = true;
			children.erase(pos);

			allocator<AbstractXML> alloc;
			alloc.destroy(child);
			alloc.deallocate(child, 1);
		}
	}

	return notFound;
}

uint Node::getType() const
{
	return TYPE_ID;
}

string Node::toXML() const
{
	// open tag
	string xml = "<" + getTagName();

	for (AttributeList::const_iterator pos = getAttrs().cbegin();
		pos != getAttrs().cend(); ++pos)
	{
		xml += " " + pos->first + "=\"" + pos->second + "\"";
	}

	// close tag
	xml += ">";

	for (ChildList::const_iterator pos = children.cbegin();
		pos != children.cend(); ++pos)
	{
		xml += (*pos)->toXML();
	}

	xml += "</" + getTagName() + ">";

	return xml;
}
