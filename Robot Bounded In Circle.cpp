On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.
Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool isRobotBounded(string A) {
        
        int n = A.length();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int dir=0,x=0,y=0;
      for(int i=0;i<A.length();i++)
        {
            if(A[i] == 'G')
            {
                x = x + dx[dir];
                y = y + dy[dir];
            }
            
            else if(A[i] == 'L')
            {
                if(dir == 0)
                  dir =3;
                else if(dir ==1)
                    dir =0;
                
                else if(dir == 2)
                    dir = 1;
                
                else
                    dir =2;
            }
            
            else if(A[i] == 'R')
            {
                if(dir == 0)
                    dir = 1;
                else if(dir == 1)
                    dir =2;
                else if(dir ==2)
                    dir = 3;
                else
                    dir = 0;
            }
        }
        
        
        
        if(x == 0 && y == 0)
            return 1;
        
        if(dir == 0)
        return 0;
        
        return 1;
    }
};
