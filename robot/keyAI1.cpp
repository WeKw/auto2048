#include "api.hpp"
namespace keyAI1 {

int cnt = 3;
int solve(int data[4][4]) {
    int a = step(3, data), b = step(2, data);
    if (cnt == 4) {
        cnt = 3;
        return 2;
    }
    if (!data[3][0] && test(3)) return 3;
    if (!data[3][3] && test(2)) return 2;
    if (a > b && test(3)) return 3;
    if (b > a && test(2)) return 2;
    cnt = 5 - cnt;
    if (test(cnt)) return cnt;
    cnt = 5 - cnt;
    if (test(cnt)) return cnt;
    cnt = 2;
    if (test(1)) return 1;
    cnt = 4;
    return 0;
}

}  // namespace keyAI1