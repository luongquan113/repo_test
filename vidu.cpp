#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum employee_t{
    INTERN = 2,
    FRESHER = 1,
    EXPERIENCE = 0,
};

class Certificated{
private:
    string cer_id;
    string cer_name;
    string cer_rank;
    string cer_date;
public:
    Certificated() {}
    Certificated(string cer_id, string cer_name, string cer_rank, string cer_date) : 
        cer_id(cer_id), cer_name(cer_name), cer_rank(cer_rank), cer_date(cer_date) { }
    void add(string id, string name, string rank, string date){
        cer_id = id;
        cer_name = name;
        cer_rank = rank;
        cer_date = date;
    }
    void nhap(){
        cout << "ID: ";
        cin >> cer_id;
        cout << "Name: ";
        cin >> cer_name;
        cout << "Rank: ";
        cin >> cer_rank;
        cout << "Date: ";
        cin >> cer_date;
    }
    void show(){
        cout << "Certificated ID: " << cer_id << endl;
        cout << "Name: " << cer_name << endl;
        cout << "Rank: " << cer_rank << endl;
        cout << "Date: " << cer_date << endl;
    }
};

class Employee2{
private:
    int id;
    string fullname;
    string birthday;
    string phone;
    string email;
    employee_t emp_type;
    vector<Certificated> v_certificates;
    static int count;
public:
    Employee2() {
        count += 1;
    }
    Employee2(int id, string fullname, string birthday, string phone, string email, employee_t emp_type, vector<Certificated> v_certificates) :
        id(id), fullname(fullname), birthday(birthday), phone(phone), email(email), emp_type(emp_type), v_certificates(v_certificates) {
        count += 1;
    }
    virtual ~Employee2() {}
    virtual void nhap_info(){
        cout << "Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "FullName: ";
        getline(cin, fullname);
        cout << "Birthday: ";
        cin >> birthday;
        cout << "Phone: ";
        cin >> phone;
        cout << "Email: ";
        cin >> email;
        int temp;
        /*do{
            cout << "Employee type (0 experience, 1 fresher, 2 intern): ";
            cin >> temp;
            if ((temp > 2) || (temp < 0)){
                cout << "Wrong...\n";
            }
        }while((temp > 2) || (temp < 0));
        emp_type = (employee_t)temp;*/
        cout << "Number of certificates: ";
        cin >> temp;
        cin.ignore();
        if(temp > 0){
            for (int i = 0; i < temp; i++){
                Certificated c;
                cout << "Enter information for the certificate " << i+1 << "st: ";
                c.nhap();
                v_certificates.push_back(c);
            }
        }
    }
    size_t getNumberCertificates(){
        return v_certificates.size();
    }
    int getID(){
        return id;
    }
    void setEmployeeType(employee_t type){
        this->emp_type = type;
    }
    employee_t getEmployeeType(){
        return emp_type;
    }
    static int getCount(){
        return count;
    }
    virtual void showinfo(){
        cout << "ID: " << id << endl;
        cout << "Fullname: " << fullname << endl;
        cout << "Birthday: " << birthday << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Employee type: ";
        switch (emp_type){
            case EXPERIENCE : cout <<  "experience" << endl;
                break;
            case FRESHER : cout <<  "fresher" << endl;
                break;
            case INTERN : cout <<  "intern" << endl;
                break;
        }
        cout << "Certificates: " << v_certificates.size() << endl;
        for (int i = 0; i < v_certificates.size(); i++){
            v_certificates[i].show();
        }
    } 

};
int Employee2::count = 0;

class Experience : public Employee2{
private:
    size_t exp_year;
    string pro_skill;
public:
    Experience() : Employee2() { 
        setEmployeeType(EXPERIENCE);
    }
    Experience(int id, string fullname, string birthday, string phone, string email, vector<Certificated> v_certificates, size_t exp_year, string pro_skill) :
        Employee2(id, fullname, birthday, phone, email, EXPERIENCE, v_certificates), exp_year(exp_year), pro_skill(pro_skill) { }
    ~Experience() { cout << "experience ";}
    void showme(){
        cout << "ExpInYear: " << exp_year << endl;
        cout << "ProSkill: " << pro_skill << endl;
    }
    void nhap_info(){
        Employee2::nhap_info();
        cout << "Exp in years: ";
        cin >> exp_year;
        cin.ignore();
        cout << "Professional skill: ";
        getline(cin, pro_skill);
    }
    void showinfo(){
        cout << "Experience employee" << endl;
        Employee2::showinfo();
        showme();
    }
};
class Fresher : public Employee2{
private:
    string graduation_date;
    string graduation_rank;
    string education_name;
public:
    Fresher() : Employee2() {
        setEmployeeType(FRESHER);
    }
    Fresher(int id, string fullname, string birthday, string phone, string email, vector<Certificated> v_certificates, string graduation_date, string graduation_rank, string education_name) :
        Employee2(id, fullname, birthday, phone, email, FRESHER, v_certificates), graduation_date(graduation_date), graduation_rank(graduation_rank), education_name(education_name) { }
    ~Fresher() { cout << "de_fresher ";}
    void showme(){
        cout << "Graduation date: " << graduation_date << endl;
        cout << "Graduation rank: " << graduation_rank << endl;
        cout << "Education name: " << education_name << endl;
    }
    void nhap_info(){
        Employee2::nhap_info();
        cout << "graduation_date: ";
        cin >> graduation_date;
        cout << "graduation_rank: ";
        cin >> graduation_rank;
        cout << "education_name: ";
        cin >> education_name;
    }
    void showinfo(){
        cout << "Fresher employee" << endl;
        Employee2::showinfo();
        showme();
    }
};
class Intern : public Employee2{
private:
    string majors;
    string semester;
    string university_name;
public:
    Intern() {
        setEmployeeType(INTERN);
    }
    Intern(int id, string fullname, string birthday, string phone, string email, vector<Certificated> v_certificates, string majors, string semester, string university_name) :
        Employee2(id, fullname, birthday, phone, email, INTERN, v_certificates), majors(majors), semester(semester), university_name(university_name) { }
    ~Intern() { cout << "de_intern ";}
    void nhap_info(){
        Employee2::nhap_info();
        cout << "majors: ";
        cin >> majors;
        cout << "semester: ";
        cin >> semester;
        cout << "university_name: ";
        cin >> university_name;
    }
    void showme(){
        cout << "Graduation date: " << majors << endl;
        cout << "Graduation rank: " << semester << endl;
        cout << "Education name: " << university_name << endl;
    }
    void showinfo(){
        cout << "Intern employee" << endl;
        Employee2::showinfo();
        showme();
    }
};

