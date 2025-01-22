// Radio_CSV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _AFXDLL

#include <string>
#include <iostream>
#include <fstream>
#include "Chirp.h"
#include "cps.h"
#include "cTools.h"

#include "Translators.h"


int main()
{
	std::locale lollocale(locale);
	::setlocale(LC_ALL, ""); // Restore the CRT. 1251

	std::cout << "Convert between CSV files!\n";
	string chFName = "h:\\temp\\radio\\Chirp_All_repeaters_all.csv";
	vector <chirp::chirp> ChRecords;                // CHIRP construction
	chirp::readCSVfile(chFName, ChRecords);

	vector <cps::cps> cpsRecords;					// CPS AnyTone D878UV II construction
	cps::cps cps;
	for (int i = 0; i < ChRecords.size(); i++)
	{
		translateChirp2CPS(ChRecords[i], cps);
		cpsRecords.push_back(cps);
	}
	string cpsFName = "H:\\Temp\\Radio\\testChannel.csv";
	cps::writeCSVfile(cpsFName, cpsRecords);


	return 0;
}
