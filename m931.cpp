#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// 有n個角色，每個角色有攻擊力和防禦力。
// 角色的能力值是攻擊力和防禦力的平方和，輸出能力值第二大的攻擊力和防禦力數值。
// 保證每個角色的能力值相異。

struct Character {
    int attack;
    int defense;
    int power; // 能力值

    Character(int a, int d) : attack(a), defense(d) {
        power = a * a + d * d;
    }
};

bool comparePower(const Character& c1, const Character& c2) {
    return c1.power > c2.power;
}

int main() {
    int n;
    cin >> n;

    vector<Character> characters;

    cout << endl;
    for (int i = 0; i < n; ++i) {
        int attack, defense;
        cin >> attack >> defense;
        characters.push_back(Character(attack, defense));
    }

    sort(characters.begin(), characters.end(), comparePower);

    cout << characters[1].attack << " " << characters[1].defense << endl;

    return 0;
}