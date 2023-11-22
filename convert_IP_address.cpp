#include <bits/stdc++.h>
using namespace std;      

string BinToDec(string s){
    if(s.size()!=32) return "Invalid";
    for(int i=0; i<s.size(); i++){
        if (!(s[i]== '0' || s[i] == '1')) {
            return "Invalid";
        }
    }
    string ans="";
    for(int i=0; i<s.size(); i+=8){
        string temp=s.substr(i,8);
        int num=stoi(temp,0,2);
        ans+=to_string(num)+'.';
    }
    ans.pop_back();
    return ans;
}

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
    if(ans.size()>32) return "Invalid";
    return ans;
}

int main() {
    int choice;
    while (true) {
        cout << "\033[1;32mMenu:\n";
        cout << "\033[1;37m1. Binary to Dotted Decimal\033[0m\n";
        cout << "\033[1;37m2. Dotted Decimal to Binary\033[0m\n";
        cout << "\033[1;31m3. Exit\033[0m\n";
        cout << "\033[0mEnter your choice: \033[0m";
        cin >> choice;
        switch (choice) {
            case 1: {
                string binaryInput;
                cout << "\033[1;32mEnter binary IP address: ";
                cin >> binaryInput;
                cout << "\033[0;36mDotted Decimal IP address: " << BinToDec(binaryInput) << "\033[0m" << endl;
                cout << endl;
                cout << "\033[1;32;47m--------------------------------------------------------\033[0m" << endl;
                cout << endl;
                break;
            }
            case 2: {
                string dottedDecimalInput;
                cout << "\033[1;32mEnter Dotted Decimal IP address: ";
                cin >> dottedDecimalInput;
                cout << "\033[0;36mBinary IP address: " << DecToBin(dottedDecimalInput) << "\033[0m" << endl;
                cout << endl;
                cout << "\033[1;32;47m--------------------------------------------------------\033[0m" << endl;
                cout << endl;
                break;
            }
            case 3: {
                cout << "\033[1;31mExiting the program.\n";
                cout << endl;
                cout << "\033[1;32;47m--------------------------------------------------------\033[0m" << endl;
                cout << endl;
                return 0;
            }
            default: {
                cout << "\033[1;31mInvalid choice. Please select a valid option.\033[0m" << endl;
                break;
            }}}
    return 0;
}