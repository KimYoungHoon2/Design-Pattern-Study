#include <iostream>
#include <string>
using namespace std;

class Character {
public:
	string Name;
	string Class;
	int Level;
	string Weapon;

	string ToString()
	{
		return Name + " (" + Class + ") - Level " + to_string(Level) + " - Weapon : " + Weapon;
	}
};

class ICharacterBuilder {
public:
	virtual void SetName(string name) = 0;
	virtual void SetClass(string charClass) = 0;
	virtual void SetLevel(int level) = 0;
	virtual void SetWeapon(string weapon) = 0;
	virtual Character Builder() = 0;
};

class WarriorBuilder : public ICharacterBuilder {
private:
	Character character;
public:
	void SetName(string name) override {
		character.Name = name;
	}
	void SetClass(string charClass) override {
		character.Class = charClass;
	}
	void SetLevel(int level) override {
		character.Level = level;
	}
	void SetWeapon(string weapon) override {
		character.Weapon = weapon;
	}

	Character Builder() override {
		return character;
	}
};

class CharacterDirector {
public:
	Character Construct(ICharacterBuilder& builder, string name, int level) {
		builder.SetName(name);
		builder.SetClass("Warrior");
		builder.SetLevel(level);
		builder.SetWeapon("Sword");
		return builder.Builder();
	}
};
int main()
{
	CharacterDirector director;
	WarriorBuilder builder;

	Character warrior = director.Construct(builder, "TaeHyun", 25);

	cout << warrior.ToString() << endl;
	return 0;
}