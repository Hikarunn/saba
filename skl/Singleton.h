#pragma once
class Singleton
{

private:
	Singleton() {};
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
	int counter = 0;
public:
	static Singleton& Intance() {
		static Singleton intance;
		return intance;
	}
	void Out();
};

