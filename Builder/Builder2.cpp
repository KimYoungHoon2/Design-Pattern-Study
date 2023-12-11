#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;
    string color;

public:
    Car(const string& brand, const string& model, int year, const string& color)
        : brand(brand), model(model), year(year), color(color) {}

    // Builder
    class Builder {
    private:
        string brand;
        string model;
        int year;
        string color;

    public:
        Builder& setBrand(const string& brand) {
            this->brand = brand;
            return *this;
        }

        Builder& setModel(const string& model) {
            this->model = model;
            return *this;
        }

        Builder& setYear(int year) {
            this->year = year;
            return *this;
        }

        Builder& setColor(const string& color) {
            this->color = color;
            return *this;
        }

        Car build() {
            return Car(brand, model, year, color);
        }
    };
};

int main() {
    Car::Builder br;
    Car car = br
        .setBrand("GENESIS")
        .setModel("Gv80")
        .setYear(2024)
        .setColor("NCM")
        .build();

    cout << "차 정보" << endl;
    cout << "브랜드: " << car.brand << endl;
    cout << "모델: " << car.model << endl;
    cout << "연도: " << car.year << endl;
    cout << "색상: " << car.color << endl;

    return 0;
}