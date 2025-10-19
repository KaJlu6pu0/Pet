#include <iostream>
#include <cstring>
using namespace std;

class Pet {
private:
    char* name;
    int age;

public:
    Pet(const char* petName, int petAge) {
        name = new char[strlen(petName) + 1];
        strcpy_s(name, strlen(petName) + 1, petName);
        age = petAge;
    }

    Pet(const Pet& other) {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
        age = other.age;
    }

    Pet& operator=(const Pet& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);
            age = other.age;
        }
        return *this;
    }

    virtual ~Pet() {
        delete[] name;
    }

    virtual void Sound() const = 0;

    virtual void ShowInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual void Info() const = 0;
    virtual void Type() const = 0;
};

class Dog : public Pet {
public:
    Dog(const char* name, int age) : Pet(name, age) {}

    void Sound() const override {
        cout << " Woof, Woof, Woof!" << endl;
    }

    void Info() const override {
        cout << "------characteristics--------" << endl;
        cout << "Protects the home and is man's best friend." << endl;
        cout << "Speed: 15–20 km/h" << endl;
        cout << "Leg span: standard for running" << endl;
        cout << "How it jumps: high and energetically" << endl;
        cout << "What it hunts: small animals, sometimes birds" << endl;
        cout << "What it likes to do: play, run, guard, be with humans" << endl;
        cout << "------SPEAK--------" << endl;
    }

    void Type() const override {
        cout << "This is a Dog." << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const char* name, int age) : Pet(name, age) {}

    void Sound() const override {
        cout << "SPEAK: Meow, Meow!" << endl;
    }

    void Info() const override {
        cout << "------characteristics--------" << endl;
        cout << "Loves to nap and chase mice." << endl;
        cout << "Speed: 20–30 km/h" << endl;
        cout << "Leg span: flexible and agile" << endl;
        cout << "How it jumps: high and silently" << endl;
        cout << "What it hunts: mice, birds, insects" << endl;
        cout << "What it likes to do: sleep, explore territory, chase toys" << endl;
        cout << "------SPEAK--------" << endl;
    }

    void Type() const override {
        cout << "This is a Cat." << endl;
    }
};

class Parrot : public Pet {
public:
    Parrot(const char* name, int age) : Pet(name, age) {}

    void Sound() const override {
        cout << "SPEAK: Chirp, Chirp, Chirp!" << endl;
    }

    void Info() const override {
        cout << "------characteristics--------" << endl;
        cout << "Good conversationalist." << endl;
        cout << "Speed: 20–50 km/h (in flight)" << endl;
        cout << "Wingspan: 25–40 cm (depending on species)" << endl;
        cout << "How it jumps: hops from branch to branch" << endl;
        cout << "What it hunts: none, eats seeds and fruits" << endl;
        cout << "What it likes to do: repeat words, play with toys, socialize" << endl;
        cout << "------SPEAK----------" << endl;
    }

    void Type() const override {
        cout << "This is a Parrot." << endl;
    }
};

class Hamster : public Pet {
public:
    Hamster(const char* name, int age) : Pet(name, age) {}

    void Sound() const override {
        cout << "SPEAK: Squeak, Squeak, Squeak!" << endl;
    }

    void Info() const override {
        cout << "------characteristics--------" << endl;
        cout << "Loves to run on the wheel." << endl;
        cout << "Speed: up to 8 km/h" << endl;
        cout << "Leg span: short, runs in wheel" << endl;
        cout << "How it jumps: low, small jumps" << endl;
        cout << "What it hunts: none, gathers food in burrows" << endl;
        cout << "What it likes to do: run in wheel, dig burrows, gnaw food" << endl;
        cout << "------SPEAK--------" << endl;
    }

    void Type() const override {
        cout << "This is a Hamster." << endl;
    }
};

int main() {
    cout << "------------------------" << endl;
    cout << "------------------------" << endl;
    Pet* myDog = new Dog("Mugtar", 9);
    myDog->ShowInfo();
    myDog->Type();
    myDog->Info();
    myDog->Sound();
    delete myDog;
    cout << "------------------------" << endl;
    cout << "------------------------" << endl;

    Pet* myCat = new Cat("Kyzia", 7);
    myCat->ShowInfo();
    myCat->Type();
    myCat->Info();
    myCat->Sound();
    delete myCat;
    cout << "------------------------" << endl;
    cout << "------------------------" << endl;

    Pet* myParrot = new Parrot("Kesha", 25);
    myParrot->ShowInfo();
    myParrot->Type();
    myParrot->Info();
    myParrot->Sound();
    delete myParrot;
    cout << "------------------------" << endl;
    cout << "------------------------" << endl;

    Pet* myHamster = new Hamster("Xoma", 2);
    myHamster->ShowInfo();
    myHamster->Type();
    myHamster->Info();
    myHamster->Sound();
    delete myHamster;
    cout << "------------------------" << endl;
    cout << "------------------------" << endl;
}
