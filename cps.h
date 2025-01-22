// cps.h
// CPS AnyTone Channel.CSV file read, write
// Header: 55 fields!
// "No.","Channel Name","Receive Frequency","Transmit Frequency","Channel Type","Transmit Power","Band Width","CTCSS/DCS Decode","CTCSS/DCS Encode","Contact","Contact Call Type","Contact TG/DMR ID","Radio ID","Busy Lock/TX Permit","Squelch Mode","Optional Signal","DTMF ID","2Tone ID","5Tone ID","PTT ID","Color Code","Slot","Scan List","Receive Group List","PTT Prohibit","Reverse","Simplex TDMA","Slot Suit","AES Digital Encryption","Digital Encryption","Call Confirmation","Talk Around(Simplex)","Work Alone","Custom CTCSS","2TONE Decode","Ranging","Through Mode","APRS RX","Analog APRS PTT Mode","Digital APRS PTT Mode","APRS Report Type","Digital APRS Report Channel","Correct Frequency[Hz]","SMS Confirmation","Exclude channel from roaming","DMR MODE","DataACK Disable","R5toneBot","R5ToneEot","Auto Scan","Ana Aprs Mute","Send Talker Alias","AnaAprsTxPath","ARC4","ex_emg_kind"


#pragma once

#ifndef __cCPS_PGP2508GFK__
#define __cCPS_PGP2508GFK__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

