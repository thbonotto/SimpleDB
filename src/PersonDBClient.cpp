//============================================================================
// Name        : SimpleDB.cpp
// Author      : Thiago Bonotto
// Version     :
// Copyright   : This is FREE SOFTWARE!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "SimpleDB.h"

#include <exception>
#include <iostream>

using namespace bcd;

void menuPessoa(SimpleDB& db, Person& pessoa) {
	unsigned short option;
	while (true) {
		std::cout << "Digite a opção desejada abaixo:" << std::endl
				<< "1: Imprimir dados em JSON." << std::endl
				<< "2: Imprimir dados em XML." << std::endl << "3: Deletar"
				<< std::endl << "Qualquer outro número para voltar"
				<< std::endl;

		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << pessoa.getJSONEncoded() << std::endl;
			break;
		case 2:
			std::cout << pessoa.getXMLEncoded() << std::endl;
			break;
		case 3:
			db.removePerson(pessoa);
			return;
			break;
		default:
			return;
		}
	}
}

int main() {
	SimpleDB mDatabase;
	unsigned short option;
	unsigned int cpf, telefone;
	std::vector<unsigned int> telefones;
	std::string nome, endereco;
	try {
		while (true) {
			std::cout << "Digite a opção desejada abaixo:" << std::endl
					<< "1: Importar banco de dados de um arquivo." << std::endl
					<< "2: Cadastrar pessoa." << std::endl
					<< "3: Pesquisar pessoa." << std::endl
					<< "4: Salvar banco de dados em arquivo." << std::endl;

			std::cin >> option;
			switch (option) {
			case 1:{
				std::string inputFile;
				std::cin.ignore();
				std::cout << "Digite o caminho do arquivo em que se enconta o DB." << std::endl;
				std::getline(std::cin, inputFile);
				SimpleDB loadedDB(inputFile);
				mDatabase = loadedDB;
				break;
			}
			case 2: {
				std::cin.ignore();
				std::cout << "Digite o nome da pessoa:" << std::endl;
				std::getline(std::cin, nome);
				std::cout << "Digite o endereço da pessoa:" << std::endl;
                                std::getline(std::cin, endereco);
				std::cout << "Digite o CPF da pessoa:" << std::endl;
				std::cin >> cpf;
				std::string tmp;
				while (true) {
					std::cout << "Digite um número de telefone:" << std::endl;
					std::cin >> telefone;
					std::getline(std::cin, tmp);
					telefones.push_back(telefone);
					std::cout << "Deseja adicionar mais um novo numero? s/N"
							<< std::endl;
					std::getline(std::cin, tmp);
					if (tmp != "s")
						break;
				};
				Person temp(nome, cpf, endereco, telefones);
				mDatabase.insertPerson(temp);
				break;
			}
			case 3:
				if (mDatabase.getSize() == 0) {
					std::cerr
							<< "Banco de dados vazio, importe um banco ou cadastre uma pessoa primeiro."
							<< std::endl;
					break;
				}

				std::cout << "Digite o CPF ou Passaporte da pessoa:"
						<< std::endl;
				std::cin >> cpf;
				std::cout << cpf;
				try {
					Person& temp = mDatabase.getPerson(cpf);
					menuPessoa(mDatabase, temp);
				} catch (...) {
					std::cerr
							<< "Impossível encontrar pessoa com os dados informados."
							<< std::endl;
				}
				break;
			case 4: {
				if (mDatabase.getSize() == 0) {
					std::cerr
							<< "Banco de dados vazio, importe um banco ou cadastre uma pessoa primeiro."
							<< std::endl;
					break;
				}
				std::string tmp;
				std::cin.ignore();
				std::cout << "Digite o caminho do arquivo:" << std::endl;
				std::getline(std::cin, tmp);
				mDatabase.saveToFile(tmp);
				break;
			}
			default:
				std::cerr << "Opção invalida." << std::endl;
			}

		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
