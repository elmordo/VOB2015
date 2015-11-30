#include "TextPriner.h"


TextPrinter::TextPrinter()
{
}


TextPrinter::~TextPrinter()
{
}

void TextPrinter::handle(Event &e)
{
	cout << e.getData() << endl;
}
