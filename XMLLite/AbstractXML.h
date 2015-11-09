#pragma once

#include <string>

#include "include.h"

using namespace std;

class Node;


class AbstractXML
{

	Node *parent;

	static uint nextId;

public:

	static uint generateId();

	/**
	 * @brief create instance with parent set to NULL
	 */
	AbstractXML();

	/**
	 * @brief create instance with parent
	 * @param parent parent node
	 */
	AbstractXML(Node *parent);

	/**
	 * @brief remove self from parent container
	 */
	virtual ~AbstractXML();

	/**
	 * @brief return pointer to parent container
	 */
	Node *getParent() const;

	/**
	 * @brief return type id of instance
	 */
	virtual uint getType() const = 0;

	/**
	 * @brief convert instance to XML string
	 */
	virtual string toXML() const = 0;

};

