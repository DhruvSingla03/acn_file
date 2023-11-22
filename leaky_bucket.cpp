#include <bits/stdc++.h>
using namespace std;

int main() {
    int storage=0, no_of_queries=10;
    int bucket_size=15, input_pkt_size=4, output_pkt_size=2;
    for (int i=0;i<no_of_queries;i++) {
        int size_left=bucket_size-storage;
        if (input_pkt_size<=size_left) {
            storage+=input_pkt_size;
        } else {
            cout<<"Packet loss = "<<input_pkt_size<<endl;
        }
        cout<<"Buffer size="<<storage<<" out of bucket size="<< bucket_size<<endl;
        storage-=output_pkt_size;
    }
    return 0;
}