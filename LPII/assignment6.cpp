#include<bits/stdc++.h>
using namespace std;

struct rule{
    vector<string> conditions;
    string conclusions;
    string action;
};

bool high_tech = false, low_tech = false;
bool high_soft = false, low_soft = false;
bool high_reliable = false, low_reliable = false;

bool ask(string question){
    char response;
    cout << question << "(y/n): ";
    cin >> response;
    return(response == 'y' || response == 'Y');
}

int main(){
    vector<rule> rules;
    
    rules = {
        { {"high_tech", "high_reliable", "high_soft"}, "EXECUTIVE MATERIAL (L5)", "Immediate promotion to Lead/Architect role." },
        { {"high_tech", "low_soft"}, "TECHNICAL SPECIALIST", "Focus on leadership and communication workshops." },
        { {"high_soft", "low_tech"}, "TEAM CATALYST", "Enroll in technical upskilling/bootcamps." },
        { {"low_reliable"}, "CRITICAL RISK", "Immediate performance review and PIP." },
        { {"high_reliable", "high_tech"}, "CORE SENIOR DEVELOPER", "Retain with high increment and technical autonomy." }
    };
    
    cout<< "====Expert System(Employee Performance analyzer===" << endl;
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    
    int t_score = 0;
    if (ask("1. Writes clean, optimized code?")) t_score++;
    if (ask("2. Successfully handles complex debugging?")) t_score++;
    if (ask("3. Mentors others on technical architecture?")) t_score++;
    if (ask("4. Stays updated with latest AI/Cloud trends?")) t_score++;
    
    int r_score = 0;
    if (ask("5. Consistently meets sprint deadlines?")) r_score++;
    if (ask("6. Requires minimal follow-up from managers?")) r_score++;
    if (ask("7. Follows documentation and coding standards?")) r_score++;
    if (ask("8. Maintains high punctuality and availability?")) r_score++;

    int s_score = 0;
    if (ask("9. Communicates effectively in meetings?")) s_score++;
    if (ask("10. Handles critical feedback professionally?")) s_score++;
    if (ask("11. Actively helps teammates during blockers?")) s_score++;
    if (ask("12. Demonstrates high emotional intelligence?")) s_score++;

    if (ask("13. Suggests process or tool improvements?")) {} 
    if (ask("14. Takes ownership of unassigned tasks?")) {}
    if (ask("15. Demonstrates a 'product-first' mindset?")) {}
    
    high_tech = (t_score >= 3);
    low_tech = (t_score <= 1);
    high_soft = (s_score >= 3);
    low_soft = (s_score <= 1);
    high_reliable = (r_score >= 3);
    low_reliable = (r_score <= 1);
    
    cout << "\n[Inference Engine]: Matching Working Memory against Knowledge Base...\n";
    
    string final_conclusion = "Standard Performer!";
    string final_action = "Continue regular growth and quarterly reviews.";
    
    for(auto rule : rules){
        bool all_conditions_met = true;
        for(auto cond : rule.conditions){
            if(cond == "high_tech" && !high_tech) all_conditions_met = false;
            if (cond == "low_tech" && !low_tech) all_conditions_met = false;
            if (cond == "high_reliable" && !high_reliable) all_conditions_met = false;
            if (cond == "low_reliable" && !low_reliable) all_conditions_met = false;
            if (cond == "high_soft" && !high_soft) all_conditions_met = false;
            if (cond == "low_soft" && !low_soft) all_conditions_met = false;
        }
        
        if(all_conditions_met){
            final_conclusion = rule.conclusions;
            final_action = rule.action;
        }
    }
    
    cout << "\n=================================================================\n";
    cout << " FINAL PERFORMANCE DIAGNOSIS: " << name << "\n";
    cout << "=================================================================\n";
    cout << "CONCLUSION : " << final_conclusion << "\n";
    cout << "ACTION     : " << final_action << "\n";
    cout << "=================================================================\n";
    
    return 0;
}