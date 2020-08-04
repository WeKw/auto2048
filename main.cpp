#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <conio.h>
/* up: 0 72
 * right: 0 77
 * down: 0 80
 * left: 0 75
 */
int getchange() {
    int ch;
    while (ch = _getch(), 1) {
        if (ch) continue;
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
int score;
int data[4][4], tmp[4][4];
std::mt19937 rand_num;
void clear() {
#ifdef _WIN64
    system("cls");
#else
    system("clear");
#endif
}
void print() {
    clear();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << (data[i][j] ? 1 << data[i][j] : 0) << "\t";
        }
        std::cout << std::endl << std::endl << std::endl;
    }
    std::cout << "score: " << score << std::endl;
}
void random() {
    std::vector<std::pair<int, int> > vec;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!data[i][j]) vec.push_back(std::make_pair(i, j));
        }
    }
    if (vec.size()) {
        int x = rand_num() % vec.size();
        int y = rand_num() % 10;
        y = y ? 1 : 2;
        data[vec[x].first][vec[x].second] = y;
    }
}
void solve(int x, int data[4][4], int &score) {
    if (x == 0) {
        for (int j = 0; j < 4; ++j) {
            int cnt = 0;
            for (int i = 0; i < 4; ++i) {
                if (data[i][j]) std::swap(data[cnt++][j], data[i][j]);
            }
        }
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 3; ++i) {
                if (data[i][j] && data[i][j] == data[i + 1][j]) {
                    ++data[i][j];
                    score += 1 << data[i][j];
                    data[i + 1][j] = 0;
                }
            }
        }
        for (int j = 0; j < 4; ++j) {
            int cnt = 0;
            for (int i = 0; i < 4; ++i) {
                if (data[i][j]) std::swap(data[cnt++][j], data[i][j]);
            }
        }
    } else if (x == 1) {
        for (int i = 0; i < 4; ++i) {
            int cnt = 4;
            for (int j = 3; ~j; --j) {
                if (data[i][j]) std::swap(data[i][--cnt], data[i][j]);
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 2; ~j; --j) {
                if (data[i][j] && data[i][j] == data[i][j + 1]) {
                    ++data[i][j];
                    score += 1 << data[i][j];
                    data[i][j + 1] = 0;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            int cnt = 4;
            for (int j = 3; ~j; --j) {
                if (data[i][j]) std::swap(data[i][--cnt], data[i][j]);
            }
        }
    } else if (x == 2) {
        for (int j = 0; j < 4; ++j) {
            int cnt = 4;
            for (int i = 3; ~i; --i) {
                if (data[i][j]) std::swap(data[--cnt][j], data[i][j]);
            }
        }
        for (int j = 0; j < 4; ++j) {
            for (int i = 2; ~i; --i) {
                if (data[i][j] && data[i][j] == data[i + 1][j]) {
                    ++data[i][j];
                    score += 1 << data[i][j];
                    data[i + 1][j] = 0;
                }
            }
        }
        for (int j = 0; j < 4; ++j) {
            int cnt = 4;
            for (int i = 3; ~i; --i) {
                if (data[i][j]) std::swap(data[--cnt][j], data[i][j]);
            }
        }
    } else if (x == 3) {
        for (int i = 0; i < 4; ++i) {
            int cnt = 0;
            for (int j = 0; j < 4; ++j) {
                if (data[i][j]) std::swap(data[i][cnt++], data[i][j]);
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (data[i][j] && data[i][j] == data[i][j + 1]) {
                    ++data[i][j];
                    score += 1 << data[i][j];
                    data[i][j + 1] = 0;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            int cnt = 0;
            for (int j = 0; j < 4; ++j) {
                if (data[i][j]) std::swap(data[i][cnt++], data[i][j]);
            }
        }
    }
}
int test(int x) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) tmp[i][j] = data[i][j];
    }
    int plain = 0;
    solve(x, tmp, plain);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tmp[i][j] != data[i][j]) return 1;
        }
    }
    return 0;
}
int test() {
    for (int x = 0; x < 4; ++x)
        if (test(x)) return 1;
    return 0;
}
int step(int x) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) tmp[i][j] = data[i][j];
    }
    solve(x, data, score);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (data[i][j] != tmp[i][j]) {
                random();
                return 1;
            }
        }
    }
    return 0;
}
int step(int x, int data[4][4]) {
    int tmp[4][4], score = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) tmp[i][j] = data[i][j];
    }
    solve(x, tmp, score);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (data[i][j] != tmp[i][j]) return score | 1;
        }
    }
    return score;
}
int main() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rand_num = std::mt19937(seed);
    random();
    random();
    print();
    while (step(getchange()), 1) {
        print();
        if (!test()) {
            clear();
            std::cout << "Game over!" << std::endl;
            return 0;
        }
    }
    return 0;
}