#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int>StackintBlock;
int Count = 0;

void StackBlock(int input) {
    if (StackintBlock.empty() == true) {
        StackintBlock.push_back(input);
    }
    else {
        if (StackintBlock.back() == input) {
            StackintBlock.pop_back();
            Count += 2;
        }
        else {
            StackintBlock.push_back(input);
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int height = 0;
    int Crankindex = 0;

    height = board.size();
    for (int i = 0; i < moves.size(); i++) {
        Crankindex = moves[i];
        for (int j = 0; j < height; j++) {
            if (board[j][Crankindex - 1] != 0) {
                StackBlock(board[j][Crankindex - 1]);
                board[j][Crankindex - 1] = 0;
                break;
            }
        }
    }
    int answer = Count;
    return answer;
}

