#pragma once
#ifndef cType_H
#define cType_H
#include"lnkList.h"
#include"function.h"
class cType
{
public:
	cType() {};
	void push(int IDcode, char* Type);
	void get(char* Type, int* &IDcodeList);
	int  length(char* Type);     //Çó±í³¤

private:
	lnkList<int> DZ_1383;
	lnkList<int> KH_9123;
	lnkList<int> QC_1130;
	lnkList<int> JQ_4553;
	lnkList<int> XJ_439;
	lnkList<int> AQ_5417;
	lnkList<int> JLP_6812;
	lnkList<int> KB_4656;
	lnkList<int> DH_1917;
	lnkList<int> XY_3721;
	lnkList<int> FZ_5507;
	lnkList<int> ZZ_857;
	lnkList<int> GZ_3520;
	lnkList<int> ZN_8849;
	lnkList<int> QT_2475;
};
void cType::push(int IDcode, char* Type) {
	lnkList<char*> tempList;
	char_split(Type, tempList);
	int len = tempList.length();
	if (len)
		for (int i = 0; i < len; i++)
		{
			char *tempNode = new char[32];
			tempList.getValue(i, tempNode);
			int tempType = ELFhash(tempNode);
			switch (tempType)
			{
			case 1383: DZ_1383.append(IDcode);
				break;
			case 9123: KH_9123.append(IDcode);
				break;
			case 1130: QC_1130.append(IDcode);
				break;
			case 4553: JQ_4553.append(IDcode);
				break;
			case 439:  XJ_439.append(IDcode);
				break;
			case 5417: AQ_5417.append(IDcode);
				break;
			case 6812: JLP_6812.append(IDcode);
				break;
			case 4656: KB_4656.append(IDcode);
				break;
			case 1917: DH_1917.append(IDcode);
				break;
			case 3721: XY_3721.append(IDcode);
				break;
			case 5507: FZ_5507.append(IDcode);
				break;
			case 857: ZZ_857.append(IDcode);
				break;
			case 3520: GZ_3520.append(IDcode);
				break;
			case 8849: ZN_8849.append(IDcode);
				break;
			case 2475:
			default:	QT_2475.append(IDcode);
				break;
			}
			delete tempNode;
		}
}

void cType::get(char* Type, int* &IDcodeList) {
	int iType = ELFhash(Type);
	switch (iType)
	{
	case 1383: DZ_1383.travel(IDcodeList);
		break;
	case 9123: KH_9123.travel(IDcodeList);
		break;
	case 1130: QC_1130.travel(IDcodeList);
		break;
	case 4553: JQ_4553.travel(IDcodeList);
		break;
	case 439:  XJ_439.travel(IDcodeList);
		break;
	case 5417: AQ_5417.travel(IDcodeList);
		break;
	case 6812: JLP_6812.travel(IDcodeList);
		break;
	case 4656: KB_4656.travel(IDcodeList);
		break;
	case 1917: DH_1917.travel(IDcodeList);
		break;
	case 3721: XY_3721.travel(IDcodeList);
		break;
	case 5507: FZ_5507.travel(IDcodeList);
		break;
	case 857: ZZ_857.travel(IDcodeList);
		break;
	case 3520: GZ_3520.travel(IDcodeList);
		break;
	case 8849: ZN_8849.travel(IDcodeList);
		break;
	case 2475:
	default:	QT_2475.travel(IDcodeList);
		break;
	}
}

int cType::length(char* Type) {
	int iType = ELFhash(Type);
	switch (iType)
	{
	case 1383: return DZ_1383.length();
		break;
	case 9123: return KH_9123.length();
		break;
	case 1130: return QC_1130.length();
		break;
	case 4553: return JQ_4553.length();
		break;
	case 439:  return XJ_439.length();
		break;
	case 5417: return AQ_5417.length();
		break;
	case 6812: return JLP_6812.length();
		break;
	case 4656: return KB_4656.length();
		break;
	case 1917: return DH_1917.length();
		break;
	case 3721: return XY_3721.length();
		break;
	case 5507: return FZ_5507.length();
		break;
	case 857:  return ZZ_857.length();
		break;
	case 3520: return GZ_3520.length();
		break;
	case 8849: return ZN_8849.length();
		break;
	case 2475:
	default:	return QT_2475.length();
		break;
	}
}

#endif//cType_H
