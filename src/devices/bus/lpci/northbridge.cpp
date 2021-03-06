// license:BSD-3-Clause
// copyright-holders:Miodrag Milanovic
/***************************************************************************

  Northbridge implementation

***************************************************************************/

#include "emu.h"
#include "northbridge.h"

//**************************************************************************
//  GLOBAL VARIABLES
//**************************************************************************

northbridge_device::northbridge_device(const machine_config& mconfig, device_type type, const char* tag, device_t* owner, uint32_t clock)
	: device_t(mconfig, type, tag, owner, clock),
	m_cpu(*this, finder_base::DUMMY_TAG),
	m_ram(*this, ":" RAM_TAG)
{
}

//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void northbridge_device::device_start()
{
	address_space &space = m_cpu->space(AS_PROGRAM);

	machine().root_device().membank("bank10")->set_base(m_ram->pointer());

	if (m_ram->size() > 0x100000)
	{
		offs_t ram_limit = 0x100000 + m_ram->size() - 0x100000;
		space.install_ram(0x100000, ram_limit - 1, m_ram->pointer() + 0x100000);
	}
}

//-------------------------------------------------
//  device_reset - device-specific reset
//-------------------------------------------------

void northbridge_device::device_reset()
{
}
