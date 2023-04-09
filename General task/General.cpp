#include <iostream>
using namespace std;

class Worker
{
public:
	int age = 0;
	string name;
	void eat(float how_much);
	float get_weight();
	void walk();
	void dance();
	void work();
	int get_mood();

private:
	float weight = 0;
	int mood = 10;
};

void Worker::eat(float how_much)
{
	if (how_much <= 10)
		weight += how_much;
	else
	{
		weight += how_much / 2;
		age++;
	}

}

float Worker::get_weight()
{
	return weight;
}

void Worker::walk()
{
	mood++;
}

void Worker::dance()
{
	mood += 2;
}

void Worker::work()
{
	if (mood >= 2)
		mood -= 2;
	else
		mood -= mood;
}

int Worker::get_mood()
{
	return mood;
}

int main()
{
	system("chcp 1251");
	system("cls");

	Worker* wrk1 = new Worker();

	cout << "Укажите возраст рабочего: ";
	cin >> wrk1->age;
	cout << "Укажите имя рабочего: ";
	cin >> wrk1->name;

	wrk1->eat(15);
	wrk1->walk();
	wrk1->walk();
	wrk1->dance();
	wrk1->dance();
	wrk1->dance();

	for (int i = 0; i < 10; i++)
		wrk1->work();

	cout << "age = " << wrk1->age << endl << "name = " << wrk1->name << endl << "weight = " << wrk1->get_weight() << endl << "mood = " << wrk1->get_mood() << endl;

	delete wrk1;
	system("pause");
	return 0;
}