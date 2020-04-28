#ifndef BEEMIPS_TABLES
#define BEEMIPS_TABLES

#include <array>
#include <unordered_map>
#include <functional>
using namespace std;

namespace beemips
{
    using beemipsfunc = function<void(BeeMIPS*)>;

    void unknowninstr(BeeMIPS *mips)
    {
	cout << "Unrecognized opcode of " << hex << (int)(mips->currentinstr.value) << endl;
	exit(1);
    }

    unordered_map<int, beemipsfunc> insttable =
    {
	{0x00, specialinstr},
	{0x01, unknowninstr},
	{0x02, unknowninstr},
	{0x03, unknowninstr},
	{0x04, unknowninstr},
	{0x05, unknowninstr},
	{0x06, unknowninstr},
	{0x07, unknowninstr},
	{0x08, unknowninstr},
	{0x09, unknowninstr},
	{0x0A, unknowninstr},
	{0x0B, unknowninstr},
	{0x0C, unknowninstr},
	{0x0D, unknowninstr},
	{0x0E, unknowninstr},
	{0x0F, unknowninstr},
	{0x10, unknowninstr},
	{0x11, unknowninstr},
	{0x12, unknowninstr},
	{0x13, unknowninstr},
	{0x14, unknowninstr},
	{0x15, unknowninstr},
	{0x16, unknowninstr},
	{0x17, unknowninstr},
	{0x18, unknowninstr},
	{0x19, unknowninstr},
	{0x1A, unknowninstr},
	{0x1B, unknowninstr},
	{0x1C, unknowninstr},
	{0x1D, unknowninstr},
	{0x1E, unknowninstr},
	{0x1F, unknowninstr},
	{0x20, unknowninstr},
	{0x21, unknowninstr},
	{0x22, unknowninstr},
	{0x23, unknowninstr},
	{0x24, unknowninstr},
	{0x25, unknowninstr},
	{0x26, unknowninstr},
	{0x27, unknowninstr},
	{0x28, unknowninstr},
	{0x29, unknowninstr},
	{0x2A, unknowninstr},
	{0x2B, unknowninstr},
	{0x2C, unknowninstr},
	{0x2D, unknowninstr},
	{0x2E, unknowninstr},
	{0x2F, unknowninstr},
	{0x30, unknowninstr},
	{0x31, unknowninstr},
	{0x32, unknowninstr},
	{0x33, unknowninstr},
	{0x34, unknowninstr},
	{0x35, unknowninstr},
	{0x36, unknowninstr},
	{0x37, unknowninstr},
	{0x38, unknowninstr},
	{0x39, unknowninstr},
	{0x3A, unknowninstr},
	{0x3B, unknowninstr},
	{0x3C, unknowninstr},
	{0x3D, unknowninstr},
	{0x3E, unknowninstr},
	{0x3F, unknowninstr},
    };

    unordered_map<int, beemipsfunc> specinsttable =
    {
	{0x00, unknowninstr},
	{0x01, unknowninstr},
	{0x02, unknowninstr},
	{0x03, unknowninstr},
	{0x04, unknowninstr},
	{0x05, unknowninstr},
	{0x06, unknowninstr},
	{0x07, unknowninstr},
	{0x08, unknowninstr},
	{0x09, unknowninstr},
	{0x0A, unknowninstr},
	{0x0B, unknowninstr},
	{0x0C, unknowninstr},
	{0x0D, unknowninstr},
	{0x0E, unknowninstr},
	{0x0F, unknowninstr},
	{0x10, unknowninstr},
	{0x11, unknowninstr},
	{0x12, unknowninstr},
	{0x13, unknowninstr},
	{0x14, unknowninstr},
	{0x15, unknowninstr},
	{0x16, unknowninstr},
	{0x17, unknowninstr},
	{0x18, unknowninstr},
	{0x19, unknowninstr},
	{0x1A, unknowninstr},
	{0x1B, unknowninstr},
	{0x1C, unknowninstr},
	{0x1D, unknowninstr},
	{0x1E, unknowninstr},
	{0x1F, unknowninstr},
	{0x20, unknowninstr},
	{0x21, unknowninstr},
	{0x22, unknowninstr},
	{0x23, unknowninstr},
	{0x24, unknowninstr},
	{0x25, unknowninstr},
	{0x26, unknowninstr},
	{0x27, unknowninstr},
	{0x28, unknowninstr},
	{0x29, unknowninstr},
	{0x2A, unknowninstr},
	{0x2B, unknowninstr},
	{0x2C, unknowninstr},
	{0x2D, unknowninstr},
	{0x2E, unknowninstr},
	{0x2F, unknowninstr},
	{0x30, unknowninstr},
	{0x31, unknowninstr},
	{0x32, unknowninstr},
	{0x33, unknowninstr},
	{0x34, unknowninstr},
	{0x35, unknowninstr},
	{0x36, unknowninstr},
	{0x37, unknowninstr},
	{0x38, unknowninstr},
	{0x39, unknowninstr},
	{0x3A, unknowninstr},
	{0x3B, unknowninstr},
	{0x3C, unknowninstr},
	{0x3D, unknowninstr},
	{0x3E, unknowninstr},
	{0x3F, unknowninstr},
    };

    void specialinstr(BeeMIPS *mips)
    {
	cout << "Special opcodes" << endl;
	
	int value = (mips->currentinstr & 0x3F);
	specinsttable[value](mips);
    }
};

#endif // BEEMIPS_TABLES
