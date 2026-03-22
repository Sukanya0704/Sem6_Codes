#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& readings){
    int n = readings.size();
    int swaps = 0;

    for(int i=0;  i<n-1; i++){
        int min_index = i;
        for(int j=i+1; j<n; j++){
            if(readings[j] < readings[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            swap(readings[min_index], readings[i]);
            swaps++;
        }
    }

    cout<<"Optimized write operations (Total swaps): "<< swaps <<endl;
}

int main(){
    int n;
    cout << "---Hardware Sensor Sort---\nEnter number of sensor readings: ";
    cin >> n;
    vector<int> readings(n);
    cout << "Enter " << n << " readings: ";
    for(int i=0; i<n; i++) std::cin >> readings[i];

    selection_sort(readings);

    cout << "Optimized Sorted Data: ";
    for (int x : readings) std::cout << x << " ";
    return 0;
}