#pragma once


class IVisitor;


class IDoktor
{

protected:

	int numberOfPatients;

public:
	IDoktor();

	IDoktor(const IDoktor &original);

	virtual ~IDoktor();

	int getNumberOfPatient() const;

	void incrementNumberOfPatient();

	virtual void visitMe(IVisitor *visitor) = 0;

};

