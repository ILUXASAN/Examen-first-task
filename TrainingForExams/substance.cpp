#include "substance.h"

//functions
void substance::show()
{
	std::cout << name << "\t" << bandGapWidth << "\t" << electronMotion << "\t" << holeMotion << std::endl;
}

void substance::operator=(const substance original)
{
	setName(original.getName());
	bandGapWidth = original.bandGapWidth;
	electronMotion = original.electronMotion;
	holeMotion = original.holeMotion;
}

bool substance::operator==(const substance& one)
{
	if (bandGapWidth == one.bandGapWidth && electronMotion == one.electronMotion && holeMotion == one.holeMotion) {
		char oneSym = name[0], twoSym = one.name[0];
		for (size_t i = 0; true ; ++i) {
			if (oneSym != twoSym)
				return false;
			if (oneSym == '\0')
				return true;
			oneSym = name[i];
			twoSym = one.name[i];
		}
	}
	return false;
}

//Constructors/Destructors

substance::substance()
{
	name = new char[1];
	name[0] = '\0';
	bandGapWidth = 0.0;
	electronMotion = 0;
	holeMotion = 0;
}

substance::substance(const substance& original)
{
	//operator=(original); //можно так, но не нужно
	setName(original.getName());
	bandGapWidth = original.bandGapWidth;
	electronMotion = original.electronMotion;
	holeMotion = original.holeMotion;
}

substance::~substance()
{
	delete name;
}

//Getters/Setters

char* substance::getName() const
{
	return name;
}

void substance::setName(const char* symLine)
{
	size_t size;
	for (size = 0; symLine[size] != '\0'; ++size);//подсчитываем размер передаваемой строки
	delete name;
	name = new char[size + 1];// создаём новую строку
	for (size_t i = 0; i < size; ++i) {//заполняем новую строку
		name[i] = symLine[i];
	}
	name[size] = '\0';
}

double substance::getBandGapWidth() const
{
	return bandGapWidth;
}

void substance::setBandGapWidth(double number)
{
	bandGapWidth = number;
}

int32_t substance::getElectronMotion() const
{
	return electronMotion;
}

void substance::setElectronMotion(int32_t number)
{
	electronMotion = number;
}

int32_t substance::getHoleMotion() const
{
	return holeMotion;
}

void substance::setHoleMotion(int32_t number)
{
	holeMotion = number;
}

//Overloading operators

substance operator+(const substance& one, const substance& two)
{
	substance local;
	local.bandGapWidth = one.bandGapWidth + two.bandGapWidth;
	local.electronMotion = one.electronMotion + two.electronMotion;
	local.holeMotion = one.holeMotion + two.holeMotion;

	size_t sizeOne, sizeTwo;
	for (sizeOne = 0; one.name[sizeOne] != '\0'; ++sizeOne);//подсчитываем размер первой передаваемой строки
	for (sizeTwo = 0; two.name[sizeTwo] != '\0'; ++sizeTwo);//подсчитываем размер второй передаваемой строки

	delete local.name;
	local.name = new char[sizeOne + sizeTwo + 1];// создаём новую строку
	size_t i= 0;
	while(i < sizeOne) {//заполняем новую строку
		local.name[i] = one.name[i];
		++i;
	}
	while (i < sizeTwo + sizeOne) {//заполняем новую строку вторая часть
		local.name[i] = two.name[i];
		++i;
	}
	local.name[i] = '\0';

	return local;
}
