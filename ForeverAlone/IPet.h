#pragma once

#include <string>

using namespace std;

class IPet
{

	string name;

public:

	/**
	 * @brief create pet with no name
	 */
	IPet();

	/**
	 * @brief destructor do nothing
	 */
	virtual ~IPet();

	/**
	 * @brief return pet's name
	 * @return name as std::string
	 */
	virtual string getName() const;

	/**
	 * @brief set new name to pet
	 * @param name new name to set
	 */
	void setName(const string &name);

	/**
	 * @brief make pet's sound (we do not know what animal
	 *      is it, so it is pure virtual)
	 * @return iteral representation of sound
	 */
	virtual string makeSound() const = 0;

};

