#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MonsterState.h"
#include "HeroState.h"
using namespace std;

int main() {
    Hero hero(new IdleState, 100);
    Monster monster(new M_IdleState, 100);
    srand(static_cast<unsigned int>(time(0)));
    //랜덤하게 누가 먼저 공격할건지 결정
    bool heroTurn = rand() % 2;

    while (true)
    {
        if (heroTurn) {
            hero.setState(new AttackState);
            hero.handle();
            monster.takeDamage(rand() % 30 + 1);

            hero.setState(new DefenceState);

        }
        else {
            monster.setState(new M_AttackState);
            monster.handle();
            hero.takeDamage(rand() % 30 + 1);

            monster.setState(new M_DefenceState);

        }

        if (hero.getState() == DIE || monster.getState() == M_DIE)
        {
            break;
        }

        heroTurn = !heroTurn;
    }

    return 0;
}