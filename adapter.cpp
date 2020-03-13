/////////////////////////////////////////////////////////Adapter Pattern////////////////////////////////////////////////////////////////////
//Convert the interface of a class into another interface that clients expect. Adapter lets classes work together that couldn't otherwise because of
//incompatible interfaces.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

class Muslim {  // Abstract Target
	virtual ~Muslim() = default;
	virtual void performsMuslimRitual() = 0;
};

class MuslimFemale : public Muslim {  // Concrete Target
	virtual void performsMuslimRitual() override {std::cout << "Muslim girl performs Muslim ritual." << std::endl;}
};

class Hindu {  // Abstract Adaptee
	virtual ~Hindu() = default;
	virtual void performsHinduRitual() = 0;
};

class HinduFemale : public Hindu {  // Concrete Adaptee
	virtual void performsHinduRitual() override {std::cout << "Hindu girl performs Hindu ritual." << std::endl;}
};

class MuslimRitual {
	void carryOutRitual (Muslim* muslim) {
		std::cout << "On with the Muslim rituals!" << std::endl;
		muslim->performsMuslimRitual();
	}
};

class MuslimAdapter : public Muslim {  // Adapter
	private:
		Hindu* hindu;
	public:
		MuslimAdapter (Hindu* h) : hindu(h) {}
		virtual void performsMuslimRitual() override {hindu->performsHinduRitual();}
};

int main() {  // Client code
	HinduFemale* hinduGirl = new HinduFemale;
	MuslimFemale* muslimGirl = new MuslimFemale;
	MuslimRitual muslimRitual;
//	muslimRitual.carryOutRitual (hinduGirl);  // Will not compile of course since the parameter must be of type Muslim*.
	MuslimAdapter* adaptedHindu = new MuslimAdapter (hinduGirl);  // hinduGirl has adapted to become a Muslim!
	
	muslimRitual.carryOutRitual (muslimGirl);
	muslimRitual.carryOutRitual (adaptedHindu);  // So now hinduGirl, in the form of adaptedHindu, participates in the muslimRitual!
                // Note that hinduGirl is carrying out her own type of ritual in muslimRitual though.
	
	delete adaptedHindu;  // adaptedHindu is not needed anymore
}