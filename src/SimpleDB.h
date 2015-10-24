/*
 * SimpleDB.h
 *
 *  Created on: Oct 19, 2015
 *      Author: thiago.b
 */

#ifndef SIMPLEDB_H_
#define SIMPLEDB_H_

#include "Person.h"

namespace bcd {

class SimpleDB {
public:
	SimpleDB();
	SimpleDB(const std::string& filePath);
	void insertPerson(Person& newPerson);
	Person& getPerson(const unsigned int& CPForPassport);
	void removePerson(Person& person2Bdeleted);
	virtual ~SimpleDB();
	void saveToFile(const std::string& filePath);
	const size_t getSize() const;
private:
	std::vector<Person> mDB;
};

} /* namespace bcd */

#endif /* SIMPLEDB_H_ */
