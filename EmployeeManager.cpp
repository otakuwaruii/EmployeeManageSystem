#include "EmployeeManager.h"
#include <fstream>
#include <iomanip>

EmployeeManager::EmployeeManager(string file) : head(nullptr), filename(file) {
    loadFromFile(); // 启动时自动读取文件加载到内存
}

EmployeeManager::~EmployeeManager() {
    saveToFile();   // 退出时自动保存
    clear();        // 释放内存
}

void EmployeeManager::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void EmployeeManager::loadFromFile() {
    ifstream inFile(filename);
    if (!inFile) return; // 文件不存在则直接返回

    string n, g, bd, wd, e, p, a, ph;
    // 按空格分隔读取，因此输入信息时建议不要包含空格（可用-或_代替）
    while (inFile >> n >> g >> bd >> wd >> e >> p >> a >> ph) {
        Employee emp(n, g, bd, wd, e, p, a, ph);
        insertSorted(emp); // 读入时自动按字典序构建链表
    }
    inFile.close();
}

void EmployeeManager::saveToFile() const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "无法保存文件!" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        outFile << current->data.getName() << " "
            << current->data.getGender() << " "
            << current->data.getBirthDate() << " "
            << current->data.getWorkDate() << " "
            << current->data.getEducation() << " "
            << current->data.getPosition() << " "
            << current->data.getAddress() << " "
            << current->data.getPhone() << "\n";
        current = current->next;
    }
    outFile.close();
}

// 插入：按姓名字典顺序
void EmployeeManager::insertSorted(const Employee& emp) {
    Node* newNode = new Node(emp);

    // 链表为空，或者新节点姓名小于头节点姓名
    if (head == nullptr || head->data.getName() >= emp.getName()) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        // 查找插入位置
        while (current->next != nullptr && current->next->data.getName() < emp.getName()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 删除
bool EmployeeManager::removeEmployee(string name) {
    if (head == nullptr) return false;

    if (head->data.getName() == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.getName() != name) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
    return false; // 未找到
}

// 查找
Node* EmployeeManager::searchEmployee(string name) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.getName() == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// 修改
bool EmployeeManager::modifyEmployee(string name) {
    Node* target = searchEmployee(name);
    if (target == nullptr) return false;

    cout << "\n找到职工：" << name << "，请输入新的信息（不含空格）：" << endl;
    string g, bd, wd, e, p, a, ph;
    cout << "性别: "; cin >> g;
    cout << "出生年月: "; cin >> bd;
    cout << "工作年月: "; cin >> wd;
    cout << "学历: "; cin >> e;
    cout << "职务: "; cin >> p;
    cout << "住址: "; cin >> a;
    cout << "电话: "; cin >> ph;

    target->data.setGender(g);
    target->data.setBirthDate(bd);
    target->data.setWorkDate(wd);
    target->data.setEducation(e);
    target->data.setPosition(p);
    target->data.setAddress(a);
    target->data.setPhone(ph);

    return true;
}

// 排序算法：冒泡排序（按工作年月），满足“按某种需要对职工排序”的要求
void EmployeeManager::sortByWorkDate() {
    if (head == nullptr || head->next == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            // 字符串直接比较即可（格式需统一为 YYYY-MM）
            if (ptr1->data.getWorkDate() > ptr1->next->data.getWorkDate()) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// 排序算法：冒泡排序（按姓名恢复字典序）
void EmployeeManager::sortByName() {
    if (head == nullptr || head->next == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data.getName() > ptr1->next->data.getName()) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void EmployeeManager::displayAll() const {
    if (head == nullptr) {
        cout << "当前没有职工记录！" << endl;
        return;
    }
    cout << string(100, '-') << endl;
    cout << left
        << setw(12) << "姓名"
        << setw(8) << "性别"
        << setw(12) << "出生年月"
        << setw(12) << "工作年月"
        << setw(10) << "学历"
        << setw(12) << "职务"
        << setw(20) << "住址"
        << setw(15) << "电话" << endl;
    cout << string(100, '-') << endl;

    Node* current = head;
    while (current != nullptr) {
        current->data.display();
        current = current->next;
    }
    cout << string(100, '-') << endl;
}