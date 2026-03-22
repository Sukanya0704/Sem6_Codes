#include<bits/stdc++.h>
using namespace std;

struct job{
    string id;
    int deadline;
    int profit;
};

bool compareJobs(job a, job b){
    return a.profit > b.profit;
}

int main(){
    cout<<"---Freelance Profit Optimizer---"<<endl;
    cout<<"Enter the number of available jobs ";
    int n;
    cin>>n;

    vector<job> jobs(n);
    for(int i=0; i<n; i++){
        cout<<"Job "<<i+1<<" Id, Deadline, Profit: ";
        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<string> schedule(n, "Empty");
    vector<bool> slot(n, false);
    int total_profit = 0;

    for(int i=0; i<n; i++){
        for(int j=min(n, jobs[i].deadline)-1; j>=0; j--){
            if(!slot[j]){
                slot[j] = true;
                schedule[j] = jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    cout<<endl<<"---Optimal Work Schedule---: ";
    for(const auto& s : schedule){
        if(s!="Empty"){
            cout<<"["<<s<<"]";
        }
    }

    cout<<endl;
    cout<<"Total Profit Earned :"<<total_profit<<endl;

    return 0;
}