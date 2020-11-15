#include "student.h"
#include "personal.h"
#include "database.h"

#include <iostream>

using namespace std;

namespace DSAA
{
	template<typename T>
		DataBase<T>::DataBase()
	{
	}
	
	template<typename T>
	void DataBase<T>::add(T& d)
	{
		database.open(fName, ios::in | ios::out | ios::binary);
		database.seekp(0, ios::end);
		d.WriteToFile(database);
		database.close();
	}
	
	template<typename T>
	void DataBase<T>::modify(const T& d)
	{
		T tmp;
		database.open(fName, ios::in | ios::out | ios::binary);
		while (database.eof())
		{
			tmp.ReadFromFile(database);
			if (tmp == d)
			{
				cin >> tmp;
				database.seekp(-d.size(), ios::cur);
				tmp.WriteToFile(database);
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
			tmp.ReadFromFile(database);
			if (tmp == d)
			{
				database.close();
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
			tmp.ReadFromFile(database);
			if (database.eof())
				break;
			out << tmp << endl;
		}
		database.close();
		return out;
	}

	template<typename T>
	void DataBase<T>::run()
	{
		cout << "File name: ";
		cin >> fName;
		cin.ignore();	// skip '\n';
		database.open(fName, ios::in);
		if (database.fail())
			database.open(fName, ios::out);
		database.close();
		char option[5];
		T rec;
		cout << "1. Add 2. Find 3. Modify a record; 4. Exit\n";
		cout << "Enter an option: ";
		while (cin.getline(option, 5)) 
		{
			if (*option == '1') 
			{
				cin >> rec;   // overloaded >>
				add(rec);
			}
			else if (*option == '2') 
			{
				rec.ReadKey();
				cout << "The record is ";
				if (find(rec) == false)
					cout << "not ";
				cout << "in the database\n";
			}
			else if (*option == '3') 
			{
				rec.ReadKey();
				modify(rec);
			}
			else if (*option != '4')
				cout << "Wrong option\n";
			else return;
			cout << *this;   // overloaded <<
			cout << "Enter an option: ";
		}
	}
}

int main(int argc, char* argv[])
{
	DSAA::DataBase<DSAA::Personal>().run();
}