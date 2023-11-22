#include<bits/stdc++.h>
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

pair<string,string> GetCIDR(string address, int n){
    string bin=address;
    if(address.size()!=32){
        bin=DecToBin(address);
    }
    string netID=bin.substr(0,n-1);
    string hostID=bin.substr(n,bin.size()-n);
    for(int i=0; i<32-n+1; i++){
        netID+='0';
    }
    for(int i=0; i<n; i++){
        hostID='0'+hostID;
    }
    return {BinToDec(netID),BinToDec(hostID)};
}

int main() {
    int choice;
    while (true) {
        cout << "\033[1;32mMenu:\n";
        cout << "\033[1;37m1. Get CIDR\033[0m\n";
        cout << "\033[1;31m2. Exit\033[0m\n";
        cout << "\033[5mEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string ipInput; int n;
                cout << "\033[1;32mEnter IP address (binary or dotted decimal): ";
                cin >> ipInput; 
                cout << "\033[1;32mEnter subnet mask size : ";
                cin >> n;
                if(n>32){
                    cout << "\033[0;36m" << "Invalid mask! Please enter again." << "\033[0m" << endl;
                    cout << endl;
                    cout << "\033[1;32;47m--------------------------------------------------------\033[0m" << endl;
                    cout << endl;
                    break;
                } 
                pair<string,string> outID=GetCIDR(ipInput,n);
                cout << "\033[0;36mIP netID: " << outID.first << "\033[0m" << endl;
                cout << "\033[0;36mIP hostID: " << outID.second << "\033[0m" << endl;
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
            }}}
    return 0;
}
