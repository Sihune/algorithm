#include <bits/stdc++.h>
using namespace std;

void touchLeft(int &hand, int &num, string &answer){
    hand = num; answer +='L';
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for(auto &num:numbers){
        if(num == 0) num=10;
        else num--;
    }

    int left = 9, right =11;

    for(int i=0; i<numbers.size(); i++){
        cout << left+1 << ' '<< right+1 <<'\n';
        int num = numbers[i];

        if(num == 0 || num == 3 || num == 6){
            answer += 'L';
            left = num;
        }
        else if(num == 2 || num ==5 || num == 8){
            answer += 'R';
            right = num;
        }
        else{
            int r = num/3, c = num%3;
            int leftD = abs(left/3-r) + abs(left%3-c);
            int rightD = abs(right/3-r) + abs(right%3-c);

            if(leftD > rightD) {
                answer += 'R';
                right = num;
            }
            else if(leftD < rightD){
                answer += 'L';
                left = num;
            }
            else {
                if(hand=="right"){ 
                    answer += 'R';
                    right = num;
                }
                else {
                    answer += 'L';
                    left = num;
                }
            }
        }
    }

    return answer;
}

int main(){
    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";

    cout << solution(numbers, hand);

    return 0;
}