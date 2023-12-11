#include "Singleton.h"

void EnhanceItem(Inven* playerInven) // 강화 함수
{
    vector<string>& items = playerInven->getItems();

    string ItemName;
    bool WeaponCheck = false;

    while (!WeaponCheck) // 아이템 선택 반복문
    {
        cout << "강화할 아이템을 선택하세요 (검 또는 방패): ";
        cin >> ItemName;

        if (ItemName == "검" || ItemName == "방패")
        {
            WeaponCheck = true;
        }
        else
        {
            cout << "다시 입력해주세요." << endl;
        }
    }

    int itemCount = count(items.begin(), items.end(), ItemName);

    if (ItemName == "검") // 검을 선택했을 시
    {
        if (itemCount == 2) // 2개를 +1강으로
        {
            items.erase(remove(items.begin(), items.end(), ItemName), items.end());
            items.push_back(ItemName + "+1");
        }
        else if (itemCount == 3) // 3개를 +2강으로
        {
            items.erase(remove(items.begin(), items.end(), ItemName), items.end());
            items.push_back(ItemName + "+2");
        }
        else if (itemCount > 3)  // 4개이상을 +3강으로
        {
            items.erase(remove(items.begin(), items.end(), ItemName), items.end());
            items.push_back(ItemName + "+3");
        }
    }
    else if (ItemName == "방패") // 검과 동일
    {
        if (itemCount == 2)
        {
            items.erase(remove(items.begin(), items.end(), ItemName), items.end());
            items.push_back(ItemName + "+1");
        }
        else if (itemCount == 3)
        {
            items.erase(remove(items.begin(), items.end(), ItemName), items.end());
            items.push_back(ItemName + "+2");
        }
        else if (itemCount > 3)
        {
            items.erase(remove(items.begin(), items.end(), ItemName), items.end());
            items.push_back(ItemName + "+3");
        }
    }
}

void chooseWeapon(Inven* playerInven) // 무기 선택 함수
{
    playerInven->displayInven();


    bool foundWeapon = false;

    while (!foundWeapon)
    {
        cout << "무기를 선택하세요: ";
        string weapon;
        cin >> weapon;
        for (const auto& item : playerInven->getItems())
        {
            if (item == weapon)
            {
                foundWeapon = true;
                cout << weapon << " 무기를 선택하였습니다. " << endl;
                break;
            }
        }
        if (!foundWeapon)
        {
            cout << "인벤토리에 해당 무기가 없습니다." << endl;
        }
    }
}

int main()
{
    Inven* PlayerInven = Inven::getInstance();
    Inven* PetInven = Inven::getInstance();

    cout << "플레이어가 활동합니다." << endl; // 플레이어가 움직입니다.
    playerHavior(PlayerInven);

    cout << endl;

    cout << "펫이 활동합니다." << endl; // 펫이 움직입니다.
    playerHavior(PetInven);

    cout << endl;

    EnhanceItem(PlayerInven);

    cout << endl;

    chooseWeapon(PlayerInven);
    return 0;
}