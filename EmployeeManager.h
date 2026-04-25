#pragma once
#include "Employee.h"

// 链表节点定义
struct Node {
    Employee data;
    Node* next;
    Node(Employee emp) : data(emp), next(nullptr) {}
};

class EmployeeManager {
private:
    Node* head;         // 链表头指针
    string filename;    // 数据保存文件名

    // 释放链表内存
    void clear();

public:
    EmployeeManager(string file);
    ~EmployeeManager();

    // 文件操作
    void loadFromFile();
    void saveToFile() const;

    // 基本操作
    void insertSorted(const Employee& emp); // 1. 按姓名字典序插入
    bool removeEmployee(string name);       // 2. 删除职工
    Node* searchEmployee(string name) const;// 3. 查询职工
    bool modifyEmployee(string name);       // 4. 修改职工信息
    void sortByWorkDate();                  // 5. 排序：按工作年月排序
    void sortByName();                      // 5. 排序：重新按姓名排序
    void displayAll() const;                // 显示全部信息
};