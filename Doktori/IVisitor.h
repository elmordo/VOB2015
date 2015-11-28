#pragma once

class Dentist;
class Common;
class Butcher;

class IVisitor
{
public:
	IVisitor();

	virtual ~IVisitor();

	virtual void apply(Dentist *dentist) = 0;

	virtual void apply(Common *common) = 0;

	virtual void apply(Butcher *butcher) = 0;

};

