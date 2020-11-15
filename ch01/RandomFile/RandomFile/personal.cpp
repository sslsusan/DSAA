#include "personal.h"
#include <iostream>
namespace DSAA
{
	Personal::Personal() : m_name_len(10),
		m_city_len(10)
	{
		m_name = new char[m_name_len + 1];
		m_city = new char[m_city_len + 1];
	}

	Personal::Personal(const char* ssn, const char* name, const char* city, const int& year, const long& salary)
		: m_name_len(10), m_city_len(10)
	{
		std::strcpy(SSN, ssn);
		m_name = new char[m_name_len + 1];
		m_name[m_name_len] = '\0';
		std::strcpy(m_name, name);
		m_city = new char[m_city_len + 1];
		m_city[m_city_len] = '\0';
		std::strcpy(m_city, city);
		m_year = year;
		m_salary = salary;
	}

	void Personal::WriteToFile(std::fstream& out) const
	{
		out.write(SSN, 9);
		out.write(m_name, m_name_len);
		out.write(m_city, m_city_len);
		out.write(reinterpret_cast<const char*>(&m_year), sizeof(int));
		out.write(reinterpret_cast<const char*>(&m_salary), sizeof(long));
	}
	
	void Personal::ReadFromFile(std::fstream& in)
	{
		in.read(SSN, 9);
		in.read(m_name, m_name_len);
		in.read(m_city, m_city_len);
		in.read(reinterpret_cast<char*>(&m_year), sizeof(int));
		in.read(reinterpret_cast<char*>(&m_salary), sizeof(long));
	}

	void Personal::ReadKey()
	{
		char s[80];
		std::cout << "Enter SSN: ";
		std::cin.getline(s, 80);
		std::strncpy(SSN, s, 9);
	}

	std::ostream& Personal::WriteLegibly(std::ostream& out)
	{
		SSN[9] = m_name[m_name_len] = m_city[m_city_len] = '\0';
		out << "SSN = " << SSN << ", name = " << m_name << ", city = " << m_city
			<< ", year = " << m_year << ", salary = " << m_salary << std::endl;
		return out;
	}
	
	std::istream& Personal::ReadFromConsole(std::istream& in)
	{
		SSN[9] = m_name[m_name_len] = m_city[m_city_len] = '\0';
		char s[80];
		std::cout << "SSN: ";
		in.getline(s, 80);
		strncpy(SSN, s, 9);
		std::cout << "name: ";
		in.getline(s, 80);
		strncpy(m_name, s, m_name_len);
		std::cout << "city: ";
		in.getline(s, 80);
		strncpy(m_city, s, m_city_len);
		std::cout << "Birthyear: ";
		in >> m_year;
		std::cout << "Salary: ";
		in >> m_salary;
		in.ignore();
		return in;
	}
}