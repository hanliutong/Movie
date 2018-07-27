#include<iostream>
#include"lnkList.h"
#include"function.h"
#include"cType.h"
#include"cYear.h"
#include"cNation.h"
#include"cClass.h"
using namespace std;
/*	*数据结构:
	*类或对象：
		Movie	单个电影的类
		YEAR	按年份统计的数据（对象）
		TYPE	按类型统计的数据（对象）
		NATION	按地区统计的数据（对象）
		LANGUAGE按语言统计的数据（对象）


	*散列表：MOVIE[10000]。长度为10000的存储Movie类指针的数组。
		搜索的实践复杂度为O(1)。因为负载因子很小，采用开地址法解决冲突
*/


//cType TYPE;
//cYear YEAR;
//cNation NATION;

cYear YEAR;;
cClass NATION;
cClass TYPE;
cClass DIRECTOR;

class cDate {//Movie类中存储日期的类
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
	Movie(char *name_C, char *name_E, char* date, float* DB, char *Award, char *Nation, char *Type, char *Director, char *Actor, char *Language, char *story, char *comment,int ID) {
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
		IDcode = ID;
		Date = cDate(date);
		DouBan = *DB;
		click = 0;
		YEAR.push(IDcode, getDate_yy());
		TYPE.push(IDcode, Type_char);
		NATION.push(IDcode, Nation_char);
		DIRECTOR.push(IDcode, Director_char);

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



// };
bool ShowMovie(char* Name_chn) {
	int temp_ID = ELFhash(Name_chn);
	if (MOVIE[temp_ID] == NULL)
		return false;
	
	while (strcmp(MOVIE[temp_ID]->GetName_CHN(),Name_chn) != 0) {
		temp_ID++;
		if (MOVIE[temp_ID] == NULL)
			return false;
	}
	
	Movie M1 = *MOVIE[temp_ID];
	printf("中文名： %s\nID:%i\n上映日期：%d\n豆瓣评分：%2.1f\n获奖：%s\n地区：%s\n类型：%s\n导演：%s\n主演：%s\n语言：%s\n剧情：%s\n影评：%s\n",
		M1.GetName_CHN(), M1.GetID(), M1.getDate(), M1.getDB(), M1.getAward(), M1.getNation(), M1.getType(), M1.getDirector(), M1.getActor(), M1.getLanguage(), M1.getStory(), M1.getComment());
	cout << "\n\n";
	return true;
};

bool ShowMovie(int ID) {
	if (MOVIE[ID] == NULL)
		return false;

	Movie M1 = *MOVIE[ID];
	printf("中文名： %s\nID:%i\n上映日期：%d\n豆瓣评分：%2.1f\n获奖：%s\n地区：%s\n类型：%s\n导演：%s\n主演：%s\n语言：%s\n剧情：%s\n影评：%s\n",
		M1.GetName_CHN(), M1.GetID(), M1.getDate(), M1.getDB(), M1.getAward(), M1.getNation(), M1.getType(), M1.getDirector(), M1.getActor(), M1.getLanguage(), M1.getStory(), M1.getComment());
	cout << "\n\n";
	return true;
};

bool ShowName(int ID) {
	if (MOVIE[ID] == NULL)
		return false;
	Movie M1 = *MOVIE[ID];
	printf("中文名： %s\nID:%i\n豆瓣评分：%2.1f\n",
		M1.GetName_CHN(), M1.GetID(),  M1.getDB());
	cout << "\n\n";
	return true;
};

bool GetData() {//从数据库读取数据
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
			int index = ELFhash(name_chn);
			//cout << "index = " << index << endl;
			while (MOVIE[index]) {
				
				index++;
			}
			MOVIE[index] = new  Movie(name_chn, name_eng, date, &DB, award, Nation, Type, Director, Actor, Language, story, comment, index);
		}
	}
	else return false;
	fclose(fp);
	return true;
}

bool GetMovieList(cClass Class,char* info) {
	int len = Class.length(info);
	cout << "命中结果 " << len << " 个" << endl;
	if (len)
	{
		int* TList = new int[len];
		Class.get(info, TList);
		for (int i = 0; i < len; i++)
		{
			ShowMovie(TList[i]);
		}
		delete TList;
		return true;

	}
	return false;
}

bool GetMovieList(int Year) {
	int len = YEAR.length(Year);
	cout << "命中结果 " << len << " 个" << endl;
	if (len)
	{
		int* TList = new int[len];
		YEAR.get(Year, TList);
		for (int i = 0; i < len; i++)
		{
			ShowMovie(TList[i]);
		}
		delete TList;
		return true;

	}
	return false;
}

		//bool TypeList(char* tpye) {
		//	int len = TYPE.length(tpye);
		//	cout << "命中结果 " << len << " 个" << endl;
		//	if (len)
		//	{
		//		int* TList = new int[len];
		//		TYPE.get(tpye, TList);
		//		for (int i = 0; i < len; i++)
		//		{
		//			ShowName(TList[i]);
		//		}
		//		delete TList;
		//		return true;
		//
		//	}
		//	return false;
		//}
		//
		//bool NationList(char* tpye) {
		//	int len = NATION.length(tpye);
		//	cout << "命中结果 " << len << " 个"<< endl;
		//	if (len)
		//	{
		//		int* TList = new int[len];
		//		NATION.get(tpye, TList);
		//		for (int i = 0; i < len; i++)
		//		{
		//			ShowName(TList[i]);
		//		}
		//		delete TList;
		//		return true;
		//
		//	}
		//	return false;
		//}

int main() {
	
	if (!GetData())
		return 1;
	
	char search[256] = { "头号玩家" };
	cout << "搜索：“"<< search << "”\n";
	ShowMovie(search); 

	int year = 2018;
	cout << "搜索："<< year <<"年的电影\n";
	GetMovieList(year);

	char type[32] = { "战争" };
	cout << "搜索：类型为“" << type << "”的电影\n";
	GetMovieList(TYPE, type);

	char nation[32] = { "中国" };
	cout << "搜索：地区为“" << nation << "”的电影\n";
	GetMovieList(NATION, nation);

	char director[32] = { "林超贤" };
	cout << "搜索：导演为“" << director << "”的电影\n";
	GetMovieList(DIRECTOR, director);

	system("pause");
	return 0;
}
