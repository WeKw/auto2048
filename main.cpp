#include <bits/stdc++.h>
#include <conio.h>
/* up: 224 72
 * right: 224 77
 * down: 224 80
 * left: 224 75
 */
int getchange() {
    int ch;
    while (ch = _getch()) {
        if (ch != 224) continue;
        ch = _getch();
        switch (ch) {
            case 72:
                return 0;
            case 77:
                return 1;
            case 80:
                return 2;
            case 75:
                return 3;
        }
    }
}
int main() { return 0; }