class EmployeeManager {
private:
    vector<Employee2*> listnv;
public:
    EmployeeManager() { }
    ~EmployeeManager() {
        for (int i = 0; i < listnv.size(); i++){
            delete listnv[i];
        }
        listnv.clear();
    }
    void add_nv(Employee2 * nv){
        if (nv->getNumberCertificates() >= 1){
            listnv.push_back(nv);
            cout << "Added!\n";
        }
        else{
            cout << "This employee doesn't have enough certifications to join the company!" << endl;
        }
    }
    void add_nv(){
        Employee2 * nv = NULL;
        int temp;
        do{
            cout << "Employee type (0 experience, 1 fresher, 2 intern): ";
            cin >> temp;
            switch (temp)
            {
            case 0:
                nv = new Experience;
                break;
            case 1:
                nv = new Fresher;
                break;
            case 2:
                nv = new Intern;
                break;
            default:
                cout << "Wrong...\n";
                break;
            }
        }while((temp > 2) || (temp < 0));
        nv->nhap_info();
        add_nv(nv);
    }
    
    void delete_nv(int id){
        bool find = false;
        for (int i = 0; i < listnv.size(); i++){
            if (listnv[i]->getID() == id){
                delete listnv[i];
                listnv.erase(listnv.begin() + i);
                cout << "Employee with ID " << id << " has been removed." << endl;
                find = true;
                break;
            }
        }
        if (find == false){
            cout << "Not found this id" << endl;
        }
    }
    void show_nv(int id){
        bool find = false;
        for (int i = 0; i < listnv.size(); i++){
            if (listnv[i]->getID() == id){
                listnv[i]->showinfo();
                find = true;
                break;
            }
        }
        if (find == false){
            cout << "Not found this id" << endl;
        }
    }
    void show_all(){
        cout << "All employees:\n";
        for (int i = 0; i < listnv.size(); i++){
            listnv[i]->showinfo();
            cout << "--------------------\n";
        }
    }
    size_t getSize(){
        return listnv.size();
    }
    vector<Employee2*> find_nv(employee_t emp){
        vector<Employee2*> v;
        for(int i = 0; i <listnv.size(); i++){
            if (listnv[i]->getEmployeeType() == emp){
                v.push_back(listnv[i]);
            }
        }
        return v;
    }
};

enum menuchoice_t{
    choice_add1   = 1,
    choice_add2   = 2,
    choice_add3   = 3,
    choice_find   = 6,
    choice_show   = 4,
    choice_delete = 5,
    choice_size   = 9,
    choice_exit   = 0,
};

int main()
{
    EmployeeManager congty;
    int x;
    menuchoice_t choice;
    vector<Certificated> cers;
    Employee2 * temp = NULL;
    do{
        system("cls");
        cout << "1. Add fresher\n2. Add experience\n3. Add intern\n4. Print list\n5. Delete\n6. Find\n9. Number of Employees\n0. exit\nChoice: ";
        cin >> x;
        cin.ignore();
        choice = (menuchoice_t)x;
        switch (choice){
            case choice_add1:  
                temp = new Fresher(1955, "Nguyen Quan", "1/1/2000", "012345", "quan@gmail.com", cers, "1/1/2023", "Good", "Haui");
                congty.add_nv(temp);
                cout << "Added!\n";
                break;
            case choice_add2:
                congty.add_nv();
                cout << "Added!\n";
                break;
            case choice_add3:
                temp = new Employee2;
                temp->nhap_info();
                //temp = new Intern(1934, "Le Quan", "10/1/2001", "0123245", "quan89@gmail.com", cers, "Electronics", "HK5", "Haui");
                congty.add_nv(temp);
                cout << "Added!\n";
                break;
            case choice_show:
                congty.show_all();
                break;
            case choice_size:
                cout << "Total number of employees: " << congty.getSize() << endl;
                break;
            case choice_exit:
                cout << "Exit....\n";
                break;
            default:
                cout << "Wrong choice...\n";
                break;
        }
        system("pause");
    }while(choice != choice_exit);
    return 0;
}
