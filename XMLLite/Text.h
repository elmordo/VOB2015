#pragma once
#include "AbstractXML.h"


class Text : public AbstractXML
{

	string content;

	static const uint NODE_ID;

public:

	Text();

	Text(Node *parent, const string &content="");

	virtual ~Text();

	void setContent(const string &val);

	string getContent() const;

	virtual string toXML() const;

	virtual uint getType() const;

};

