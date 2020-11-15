#include "student.h"
#include "personal.h"
#include "database.h"

#include <iostream>

namespace DSAA
{
	template<typename T>
		DataBase<T>::DataBase()
	{
	}
	
	template<typename T>
	void DataBase<T>::add(T&)
	{
		database.open(fName, ios::in | ios::out | ios::binary);
		database.seekp(0, ios::end);
		d.writeToFile(database);
		database.close();
	}
	
	template<typename T>
	void DataBase<T>::modify(const T& d)
	{
		T tmp;
		database.open(fName, ios::in | ios::out | ios::binary);
		while (database.eof())
		{
			tmp.readFromFile(databanse);
			if (tmp == d)
			{
				cin >> tmp;
				database.seekp(-d.size(), ios::cur);
				tmp.writeToFile(database);
				database.close();
				return;
			}
		}
		database.close();
		std::cout << "The record to be modified is not in the database" << std::endl;
	}

	template<typename T>
	bool DataBase<T>::find(const T& d)
	{
		T tmp;
		database.open(fName, ios::in | ios::binary);
		while (database.eof())
		{
			tmp.readFromFile(database);
			if (tmp == d)
			{
				database.colse();
				return true;
			}
		}
		database.close();
		return false;
	}

	template<typename T>
	std::ostream& DataBase<T>::print(std::ostream& out)
	{
		T tmp;
		database.open(fName, ios::in | ios::binary);
		while (true)
		{
			tmp.readFromFile(database);
			if (database.eof())
				break;
			std::out << tmp << std::endl;
		}
		database.close();
		return out;
	}

	template<typename T>
	void DataBase<T>::run()
	{
		std::cout << "File name: ";
		std::cin >> fName;
		char option[5];
		T rec;
		std::cout << "1. Add 2. Find 3. Modify a record; 4. Exit" << std::endl;
		std::cout << "Enter an option: ";
		std::cin.getline(option, 4);
		while (std::cin.getline(option, 4))
		{
			if (*option == '1')
			{
				std::cin >> rec;
				add(rec);
			}
			else if (*option == '2')
			{
				rec.readKey();
				std::cout << "The record is ";
				if (find(rec) == false)
				{
					std::cout << "not ";
				}
				std::cout << "in the database" << std::endl;
			}
			else if (*option == '3')
			{
				rec.readKey();
				modify(rec);
			}
			else if (*option != 4)
			{
				std::cout << "Worng option" << std::endl;
			}
			else
				return;

			std::cout << *this;
			std::cout << "Enter an option: ";
		}
	}
}