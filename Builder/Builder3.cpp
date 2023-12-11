#include <iostream>
#include <string>

using namespace std;

class Character
{
public:
	string name;
	string gender;
	string hairLen;
	string hairColor;
	int height;
	int age;
	string mbti;
	string job;

	void setName(string name) { this->name = name; }
	void setGender(string gender) { this->gender = gender; }
	void setHair(string hairLen, string color) { this->hairLen = hairLen; this->hairColor = color; }
	void setHeight(int height) { this->height = height; }
	void setAge(int age) { this->age = age; }
	void setMBTI(string mbti) { this->mbti = mbti; }
	void setJob(string job) { this->job = job; }
};

class Builder
{
private:
	Character character;

public:

	virtual void buildGender(string gender) { character.setGender(gender); }
	virtual void buildHair(string hairLen, string color) { character.setHair(hairLen, color); }
	virtual void buildHeight(int height) { character.setHeight(height); }
	virtual void buildAge(int age) { character.setAge(age); }
	virtual void buildName(string name) { character.setName(name); }
	virtual void buildMBTI(string mbti) { character.setMBTI(mbti); }
	virtual void buildJob(string job) { character.setJob(job); }

};

class CharacterBuilder : public Builder
{
private:
	Character character;

public:

	void buildName(string name) override { character.setName(name); }
	void buildGender(string gender) override { character.gender = gender; }
	void buildHair(string hairLen, string color) override { character.hairLen = hairLen; character.hairColor = color; }
	void buildHeight(int height) override { character.height = height; }
	void buildAge(int age) override { character.age = age; }
	void buildMBTI(string mbti) override { character.mbti = mbti; }
	void buildJob(string job) override { character.setJob(job); }

	void getData()
	{
		cout << "이름: " << character.name << endl;
		cout << "성별: " << character.gender << endl;
		cout << "머리 길이: " << character.hairLen << endl;
		cout << "머리 색깔: " << character.hairColor << endl;
		cout << "키: " << character.height << endl;
		cout << "나이: " << character.age << endl;
		cout << "MBTI: " << character.mbti << endl;
		cout << "직업: " << character.job << endl;
	}
};

int main()
{
	CharacterBuilder HyeongJun;

	HyeongJun.buildName("배형준");
	HyeongJun.buildGender("남성");
	HyeongJun.buildHair("중간", "검은색");
	HyeongJun.buildHeight(181);
	HyeongJun.buildAge(23);
	HyeongJun.buildMBTI("INFP");
	HyeongJun.buildJob("대학생");

	HyeongJun.getData();

	return 0;
}