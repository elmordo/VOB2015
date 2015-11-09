#pragma once

#include <map>

#include "AbstractXML.h"


class Element : public AbstractXML
{
public:

	typedef map<string, string> AttributeList;

private:

	AttributeList attributes;

	string tagName;

	static const uint TYPE_ID;

public:
	Element();

	Element(Node *parent, const string &name);

	virtual ~Element();

	string getTagName() const;

	AttributeList &getAttrs();

	AttributeList getAttrs() const;

	virtual uint getType() const;

	virtual string toXML() const;

};

