#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <fstream>
#include <istream>
#include <ostream>
#include <string>

namespace DSAA
{
	template<typename T>
	class DataBase
	{
	public: 
		DataBase(); 
		void run();
	private:
		std::fstream database;
		char fName[20];
		std::ostream& print(std::ostream&);
		void add(T&);
		bool find(const T&);
		void modify(const T&);
		friend std::ostream& operator << (std::ostream& out, DataBase& db)
		{
			return db.print(out);
		}
	};
}

#endif