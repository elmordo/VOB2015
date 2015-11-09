#pragma once

#include<list>
#include<memory>

#include "Element.h"


class Node : public Element
{
public:

	typedef list<AbstractXML *> ChildList;

private:

	ChildList children;

	static const uint TYPE_ID;

public:
	Node();

	Node(Node* parent, const string &name);

	virtual ~Node();

	ChildList &getChildren();

	ChildList getChildren() const;

	int killChild(AbstractXML *child);

	uint getType() const;

	string toXML() const;

};

