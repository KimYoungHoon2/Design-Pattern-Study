#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "MonsterState.h"
#include "HeroState.h"
using namespace std;

int main() {
    Hero hero(new IdleState, 100);
    Monster monster(new M_IdleState, 100);
    srand(static_cast<unsigned int>(time(0)));
    //랜덤하게 누가 먼저 공격할건지 결정
    bool heroTurn = rand() % 2;
    int choose;
   
    while (true)
    {
        system("cls");
        cout << "레이드존에 오신 것을 환영합니다." << endl;
        cout << "용사 Hp : " << hero.getHp() << ", Mp : " << hero.getMp() << endl;
        cout << "몬스터 Hp : " << monster.getHp() << endl;

        if (heroTurn) {
            cout << "용사님의 턴입니다." << endl;
            cout << "1. 일반 공격 2. 필살기(MP게이지 50이상)" << endl;
            cout << "입력 : ";
            cin >> choose;
            if (choose == 1)
            {
                hero.setState(new AttackState);
                hero.handle();
                int damage = rand() % 20 + 1;
                monster.takeDamage(damage);
                hero.increaseMP(damage);
            }
            else if (choose == 2 && hero.isEnoughMP())
            {
                hero.setState(new SpecialAttackState);
                hero.handle();
                monster.takeDamage(50);
                hero.useMP(); //필살기 사용 후  MP감소
            }
            else {
                cout << "MP가 부족하거나 잘못 선택하셨습니다. 다시 선택해주세요." << endl;
                system("pause");
                continue;
            }
           
            hero.setState(new DefenceState);

        }
        else {
            cout << "몬스터의 턴입니다." << endl;
            monster.setState(new M_AttackState);
            monster.handle();
            Sleep(2000);
            if (hero.getState() == DEFEND && hero.isDefenceSuccess())
                cout << "용사님이 공격을 완벽하게 막았습니다!" << endl;
            else
                hero.takeDamage(rand() % 20 + 1);
           
            monster.setState(new M_DefenceState);
        }

        if (hero.getState() == DIE || monster.getState() == M_DIE)
        {
            if (hero.getState() == DIE)
                cout << "용사님이 패배하셨습니다." << endl;
            else
                cout << "용사님이 승리하셨습니다." << endl;
            break;
        }

        heroTurn = !heroTurn;

        system("pause");
    }

    return 0;
}