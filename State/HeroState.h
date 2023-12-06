#pragma once
#include <iostream>
using namespace std;

enum HeroStateType {
	IDLE,
	ATTACK,
	DEFEND,
	DIE
};

class HeroState {
public:
	virtual ~HeroState() {}
	virtual void handle() = 0;
	virtual HeroStateType getStateType() = 0;
};

// 기본 상태
class IdleState : public HeroState {
public:
	void handle() override {
		cout << "Hero is in Idle state." << endl;
	}
	HeroStateType getStateType() override { return HeroStateType::IDLE; }
};

class AttackState : public HeroState {
public:
	void handle() override {
		cout << "Hero is in attack State!" << endl;
	}
	HeroStateType getStateType() override { return HeroStateType::ATTACK; }
};

class DefenceState : public HeroState {
public:
	void handle() override {
		cout << "Hero is in Defence State!" << endl;
	}
	HeroStateType getStateType() override { return HeroStateType::DEFEND; }
};

class DieState : public HeroState {
public:
	void handle() override {
		cout << "Hero is in die State!" << endl;
	}
	HeroStateType getStateType() override { return HeroStateType::DIE; }
};

class Hero
{
private:
	HeroState* state;
	int health;
public:
	Hero(HeroState* state, int hp) : state(state), health(hp) {}

	void setState(HeroState* newState)
	{
		delete state;
		state = newState;
	}

	void takeDamage(int damage)
	{
		health -= damage;
		cout << "용사에게 " << damage << "데미지 적중. 용사의 남은 체력 : " << health << endl;

		if (health <= 0)
		{
			setState(new DieState);
			cout << "hero dies!" << endl;

		}
		else if (health >= 0)
		{
			setState(new AttackState);
		}
	}

	HeroStateType getState() { return state->getStateType(); }

	void handle() {
		state->handle();
	}

	~Hero()
	{
		delete state;
	}
};