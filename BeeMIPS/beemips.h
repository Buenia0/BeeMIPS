#ifndef BEEMIPS_H
#define BEEMIPS_H

#include <iostream>
#include <cstdint>
#include <array>
using namespace std;

namespace beemips
{
    class BeeMIPSInterface
    {
	public:
	    BeeMIPSInterface();
	    ~BeeMIPSInterface();

	    virtual uint32_t readLong(uint32_t addr) = 0;
    };

    class BeeMIPS
    {
	public:
	    BeeMIPS();
	    ~BeeMIPS();

	    void init(uint32_t val);

	    BeeMIPSInterface *inter = NULL;

	    void setinterface(BeeMIPSInterface *cb)
	    {
		inter = cb;
	    }

	    uint32_t readLong(uint32_t addr)
	    {
		if (inter != NULL)
		{
		    return inter->readLong(addr);
		}
		else
		{
		    return 0xFFFFFFFF;
		}
	    }

	    struct pipelinestage
	    {
		bool ispipelinefill = true;
		uint32_t value;

		bool isbranchinst()
		{
		    bool temp = false;
		    int instr = (value >> 26);
		    int spec = (value & 0x1F);

		    if ((instr >= 2) && (instr <= 7))
		    {
			temp = true;
		    }
		    else if (instr == 0)
		    {
			temp = ((spec >= 8) && (spec <= 9));
		    }
		    else
		    {
			temp = false;
		    }

		    return temp;
		}
	    };

	    struct mipsregisters
	    {
		uint32_t r0 = 0;
		uint32_t pc = 0;

		uint32_t getreg(int reg)
		{
		    uint32_t temp = 0;

		    switch (reg)
		    {
			case 0: temp = r0; break;
			default: cout << "Unrecognized register of " << dec << (int)(reg) << endl; exit(1); break;
		    }

		    return temp;
		}

		void setreg(int reg, uint32_t val)
		{
		    switch (reg)
		    {
			case 0: r0 = 0; break;
			default: cout << "Unrecognized register of " << dec << (int)(reg) << endl; exit(1); break;
		    }
		}
	    };

	    mipsregisters mipsreg;

	    struct loadcache
	    {
		bool isloaded = false;
		int regnum = 0;
		uint32_t regvalue = 0;

		void setload(int reg, uint32_t val)
		{
		    isloaded = true;
		    regnum = reg;
		    regvalue = val;
		}

		void clearload()
		{
		    isloaded = false;
		    regnum = 0;
		    regvalue = 0;
		}
	    };

	    loadcache delayslot;

	    void executenextinstr();

	    pipelinestage currentinstr;
	    array<pipelinestage, 2> nextinstr;
    };
};



#endif // BEEMIPS_H
