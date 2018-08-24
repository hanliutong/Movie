#include<iostream>
#include"lnkList.h"
#include"function.h"
#include"cDouban.h"
#include"cYear.h"
#include"cClass.h"
#include"movie.h"
using namespace std;
/*	*���ݽṹ:
	*������
		Movie	������Ӱ����
		YEAR	�����ͳ�Ƶ����ݣ�����
		TYPE	������ͳ�Ƶ����ݣ�����
		NATION	������ͳ�Ƶ����ݣ�����
		LANGUAGE������ͳ�Ƶ����ݣ�����


	*ɢ�б�MOVIE[10000]������Ϊ10000�Ĵ洢Movie��ָ������顣
		������ʵ�����Ӷ�ΪO(1)����Ϊ�������Ӻ�С�����ÿ���ַ�������ͻ
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
	printf("�������� %s\nID:%i\n��ӳ���ڣ�%d\n�������֣�%2.1f\n�񽱣�%s\n������%s\n���ͣ�%s\n���ݣ�%s\n���ݣ�%s\n���ԣ�%s\n���飺%s\nӰ����%s\n",
		M1.GetName_CHN(), M1.GetID(), M1.getDate(), M1.getDB(), M1.getAward(), M1.getNation(), M1.getType(), M1.getDirector(), M1.getActor(), M1.getLanguage(), M1.getStory(), M1.getComment());
	cout << "\n\n";
	return true;
};

bool ShowMovie(int ID) {
	if (MOVIE[ID] == NULL)
		return false;

	Movie M1 = *MOVIE[ID];
	printf("�������� %s\nID:%i\n��ӳ���ڣ�%d\n�������֣�%2.1f\n�񽱣�%s\n������%s\n���ͣ�%s\n���ݣ�%s\n���ݣ�%s\n���ԣ�%s\n���飺%s\nӰ����%s\n",
		M1.GetName_CHN(), M1.GetID(), M1.getDate(), M1.getDB(), M1.getAward(), M1.getNation(), M1.getType(), M1.getDirector(), M1.getActor(), M1.getLanguage(), M1.getStory(), M1.getComment());
	cout << "\n\n";
	return true;
};

bool ShowName(int ID) {
	if (MOVIE[ID] == NULL)
		return false;
	Movie M1 = *MOVIE[ID];
	printf("�������� %s\nID:%i\n�������֣�%2.1f\n",
		M1.GetName_CHN(), M1.GetID(),  M1.getDB());
	cout << "\n\n";
	return true;
};

bool GetData() {//�����ݿ��ȡ����
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

	FILE* fp = fopen("database.csv", "r"); //���ļ�
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
	cout << "���н�� " << len << " ��" << endl;
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
	cout << "���н�� " << len << " ��" << endl;
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
	
	char search[256] = { "ͷ�����" };
	cout << "��������"<< search << "��\n";
	ShowMovie(search); 

	int year = 2018;
	cout << "������"<< year <<"��ĵ�Ӱ\n";
	GetMovieList(year);

	char type[32] = { "ս��" };
	cout << "����������Ϊ��" << type << "���ĵ�Ӱ\n";
	GetMovieList(TYPE, type);

	char nation[32] = { "�й���½" };
	cout << "����������Ϊ��" << nation << "���ĵ�Ӱ\n";
	GetMovieList(NATION, nation);

	char director[32] = { "�ֳ���" };
	cout << "����������Ϊ��" << director << "���ĵ�Ӱ\n";
	GetMovieList(DIRECTOR, director);
	
	char actor[32] = { "��ˡ�����˹" };
	cout << "��������ԱΪ��" << actor << "���ĵ�Ӱ\n";
	GetMovieList(ACTOR, actor);

	int DB_d = 7;
	int DB_u = 10;
	cout << "������DB�� " << DB_d << " (��)�� " << DB_u << " (����)֮��ĵ�Ӱ\n";
	GetMovieList(DB_d, DB_u);
	system("pause");
	return 0;
}
