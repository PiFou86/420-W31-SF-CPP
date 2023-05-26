#pragma once

class Actionnable {
public:
	virtual bool estAllume() const = 0;
	virtual void allumer() = 0;
	virtual void eteindre() = 0;
};
