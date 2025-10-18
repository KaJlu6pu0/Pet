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
		cout << "SPEAK: Woof,Woof,Woof!" << endl;
	}
	
	void Info() const override {
		cout << "Protects the home and is man's best friend." << endl;
	}
	
	void Type() const override {
		cout << "This is a Dog." << endl;
	}
};


class Cat : public Pet {
public:
	
	Cat(const char* name, int age) : Pet(name, age) {}
	
	void Sound() const override {
		cout << "SPEAK: Meow,Meow,!" << endl;
	}

	void Info() const override {
		cout << "Loves to nap and chase mice." << endl;
	}
	
	void Type() const override {
		cout << "This is a Cat." << endl;
	}
};

class parrot : public Pet {
public:
	parrot(const char* name, int age) : Pet(name, age) {}
	
	void Sound() const override {
		cout << "SPEAK: Chirp,Chirp,Chirp!" << endl;
	}

	void Info() const override {
		cout << "Good conversationalist." << endl;
	}
	
	void Type() const override {
		cout << "This is a Parrot." << endl;
	}
};

class Hamster : public Pet {
	public:
	Hamster(const char* name, int age) : Pet(name, age) {}
	
	void Sound() const override {
		cout << "SPEAK: Squeak,Squeak,Squeak!" << endl;
	}

	void Info() const override {
		cout << "Loves to run on the wheel." << endl;
	}
	
	void Type() const override {
		cout << "This is a Hamster." << endl;
	}
};

int main() {
	std::cout << "------------------------" << endl;
	Pet* myDog = new Dog("Mugtar", 9);
	myDog->ShowInfo();
	myDog->Type();
	myDog->Info();
	myDog->Sound();
	delete myDog;
	cout << "------------------------" << endl;
	
	Pet* myCat = new Cat("Kyzia", 7);
	myCat->ShowInfo();
	myCat->Type();
	myCat->Info();
	myCat->Sound();
	delete myCat;
	cout << "------------------------" << endl;

	Pet* myParrot = new parrot("Kesha", 25);
	myParrot->ShowInfo();
	myParrot->Type();
	myParrot->Info();
	myParrot->Sound();
	delete myParrot;
	cout << "------------------------" << endl;
	
	Pet* myHamster = new Hamster("Xoma", 2);
	myHamster->ShowInfo();
	myHamster->Type();
	myHamster->Info();
	myHamster->Sound();
	delete myHamster;
	cout << "------------------------" << endl;

};