namespace cps			// Defining a workspace - CPS AnyTone D878UVII 3.05
{
	//enum ctcss {
	//	"62.5", "67.0", "69.3", "71.9", "74.4", "77.0", "79.7", "82.5", "85.4", "88.5", "91.5",
	//	"94.8", "97.4", "100.0", "103.5", "107.2", "110.9", "114.8", "118.8", "123.0", "127.3", "131.8",
	//	"136.5", "141.3", "146.2", "151.4", "156.7", "159.8", "162.2", "165.5", "167.9", "171.3", "173.8",
	//	"177.3", "179.9", "183.5", "186.2", "189.9", "192.8", "196.6", "199.5", "203.5", "206.5", "210.7",
	//	"218.1", "225.7", "229.1", "233.6", "241.8", "250.3", "254.1"
	//};
	struct cps {
		string No = "1";						// No. -> 1-4000 Location "17" 
		string ChannelName = "Channel1";		// Channel name "Channel17"
		string ReceiveFrequency = "440.00000";	// "Receive Frequency"			-> "440.00000"
		string TransmitFrequency = "440.00000";	// "Transmit Frequency"			-> "440.00000"
		string ChannelType = "A-Analog";		// "Channel Type"				-> "A-Analog", "D-Digital", "A+D TX A", "D+A TX D"
		string TransmitPower = "Mid";			// "Transmit Power"				-> "Low", "Mid", "High", "Turbo"
		string BandWidth = "12.5K";				// "Band Width"					-> "12.5K", "25K" Bandwidth - "25K" for FM or "12.5K" for NFM
		string CTCSS_DCS_Decode = "Off";		// "CTCSS/DCS Decode"			-> "Off", CTCSS_CODES, DTCS_CODES
		string CTCSS_DCS_Encode = "Off";		// "CTCSS/DCS Encode"			-> "Off", CTCSS_CODES, DTCS_CODES
		string Contact = "Contact 1";			// "Contact"					-> "Contact 1"
		string ContactCallType = "Group Call";	// "Contact Call Type"			-> "Group Call"
		string ContactTG_DMR_ID = "1";			// "Contact TG/DMR ID"			-> "1"
		string Radio_ID = "";					// "Radio ID"					-> ""
		string BusyLockTXPermit = "Always";		// "Busy Lock/TX Permit"		-> "Always"
		string Squelch_Mode = "Carrier";		// "Squelch Mode"				-> "Carrier", "CTCSS/DCS"
		string Optional_Signal = "Off";			// "Optional Signal"			-> "Off"
		string DTMF_ID = "1";					// "DTMF ID"					-> "1"
		string _2Tone_ID = "1";					// "2Tone ID"					-> "1"
		string _5Tone_ID = "1";					// "5Tone ID"					-> "1"
		string PTT_ID = "Off";					// "PTT ID"						-> "Off"
		string Color_Code = "1";				// "Color Code"					-> "0"-"14"
		string Slot = "1";						// "Slot"						-> "1"Slot1, "?"Slot2
		string Scan_List = "None";				// "Scan List"					-> "None"
		string Receive_Group_List = "None";		// "Receive Group List"			-> "None"
		string PTT_Prohibit = "Off";			// "PTT Prohibit"				-> "Off"
		string Reverse = "Off";					// "Reverse"					-> "Off"
		string Simplex_TDMA = "Off";			// "Simplex TDMA"				-> "Off"
		string Slot_Suit = "Off";				// "Slot Suit"					-> "Off"
		string AES_Digital_Encryption = "Normal Encryption";	// "AES Digital Encryption"	-> "Normal Encryption"
		string Digital_Encryption = "Off";		// "Digital Encryption"			-> "Off"
		string Call_Confirmation = "Off";		// "Call Confirmation"			-> "Off"
		string Talk_Around_Simplex = "Off";		// "Talk Around(Simplex)"		-> "Off"
		string Work_Alone = "Off";				// "Work Alone"					-> "Off"
		string Custom_CTCSS = "251.1";			// "Custom CTCSS"				-> "251.1"
		string _2TONE_Decode = "0";				// "2TONE Decode"				-> "0"
		string Ranging = "Off";					// "Ranging"					-> "Off"
		string Through_Mode = "Off";			// "Through Mode"				-> "Off"
		string APRS_RX = "Off";					// "APRS RX"					-> "Off"
		string Analog_APRS_PTT_Mode = "Off";	// "Analog APRS PTT Mode"		-> "Off"
		string Digital_APRS_PTT_Mode = "Off";	// "Digital APRS PTT Mode"		-> "Off"
		string APRS_Report_Type = "Off";		// "APRS Report Type"			-> "Off"
		string Digital_APRS_Report_Channel = "1";// "Digital APRS Report Channel"	-> "1"
		string Correct_FrequencyHz = "0";		// "Correct Frequency[Hz]"		-> "0"
		string SMS_Confirmation = "Off";		// "SMS Confirmation"			-> "Off" "On"
		string Exclude_channel_from_roaming = "0";	// Exclude channel from roaming 0-Off, 1-On
		string DMR_MODE = "0";					// DMR MODE 0-DMO/Simplex, 1-Repeater, 2-DCDM/Double slot, 3-DCDM TS Split
		string DataACK_Disable = "0";			// "DataACK Disable"			-> "0"
		string R5toneBot = "0";					// "R5toneBot"					-> "0"
		string R5ToneEot = "0";					// "R5ToneEot"					-> "0"
		string Auto_Scan = "0";					// "Auto Scan"					-> "0"
		string Ana_Aprs_Mute = "0";				// "Ana Aprs Mute"				-> "0"
		string Send_Talker_Alias = "0";			// "Send Talker Alias"			-> "0","1"
		string AnaAprsTxPath = "0";				// "AnaAprsTxPath"				-> "0"
		string ARC4 = "0";						// "ARC4"						-> "0"
		string ex_emg_kind = "0";				// "ex_emg_kind"				-> "0"
		void clear()
		{
			No.clear();							// "No. -> Location"				-> "19"
			ChannelName.clear();				// "Chanel Name"					-> "Channel18"
			ReceiveFrequency.clear();			// "Receive Frequency"				-> "440.00000"
			TransmitFrequency.clear();			// "Transmit Frequency"				-> "440.00000"
			ChannelType.clear();                 // "Channel Type"					-> "A-Analog", "D-Digital", "A+D TX A", "D+A TX D"
			TransmitPower.clear();               // "Transmit Power"					-> "Low", "Mid", "High", "Turbo"
			BandWidth.clear();                  // "Band Width"						-> "12.5K", "25K"
			CTCSS_DCS_Decode.clear();            // "CTCSS/DCS Decode"				-> "Off", "CTCSS", "DCS"
			CTCSS_DCS_Encode.clear();            // "CTCSS/DCS Encode"				-> "Off", "CTCSS", "DCS"
			Contact.clear();                     // "Contact"						-> "Contact 1"
			ContactCallType.clear();             // "Contact Call Type"				-> "Group Call"
			ContactTG_DMR_ID.clear();            // "Contact TG/DMR ID"				-> "1"
			Radio_ID.clear();                    // "Radio ID"						-> ""
			BusyLockTXPermit.clear();            // "Busy Lock/TX Permit"			-> "Always"
			Squelch_Mode.clear();                // "Squelch Mode"					-> "Carrier", "CTCSS/DCS"
			Optional_Signal.clear();             // "Optional Signal"				-> "Off"
			DTMF_ID.clear();                     // "DTMF ID"						-> "1"
			_2Tone_ID.clear();                   // "2Tone ID"						-> "1"
			_5Tone_ID.clear();                   // "5Tone ID"						-> "1"
			PTT_ID.clear();                      // "PTT ID"							-> "Off"
			Color_Code.clear();                  // "Color Code"						-> "1"
			Slot.clear();                        // "Slot"							-> "1"
			Scan_List.clear();                   // "Scan List"						-> "None"
			Receive_Group_List.clear();          // "Receive Group List"				-> "None"
			PTT_Prohibit.clear();                // "PTT Prohibit"					-> "Off"
			Reverse.clear();                     // "Reverse"						-> "Off"
			Simplex_TDMA.clear();                // "Simplex TDMA"					-> "Off"
			Slot_Suit.clear();                   // "Slot Suit"						-> "Off"
			AES_Digital_Encryption.clear();      // "AES Digital Encryption"			-> "Normal Encryption"
			Digital_Encryption.clear();          // "Digital Encryption"				-> "Off"
			Call_Confirmation.clear();           // "Call Confirmation"				-> "Off"
			Talk_Around_Simplex.clear();         // "Talk Around(Simplex)"			-> "Off"
			Work_Alone.clear();                  // "Work Alone"						-> "Off"
			Custom_CTCSS.clear();                // "Custom CTCSS"					-> "251.1"
			_2TONE_Decode.clear();               // "2TONE Decode"					-> "0"
			Ranging.clear();                     // "Ranging"						-> "Off"
			Through_Mode.clear();                // "Through Mode"					-> "Off"
			APRS_RX.clear();                     // "APRS RX"						-> "Off"
			Analog_APRS_PTT_Mode.clear();        // "Analog APRS PTT Mode"			-> "Off"
			Digital_APRS_PTT_Mode.clear();       // "Digital APRS PTT Mode"			-> "Off"
			APRS_Report_Type.clear();            // "APRS Report Type"				-> "Off"
			Digital_APRS_Report_Channel.clear(); // "Digital APRS Report Channel"	-> "1"
			Correct_FrequencyHz.clear();         // "Correct Frequency[Hz]"			-> "0"
			SMS_Confirmation.clear();            // "SMS Confirmation"				-> "Off"
			Exclude_channel_from_roaming.clear();//' "Exclude channel from roaming"	-> "0"
			DMR_MODE.clear();                    // "DMR MODE"						-> "0"
			DataACK_Disable.clear();             // "DataACK Disable"				-> "0"
			R5toneBot.clear();                   // "R5toneBot"						-> "0"
			R5ToneEot.clear();                   // "R5ToneEot"						-> "0"
			Auto_Scan.clear();                   // "Auto Scan"						-> "0"
			Ana_Aprs_Mute.clear();               // "Ana Aprs Mute"					-> "0"
			Send_Talker_Alias.clear();           // "Send Talker Alias"				-> "0"
			AnaAprsTxPath.clear();               // "AnaAprsTxPath"					-> "0"
			ARC4.clear();                        // "ARC4"							-> "0"
			ex_emg_kind.clear();                 // "ex_emg_kind"					-> "0"
		}
	};

	bool readCSVfile(string fName, vector <cps>& records);
	bool writeCSVfile(string fName, vector <cps> records);

}


#endif	/* __cCPS_PGP2508GFK__ */

