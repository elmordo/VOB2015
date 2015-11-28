// Doktori.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

#include "Dentist.h"
#include "Common.h"
#include "Butcher.h"

#include "Audit.h"
#include "Patient.h"

void visitDoctor(IDoktor *doc, IVisitor *visitor)
{
	doc->visitMe(visitor);
}

int _tmain(int argc, _TCHAR* argv[])
{

	Dentist dentist;
	Common common;
	Butcher butcher;

	Audit audit;
	Patient patien;

	audit.apply(&dentist);

	dentist.visitMe(&patien);
	dentist.visitMe(&patien);

	common.visitMe(&patien);
	common.visitMe(&patien);
	common.visitMe(&patien);

	butcher.visitMe(&patien);

	dentist.visitMe(&audit);
	common.visitMe(&audit);
	butcher.visitMe(&audit);

	getchar();

	return 0;
}

