/*
 * SimpleDB.cpp
 *
 *  Created on: Oct 19, 2015
 *      Author: thiago.b
 */

#include "SimpleDB.h"
#include <iostream>
#include <fstream>
//#include <jsoncpp/json/reader.h>
namespace bcd {

SimpleDB::SimpleDB() {
	// TODO Auto-generated constructor stub

}

SimpleDB::SimpleDB(const std::string& filePath){
	std::ifstream myfile;
	std::string buffer, buffer2;
	myfile.open(filePath);
/*	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;

	reader.parse(myfile,root);

	std::vector<std::string> r=root.getMemberNames();

	std::cout << root.get("Pessoa.CPFouPassorte",root).asString()  << std::endl;

	unsigned int cpf, telefone;
	std::vector<unsigned int> telefones;
	std::string nome, endereco;


*/

}

SimpleDB::~SimpleDB() {
	// TODO Auto-generated destructor stub
}
void SimpleDB::insertPerson(Person& newPerson) {
	mDB.push_back(newPerson);
}
Person& SimpleDB::getPerson(const unsigned int& CPForPassport) {
	for (Person& temp : this->mDB)
		if (temp.getCpf() == CPForPassport)
			return temp;
	throw "Nenhum pessoa encontrada";
}
void SimpleDB::removePerson(Person& person2Bdeleted) {
	int pos = -1;
	for (Person& tmp : mDB) {
		pos++;
		if (tmp.getCpf() == person2Bdeleted.getCpf())
			break;
	}
	if (pos != -1)
		mDB.erase(mDB.begin() + pos);
}

void SimpleDB::saveToFile(const std::string& filePath) {
	std::ofstream myfile;
	myfile.open(filePath);
	std::string db{"{ \"Database\": ["};
		for(const auto& tmp : mDB)
			db+="\""+ tmp.getJSONEncoded() +"\",";
	const char* fim = "]\0";
	db.back()=*fim;
	db+="\n}";
	myfile << db;
	myfile.close();


}
const size_t SimpleDB::getSize() const {
	return mDB.size();
}
} /* namespace bcd */
