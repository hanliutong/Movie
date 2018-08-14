#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include"lnkList.h"
#include"function.h"
#include"cDouban.h"
#include"cYear.h"
#include"cClass.h"
#include"cDate.h"

extern cYear YEAR;
extern cDouban DOUBAN;
extern cClass NATION;
extern cClass TYPE;
extern cClass DIRECTOR;
extern cClass AWARD;
extern cClass ACTOR;
extern cClass LANGUAGE;


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
	Movie(char *name_C, char *name_E, char* date, float* DB, char *Award, char *Nation, char *Type, char *Director, char *Actor, char *Language, char *story, char *comment, int ID) {
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
		YEAR.push(IDcode, getDate_yy(),getDate());
		TYPE.push(IDcode, Type_char);
		NATION.push(IDcode, Nation_char);
		DIRECTOR.push(IDcode, Director_char);
		AWARD.push(IDcode, Award_char);
		ACTOR.push(IDcode, Actor_char);
		LANGUAGE.push(IDcode, Language_char);
		DOUBAN.push(IDcode, DouBan);

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

#endif//MOVIE_H