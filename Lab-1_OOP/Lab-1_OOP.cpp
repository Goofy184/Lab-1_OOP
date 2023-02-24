#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>
using namespace std;
class Student {

    string surname;
    int id;
    double rating;
public:
    Student()
    {
    }
    Student(string surname, int id, double rating) {
        this->surname = surname;
        this->id = id;
        this->rating = rating;
    }
    string get_surname() {
        return surname;
    }
    friend ostream& operator << (ostream& os, const Student& s) {
        os << "ID: " << s.id << endl
           << "rating: " << s.rating << endl
           << "surname: " << s.surname << endl;
        return os;
    }
    friend istream& operator >> (istream& is, Student& s) {
        getline(is, s.surname);
        string buffer;
        getline(is, buffer);
        s.id = stoi(buffer);
        buffer.clear();
        getline(is, buffer);
        s.rating = stod(buffer);
        return is;
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    stack<Student> students;
    Student buffer;
    for (int i = 0; i < 2; i++) {
        cin >> buffer;
        students.push(buffer);
    }
    string surname_to_remove = "Ткаченко";
    while (!students.empty() ) {
        if (students.top().get_surname() == surname_to_remove)
        {
            cout  << students.top() << endl;
            break;
        }
        students.pop();
    }
     return 0;
}