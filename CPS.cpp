// cps.cpp
// CPS AnyTone Channel.csv file read, write

#include "cps.h"
#include "cTools.h"


// readCSVfile CPS AnyTone Channel.csv CSV file
// input CSV file name
// output vector CPS Channel.csv records
bool cps::readCSVfile(string fName, vector <cps>& records)
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
	if (cfield != 55) cout << "CSV file is NOT CPS AnyTone Channel" << endl << "Error!!!" << endl;
	unsigned int i = 0;
	cps ch;

	while (!fin.eof())							// Reads a line from the file: record
	{
		getline(fin, ln, fin.widen('\n'));		// Reads to the end of the line
		if (ln.size() < 1) continue;
		rows = ln;
		words = CSVParser::parseCSVLine(ln);
		if (words.size() < cfield)				// If a record is split into multiple lines!!!
			while (!fin.eof())
			{
				getline(fin, ln, fin.widen('\n'));	// Reads to the end of the line
				rows = rows + ln;
				words = CSVParser::parseCSVLine(rows);
				if (words.size() >= cfield) break;
			};
		i = 0;
		ch.No = Trim(words[i++]);
		ch.ChannelName = Trim(words[i++]);
		ch.ReceiveFrequency = Trim(words[i++]);
		ch.TransmitFrequency = Trim(words[i++]);
		ch.ChannelType = Trim(words[i++]);
		ch.TransmitPower = Trim(words[i++]);
		ch.BandWidth = Trim(words[i++]);
		ch.CTCSS_DCS_Decode = Trim(words[i++]);
		ch.CTCSS_DCS_Encode = Trim(words[i++]);
		ch.Contact = Trim(words[i++]);
		ch.ContactCallType = Trim(words[i++]);
		ch.ContactTG_DMR_ID = Trim(words[i++]);
		ch.Radio_ID = Trim(words[i++]);
		ch.BusyLockTXPermit = Trim(words[i++]);
		ch.Squelch_Mode = Trim(words[i++]);
		ch.Optional_Signal = Trim(words[i++]);
		ch.DTMF_ID = Trim(words[i++]);
		ch._2Tone_ID = Trim(words[i++]);
		ch._5Tone_ID = Trim(words[i++]);
		ch.PTT_ID = Trim(words[i++]);
		ch.Color_Code = Trim(words[i++]);
		ch.Slot = Trim(words[i++]);
		ch.Scan_List = Trim(words[i++]);
		ch.Receive_Group_List = Trim(words[i++]);
		ch.PTT_Prohibit = Trim(words[i++]);
		ch.Reverse = Trim(words[i++]);
		ch.Simplex_TDMA = Trim(words[i++]);
		ch.Slot_Suit = Trim(words[i++]);
		ch.AES_Digital_Encryption = Trim(words[i++]);
		ch.Digital_Encryption = Trim(words[i++]);
		ch.Call_Confirmation = Trim(words[i++]);
		ch.Talk_Around_Simplex = Trim(words[i++]);
		ch.Work_Alone = Trim(words[i++]);
		ch.Custom_CTCSS = Trim(words[i++]);
		ch._2TONE_Decode = Trim(words[i++]);
		ch.Ranging = Trim(words[i++]);
		ch.Through_Mode = Trim(words[i++]);
		ch.APRS_RX = Trim(words[i++]);
		ch.Analog_APRS_PTT_Mode = Trim(words[i++]);
		ch.Digital_APRS_PTT_Mode = Trim(words[i++]);
		ch.APRS_Report_Type = Trim(words[i++]);
		ch.Digital_APRS_Report_Channel = Trim(words[i++]);
		ch.Correct_FrequencyHz = Trim(words[i++]);
		ch.SMS_Confirmation = Trim(words[i++]);
		ch.Exclude_channel_from_roaming = Trim(words[i++]);
		ch.DMR_MODE = Trim(words[i++]);
		ch.DataACK_Disable = Trim(words[i++]);
		ch.R5toneBot = Trim(words[i++]);
		ch.R5ToneEot = Trim(words[i++]);
		ch.Auto_Scan = Trim(words[i++]);
		ch.Ana_Aprs_Mute = Trim(words[i++]);
		ch.Send_Talker_Alias = Trim(words[i++]);
		ch.AnaAprsTxPath = Trim(words[i++]);
		ch.ARC4 = Trim(words[i++]);
		ch.ex_emg_kind = Trim(words[i++]);

		records.push_back(ch);
	}

	fin.close();

	return true;
}

