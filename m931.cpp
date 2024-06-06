#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// ��n�Ө���A�C�Ө��⦳�����O�M���m�O�C
// ���⪺��O�ȬO�����O�M���m�O������M�A��X��O�ȲĤG�j�������O�M���m�O�ƭȡC
// �O�ҨC�Ө��⪺��O�Ȭ۲��C

struct Character {
    int attack;
    int defense;
    int power; // ��O��

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