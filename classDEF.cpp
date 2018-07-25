#include<iostream>
#include"lnkList.h"
#include<vector>
using namespace std;

int ELFhash(const char *key)
{
	unsigned long h = 0;
	unsigned long g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % 10000;
}

class cDate {
public:
	int yy;
	int mm;
	int dd;
	cDate() {
		yy = 0;
		mm = 0;
		dd = 0;
	}
	cDate(char* sDate) {

		int index = 0;
		char* syy = new char;
		char* smm = new char;
		char* sdd = new char;
		while (sDate[index] != '/') {
			syy[index] = sDate[index];
			index++;
		}
		yy = atoi(syy);
		delete syy;
		index++;
		while (sDate[index] != '/') {
			smm[index - 5] = sDate[index];
			index++;
		}
		mm = atoi(smm);
		delete smm;
		index++;
		int count = 0;
		while (sDate[index]) {
			sdd[count++] = sDate[index];
			index++;
		}
		dd = atoi(sdd);
		delete sdd;
	}
};

void f_Award(char* Award, lnkList<char*> &AwardList) {

	int index = 0;
	int count = 0;

	while (Award[index]) {
		char* temp = new char;
		while (Award[index] != '/' && Award[index] != '\0') {

			temp[count++] = Award[index];
			index++;
		}
		temp[index] = '\0';
		index++;
		count = 0;
		AwardList.append(temp);
	}
}
class cNation
{
private:
	lnkList<int> China;
	lnkList<int> America;
	lnkList<int> Europe;
	lnkList<int> TW_HK_MC;
	lnkList<int> JP_SK;
public:
	cNation();
	~cNation();

};
class Movie {
private:
	char name_CHN[256];
	char name_ENG[256];
	int IDcode;
	cDate Date;
	float DouBan;
	char Award_char[256];
	char Nation_char[256];
	char Type_char[256];
	char Director_char[256];
	char Actor_char[256];
	char Language_char[256];
	char Story[1024];
	char Comment[1024];

	int click;


	//lnkList<char*> AwardList;
	//lnkList<char*> NationList;

public:
	Movie() {
		IDcode = 0;
	}
	Movie(char *name_C, char *name_E, char* date, float* DB, char *Award, char *Nation, char *Type, char *Director, char *Actor, char *Language, char *story, char *comment) {
		//*name_CHN = *name_C;
		strcpy(name_CHN, name_C);
		strcpy(name_ENG, name_E);
		strcpy(Award_char, Award);
		strcpy(Nation_char, Nation);
		strcpy(Type_char, Type);
		strcpy(Director_char, Director);
		strcpy(Actor_char, Actor);
		strcpy(Language_char, Language);
		strcpy(Story, story);
		strcpy(Comment, comment);
		IDcode = ELFhash(name_C);
		Date = cDate(date);
		DouBan = *DB;
		click = 0;


	}
	char* GetName_CHN() {
		return name_CHN;
	}

	int GetID() {
		return IDcode;
	}
	int getDate_yy() {
		return Date.yy;
	}

	int getDate_mm() {
		return Date.mm;
	}

	int getDate_dd() {
		return Date.dd;
	}
	int getDate() {
		return Date.yy * 10000 + Date.mm * 100 + Date.dd;
	}
	float getDB() {
		return DouBan;
	}
	char* getAward() {
		return Award_char;
	}
	char* getNation() {
		return Nation_char;
	}
	char* getType() {
		return Type_char;
	}
	char* getDirector() {
		return Director_char;
	}
	char* getActor() {
		return Actor_char;
	}
	char* getLanguage() {
		return Language_char;
	}
	char* getStory() {
		return Story;
	}
	char* getComment() {
		return Comment;
	}
	int getclick() {
		return click;
	}
};
Movie* MOVIE[10000];
// class Type{
// private:
// 	lnkList<int> DZ_1383;
// 	lnkList<int> KH_9123;
// 	lnkList<int> QC_1130;
// 	lnkList<int> JQ_4553;
// 	lnkList<int> XJ_439;
// 	lnkList<int> AQ_5417;
// 	lnkList<int> JLP_6812;
// 	lnkList<int> KB_4656;
// 	lnkList<int> DH_1917;
// 	lnkList<int> XY_3721;
// 	lnkList<int> FZ_5507;
// 	lnkList<int> ZZ_857;
// 	lnkList<int> GZ_3520;
// 	lnkList<int> ZN_8849;
// 	lnkList<int> QT_2475;
// public:
// 	Type();
// 	push(char* Type, int IDcode){
// 		switch(ELFhash(Type)){
// 			case 1383
// 		}
// 	}


// };
bool ShowMovie(char* Name_chn) {
	int temp_ID = ELFhash(Name_chn);
	if (MOVIE[temp_ID] == NULL)
		return false;
	else
	{
		Movie M1 = *MOVIE[temp_ID];
		printf("中文名： %s\nID:%i\n上映日期：%d\n豆瓣评分：%2.1f\n获奖：%s\n地区：%s\n类型：%s\n导演：%s\n主演：%s\n语言：%s\n剧情：%s\n影评：%s\n",
			M1.GetName_CHN(), M1.GetID(), M1.getDate(), M1.getDB(), M1.getAward(), M1.getNation(), M1.getType(), M1.getDirector(), M1.getActor(), M1.getLanguage(), M1.getStory(), M1.getComment());
		cout << "\n\n";
		return true;
	}
	
};
int main() {
	
	char name_chn[256];
	char name_eng[256];
	char date[256];
	float DB;
	char award[256];
	char Nation[256];
	char Type[256];
	char Director[256];
	char Actor[256];
	char Language[256];
	char story[1024];
	char comment[1024];

	FILE* fp = fopen("database.csv", "r"); //打开文件
	float flag = 0;
	if (fp) {
		while (flag = fscanf(fp, "%[^,],%[^,],%[^,],%f,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
			name_chn, name_eng, date, &DB, award, Nation, Type, Director, Actor, Language, story, comment) != -1) {
			MOVIE[ELFhash(name_chn)] = new  Movie(name_chn, name_eng, date, &DB, award, Nation, Type, Director, Actor, Language, story, comment);
		}
	}
	else return 1;
	fclose(fp);
	char search[256] = { "头号玩家" };
	ShowMovie(search); 
	strcpy(search ,  "红海行动" );
	ShowMovie(search);
	
	system("pause");
	return 0;
}
