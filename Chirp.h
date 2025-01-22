// cChirp.h
// CHIRP Generic csv file 
// Header: 21 fields!
// Location,Name,Frequency,Duplex,Offset,Tone,rToneFreq,cToneFreq,DtcsCode,DtcsPolarity,RxDtcsCode,CrossMode,Mode,TStep,Skip,Power,Comment,URCALL,RPT1CALL,RPT2CALL,DVCODE

#pragma once

#ifndef __cChirp_PGP2508GFK__
#define __cChirp_PGP2508GFK__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
// Location,Name,Frequency,Duplex,Offset,Tone,rToneFreq,cToneFreq,DtcsCode,DtcsPolarity,RxDtcsCode,CrossMode,Mode,TStep,Skip,Power,Comment,URCALL,RPT1CALL,RPT2CALL,DVCODE

namespace chirp			// Defining a workspace - Chirp
{
	//const char* ctcss_codes[] = {
	//	"62.5", "67.0", "69.3", "71.9", "74.4", "77.0", "79.7", "82.5", "85.4", "88.5", "91.5",
	//	"94.8", "97.4", "100.0", "103.5", "107.2", "110.9", "114.8", "118.8", "123.0", "127.3", "131.8",
	//	"136.5", "141.3", "146.2", "151.4", "156.7", "159.8", "162.2", "165.5", "167.9", "171.3", "173.8",
	//	"177.3", "179.9", "183.5", "186.2", "189.9", "192.8", "196.6", "199.5", "203.5", "206.5", "210.7",
	//	"218.1", "225.7", "229.1", "233.6", "241.8", "250.3", "254.1" };
	//DTCS_CODES = {
	//	23, 25, 26, 31, 32, 36, 43, 47, 51, 53, 54, 65, 71, 72, 73, 74, 114, 115, 116, 122, 125, 131,
	//		132, 134, 143, 145, 152, 155, 156, 162, 165, 172, 174, 205, 212, 223, 225, 226, 243, 244, 245,
	//		246, 251, 252, 255, 261, 263, 265, 266, 271, 274, 306, 311, 315, 325, 331, 332, 343, 346, 351,
	//		356, 364, 365, 371, 411, 412, 413, 423, 431, 432, 445, 446, 452, 454, 455, 462, 464, 465, 466,
	//		503, 506, 516, 523, 526, 532, 546, 565, 606, 612, 624, 627, 631, 632, 654, 662, 664, 703, 712,
	//		723, 731, 732, 734, 743, 754 };

	struct chirp {
		~chirp() { clear(); }
		unsigned int Location = 1;		// Location: 1, 2, 3, ...
		string ChannelName = "";		// ChannelName: LZ0CUM
		float Frequency = 444.000;		// Frequency 144-146, 430-440
		string Duplex = "";				// Duplex: '', '-', '+', 'split', 'off'
		float Offset = 0.000;			// Offset - difference between the transmit and receive frequencies used for the channel if Duplex is not (None) or off (in which case it is ignored)
		string Tone = "";				// Tone: (None) 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->'Tone->', 'Tone->Tone', '->Tone', 'Tone->DTCS', 'DTCS->', 'DTCS->Tone', '->DTCS', 'DTCS->DTCS'
		string rToneFreq = "79.7";		// rToneFreq: "79.7" Receive
		string cToneFreq = "79.7";		// cToneFreq: "79.7"
		string DtcsCode = "023";		// DtcsCode: 023-754
		string DtcsPolarity = "NN";		// DtcsPolarity: NN, NR, RN, RR
		string RxDtcsCode = "";			// RxDtcsCode: 023-754
		string CrossMode = "";			// CrossMode:Tone->Tone, ->Tone, Tone->DTCS, ->DTCS, DTCS->DTCS
		string Mode = "FM";				// Mode: 'WFM', 'FM', 'NFM', 'AM', 'NAM', 'DV', 'USB', 'LSB', 'CW', 'RTTY', 'DIG', 'PKT', 'NCW', 'NCWR', 'CWR', 'P25', 'Auto', 'RTTYR', 'FSK', 'FSKR', 'DMR', 'DN'
		float TStep = 5.00;				// TStep: '2.50','5.00','6.25','10.00','12.50','20.00','25.00','30.00','50.00', '100', '125', '200', '9.0', '1.0'
		string Skip = "";				// Skip: '', 'S'
		string Power = "50W";			// Power: '5.0W','10W','20W' ['L','M','H']
		string Comment = "";			// Comment
		string URCALL = "";				// URCALL is ostensibly for the call sign of the station you're trying to call, or "CQCQCQ" for calling any station or to talk on a repeater; URCALL can also be used to hold routing information or linking commands.
		string RPT1CALL = "";			// RPT1CALL RPT1 ("RPT1CALL" in CHIRP) should be set to the local repeater and module that you're trying to access. (The setting doesn't matter for D-STAR simplex.)
		string RPT2CALL = "";			// RPT2CALL RPT2 ("RPT2CALL" in CHIRP) designates where you want your signal to be routed on your local repeater; normally RPT2 is set to the call sign of the local repeater, followed by "G". (The setting doesn't matter for D-STAR simplex.)
		string DVCODE = "";				// DVCODE

		void clear() {

			Location = 1;
			ChannelName = "";
			Frequency = 444.000;
			Duplex = "";
			Offset = 0.000;
			Tone = "";
			rToneFreq = "79.7";
			cToneFreq = "79.7";
			DtcsCode = "023";
			DtcsPolarity = "NN";
			RxDtcsCode = "";
			CrossMode = "";
			Mode = "FM";
			TStep = 5.00;
			Skip = "";
			Power = "50W";
			Comment = "";
			URCALL = "";
			RPT1CALL = "";
			RPT2CALL = "";
			DVCODE = "";
		}
	};
	bool readCSVfile(string fName, vector <chirp>&records);

	bool writeCSVfile(string fName, vector <chirp> records);

}


#endif	/* __cChirp_PGP2508GFK__ */

//	struct chirp_reduced {
//
//		string Location;	// Location
//		string ChanelName;	// Name
//		string Frequency;	// Frequency
//		string Duplex;		// Duplex		-> '', '-', '+', 'split', 'off'
//		string Offset;		// Offset
//		string Tone;		// Tone			-> 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->'Tone->', 'Tone->Tone', '->Tone', 'Tone->DTCS', 'DTCS->', 'DTCS->Tone', '->DTCS'
//		string rToneFreq;	// rToneFreq
//		string cToneFreq;	// cToneFreq
//		string Mode = "FM";		// Mode			-> 'WFM', 'FM', 'NFM', 'AM', 'NAM', 'DV', 'USB', 'LSB', 'DMR', 'Auto', ...
//		string Comment = "";		// Comment
//		void clear()
//		{
//			Location.clear();
//			ChanelName.clear();
//			Frequency.clear();
//			Duplex.clear();
//			Offset.clear();
//			Tone.clear();
//			rToneFreq.clear();
//			cToneFreq.clear();
//			Mode.clear();
//			Comment.clear();
//		}
//	};
