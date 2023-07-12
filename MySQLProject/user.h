#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<mysql.h>
using namespace std;
#define DB_NAME  "contact"
#define DB_HOST  "127.0.0.1"
#define DB_PORT  3306
#define DB_USER  "root"
#define DB_USER_PASSWD  "mysql"

bool connect_db(MYSQL& mysql) {

    //1.初始化数据库句柄
    mysql_init(&mysql);

    //2.设置字符编码
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

    //3.连接数据库
    if (mysql_real_connect(&mysql, DB_HOST, DB_USER, DB_USER_PASSWD, DB_NAME, DB_PORT, NULL, 0) == NULL) {
        cout << "数据库连接出错， 错误原因: " << mysql_error(&mysql) << endl;
        return false;
    }

    return true;
}

typedef struct {
	char name[12];
	char phone[12];
	char email[18];
	char relation[8];
}contact;
class user {
public:
	char useName[12];
	char passWord[24];
	char phoneNum[12];
	user( char useName[12], char passWord[24], char phoneNum[12]);
	user( char passWord[24], char phoneNum[12]);
	~user();
	bool addContact(contact &c);
	bool deleteContact(contact &c);
	bool updateContact(contact &c);
	bool checkContact(contact &c);
    bool showContact();
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

//对表contact的操作，借鉴DB
bool user::addContact(contact &c) {
    MYSQL mysql;
    char sql[256];
    bool ret = false;

    //1.连接到数据库
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.根据用户名和密码获取用户信息(id, level_id)
    snprintf(sql, 256, "INSERT INTO contact VALUES ('%s','%s','%s','%s','%s')", c.name, c.phone, c.email,c.relation,this->phoneNum);
    ret = mysql_query(&mysql, sql); //成功返回0

    if (ret) {
        printf("数据库插入出错，%s 错误原因： %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.返回结果

    //关闭数据库
    mysql_close(&mysql);
	return true;
}
bool user::deleteContact(contact &c) {
    MYSQL mysql;
    MYSQL_RES* res;
    MYSQL_ROW row;
    char sql[256];
    bool ret;
    if (connect_db(mysql) == false) {
        return false;
    }
    snprintf(sql,256, "DELETE FROM contact WHERE name='%s' AND phone='%s' AND phoneNum='%s'", c.name, c.phone,this->phoneNum);
    ret = mysql_query(&mysql, sql);

    if (ret) {
        printf("数据库删除出错，%s 错误原因： %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }
    mysql_close(&mysql);
	return true;
}
bool user::updateContact(contact &c) {
    MYSQL mysql;
    char sql[256];
    bool ret = false;

    //1.连接到数据库
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.根据用户名和密码获取用户信息(id, level_id)
    snprintf(sql, 256, "UPDATE contact SET name='%s',email='%s',relation='%s' WHERE phone='%s' AND phoneNum='%s'", c.name, c.email, c.relation,c.phone,this->phoneNum);
    ret = mysql_query(&mysql, sql); //成功返回0

    if (ret) {
        printf("数据库修改出错，%s 错误原因： %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.返回结果

    //关闭数据库
    mysql_close(&mysql);
    return true;
}
bool user::checkContact(contact &c) {
    MYSQL mysql;
    MYSQL_RES* res;
    MYSQL_ROW row;
    char sql[256];
    bool ret = false;

    //1.连接到数据库
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.根据用户名和密码获取用户信息(id, level_id)
    snprintf(sql, 256, "SELECT * FROM contact WHERE name='%s' AND phoneNum='%s'", c.name,this->phoneNum);
    ret = mysql_query(&mysql, sql); //成功返回0

    if (ret) {
        printf("数据库查询出错，%s 错误原因： %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.返回结果
    res = mysql_store_result(&mysql);
    row = mysql_fetch_row(res);
    printf("姓名：%s    电话：%s   e-mail：%s   关系：%s\n", row[0], row[1], row[2], row[3]);
    system("pause");
    //4.返回结果
     //释放结果集
    mysql_free_result(res);
    //关闭数据库
    mysql_close(&mysql);
	return true;
}
bool user::showContact() {
    MYSQL mysql;
    MYSQL_RES* res; //查询结果集
    MYSQL_ROW row;  //记录结构体
    char sql[256];
    bool ret = false;
    int num;

    //1.连接到数据库
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.根据用户名和密码获取用户信息(id, level_id)
    snprintf(sql, 256, "select * from contact where phoneNum='%s'",this->phoneNum);
    ret = mysql_query(&mysql, sql); //成功返回0

    if (ret) {
        printf("数据库查询出错，%s 错误原因： %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.获取结果
    res = mysql_store_result(&mysql);
    num = mysql_num_fields(res);

    while ((row = mysql_fetch_row(res)) != NULL)
    {
        printf("姓名：%s    电话：%s   e-mail：%s   关系：%s\n", row[0], row[1], row[2], row[3]);
    }
    system("pause");
    //4.返回结果

    //释放结果集
    mysql_free_result(res);

    //关闭数据库
    mysql_close(&mysql);

    return true;
}

