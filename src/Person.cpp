/*
 * Person.cpp
 *
 *  Created on: Oct 19, 2015
 *      Author: thiago.b
 */

#include "Person.h"
#include <utility>
namespace bcd {

Person::Person(std::string& mName,
		unsigned int& mCPForPassport,
		std::string& mCompleteAdress,
		std::vector<unsigned int>& mPhones){
	this->mName = std::move(mName);
	this->mCompleteAdress = std::move(mCompleteAdress);
	this->mCPForPassport = std::move(mCPForPassport);
	this->mPhones = std::move(mPhones);
}
Person::~Person() {
	// TODO Auto-generated destructor stub
}

std::string Person::getJSONEncoded() const {
	std::string retorno;
	retorno="{ \"Pessoa\": {\n";
	//retorno="{ \"Pessoa\": {";
	retorno+="\t \"Nome\": \"" + this->mName + "\",\n";
	retorno+="\t \"CPFouPassorte\": \"" + std::to_string(this->mCPForPassport) + "\",\n";
	retorno+="\t \"Endereco\":\"" + this->mCompleteAdress + "\",\n";
//	retorno+="\"CPFouPassaporte\": \"" + std::to_string(this->mCPForPassport) + "\",";
//	retorno+="\"Endereco\":\"" + this->mCompleteAdress + "\",";
	retorno+="\"Telefones\": [";
	for(const auto& telefone : this->mPhones){
		retorno+="\""+std::to_string(telefone)+"\",";
	}
	const char* fim = "]\0";
	retorno.back()=*fim;
	retorno+="\n\t} \n}";
//	retorno+="} }";
	return retorno;
}

std::string Person::getXMLEncoded() const {
	std::string retorno;
	retorno="<Pessoa> \n";
	retorno+="\t <Nome>" + this->mName + "</Nome>\n";
	retorno+="\t <CPFouPassaporte>" + std::to_string(this->mCPForPassport) + "</CPFouPassaporte>\n";
	retorno+="\t <Endereco>" + this->mCompleteAdress + "</Endereco>\n";
	retorno+="\t <Telefones>\n";
	for(const auto& telefone : this->mPhones)
		retorno+="\t\t <Telefone>"+std::to_string(telefone)+"<Telefone>\n";
	retorno+="\t </Telefones>\n";
	retorno+="</Pessoa>";
	return retorno;
}
const unsigned int& Person::getCpf() const{
	return this->mCPForPassport;
}
} /* namespace bcd */
