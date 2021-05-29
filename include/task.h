#pragma once
#include <locale>
#include <thread>
#include <queue>
#include <mutex>

using namespace std;

class Pocupatel
{
	public:
	int colpokupok;
	chrono::system_clock::time_point nach;
	Pocupatel(int colpokupok);
	Pocupatel();
};

class Mag
{
	public:
	int colkas;
	int vrobs;
	int maxoch;
	int colpokupat;
	queue<Pocupatel> poc;
	mutex m;
	int colpokoch;
	int colobsl;
	int colneobsl;
	double srvrnacas;
	double srvrab;
	double srvroch;
	double srvrprost;
	Mag(int colkas, int vrobs, int maxoch, int colpokupat, int srcolpok);
	void Cassa();

};







