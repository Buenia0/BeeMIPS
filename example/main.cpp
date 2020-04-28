#include "beemips.h"
#include <array>
using namespace beemips;
using namespace std;

class Test : public BeeMIPSInterface
{
    public:
	Test();
	~Test();

	array<uint8_t, 0x1000000> memory;

	uint32_t readLong(uint32_t addr)
	{
	    return ((memory[addr + 3] << 24) | (memory[addr + 2] << 16) | (memory[addr + 1] << 8) | (memory[addr]));
	}

	void writeLong(uint32_t addr, uint32_t val)
	{
	    memory[addr] = (val & 0xFF);
	    memory[(addr + 1)] = ((val >> 8) & 0xFF);
	    memory[(addr + 2)] = ((val >> 16) & 0xFF);
	    memory[(addr + 3)] = (val >> 24);
	}	
};

Test::Test()
{

}

Test::~Test()
{

}

Test inter;
BeeMIPS mips;

int main()
{
    mips.setinterface(&inter);
    mips.init(4);

    mips.mipsreg.setreg(1, 0x2);
    inter.writeLong(0x0, 0xFFFFFFFF);
    inter.writeLong(0x4, 0x8C010000);
    inter.writeLong(0x8, 0x000100A1);
    inter.writeLong(0xC, 0x000100E1);

    for (int i = 0; i < 4; i++)
    {
	mips.executenextinstr();
    }

    cout << hex << (int)(mips.mipsreg.getreg(1)) << endl;
    mips.executenextinstr();
    cout << hex << (int)(mips.mipsreg.getreg(1)) << endl;

    mips.init(4);

    mips.mipsreg.setreg(1, 0);
    inter.writeLong(0x0, 0xFFFFFFFF);
    inter.writeLong(0x4, 0x8C010000);
    inter.writeLong(0x8, 0x2401002A);

    for (int i = 0; i < 3; i++)
    {
	mips.executenextinstr();
    }

    cout << hex << (int)(mips.mipsreg.getreg(1)) << endl;
    mips.executenextinstr();
    cout << hex << (int)(mips.mipsreg.getreg(1)) << endl;
    mips.executenextinstr();
    cout << hex << (int)(mips.mipsreg.getreg(1)) << endl;

    return 0;
    
}
