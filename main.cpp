#include<iostream>
#include"lnkList.h"
#include"function.h"
#include"cDouban.h"
#include"cYear.h"
#include"cClass.h"
#include"movie.h"
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

cYear YEAR;
cDouban DOUBAN;
cClass NATION;
cClass TYPE;
cClass DIRECTOR;
cClass AWARD;
cClass ACTOR;
cClass LANGUAGE;
Movie* MOVIE[10000];
int a = 10;


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
			ShowName(TList[i]);
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
			ShowName(TList[i]);
		}
		delete TList;
		return true;
	}
	return false;
}


int GetMovieList(int Douban_d, int Douban_u) {
	int count = 0;
	for (int i = Douban_u -1 ;i >= Douban_d; i--)
	{
		int len = DOUBAN.length(i);
		count += len;
		if (len)
		{
			int* TList = new int[len];
			DOUBAN.get(i, TList,len);
			for (int i = 0; i < len; i++)
			{
				ShowName(TList[i]);
			}
			delete TList;
			
		}
		
	}
	return count;
}


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

	char nation[32] = { "中国大陆" };
	cout << "搜索：地区为“" << nation << "”的电影\n";
	GetMovieList(NATION, nation);

	char director[32] = { "林超贤" };
	cout << "搜索：导演为“" << director << "”的电影\n";
	GetMovieList(DIRECTOR, director);
	
	char actor[32] = { "马克·里朗斯" };
	cout << "搜索：演员为“" << actor << "”的电影\n";
	GetMovieList(ACTOR, actor);

	int DB_d = 7;
	int DB_u = 10;
	cout << "搜索：DB在 " << DB_d << " (含)到 " << DB_u << " (不含)之间的电影\n";
	GetMovieList(DB_d, DB_u);
	system("pause");
	return 0;
}
