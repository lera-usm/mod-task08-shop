#include "task.h"
#include <ctime>
#include <chrono>
#include <iostream>
#include <vector>

Pocupatel::Pocupatel(int colpokupok)
{
	this->colpokupok = colpokupok;
	nach = chrono::system_clock::now();
}

Pocupatel::Pocupatel()
{
	nach = chrono::system_clock::now();
}

Mag::Mag(int colkas, int vrobs, int maxoch, int colpokupat, int srcolpok)
{
	this->colkas = colkas;
	this->vrobs = vrobs;
	this->maxoch = maxoch;
	this->colpokupat = colpokupat;
	srvroch = 0;
	srvrnacas = 0;
	srvrab = 0;
	srvrprost = 0;
	vector<thread> t;
	for (int i = 0; i < colkas; i++)
	{
		t.push_back(thread(&Mag::Cassa, this));
	}
	colneobsl = 0;
	srand(time(0));
	for (int i = 0; i < colpokupat; i++)
	{
		if (poc.size() >= maxoch)
		{
			colneobsl++;
		}
		else
		{
			m.lock();
			poc.push(Pocupatel(srcolpok / 2 + rand() % srcolpok));
			m.unlock();
		}
		this_thread::sleep_for(chrono::milliseconds(rand() % 600 + 200));
	}
	for (int i = 0; i < colkas; i++)
	{
		t.at(i).join();
	}
	cout << "Количество обслуженных = " << colobsl << endl;
	cout << "Количество необслуженных = " << colneobsl << endl;
	srvrnacas /= (double)(colobsl);
	srvroch /= (double)(srvroch);
	cout << "Среднее время навхождения покупателя в очереди + на кассе = " << srvrnacas + srvroch << endl;
	srvrab /= (double)(colkas);
	srvrprost /= (double)(colkas);
	cout << "Среднее время работы = " << srvrab << endl;
	cout << "Среднее время простоя = " << srvrprost << endl;
	cout << "Вероятность отказа = " << (double)(colneobsl) / (double)(colpokupat)  << endl;
	cout << "Относительная пропускная способность = " << (double)(colobsl) / (double)(colpokupat) << endl;
}

void Mag::Cassa()
{
	chrono::system_clock::time_point nach = chrono::system_clock::now();
	chrono::duration<double> vrprost = chrono::system_clock::now() - nach;
	int vrrab = 0;
	while (colneobsl + colobsl < colpokupat)
	{
		nach = chrono::system_clock::now();
		Pocupatel p;
		m.lock();
		if (poc.size() > 0)
		{
			p = poc.front();
			chrono::duration<double> d = chrono::system_clock::now() - p.nach;
			srvroch += d.count();
			poc.pop();
		}
		else
		{
			m.unlock();
			vrprost += chrono::system_clock::now() - nach;
			continue;
		}
		m.unlock();
		this_thread::sleep_for(chrono::milliseconds(vrobs * p.colpokupok));
		vrrab += vrobs * p.colpokupok;
		m.lock();
		srvrnacas += vrobs * p.colpokupok;
		colobsl++;
		m.unlock();
	}
	m.lock();
	srvrab += vrrab;
	srvrprost += vrprost.count();
	m.unlock();
}