// writeCSVfile AnyTone Channel.CSV file
// input CSV file name, vector cps records
// output file
bool cps::writeCSVfile(string fName, vector <cps> records)
{
	ofstream fout;
	fout.open(fName, ios::out);
	if (!fout.is_open() || fout.fail())
		return false;		// Error on open file
	// write header line
	fout << "\"No.\",\"Channel Name\",\"Receive Frequency\",\"Transmit Frequency\",\"Channel Type\",\"Transmit Power\",\"Band Width\",\"CTCSS/DCS Decode\",\"CTCSS/DCS Encode\",\"Contact\",\"Contact Call Type\",\"Contact TG/DMR ID\",\"Radio ID\",\"Busy Lock/TX Permit\",\"Squelch Mode\",\"Optional Signal\",\"DTMF ID\",\"2Tone ID\",\"5Tone ID\",\"PTT ID\",\"Color Code\",\"Slot\",\"Scan List\",\"Receive Group List\",\"PTT Prohibit\",\"Reverse\",\"Simplex TDMA\",\"Slot Suit\",\"AES Digital Encryption\",\"Digital Encryption\",\"Call Confirmation\",\"Talk Around(Simplex)\",\"Work Alone\",\"Custom CTCSS\",\"2TONE Decode\",\"Ranging\",\"Through Mode\",\"APRS RX\",\"Analog APRS PTT Mode\",\"Digital APRS PTT Mode\",\"APRS Report Type\",\"Digital APRS Report Channel\",\"Correct Frequency[Hz]\",\"SMS Confirmation\",\"Exclude channel from roaming\",\"DMR MODE\",\"DataACK Disable\",\"R5toneBot\",\"R5ToneEot\",\"Auto Scan\",\"Ana Aprs Mute\",\"Send Talker Alias\",\"AnaAprsTxPath\",\"ARC4\",\"ex_emg_kind\"" << endl;
	// write records
	for (unsigned int i = 0; i < records.size(); i++)
		fout << "\"" << records[i].No
		<< "\",\"" << records[i].ChannelName
		<< "\",\"" << records[i].ReceiveFrequency
		<< "\",\"" << records[i].TransmitFrequency
		<< "\",\"" << records[i].ChannelType
		<< "\",\"" << records[i].TransmitPower
		<< "\",\"" << records[i].BandWidth
		<< "\",\"" << records[i].CTCSS_DCS_Decode
		<< "\",\"" << records[i].CTCSS_DCS_Encode
		<< "\",\"" << records[i].Contact
		<< "\",\"" << records[i].ContactCallType
		<< "\",\"" << records[i].ContactTG_DMR_ID
		<< "\",\"" << records[i].Radio_ID
		<< "\",\"" << records[i].BusyLockTXPermit
		<< "\",\"" << records[i].Squelch_Mode
		<< "\",\"" << records[i].Optional_Signal
		<< "\",\"" << records[i].DTMF_ID
		<< "\",\"" << records[i]._2Tone_ID
		<< "\",\"" << records[i]._5Tone_ID
		<< "\",\"" << records[i].PTT_ID
		<< "\",\"" << records[i].Color_Code
		<< "\",\"" << records[i].Slot
		<< "\",\"" << records[i].Scan_List
		<< "\",\"" << records[i].Receive_Group_List
		<< "\",\"" << records[i].PTT_Prohibit
		<< "\",\"" << records[i].Reverse
		<< "\",\"" << records[i].Simplex_TDMA
		<< "\",\"" << records[i].Slot_Suit
		<< "\",\"" << records[i].AES_Digital_Encryption
		<< "\",\"" << records[i].Digital_Encryption
		<< "\",\"" << records[i].Call_Confirmation
		<< "\",\"" << records[i].Talk_Around_Simplex
		<< "\",\"" << records[i].Work_Alone
		<< "\",\"" << records[i].Custom_CTCSS
		<< "\",\"" << records[i]._2TONE_Decode
		<< "\",\"" << records[i].Ranging
		<< "\",\"" << records[i].Through_Mode
		<< "\",\"" << records[i].APRS_RX
		<< "\",\"" << records[i].Analog_APRS_PTT_Mode
		<< "\",\"" << records[i].Digital_APRS_PTT_Mode
		<< "\",\"" << records[i].APRS_Report_Type
		<< "\",\"" << records[i].Digital_APRS_Report_Channel
		<< "\",\"" << records[i].Correct_FrequencyHz
		<< "\",\"" << records[i].SMS_Confirmation
		<< "\",\"" << records[i].Exclude_channel_from_roaming
		<< "\",\"" << records[i].DMR_MODE
		<< "\",\"" << records[i].DataACK_Disable
		<< "\",\"" << records[i].R5toneBot
		<< "\",\"" << records[i].R5ToneEot
		<< "\",\"" << records[i].Auto_Scan
		<< "\",\"" << records[i].Ana_Aprs_Mute
		<< "\",\"" << records[i].Send_Talker_Alias
		<< "\",\"" << records[i].AnaAprsTxPath
		<< "\",\"" << records[i].ARC4
		<< "\",\"" << records[i].ex_emg_kind<< "\"" << endl;

	fout.close();

	return true;
}

