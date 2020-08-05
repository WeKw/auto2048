#include "api.hpp"
int cnt = 0;
int solve(int data[4][4]) {
    int temp;
    if (cnt & 1){
        temp = 3;}
    else{
        temp = 2;}
    if (!test(temp)) temp = 5 - temp;
    if (!test(temp)) {
        temp = 1;
        if (!test(temp)) temp = 0;
        cnt = -1;
    }
    cnt++;
    return temp;
}