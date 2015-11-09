// ForeverAlone.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

#include "stdafx.h"

#include "Cat.h"
#include "Dog.h"
#include "CatFactory.h"
#include "DogFactory.h"
#include "AbstractPetFactory.h"
#include "ShoutSound.h"
#include "HtmlSound.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int petType;

	cout << "Jaky zvire bude baba mit (" << AbstractPetFactory::CAT_FACTORY << 
		" - kocka, " << AbstractPetFactory::DOG_FACTORY << " - pes)? ";
	cin >> petType;

	AbstractPetFactory abstractFactory;
	IPetFactory *petFactory = abstractFactory.createFactory(
		(AbstractPetFactory::FACTORY_TYPE)petType);

	if (petFactory == NULL)
	{
		cout << "Spatna tovarna" << endl;
		return 1;
	}

	int action = 1;
	vector<IPet *> zverinec;

	do
	{
		cout << "Vytvorit zvire? (1 - ano, 0 - ne)";
		cin >> action;

		if (action == 1)
		{
			IPet *pet;
			string name;
			cout << "Jmeno: ";
			cin >> name;

			pet = petFactory->createPet(name);

			ShoutSound *decoratorShout = new ShoutSound();
			HtmlSound *decoratorHtml = new HtmlSound();

			decoratorShout->setParent(pet);
			decoratorHtml->setParent(decoratorShout);

			zverinec.push_back(decoratorHtml);
		}

	} while (action);

	cout << "Mame " << zverinec.size() << " zvirat" << endl;
	allocator<IPet> petAlloc;

	for (int i = 0; i < zverinec.size(); ++i)
	{
		cout << zverinec[i]->getName() << " dela " << 
			zverinec[i]->makeSound() << endl;
		petAlloc.destroy(zverinec[i]);
		petAlloc.deallocate(zverinec[i], 1);
	}

	getchar();
	delete petFactory;

	return 0;
}

