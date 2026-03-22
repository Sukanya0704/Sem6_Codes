#include<bits/stdc++.h>
using namespace std;

struct State{
    vector<int> board;
    int g;
    int h;
    int f;
    int blank_idx;

    vector<vector<int>> history;

    bool operator>(const State& other) const{
        return f > other.f;
    }
};

int calculateHeuristic(const vector<int>& board, const vector<int>& goal) {
    int totalDistance = 0;
    
    vector<int> goalPos(9);
    for (int i = 0; i < 9; i++) {
        goalPos[goal[i]] = i;
    }

    for (int i = 0; i < 9; i++) {
        int tile = board[i];
        if (tile != 0) { 
            int current_row = i / 3;
            int current_col = i % 3;
            
            int goal_idx = goalPos[tile];
            int goal_row = goal_idx / 3;
            int goal_col = goal_idx % 3;

            totalDistance += abs(current_row - goal_row) + abs(current_col - goal_col);
        }
    }
    return totalDistance;
}

bool isSolvable(vector<int> start, vector<int> goal) {
    auto countInversions = [](vector<int> board) {
        int inv = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (board[i] != 0 && board[j] != 0 && board[i] > board[j]) {
                    inv++;
                }
            }
        }
        return inv;
    };
    int startInversions = countInversions(start);
    int goalInversions = countInversions(goal);

    return (startInversions % 2 == goalInversions % 2);
}

void printGrid(const vector<int>& board){
    for(int i=0; i<9; i++){
        if(board[i]==0){
            cout<<"_ ";
        }
        else{
            cout<<board[i]<<" ";
        }
        if((i+1)%3 == 0) cout<<endl;
    }
}

void solve(const vector<int>& start, const vector<int>& goal){
    if (!isSolvable(start, goal)) {
        cout << "The puzzle is NOT solvable from this starting state." << endl;
        return;
    }

    priority_queue<State, vector<State>, greater<State>> openList;
    map<vector<int>, int> closedList;

    int start_blank = find(start.begin(), start.end(), 0) - start.begin();
    int h_start = calculateHeuristic(start, goal);

    openList.push({start, 0, h_start, h_start, start_blank, {start}});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!openList.empty()){
        State current = openList.top();
        openList.pop();

        if(current.board == goal){
            cout << "--- SOLUTION FOUND ---" << endl;
            int stepNum = 0;
            for (const auto& stepBoard : current.history) {
                int current_h = calculateHeuristic(stepBoard, goal);
                cout << "Step " << stepNum << " | f(n)=" << (stepNum + current_h) 
                     << " [g=" << stepNum << ", h=" << current_h << "]" << endl;
                printGrid(stepBoard);
                cout << "--------------------" << endl;
                stepNum++;
            }
            return;
        }

        if(closedList.count(current.board) && closedList[current.board] <= current.g) continue;
        closedList[current.board] = current.g;

        int x = current.blank_idx/3;
        int y = current.blank_idx%3;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<3 && ny>=0 && ny<3){
                vector<int> next_board = current.board;
                int next_blank = nx*3 + ny;
                swap(next_board[current.blank_idx], next_board[next_blank]);

                int g_new = current.g + 1;
                if (!closedList.count(next_board) || closedList[next_board] > g_new) {
                    int h_new = calculateHeuristic(next_board, goal);
                    vector<vector<int>> next_history = current.history;
                    next_history.push_back(next_board);
                    
                    openList.push({next_board, g_new, h_new, g_new + h_new, next_blank, next_history});
                }
            }
        }
    }
}

int main(){
    vector<int> start;
    vector<int> goal;
    cout<<"Enter the starting board: "<<endl;
    for(int i=0; i<9; i++){
        int temp;
        cin >> temp;
        start.push_back(temp);
    }
    cout<<endl;
    cout<<"Enter the goal board: "<<endl;
    for(int i=0; i<9; i++){
        int temp;
        cin >> temp;
        goal.push_back(temp);
    }
    solve(start, goal);
    cout<<endl;
    return 0;
}   