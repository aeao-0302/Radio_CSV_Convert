// Translators.cpp
// Converter

#include "Translators.h"

// CHIRP Generic CSV file -> CPS AnyTone Channel.csv file
bool translateChirp2CPS(chirp::chirp ch, cps::cps& cps)
{
	cps.No = ToString(ch.Location);
	cps.ChannelName = ch.ChannelName;

	cps.ReceiveFrequency = ToString(ch.Frequency);			// Receive frequency

	cps.TransmitFrequency = ToString(ch.Offset);
	if (ch.Duplex == "-") cps.TransmitFrequency = ToString(ch.Frequency - ch.Offset);
	if (ch.Duplex == "+") cps.TransmitFrequency = ToString(ch.Frequency + ch.Offset);
	if (ch.Duplex == "") cps.TransmitFrequency = ToString(ch.Frequency);

	if (ch.Mode == "DMR") cps.ChannelType = "D-Digital";						// Case to do
	if (ch.Mode == "FM" || ch.Mode == "NFM") cps.ChannelType = "A-Analog";		// 
	if (ch.Mode == "Auto") cps.ChannelType = "A+D TX A";		// "A-Analog", "D-Digital", "A+D TX A", "D+A TX D"
	if (ch.Power == "5.0W") cps.TransmitPower = "Mid";			// "Low", "Mid", "High", "Turbo"
	if (ch.Mode == "NFM") cps.BandWidth = "12.5K";				// "Band Width"	->  "25K" for FM or "12.5K" for NFM
	if (true) cps.CTCSS_DCS_Decode = "Off";						// "CTCSS/DCS Decode"		-> "Off", "CTCSS", "DCS"
	if (true) cps.CTCSS_DCS_Encode = "Off";						// "CTCSS/DCS Encode"		-> "Off", "CTCSS", "DCS"
	if (true) cps.Squelch_Mode = "Carrier";						// "Squelch Mode"			-> "Carrier", "CTCSS/DCS"

	if (ch.Tone == "Tone")	cps.CTCSS_DCS_Encode = ch.cToneFreq;	// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
	if (ch.Tone == "TSQL") {
		//cps.CTCSS_DCS_Decode = ch.cToneFreq;
		cps.CTCSS_DCS_Encode = ch.rToneFreq;						// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
		cps.Squelch_Mode = "CTCSS/DCS";
	}
	if (ch.Tone == "TSQL-R") cps.CTCSS_DCS_Decode = ch.cToneFreq;	// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
	if (ch.Tone == "DTCS") {
		//cps.CTCSS_DCS_Decode = "DCS";
		cps.CTCSS_DCS_Encode = ch.rToneFreq;						// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
		cps.Squelch_Mode = "CTCSS/DCS";
	}
	if (ch.Tone == "Cross")
	{
		if (ch.Tone == "Tone->")cps.CTCSS_DCS_Encode = ch.cToneFreq;
		if (ch.Tone == "Tone->Tone") {
			//cps.CTCSS_DCS_Decode = ch.cToneFreq;
			cps.CTCSS_DCS_Encode = ch.cToneFreq;							// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
		}
		if (ch.Tone == "->Tone") cps.CTCSS_DCS_Decode = ch.cToneFreq;
		if (ch.Tone == "Tone->DTCS") {
			//cps.CTCSS_DCS_Decode = ch.cToneFreq;
			cps.CTCSS_DCS_Encode = "DCS";							// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
		}
		if (ch.Tone == "DTCS->") cps.CTCSS_DCS_Decode = "DCS";
		if (ch.Tone == "DTCS->DTCSS") {
			//cps.CTCSS_DCS_Decode = "DCS";
			cps.CTCSS_DCS_Encode = ch.rToneFreq;;							// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
		}
		if (ch.Tone == "DTCS->Tone") {
			//cps.CTCSS_DCS_Decode = "DCS";
			cps.CTCSS_DCS_Encode = ch.cToneFreq;							// 'Tone', 'TSQL', 'TSQL-R', 'DTCS', 'DTCS-R', 'Cross'->
		}
		if (ch.Tone == "->DTCS") cps.CTCSS_DCS_Encode = "DCS";

		cps.Squelch_Mode = "CTCSS/DCS";
	}

	if (true) cps.Contact = "Contact 1";			// "Contact"						-> "Contact 1"
	if (true) cps.ContactCallType = "Group Call";	// "Contact Call Type"				-> "Group Call"
	if (true) cps.ContactTG_DMR_ID = "1";			// "Contact TG/DMR ID"				-> "1"
	if (true) cps.Radio_ID = "My radio";			// "Radio ID"						-> ""
	if (true) cps.BusyLockTXPermit = "Always";		// "Busy Lock/TX Permit"			-> "Always"
	if (true) cps.Optional_Signal = "Off";			// "Optional Signal"				-> "Off"
	if (true) cps.DTMF_ID = "1";					// "DTMF ID"						-> "1"
	if (true) cps._2Tone_ID = "1";					// "2Tone ID"						-> "1"
	if (true) cps._5Tone_ID = "1";					// "5Tone ID"						-> "1"
	if (true) cps.PTT_ID = "Off";					// "PTT ID"							-> "Off"
	if (true) cps.Color_Code = "1";					// "Color Code"						-> "1"
	if (true) cps.Slot = "1";						// "Slot"							-> "1"
	if (true) cps.Scan_List = "None";				// "Scan List"						-> "None"
	if (true) cps.Receive_Group_List = "None";		// "Receive Group List"				-> "None"
	if (true) cps.PTT_Prohibit = "Off";				// "PTT Prohibit"					-> "Off"
	if (true) cps.Reverse = "Off";					// "Reverse"						-> "Off"
	if (true) cps.Simplex_TDMA = "Off";				// "Simplex TDMA"					-> "Off"
	if (true) cps.Slot_Suit = "Off";				// "Slot Suit"						-> "Off"
	if (true) cps.AES_Digital_Encryption = "Normal Encryption";	// "AES Digital Encryption"			-> "Normal Encryption"
	if (true) cps.Digital_Encryption = "Off";		// "Digital Encryption"				-> "Off"
	if (true) cps.Call_Confirmation = "Off";		// "Call Confirmation"				-> "Off"
	if (true) cps.Talk_Around_Simplex = "Off";		// "Talk Around(Simplex)"			-> "Off"
	if (true) cps.Work_Alone = "Off";				// "Work Alone"						-> "Off"
	if (true) cps.Custom_CTCSS = "251.1";			// "Custom CTCSS"					-> "251.1"
	if (true) cps._2TONE_Decode = "0";				// "2TONE Decode"					-> "0"
	if (true) cps.Ranging = "Off";					// "Ranging"						-> "Off"
	if (true) cps.Through_Mode = "Off";				// "Through Mode"					-> "Off"
	if (true) cps.APRS_RX = "Off";					// "APRS RX"						-> "Off"
	if (true) cps.Analog_APRS_PTT_Mode = "Off";		// "Analog APRS PTT Mode"			-> "Off"
	if (true) cps.Digital_APRS_PTT_Mode = "Off";	// "Digital APRS PTT Mode"			-> "Off"
	if (true) cps.APRS_Report_Type = "Off";			// "APRS Report Type"				-> "Off"
	if (true) cps.Digital_APRS_Report_Channel = "1";// "Digital APRS Report Channel"	-> "1"
	if (true) cps.Correct_FrequencyHz = "0";		// "Correct Frequency[Hz]"			-> "0"
	if (true) cps.SMS_Confirmation = "Off";			// "SMS Confirmation"				-> "Off"
	if (true) cps.Exclude_channel_from_roaming = "0";	// "Exclude channel from roaming"	-> "0"
	if (true) cps.DMR_MODE = "0";					// "DMR MODE"						-> "0"
	if (true) cps.DataACK_Disable = "0";			// "DataACK Disable"				-> "0"
	if (true) cps.R5toneBot = "0";					// "R5toneBot"						-> "0"
	if (true) cps.R5ToneEot = "0";					// "R5ToneEot"						-> "0"
	if (true) cps.Auto_Scan = "0";					// "Auto Scan"						-> "0"
	if (true) cps.Ana_Aprs_Mute = "0";				// "Ana Aprs Mute"					-> "0"
	if (true) cps.Send_Talker_Alias = "0";			// "Send Talker Alias"				-> "0"
	if (true) cps.AnaAprsTxPath = "0";				// "AnaAprsTxPath"					-> "0"
	if (true) cps.ARC4 = "0";						// "ARC4"							-> "0"
	if (true) cps.ex_emg_kind = "0";				// "ex_emg_kind"					-> "0"

	return true;
}


