// problem statement: https://leetcode.com/problems/walking-robot-simulation/
#include<bits\stdc++.h>
using namespace std;

/*
    intution:
    let commands [4,-1,4,-2,4], obstacles = [[1,0][2,2],[4,4]]

*/

// time complexity: O(n + d*m) => m*d for checking obstacles , d is distance to which it is moved
// space complexity: O(m)-> for obstacles set
class Solution{
    public:
        int robotSimulation(vector<int> commands , vector<vector<int>> obstacles ){
            set<vector<int>> s;
            for( auto obs : obstacles){
                s.insert(obs);
            }
            vector<int> directions = {0,1,2,3}; // n , e , s , w 
            int startX = 0, startY = 0;
            int direction = directions[0];
            int ans = 0;

            for( auto command : commands){
                if(command == -1){
                    // turn right
                    direction = directions[(direction+1) % 4];
                }else if( command == -2){
                    if(direction == 0){
                        direction = 3; // for zero we cant decrement it right so we'll rotate it anti clock wise by 3 
                    }else{
                    direction --; // for other direcs 1,2,3 we can turnn left by decrementing
                     }
                }else{
                    int temp = command;
                    
                    if(direction == 0){
                        while(temp--){
                            if(s.find({startX,startY+1})==s.end()){
                            startY++;
                            }
                            else break;
                        }
                    } else if(direction==1){
                        while(temp--){
                            if(s.find({startX+1,startY})==s.end()){
                                startX++;
                            }
                            else break;
                        }
                    } else if(direction==2){
                        while(temp--){
                            if(s.find({startX,startY-1})==s.end()){
                                startY--;
                            }
                            else break;
                        }
                    }else{
                        while(temp--){
                            if(s.find({startX-1,startY})==s.end()){
                                startX--;
                            }
                            else break;
                        }
                    }
                }
                int distance=pow(startX,2)+pow(startY,2);
                ans=max(ans,distance);
            }
            return ans;
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> commands(n);
        for(int i = 0; i<n;i++){
        cin>> commands[i];
        }
        vector<vector<int>> obstacles;
        int m;
        cin>>m;
        for(int i = 0;i<m;i++){
            cin>> obstacles[i][0] >> obstacles[i][1];
        }
        Solution sl;
        int ans = sl.robotSimulation(commands,obstacles);
        cout<< ans << endl;
    }
    return 0;
}
