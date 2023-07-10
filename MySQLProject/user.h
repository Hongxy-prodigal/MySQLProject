#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<mysql.h>
using namespace std;
typedef struct {
	char name[12];
	char phone[12];
	char email[18];
	char relation[4];
}contact;
class user {
public:
	char useName[12];
	char passWord[24];
	char phoneNum[12];
	user( char useName[12], char passWord[24], char phoneNum[12]);
	user( char passWord[24], char phoneNum[12]);
	~user();
	bool addContact(contact c);
	bool deleteContact(contact c);
	bool updateContact(contact c);
	bool checkContact(contact c);
};
user::user( char useName[12], char passWord[24], char phoneNum[12]) {
	strcpy_s(this->useName, useName);
	strcpy_s(this->passWord, passWord);
	strcpy_s(this->phoneNum, phoneNum);
}
user::user( char passWord[24], char phoneNum[12]) {
	//strcpy_s(this->useName, " ");
	strcpy_s(this->passWord, passWord);
	cout << this->passWord << endl;
	strcpy_s(this->phoneNum, phoneNum);
	cout << this->phoneNum << endl;
}
user::~user() {
	cout << "对象已被销毁" << endl;
}
bool user::addContact(contact c) {
	//对表contact的操作，借鉴DB
	return true;
}
bool user::deleteContact(contact c) {
	return true;
}
bool user::updateContact(contact c) {
	return true;
}
bool user::checkContact(contact c) {
	return true;
}

