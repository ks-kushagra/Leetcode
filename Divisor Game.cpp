Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Note:

1 <= N <= 1000
__________________________________________________________________________________________________________________________________________________________________________________________________________________________

EXPLANATION::If the N is even, you can replace N with N - 1, which leaves an odd number, N -1, to your opponent. Then, the opponent has to take an odd number x from N - 1,
which will leave an even number to you(since deducting an odd number from an odd number will produce an even number). Thus, you'll always face an even number in your round 
while the opponent will always face an odd number. Since the number keeps decreasing with the game going, finally, your opponent will face 1 and lose the game.

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool divisorGame(int N) {
        if(N%2 == 0)
            return 1;
        return 0;
    }
};
