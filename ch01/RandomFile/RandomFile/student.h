#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "personal.h"

namespace DSAA{
	class Student : public Personal
	{
	public:
		Student();
		Student(const char*, const char*, const char*, int, long, const char*);
		void WriteToFile(std::fstream&) const;
		void ReadFromFile(std::fstream&);
		int size() const
		{
			return Personal::size() + m_major_len;
		}

	protected:
		char* m_major;
		int m_major_len;
		std::ostream& WriteLegibly(std::ostream&);
		friend std::ostream& operator << (std::ostream& out, Student& s)
		{
			return s.WriteLegibly(out);
		}
		std::istream& ReadFromConsole(std::istream&);
		friend std::istream& operator >> (std::istream& in, Student s)
		{
			return s.ReadFromConsole(in);
		}
	};
}


#endif