//Composite Design Pattern
#include<iostream>
#include<string>
#include<vector>
using namespace std;



//Component
class Animal
{
public:
	virtual void info() = 0;                    //Pure Virtual Function
	
};


//Leaf
class iAnimal : public Animal
{

	string Name;
	string type;
	int Age;

    public:
	iAnimal(string name,string ntype, int age): Name(name),type(ntype),Age(age){}
	
	string getName() { return Name; }           //Accessor Function
	string getType() { return type; }           //Accessor Function
	int getAge() { return Age; }                //Accessor Function


	void info() {

		cout << getName() <<"  "<< getType() <<"   "<< getAge() << endl;

	}

};


//Composite
class AnimalGroup : public Animal
{

	vector<Animal *> v;                                  //Vector
	vector<Animal *> :: iterator i;                      //Iterator
	string Name;
	string def;

public:
	AnimalGroup(string name, string ndef) : Name(name), def(ndef) {}
	string getName() { return Name; }
	string getDef() { return def; }

	
	void add(Animal * a) {                       //Add Function
		v.push_back(a);                          //store address for individual elements 
	};
	
	void info() {
	
		cout << getName() << " " << getDef() << endl << endl;
	
		if (!v.empty()) {
		
			for (i = v.begin(); i != v.end(); i++) {               //loops through child elements via iterator
			
				(*i)->info();
			}

		}
		cout << endl;
	}


	virtual void remove(Animal *a) {                               //Remove Function
	
		for (i = v.begin(); i != v.end();) {
		
			if ((*i) == a) {   
			
				v.erase(i);
				break;
			}
			else {
			
				i++;
			}
		}
	};
	
};



int main()
{

	AnimalGroup rep ("Reptiles", " are cold-blooded egg-laying vertebrates");
	AnimalGroup sk("Snakes", ": Poisonous and Slimy Reptiles which Slither on Ground");
	AnimalGroup tort("Tortoise", ": Harmless and Long living reptiles living Both on Water & Land");
	AnimalGroup croc("Crocodiles", ": Reptiles which are Dangerous on Water & Land");
	

	iAnimal cb("Cobra", "King of Snakes", 2);
	iAnimal py("Python", " Long and Dangerous Snake", 5);
	iAnimal rt("Rattlesnake", "Highly Poisonous Snake creating Rattle sound", 4);
	
	iAnimal al("Aligator", "Ferocious Crocodile", 9);
	
	rep.add(&sk);
	rep.add(&tort);
	rep.add(&croc);
	
	sk.add(&cb);
	sk.add(&py);
	sk.add(&rt);
	
	croc.add(&al);
 	
	cout << "The Reptiles in the ZOO are :: " << endl << endl;
	rep.info();

	sk.remove(&py);

	cout << endl << endl;

	cout << "The Reptiles in the ZOO are :: " << endl << endl;
	rep.info();

	system("pause");
}




