/*
 * Person.h
 *
 *  Created on: Oct 19, 2015
 *      Author: thiago.b
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <vector>

namespace bcd {

class Person {
public:
	Person(std::string& mName,
			unsigned int& mCPForPassport,
			std::string& mCompleteAdress,
			std::vector<unsigned int>& mPhones);

	virtual ~Person();
	std::string getJSONEncoded() const;
	std::string getXMLEncoded() const;
	const unsigned int& getCpf() const;

private:
	std::string mName;
	unsigned int mCPForPassport;
	std::string mCompleteAdress;
	std::vector<unsigned int> mPhones;

};

} /* namespace bcd */

#endif /* PERSON_H_ */
