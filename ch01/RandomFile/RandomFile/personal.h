#ifndef _PERSONAL_H_
#define _PERSONAL_H_

#include <fstream>
#include <istream>
#include <ostream>
#include <string>

namespace DSAA {
	class Personal
	{
	public:
		Personal();
		Personal(const char*, const char*, const char*, const int&, const long&);
		void WriteToFile(std::fstream&) const;
		void ReadFromFile(std::fstream&);
		void ReadKey();
		int size() const
		{
			return 9 + m_name_len + m_city_len + sizeof(m_year) + sizeof(m_salary);
		}
		bool operator == (const Personal& p) const
		{
			return strncmp(p.SSN, SSN, 9) == 0;
		}

	protected:
		const int m_name_len;
		const int m_city_len;
		char SSN[10];
		char* m_name;
		char* m_city;
		int m_year;
		long m_salary;
		std::ostream& WriteLegibly(std::ostream&);
		friend std::ostream& operator<<(std::ostream& out, Personal& p)
		{
			return p.WriteLegibly(out);
		}
		std::istream& ReadFromConsole(std::istream&);
		friend std::istream& operator>>(std::istream& in, Personal& p)
		{
			return p.ReadFromConsole(in);
		}
	};
}

#endif