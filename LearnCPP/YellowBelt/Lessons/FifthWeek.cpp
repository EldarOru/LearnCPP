//������������

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Fruit {
	int health = 0;
	string type = "fruit";
};

struct Apple : public Fruit {
	Apple() {
		health = 10;
		type = "apple";
	}
};

class AppleTree {
public: 
	//����������� �� ������� ������������� 
	AppleTree() : a1(), a2() {

	}

	Apple a1;
	Apple a2;
};

struct Orange : public Fruit {
	Orange() {
		health = 5;
		type = "orange";
	}
};

class Animal {
public: 
	//����������� �� ������� ������������� 
	Animal(const string& t) : type(t) {
		
	}
	void Eat(const Fruit& f) {
		cout << type << " ate " << f.type << " with " << f.health << " hp." << endl;
	}

	//����� �������������� ����� � ������� ��������
	virtual void Voice() = 0; // = 0 ������ ����� ����������� 
	const string type;
};

class Cat : public Animal {
public:
	Cat() : Animal("cat") {
	}

	void Voice() override {
		cout << "meow!" << endl;
	}

};

class Parrot : public Animal {
public: 
	Parrot(const string& name) : Animal("parrot"), name_(name) {

	}

	void Voice() override {
		cout << name_ << " is good!" << endl;
	}
private:
	string name_;
};

//���� �� ����� ���������� �� ������, �� ����� ���������� ������� ����� Animal.Voice()
void MakeSound(Animal& an) {
	an.Voice();
}
//��� �������� ������� ������� ����� ������ ����������� �������� ������, � ����� �������
//������������ ��� ���� ��� ����� � �������� ������� - ������� �������, � ����� �������� ������
int mainY5() {
	Orange orange;
	Cat cat;
	cat.Eat(orange);
	Parrot parrot("Kesha");
	MakeSound(cat);
	cat.Voice();
	parrot.Voice();

	shared_ptr<Animal> a;
	a = make_shared<Cat>();
	a->Voice();

	vector<shared_ptr<Animal>> animals = {
		make_shared<Cat>(),
		make_shared<Parrot>("Kesha")
	};

	for (auto a : animals) {
		MakeSound(*a);
	}

	return 1;
}