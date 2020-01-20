#include "substance.h"

int main() {
	substance Bor, Telur, CdTe;
	Bor.setName("Bor");
	Telur.setName("Telur");
	CdTe.setName("CdTe");

	Bor.setBandGapWidth(1.1);
	Telur.setBandGapWidth(0.36);
	CdTe.setBandGapWidth(1.45);

	Bor.setElectronMotion(10);
	Telur.setElectronMotion(1700);
	CdTe.setElectronMotion(450);

	Bor.setHoleMotion(10);
	Telur.setHoleMotion(1200);
	CdTe.setHoleMotion(100);

	Bor.show();
	Telur.show();
	CdTe.show();

	substance Bor_and_Telur = Bor + Telur;
	std::cout << std::endl;
	std::cout << "Bor and Telur be like..." << std::endl;
	std::cout << Bor_and_Telur.getName() << "\t" << Bor_and_Telur.getBandGapWidth() << "\t" << Bor_and_Telur.getElectronMotion() << "\t" << Bor_and_Telur.getHoleMotion() << std::endl;

	substance Bor2 = Bor;
	substance Telur2(Telur);
	std::cout << std::boolalpha << std::endl;
	std::cout << "Does Bor2 equal to Bor?" << std::endl;
	std::cout << (Bor2 == Bor) << std::endl;
	std::cout << "Does Telur2 equal to Telur?" << std::endl;
	std::cout << (Telur2 == Telur) << std::endl;
	return 0;
}