#include <iostream>
#include "EmployeeManager.h"

using namespace std;

void printMenu() {
    cout << "\n====== 简单职工管理系统 ======" << endl;
    cout << "1. 新增职工 (按姓名自动排序)" << endl;
    cout << "2. 删除职工" << endl;
    cout << "3. 查询职工" << endl;
    cout << "4. 修改职工信息" << endl;
    cout << "5. 按工作年月排序 (升序)" << endl;
    cout << "6. 恢复按姓名排序 (字典序)" << endl;
    cout << "7. 显示所有职工" << endl;
    cout << "0. 退出并保存" << endl;
    cout << "==============================" << endl;
    cout << "请输入您的选择: ";
}

int main() {
    // 实例化职工管理器，并指定数据存储文件
    EmployeeManager manager("employee_data.txt");
    int choice;

    while (true) {
        printMenu();
        if (!(cin >> choice)) { // 防止输入非法字符
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0) {
            cout << "数据已保存，感谢使用！" << endl;
            break;
        }

        string n, g, bd, wd, e, p, a, ph;
        switch (choice) {
        case 1:
            cout << "\n请输入新职工信息 (中间勿加空格，可用_代替):" << endl;
            cout << "姓名: "; cin >> n;
            cout << "性别: "; cin >> g;
            cout << "出生年月 (如1990-01): "; cin >> bd;
            cout << "工作年月 (如2015-07): "; cin >> wd;
            cout << "学历: "; cin >> e;
            cout << "职务: "; cin >> p;
            cout << "住址: "; cin >> a;
            cout << "电话: "; cin >> ph;
            manager.insertSorted(Employee(n, g, bd, wd, e, p, a, ph));
            cout << "新增成功！" << endl;
            break;

        case 2:
            cout << "请输入要删除的职工姓名: ";
            cin >> n;
            if (manager.removeEmployee(n)) {
                cout << "删除成功！" << endl;
            }
            else {
                cout << "未找到该职工！" << endl;
            }
            break;

        case 3:
            cout << "请输入要查询的职工姓名: ";
            cin >> n;
            {
                Node* result = manager.searchEmployee(n);
                if (result) {
                    cout << "\n查询结果：" << endl;
                    result->data.display();
                }
                else {
                    cout << "未查找到该职工！" << endl;
                }
            }
            break;

        case 4:
            cout << "请输入要修改的职工姓名: ";
            cin >> n;
            if (manager.modifyEmployee(n)) {
                cout << "修改成功！" << endl;
            }
            else {
                cout << "未找到该职工！" << endl;
            }
            break;

        case 5:
            manager.sortByWorkDate();
            cout << "按工作年月排序完成！" << endl;
            manager.displayAll();
            break;

        case 6:
            manager.sortByName();
            cout << "按姓名排序完成！" << endl;
            manager.displayAll();
            break;

        case 7:
            manager.displayAll();
            break;

        default:
            cout << "无效的选择，请重新输入！" << endl;
            break;
        }
    }

    return 0;
}