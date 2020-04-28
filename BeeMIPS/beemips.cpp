#include "beemips.h"
using namespace beemips;

namespace beemips
{
    BeeMIPSInterface::BeeMIPSInterface()
    {

    }

    BeeMIPSInterface::~BeeMIPSInterface()
    {

    }

    BeeMIPS::BeeMIPS()
    {

    }

    BeeMIPS::~BeeMIPS()
    {

    }

    void BeeMIPS::init(uint32_t val)
    {
	mipsreg.pc = val;
    }

    void BeeMIPS::executenextinstr()
    {
	currentinstr = nextinstr[0];
	nextinstr[0] = nextinstr[1];
	nextinstr[1].ispipelinefill = false;
	nextinstr[1].value = readLong(mipsreg.pc);
	mipsreg.pc += 4;

	if (nextinstr[0].isbranchinst())
	{
	    cout << "Branch delay slot" << endl;
	    pipelinestage temp = nextinstr[1];
	    nextinstr[1] = nextinstr[0];
	    nextinstr[0] = temp;
	}

	if (currentinstr.ispipelinefill)
	{
	    cout << "Filling pipeline..." << endl;
	}
	else
	{
	    cout << "Executing instruction of " << hex << (int)(currentinstr.value) << endl;
	    int value = ((currentinstr.value >> 26));
	    insttable[value](this);
	}
    }
};
