#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Inven // 싱글톤 패턴
{
private:

    vector<string> items;
    static Inven* instance;
    Inven() { items.push_back("물약"); }

public:
    vector<string>& getItems() { return items; }
    static Inven* getInstance()
    {
        if (!instance)
        {
            instance = new Inven();
        }
        return instance;
    }

    void addItem(const string& item)
    {
        items.push_back(item);
    }

    void displayInven()
    {
        cout << "인벤토리" << endl << "『 ";

        if (!items.empty())
        {
            cout << items[0];
            for (size_t i = 1; i < items.size(); i++)
            {
                cout << "/" << items[i];
            }
        }

        cout << " 』" << endl;
        cout << endl;
    }

    auto back()
    {
        return items;
    }
};

Inven* Inven::instance = nullptr;

void playerHavior(Inven* playerInven) // 플레이어 행동 함수
{
    int choose, count = 0;
    bool endGame = false;
    srand(time(0));

    do // 총 4번의 행동이 가능합니다. 3번으로 종료할 시 즉시 종료합니다.
    {
        count++;
        cout << "1) 길을 걸어간다. 2) 인벤토리를 확인한다 3) 종료한다." << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            string foundItem;

            int randomItem = rand() % 3;

            switch (randomItem)
            {
            case 0:
                foundItem = "검";
                cout << "검을 발견했습니다." << endl;
                playerInven->addItem(foundItem);
                break;
            case 1:
                foundItem = "방패";
                cout << "방패를 발견했습니다." << endl;
                playerInven->addItem(foundItem);
                break;
            case 2:
                foundItem = "없음";
                cout << "아무것도 발견하지 못하였습니다." << endl;
                break;
            }
            break;
        }
        case 2:
            playerInven->displayInven();
            break;
        case 3:
            cout << "게임을 종료합니다." << endl;
            endGame = true;
            break;
        default:
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
            break;
        }

    } while (!endGame && count < 4);
    playerInven->displayInven();
}