#include "student.h"
#include <iostream>

namespace DSAA
{
	Student::Student() : m_major_len(10)
	{
		Personal();
		m_major = new char[m_major_len + 1];
	}
	
	Student::Student(const char* ssn, const char* name, const char* city,
		int year, long salary, const char* major) 
		: m_major_len(10)
	{
		Personal(ssn, name, city, year, salary);
		m_major = new char[m_major_len + 1];
		strcpy(m_major, major);
	}

	void Student::WriteToFile(std::fstream& out) const
	{
		Personal::WriteToFile(out);
		out.write(m_major, m_major_len);
	}
	
	void Student::ReadFromFile(std::fstream& in)
	{
		Personal::ReadFromFile(in);
		in.read(m_major, m_major_len);
	}

	std::ostream& Student::WriteLegibly(std::ostream& out)
	{
		Personal::WriteLegibly(out);
		m_major[m_major_len] = '\0';
		std::cout << ", major = " << m_major;
		return out;
	}

	std::istream& Student::ReadFromConsole(std::istream& in)
	{
		Personal::ReadFromConsole(in);
		char s[80];
		std::cout << "major: ";
		in.getline(s, 80);
		strncpy(m_major, s, 9);
		return in;
	}
}