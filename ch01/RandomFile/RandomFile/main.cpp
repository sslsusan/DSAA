#include "personal.h"
#include "student.h"
#include "database.h"
#include <iostream>

int main(int argc, char* argv[])
{
	//DSAA::Personal p("510", "sushi", "beijing", 1994, 18);
	DSAA::DataBase<DSAA::Personal>().run();
	
	//p.WriteToFile("1.txt");
	return 0;
}
