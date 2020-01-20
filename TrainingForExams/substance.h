#ifndef SUBSTANCE_H
#define SUBSTANCE_H

#include <iostream>
#include <ostream>
class substance
{
private:
	char* name;
	double bandGapWidth;
	int32_t electronMotion;
	int32_t holeMotion;
public:
//functions

	void show();
	void operator=(substance abc);
	bool operator==(const substance& one);
	friend substance operator+(const substance& one, const substance& two);

//Constructors/Destructor

	substance();
	substance(const substance& original);
	~substance();


//Getters/Setters

	char* getName() const;
	void setName(const char*);

	double getBandGapWidth() const;
	void setBandGapWidth(double);

	int32_t getElectronMotion() const;
	void setElectronMotion(int32_t);

	int32_t getHoleMotion() const;
	void setHoleMotion(int32_t);
};

//Overloading operators

substance operator+(const substance& one, const substance& two);

#endif