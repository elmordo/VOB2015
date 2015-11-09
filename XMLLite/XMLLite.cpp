// XMLLite.cpp : Defines the entry point for the console application.
//

#include <memory>

#include "stdafx.h"

#include "Text.h"
#include "Node.h"

int _tmain(int argc, _TCHAR* argv[])
{
	allocator<Text> TAlloc;
	allocator<Node> NAlloc;

	Node *node = NAlloc.allocate(1);
	NAlloc.construct(node, NULL, "product");

	Text *text = TAlloc.allocate(1);
	TAlloc.construct(text, node, "name");
	text->setContent("Lizatko");

	return 0;
}

