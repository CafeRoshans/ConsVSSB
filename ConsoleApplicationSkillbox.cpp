#include <iostream>

class Animal {
public:
    virtual void Voice() {
        std::cout << "Some sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void Voice() override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void Voice() override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

class Cow : public Animal {
public:
    void Voice() override {
        std::cout << "Moo! Moo!" << std::endl;
    }
};

class Lion : public Animal {
public:
    void Voice() override {
        std::cout << "Roar! Roar!" << std::endl;
    }
};

int main() {
    const int arraySize = 6;
    Animal* animals[arraySize];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();
    animals[3] = new Lion();
    animals[4] = new Dog();
    animals[5] = new Cat();

    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Animal " << i + 1 << ": ";
        animals[i]->Voice();
    }

    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

    Animal* animalPtr;

    animalPtr = new Dog();
    std::cout << "Dog through Animal pointer: ";
    animalPtr->Voice();
    delete animalPtr;

    animalPtr = new Cat();
    std::cout << "Cat through Animal pointer: ";
    animalPtr->Voice();
    delete animalPtr;

    animalPtr = new Cow();
    std::cout << "Cow through Animal pointer: ";
    animalPtr->Voice();
    delete animalPtr;

    animalPtr = new Lion();
    std::cout << "Lion through Animal pointer: ";
    animalPtr->Voice();
    delete animalPtr;

    return 0;
}