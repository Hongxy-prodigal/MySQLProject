#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<mysql.h>
using namespace std;
typedef struct {
	char name[12];
	char phone[11];
	char email[18];
	char relation[4];
}contact;
class user {
public:
	char useName[12];
	char passWord[24];
	char phoneNum[11];
	user( char useName[12], char passWord[24], char phoneNum[11]);
	user( char passWord[24], char phoneNum[11]);
	~user();
	bool addContact(contact c);
	bool deleteContact(contact c);
	bool updateContact(contact c);
	bool checkContact(contact c);
};
user::user( char useName[12], char passWord[24], char phoneNum[11]) {
	strcpy_s(this->useName, useName);
	strcpy_s(this->passWord, passWord);
	strcpy_s(this->phoneNum, phoneNum);
}
user::~user() {
	cout << "对象已被销毁" << endl;
}
bool user::addContact(contact c) {

}
bool user::deleteContact(contact c) {

}
bool user::updateContact(contact c) {

}
bool user::checkContact(contact c) {

}

