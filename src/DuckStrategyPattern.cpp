
#include <iostream>
#include <conio.h>

using namespace std;


// INTERFACES
class QuackBehaviour
{
public:
	virtual void quack() = 0;
    virtual ~QuackBehaviour();
};

// Quack Algorithms
class MuteQuack : public QuackBehaviour
{
public:
	//~MuteQuack();
	void quack(){
		cout<<"No sound, mute \n";
	}
};

class Quack : public QuackBehaviour
{
public:
	~Quack();
	void quack(){
		cout<<" Quack sound \n";
	}
};

class Squeak : public QuackBehaviour
{
public:
	//~Squeak();
	void quack(){
		cout<<" Squeak sound \n";
	}
};

class FlyBehaviour
{
public:
	virtual void fly() = 0;
	virtual ~FlyBehaviour();
};

//SPECIFIC IMPLEMENTATIONS FOR INTERFACES
//Fly Algorithms

class FlyWithWings : public FlyBehaviour
{
public:
	~FlyWithWings();
	void fly(){
		cout<<" Fly Wings \n";
	}
};

class FlyNoWay : public FlyBehaviour
{
public:
	//~FlyNoWay();
	void fly(){
		cout<<" No Wings \n";
	}
};

class FlyWithRocket : public FlyBehaviour
{
public:
	//~FlyWithRocket();
	void fly(){
		cout<<" Using a rocket to fly \n";
	}
};

// ABSTRACT CLASS

class Duck
{

public:

	FlyBehaviour *flyBehaviour;
	QuackBehaviour *quackBehaviour;

//    Duck(); //To make Abstract class not instantiable

	void setFlyBehaviour(FlyBehaviour * fly)
	{
		delete flyBehaviour;
		flyBehaviour = fly;
	}

	void setQuackBehaviour(QuackBehaviour * quack)
	{
		delete quackBehaviour;
		quackBehaviour = quack;
	}


	void performFly()
	{
		flyBehaviour->fly();
	}

	void performQuack()
	{
		quackBehaviour->quack();
	}

	void swim ()
	{
		cout<<" All ducks can FLY \n";
	}

	virtual void displayInfoDuck() = 0;
	virtual ~Duck()
	{
		delete quackBehaviour;
		delete flyBehaviour;
	}
};

//SPECIFIC IMPLEMENTATION

class ModelDuck : public Duck
{
public:
	ModelDuck()
    {
		flyBehaviour = new FlyWithWings();
		quackBehaviour = new Quack();
    }
	//~ModelDuck();

	void displayInfoDuck(){
		cout<<" I'am a ModelDuck \n";
	}
};

// IMPLEMENTATION OF STRATEGY PATTERN
int main()
{

 Duck *modelDuck = new ModelDuck();

 modelDuck->performQuack();
 modelDuck->performFly();

 getch();

 return 0;
}

