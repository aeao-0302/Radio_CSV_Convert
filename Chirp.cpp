// Chirp.cpp
// CHIRP Generic csv file 
// Location,Name,Frequency,Duplex,Offset,Tone,rToneFreq,cToneFreq,DtcsCode,DtcsPolarity,RxDtcsCode,CrossMode,Mode,TStep,Skip,Power,Comment,URCALL,RPT1CALL,RPT2CALL,DVCODE

#include "Chirp.h"
#include "cTools.h"

// readCSVfile CHIRP generic CSV file
// input CSV file name
// output vector chirp records
bool chirp::readCSVfile(string fName, vector <chirp>& records)
{
	ifstream fin;
	fin.open(fName, ios::in);
	if (!fin.is_open() || fin.fail())
		return false;		// Error on open file
	using NFuncConverter::Trim;
	using NFuncConverter::TokenizeNull;
	string ln, rows;
	vector <string> lines, words;
	getline(fin, ln, fin.widen('\n'));	// Reads to the end of the line  -> Location,Name,Frequency,Duplex,Offset,Tone,rToneFreq,cToneFreq,Mode,Comment
	ln = Trim(ln);
	words = CSVParser::parseCSVLine(ln);		// CSVParser is auto!!!
	unsigned short cfield = words.size();
	if (cfield != 21) cout << "CSV file is NOT GENERIC" << endl << "Error!!!" << endl;

	unsigned int i = 0;
	chirp ch;

	while (!fin.eof())								// Прочита ред от файла: record
	{
		getline(fin, ln, fin.widen('\n'));			// Reads to the end of the line
		if (ln.size() < 1) continue;
		rows = ln;
		 words = CSVParser::parseCSVLine(ln);
		if (words.size() < cfield)					// If a record is split across multiple lines! For example, comments!
			while (!fin.eof())
			{
				getline(fin, ln, fin.widen('\n'));	// Reads to the end of the line
				rows = rows + ln;
				 words = CSVParser::parseCSVLine(rows);
				if (words.size() >= cfield) break;
			};
		i = 0;
		ch.Location = atoi(Trim(words[i++]).c_str());
		ch.ChannelName = Trim(words[i++]);
		ch.Frequency = atof(Trim(words[i++]).c_str());
		ch.Duplex = Trim(words[i++]);
		ch.Offset = atof(Trim(words[i++]).c_str());
		ch.Tone = Trim(words[i++]);
		ch.rToneFreq = Trim(words[i++]);
		ch.cToneFreq = Trim(words[i++]);
		ch.DtcsCode = Trim(words[i++]);
		ch.DtcsPolarity = Trim(words[i++]);
		ch.RxDtcsCode = Trim(words[i++]);
		ch.CrossMode = Trim(words[i++]);
		ch.Mode = Trim(words[i++]);
		ch.TStep = atof(Trim(words[i++]).c_str());
		ch.Skip = Trim(words[i++]);
		ch.Power = Trim(words[i++]);
		ch.Comment = Trim(words[i++]);
		ch.URCALL = Trim(words[i++]);
		ch.RPT1CALL = Trim(words[i++]);
		ch.RPT2CALL = Trim(words[i++]);
		ch.DVCODE = Trim(words[i++]);
		records.push_back(ch);
	}

	fin.close();

	return true;
}


// writeCSVfile CHIRP generic CSV file
// input CSV file name, vector chirp records
// output file
bool chirp::writeCSVfile(string fName, vector <chirp> records)
{
	ofstream fout;
	fout.open(fName, ios::out);
	if (!fout.is_open() || fout.fail())
		return false;		// Error on open file
	// write header line
	fout << "Location,Name,Frequency,Duplex,Offset,Tone,rToneFreq,cToneFreq,DtcsCode,DtcsPolarity,RxDtcsCode,CrossMode,Mode,TStep,Skip,Power,Comment,URCALL,RPT1CALL,RPT2CALL,DVCODE" << endl;
	// write records
	for (unsigned int i=0; i<records.size(); i++)
		fout << "," << records[i].Location
			<< "," << records[i].ChannelName
			<< "," << records[i].Frequency
			<< "," << records[i].Duplex
			<< "," << records[i].Offset
			<< "," << records[i].Tone
			<< "," << records[i].rToneFreq
			<< "," << records[i].cToneFreq
			<< "," << records[i].DtcsCode
			<< "," << records[i].DtcsPolarity
			<< "," << records[i].RxDtcsCode
			<< "," << records[i].CrossMode
			<< "," << records[i].Mode
			<< "," << records[i].TStep
			<< "," << records[i].Skip
			<< "," << records[i].Power
			<< ",\"" << records[i].Comment
			<< "\"," << records[i].URCALL
			<< "," << records[i].RPT1CALL
			<< "," << records[i].RPT2CALL
			<< "," << records[i].DVCODE << endl;

	fout.close();

	return true;
}

