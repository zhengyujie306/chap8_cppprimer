#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <student_information.h>
using namespace std;

ostream&
operator << (ostream& os, const student_information& x)
{
    os << x.getid() << '\t'<< x.getname() << '\t';
    os << x.getage() << '\t' << x.getsex() << endl;
    return os;
}
fstream&
operator << (fstream& os, const student_information& x)
{
    os << x.getid() << '\t'<< x.getname() << '\t';
    os << x.getage() << '\t' << x.getsex() << endl;
    return os;
}

int main() {
    ifstream input;
    ofstream output;
    string ifile = "input.txt";
    string ofile = "output.txt";
    input.open(ifile);
    if(!(input)) {
        cerr << "open input file failed " << endl;
        return 0;
    }
    output.open(ofile);
    if(!(output)) {
        cerr << "open output file failed " << endl;
        return 0;
    }
    struct PersonInfo {
        string name;
        vector<string> phones;
    };

    student_information si("a", "a", 1, 2);
    cout << si;
    output << si;

    string line, word;
    vector<PersonInfo> people;
    while(getline(input, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        output << info.name << " ";
        while(record >> word) {
            info.phones.push_back(word);
            output << word << " ";
        }
        output << endl;

        people.push_back(info);
    }

    input.close();
    output.close();
    return 0;
}
