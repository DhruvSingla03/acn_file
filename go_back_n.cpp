#include <bits/stdc++.h>
using namespace std;

int main() {
    int frames, window_size, tot_tr = 0;
    srand(time(NULL));
    cout<<"Enter the number of frames : "; cin>>frames;
    cout<<"Enter the Window Size : "; cin>>window_size;
    int i=1;
    while (i<=frames) {
        int x = 0;
        for (int j=i;j<i+window_size && j<=frames;j++) {
            cout<<"Sent Frame "<<j<<endl;
            tot_tr++;
        }
        for (int j=i;j<i+window_size && j<=frames;j++) {
            int flag=rand()%2;
            if (!flag) {
                cout<<"Acknowledgment for Frame "<<j<<endl;
                x++;
            } else {
                cout<<"Frame "<<j<<" Not Received"<<endl;
                cout<<"Retransmitting Window"<<endl;
                break;
            }
        }
        cout<<endl;
        i+=x;
    }
    cout<<"Total number of transmissions : "<<tot_tr<<endl;
    return 0;
}