#pragma once
#include <string>
#include <iostream>

using namespace std;

class Employee {
private:
    string name;        // 姓名
    string gender;      // 性别
    string birthDate;   // 出生年月 (如: 1990-01)
    string workDate;    // 工作年月 (如: 2015-07)
    string education;   // 学历
    string position;    // 职务
    string address;     // 住址
    string phone;       // 电话

public:
    // 构造函数
    Employee();
    Employee(string n, string g, string bd, string wd, string e, string p, string a, string ph);

    // Getters
    string getName() const { return name; }
    string getGender() const { return gender; }
    string getBirthDate() const { return birthDate; }
    string getWorkDate() const { return workDate; }
    string getEducation() const { return education; }
    string getPosition() const { return position; }
    string getAddress() const { return address; }
    string getPhone() const { return phone; }

    // Setters
    void setName(string n) { name = n; }
    void setGender(string g) { gender = g; }
    void setBirthDate(string bd) { birthDate = bd; }
    void setWorkDate(string wd) { workDate = wd; }
    void setEducation(string e) { education = e; }
    void setPosition(string p) { position = p; }
    void setAddress(string a) { address = a; }
    void setPhone(string ph) { phone = ph; }

    // 打印职工信息
    void display() const;
};