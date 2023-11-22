#include <bits/stdc++.h>
using namespace std;

string DecToBin(string s){
    s+='.';
    string ans="", temp="";
    for(int i=0; i<s.size(); i++){
        if(s[i] != '.') temp+=s[i];
        else {
            if(stoi(temp) > 255){
                return "Invalid";
            }
            ans+=bitset<8> (stoi(temp)).to_string();
            temp="";
        }
    }
    return ans;
}

string getClassification(string s) {
    string ipClass = "";
    if(s.size()<32){
        s=DecToBin(s);
    }
    for (int i = 0; i < 32; i++) {
        if (!(s[i]== '0' || s[i] == '1')) {
            return "Invalid";
        }
    }

    if (s[0] == 0) {
        ipClass += "Class A";
    } else if (s[0] == '1' && s[1] == '0') {
        ipClass += "Class B";
    } else if (s[0] == '1' && s[1] == '1' && s[2] == '0') {
        ipClass += "Class C";
    } else if (s[0] == '1' && s[1] == '1' && s[2] == '1' && s[3] == '0') {
        ipClass += "Class D";
    } else {
        ipClass += "Class E";
    }
    return ipClass;
}

int main() {
    int choice;
    while (true) {
        cout << "\033[1;32mMenu:\n";
        cout << "\033[1;37m1. Get IP Classification\033[0m\n";
        cout << "\033[1;31m2. Exit\033[0m\n";
        cout << "\033[5mEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string ipInput;
                cout << "\033[1;32mEnter IP address (binary or dotted decimal): ";
                cin >> ipInput;
                cout << "\033[0;36mIP Classification: " << getClassification(ipInput) << "\033[0m" << endl;
                cout << endl;
                cout << "\033[1;32;47m--------------------------------------------------------\033[0m" << endl;
                cout << endl;
                break;
            }
            case 2: {
                cout << "\033[1;31mExiting the program.\n";
                cout << endl;
                cout << "\033[1;32;47m--------------------------------------------------------\033[0m" << endl;
                cout << endl;
                return 0;
            }
            default: {
                cout << "\033[1;31mInvalid choice. Please select a valid option.\033[0m" << endl;
                break;
            }
        }
    }
    return 0;
}
