#include "BaseMod.h"
#include <Windows.h>
#include <iostream>
#include <MinHook.h>
#include "globals.h"
#include "config.h"

bool myCheckBox = false;
int counter = 0;

//Will run once at game start, use it to setup hooks, offset address, initialize stuff...
void BaseMod::OnAttach() {
	std::cout << "This is a call from test mod attach function! dll handle is : " << mhfdll_addy << std::endl;

	uintptr_t addressBlademasterWeaponID = (uintptr_t)GetModuleHandle + 0xDC6BB52;
	if (MH_CreateHook((LPVOID)addressBlademasterWeaponID, &BaseMod::BlademasterWeaponID, reinterpret_cast<LPVOID*>(&BaseMod::originalBlademasterWeaponID)) != MH_OK) {
		std::cerr << "Failed to create hook for BlademasterWeaponID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressBlademasterWeaponID) != MH_OK) {
		std::cerr << "Failed to enable hook for BlademasterWeaponID" << std::endl;
	}

	/*uintptr_t addressGunnerWeaponID = (uintptr_t)GetModuleHandle + 0xDC6BB92;
	if (MH_CreateHook((LPVOID)addressGunnerWeaponID, &BaseMod::GunnerWeaponID, reinterpret_cast<LPVOID*>(&BaseMod::originalGunnerWeaponID)) != MH_OK) {
		std::cerr << "Failed to create hook for GunnerWeaponID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressGunnerWeaponID) != MH_OK) {
		std::cerr << "Failed to enable hook for GunnerWeaponID" << std::endl;
	}*/

	// Hooking the function mhfo-hd.dll+DC6B753
	uintptr_t addressWeaponType = (uintptr_t)GetModuleHandle + 0xDC6B753;
	if (MH_CreateHook((LPVOID)addressWeaponType, &BaseMod::WeaponType, reinterpret_cast<LPVOID*>(&BaseMod::originalWeaponType)) != MH_OK) {
		std::cerr << "Failed to create hook for WeaponType" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressWeaponType) != MH_OK) {
		std::cerr << "Failed to enable hook for WeaponType" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6C352
	uintptr_t address = (uintptr_t)GetModuleHandle + 0xDC6C352;
	if (MH_CreateHook((LPVOID)address, &BaseMod::AutomaticSkillWeapon, reinterpret_cast<LPVOID*>(&BaseMod::originalAutomaticSkillWeapon)) != MH_OK) {
		std::cerr << "Failed to create hook for AutomaticSkillWeapon" << std::endl;
	}
	if (MH_EnableHook((LPVOID)address) != MH_OK) {
		std::cerr << "Failed to enable hook for AutomaticSkillWeapon" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6BB12
	uintptr_t addressArmorHeadID = (uintptr_t)GetModuleHandle + 0xDC6BB12;
	if (MH_CreateHook((LPVOID)addressArmorHeadID, &BaseMod::ArmorHeadID, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorHeadID)) != MH_OK) {
		std::cerr << "Failed to create hook for ArmorHeadID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressArmorHeadID) != MH_OK) {
		std::cerr << "Failed to enable hook for ArmorHeadID" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6C34A
	uintptr_t addressSkillHead = (uintptr_t)GetModuleHandle + 0xDC6C34A;
	if (MH_CreateHook((LPVOID)addressSkillHead, &BaseMod::AutomaticSkillHead, reinterpret_cast<LPVOID*>(&BaseMod::originalAutomaticSkillHead)) != MH_OK) {
		std::cerr << "Failed to create hook for AutomaticSkillHead" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressSkillHead) != MH_OK) {
		std::cerr << "Failed to enable hook for AutomaticSkillHead" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6BB22
	uintptr_t addressArmorChestID = (uintptr_t)GetModuleHandle + 0xDC6BB22;
	if (MH_CreateHook((LPVOID)addressArmorChestID, &BaseMod::ArmorChestID, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorChestID)) != MH_OK) {
		std::cerr << "Failed to create hook for ArmorChestID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressArmorChestID) != MH_OK) {
		std::cerr << "Failed to enable hook for ArmorChestID" << std::endl;
	}


	// Hooking the function mhfo-hd.dll+DC6C34C
	uintptr_t addressSkillChest = (uintptr_t)GetModuleHandle + 0xDC6C34C;
	if (MH_CreateHook((LPVOID)addressSkillChest, &BaseMod::AutomaticSkillChest, reinterpret_cast<LPVOID*>(&BaseMod::originalAutomaticSkillChest)) != MH_OK) {
		std::cerr << "Failed to create hook for AutomaticSkillChest" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressSkillChest) != MH_OK) {
		std::cerr << "Failed to enable hook for AutomaticSkillChest" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6BB32
	uintptr_t addressArmorArmsID = (uintptr_t)GetModuleHandle + 0xDC6BB32;
	if (MH_CreateHook((LPVOID)addressArmorArmsID, &BaseMod::ArmorArmsID, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorArmsID)) != MH_OK) {
		std::cerr << "Failed to create hook for ArmorArmsID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressArmorArmsID) != MH_OK) {
		std::cerr << "Failed to enable hook for ArmorArmsID" << std::endl;
	}


	// Hooking the function mhfo-hd.dll+DC6C34E
	uintptr_t addressSkillArms = (uintptr_t)GetModuleHandle + 0xDC6C34E;
	if (MH_CreateHook((LPVOID)addressSkillArms, &BaseMod::AutomaticSkillArms, reinterpret_cast<LPVOID*>(&BaseMod::originalAutomaticSkillArms)) != MH_OK) {
		std::cerr << "Failed to create hook for AutomaticSkillArms" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressSkillArms) != MH_OK) {
		std::cerr << "Failed to enable hook for AutomaticSkillArms" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6BB42
	uintptr_t addressArmorWaistID = (uintptr_t)GetModuleHandle + 0xDC6BB42;
	if (MH_CreateHook((LPVOID)addressArmorWaistID, &BaseMod::ArmorWaistID, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorWaistID)) != MH_OK) {
		std::cerr << "Failed to create hook for ArmorWaistID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressArmorWaistID) != MH_OK) {
		std::cerr << "Failed to enable hook for ArmorWaistID" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6C350
	uintptr_t addressSkillWaist = (uintptr_t)GetModuleHandle + 0xDC6C350;
	if (MH_CreateHook((LPVOID)addressSkillWaist, &BaseMod::AutomaticSkillWaist, reinterpret_cast<LPVOID*>(&BaseMod::originalAutomaticSkillWaist)) != MH_OK) {
		std::cerr << "Failed to create hook for AutomaticSkillWaist" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressSkillWaist) != MH_OK) {
		std::cerr << "Failed to enable hook for AutomaticSkillWaist" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6BAF2
	uintptr_t addressArmorLegsID = (uintptr_t)GetModuleHandle + 0xDC6BAF2;
	if (MH_CreateHook((LPVOID)addressArmorLegsID, &BaseMod::ArmorLegsID, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorLegsID)) != MH_OK) {
		std::cerr << "Failed to create hook for ArmorLegsID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressArmorLegsID) != MH_OK) {
		std::cerr << "Failed to enable hook for ArmorLegsID" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6C346
	uintptr_t addressSkillLegs = (uintptr_t)GetModuleHandle + 0xDC6C346;
	if (MH_CreateHook((LPVOID)addressSkillLegs, &BaseMod::AutomaticSkillLegs, reinterpret_cast<LPVOID*>(&BaseMod::originalAutomaticSkillLegs)) != MH_OK) {
		std::cerr << "Failed to create hook for AutomaticSkillLegs" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressSkillLegs) != MH_OK) {
		std::cerr << "Failed to enable hook for AutomaticSkillLegs" << std::endl;
	}

	// Hooking the function mhfo-hd.dll+DC6BF48
	uintptr_t addressAreaID = (uintptr_t)GetModuleHandle + 0xDC6BF48;
	if (MH_CreateHook((LPVOID)addressAreaID, &BaseMod::AreaID, reinterpret_cast<LPVOID*>(&BaseMod::originalAreaID)) != MH_OK) {
		std::cerr << "Failed to create hook for AreaID" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressAreaID) != MH_OK) {
		std::cerr << "Failed to enable hook for AreaID" << std::endl;
	}

		std::cout << "This is a call from test mod attach function! dll handle is : " << mhfdll_addy << std::endl;
	uintptr_t addressHunterHP = (uintptr_t)GetModuleHandle + 0xE7FE178;
	if (MH_CreateHook((LPVOID)addressHunterHP, &BaseMod::HunterHP, reinterpret_cast<LPVOID*>(&BaseMod::originalHunterHP)) != MH_OK) {
		std::cerr << "Failed to create hook for HunterHP" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressHunterHP) != MH_OK) {
		std::cerr << "Failed to enable hook for HunterHP" << std::endl;
	}

	uintptr_t addressPartySize = (uintptr_t)GetModuleHandle + 0xE3CE388;
	if (MH_CreateHook((LPVOID)addressPartySize, &BaseMod::PartySize, reinterpret_cast<LPVOID*>(&BaseMod::originalPartySize)) != MH_OK) {
		std::cerr << "Failed to create hook for PartySize" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressPartySize) != MH_OK) {
		std::cerr << "Failed to enable hook for PartySize" << std::endl;
	}

	uintptr_t addressPartySizeMax = (uintptr_t)GetModuleHandle + 0xEDF0828;
	if (MH_CreateHook((LPVOID)addressPartySizeMax, &BaseMod::PartySizeMax, reinterpret_cast<LPVOID*>(&BaseMod::originalPartySizeMax)) != MH_OK) {
		std::cerr << "Failed to create hook for PartySizeMax" << std::endl;
	}
	if (MH_EnableHook((LPVOID)addressPartySizeMax) != MH_OK) {
		std::cerr << "Failed to enable hook for PartySizeMax" << std::endl;
	}

uintptr_t addressPlayerPositionX = (uintptr_t)GetModuleHandle + 0xE8E6640;
if (MH_CreateHook((LPVOID)addressPlayerPositionX, &BaseMod::PlayerPositionX, reinterpret_cast<LPVOID*>(&BaseMod::originalPlayerPositionX)) != MH_OK) {
	std::cerr << "Failed to create hook for PlayerPositionX" << std::endl;
}
if (MH_EnableHook((LPVOID)addressPlayerPositionX) != MH_OK) {
	std::cerr << "Failed to enable hook for PlayerPositionX" << std::endl;
}

uintptr_t addressPlayerPositionY = (uintptr_t)GetModuleHandle + 0xE8E6644;
if (MH_CreateHook((LPVOID)addressPlayerPositionY, &BaseMod::PlayerPositionY, reinterpret_cast<LPVOID*>(&BaseMod::originalPlayerPositionY)) != MH_OK) {
	std::cerr << "Failed to create hook for PlayerPositionY" << std::endl;
}
if (MH_EnableHook((LPVOID)addressPlayerPositionY) != MH_OK) {
	std::cerr << "Failed to enable hook for PlayerPositionY" << std::endl;
}

uintptr_t addressPlayerPositionZ = (uintptr_t)GetModuleHandle + 0xE8E6648;
if (MH_CreateHook((LPVOID)addressPlayerPositionZ, &BaseMod::PlayerPositionZ, reinterpret_cast<LPVOID*>(&BaseMod::originalPlayerPositionZ)) != MH_OK) {
	std::cerr << "Failed to create hook for PlayerPositionZ" << std::endl;
}
if (MH_EnableHook((LPVOID)addressPlayerPositionZ) != MH_OK) {
	std::cerr << "Failed to enable hook for PlayerPositionZ" << std::endl;

}

uintptr_t addressWeaponRaw = (uintptr_t)GetModuleHandle + 0xDC6BEFA;
if (MH_CreateHook((LPVOID)addressWeaponRaw, &BaseMod::WeaponRaw, reinterpret_cast<LPVOID*>(&BaseMod::originalWeaponRaw)) != MH_OK) {
	std::cerr << "Failed to create hook for WeaponRaw" << std::endl;
}
if (MH_EnableHook((LPVOID)addressWeaponRaw) != MH_OK) {
	std::cerr << "Failed to enable hook for WeaponRaw" << std::endl;
}

uintptr_t addressArmorSkill1 = (uintptr_t)GetModuleHandle + 0xDC6C31C;
if (MH_CreateHook((LPVOID)addressArmorSkill1, &BaseMod::ArmorSkill1, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill1)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill1" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill1) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill1" << std::endl;
}

uintptr_t addressArmorSkill2 = (uintptr_t)GetModuleHandle + 0xDC6C31E;
if (MH_CreateHook((LPVOID)addressArmorSkill2, &BaseMod::ArmorSkill2, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill2)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill2" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill2) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill2" << std::endl;
}

uintptr_t addressArmorSkill3 = (uintptr_t)GetModuleHandle + 0xDC6C320;
if (MH_CreateHook((LPVOID)addressArmorSkill3, &BaseMod::ArmorSkill3, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill3)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill3" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill3) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill3" << std::endl;
}

uintptr_t addressArmorSkill4 = (uintptr_t)GetModuleHandle + 0xDC6C322;
if (MH_CreateHook((LPVOID)addressArmorSkill4, &BaseMod::ArmorSkill4, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill4)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill4" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill4) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill4" << std::endl;
}

uintptr_t addressArmorSkill5 = (uintptr_t)GetModuleHandle + 0xDC6C324;
if (MH_CreateHook((LPVOID)addressArmorSkill5, &BaseMod::ArmorSkill5, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill5)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill5" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill5) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill5" << std::endl;
}

uintptr_t addressArmorSkill6 = (uintptr_t)GetModuleHandle + 0xDC6C326;
if (MH_CreateHook((LPVOID)addressArmorSkill6, &BaseMod::ArmorSkill6, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill6)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill6" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill6) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill6" << std::endl;
}

uintptr_t addressArmorSkill7 = (uintptr_t)GetModuleHandle + 0xDC6C328;
if (MH_CreateHook((LPVOID)addressArmorSkill7, &BaseMod::ArmorSkill7, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill7)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill7" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill7) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill7" << std::endl;
}

uintptr_t addressArmorSkill8 = (uintptr_t)GetModuleHandle + 0xDC6C32A;
if (MH_CreateHook((LPVOID)addressArmorSkill8, &BaseMod::ArmorSkill8, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill8)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill8" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill8) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill8" << std::endl;
}

uintptr_t addressArmorSkill9 = (uintptr_t)GetModuleHandle + 0xDC6C32C;
if (MH_CreateHook((LPVOID)addressArmorSkill9, &BaseMod::ArmorSkill9, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill9)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill9" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill9) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill9" << std::endl;
}

uintptr_t addressArmorSkill10 = (uintptr_t)GetModuleHandle + 0xDC6C32E;
if (MH_CreateHook((LPVOID)addressArmorSkill10, &BaseMod::ArmorSkill10, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill10)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill10" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill10) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill10" << std::endl;
}

uintptr_t addressArmorSkill11 = (uintptr_t)GetModuleHandle + 0xDC6C330;
if (MH_CreateHook((LPVOID)addressArmorSkill11, &BaseMod::ArmorSkill11, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill11)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill11" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill11) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill11" << std::endl;
}

uintptr_t addressArmorSkill12 = (uintptr_t)GetModuleHandle + 0xDC6C332;
if (MH_CreateHook((LPVOID)addressArmorSkill12, &BaseMod::ArmorSkill12, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill12)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill12" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill12) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill12" << std::endl;
}

uintptr_t addressArmorSkill13 = (uintptr_t)GetModuleHandle + 0xDC6C334;
if (MH_CreateHook((LPVOID)addressArmorSkill13, &BaseMod::ArmorSkill13, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill13)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill13" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill13) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill13" << std::endl;
}

uintptr_t addressArmorSkill14 = (uintptr_t)GetModuleHandle + 0xDC6C336;
if (MH_CreateHook((LPVOID)addressArmorSkill14, &BaseMod::ArmorSkill14, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill14)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill14" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill14) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill14" << std::endl;
}

uintptr_t addressArmorSkill15 = (uintptr_t)GetModuleHandle + 0xDC6C338;
if (MH_CreateHook((LPVOID)addressArmorSkill15, &BaseMod::ArmorSkill15, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill15)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill15" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill15) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill15" << std::endl;
}

uintptr_t addressArmorSkill16 = (uintptr_t)GetModuleHandle + 0xDC6C33A;
if (MH_CreateHook((LPVOID)addressArmorSkill16, &BaseMod::ArmorSkill16, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill16)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill16" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill16) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill16" << std::endl;
}

uintptr_t addressArmorSkill17 = (uintptr_t)GetModuleHandle + 0xDC6C33C;
if (MH_CreateHook((LPVOID)addressArmorSkill17, &BaseMod::ArmorSkill17, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill17)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill17" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill17) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill17" << std::endl;
}

uintptr_t addressArmorSkill18 = (uintptr_t)GetModuleHandle + 0xDC6C33E;
if (MH_CreateHook((LPVOID)addressArmorSkill18, &BaseMod::ArmorSkill18, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill18)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill18" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill18) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill18" << std::endl;
}

uintptr_t addressArmorSkill19 = (uintptr_t)GetModuleHandle + 0xDC6C340;
if (MH_CreateHook((LPVOID)addressArmorSkill19, &BaseMod::ArmorSkill19, reinterpret_cast<LPVOID*>(&BaseMod::originalArmorSkill19)) != MH_OK) {
	std::cerr << "Failed to create hook for ArmorSkill19" << std::endl;
}
if (MH_EnableHook((LPVOID)addressArmorSkill19) != MH_OK) {
	std::cerr << "Failed to enable hook for ArmorSkill19" << std::endl;
}

uintptr_t addressZenithSkill1 = (uintptr_t)GetModuleHandle + 0xDCD1DC8;
if (MH_CreateHook((LPVOID)addressZenithSkill1, &BaseMod::ZenithSkill1, reinterpret_cast<LPVOID*>(&BaseMod::originalZenithSkill1)) != MH_OK) {
	std::cerr << "Failed to create hook for ZenithSkill1" << std::endl;
}
if (MH_EnableHook((LPVOID)addressZenithSkill1) != MH_OK) {
	std::cerr << "Failed to enable hook for ZenithSkill1" << std::endl;
}

uintptr_t addressZenithSkill2 = (uintptr_t)GetModuleHandle + 0xDCD1DCA;
if (MH_CreateHook((LPVOID)addressZenithSkill2, &BaseMod::ZenithSkill2, reinterpret_cast<LPVOID*>(&BaseMod::originalZenithSkill2)) != MH_OK) {
	std::cerr << "Failed to create hook for ZenithSkill2" << std::endl;
}
if (MH_EnableHook((LPVOID)addressZenithSkill2) != MH_OK) {
	std::cerr << "Failed to enable hook for ZenithSkill2" << std::endl;
}

uintptr_t addressZenithSkill3 = (uintptr_t)GetModuleHandle + 0xDCD1DCC;
if (MH_CreateHook((LPVOID)addressZenithSkill3, &BaseMod::ZenithSkill3, reinterpret_cast<LPVOID*>(&BaseMod::originalZenithSkill3)) != MH_OK) {
	std::cerr << "Failed to create hook for ZenithSkill3" << std::endl;
}
if (MH_EnableHook((LPVOID)addressZenithSkill3) != MH_OK) {
	std::cerr << "Failed to enable hook for ZenithSkill3" << std::endl;
}

uintptr_t addressZenithSkill4 = (uintptr_t)GetModuleHandle + 0xDCD1DCE;
if (MH_CreateHook((LPVOID)addressZenithSkill4, &BaseMod::ZenithSkill4, reinterpret_cast<LPVOID*>(&BaseMod::originalZenithSkill4)) != MH_OK) {
	std::cerr << "Failed to create hook for ZenithSkill4" << std::endl;
}
if (MH_EnableHook((LPVOID)addressZenithSkill4) != MH_OK) {
	std::cerr << "Failed to enable hook for ZenithSkill4" << std::endl;
}

uintptr_t addressZenithSkill5 = (uintptr_t)GetModuleHandle + 0xDCD1DD0;
if (MH_CreateHook((LPVOID)addressZenithSkill5, &BaseMod::ZenithSkill5, reinterpret_cast<LPVOID*>(&BaseMod::originalZenithSkill5)) != MH_OK) {
	std::cerr << "Failed to create hook for ZenithSkill5" << std::endl;
}
if (MH_EnableHook((LPVOID)addressZenithSkill5) != MH_OK) {
	std::cerr << "Failed to enable hook for ZenithSkill5" << std::endl;
}

uintptr_t addressZenithSkill6 = (uintptr_t)GetModuleHandle + 0xDCD1DD2;
if (MH_CreateHook((LPVOID)addressZenithSkill6, &BaseMod::ZenithSkill6, reinterpret_cast<LPVOID*>(&BaseMod::originalZenithSkill6)) != MH_OK) {
	std::cerr << "Failed to create hook for ZenithSkill6" << std::endl;
}
if (MH_EnableHook((LPVOID)addressZenithSkill6) != MH_OK) {
	std::cerr << "Failed to enable hook for ZenithSkill6" << std::endl;
}

uintptr_t addressZenithSkill7 = (uintptr_t)GetModuleHandle + 0xDCD1DD4;
if (MH_CreateHook((LPVOID)addressZenithSkill7, &BaseMod::ZenithSkill7, reinterpret_cast<LPVOID*>(&BaseMod::originalZenithSkill7)) != MH_OK) {
	std::cerr << "Failed to create hook for ZenithSkill7" << std::endl;
}
if (MH_EnableHook((LPVOID)addressZenithSkill7) != MH_OK) {
	std::cerr << "Failed to enable hook for ZenithSkill7" << std::endl;
}

uintptr_t addressDivaSkill = (uintptr_t)GetModuleHandle + 0xE6CCF24;
if (MH_CreateHook((LPVOID)addressDivaSkill, &BaseMod::DivaSkill, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaSkill)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaSkill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaSkill) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaSkill" << std::endl;
}

uintptr_t addressDivaSkillUsesLeft = (uintptr_t)GetModuleHandle + 0xED3EB0A;
if (MH_CreateHook((LPVOID)addressDivaSkillUsesLeft, &BaseMod::DivaSkillUsesLeft, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaSkillUsesLeft)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaSkillUsesLeft" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaSkillUsesLeft) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaSkillUsesLeft" << std::endl;
}

uintptr_t addressDivaPrayerGemRedSkill = (uintptr_t)GetModuleHandle + 0xE6CCF14;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemRedSkill, &BaseMod::DivaPrayerGemRedSkill, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemRedSkill)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemRedSkill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemRedSkill) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemRedSkill" << std::endl;
}

uintptr_t addressDivaPrayerGemRedLevel = (uintptr_t)GetModuleHandle + 0xE6CCF16;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemRedLevel, &BaseMod::DivaPrayerGemRedLevel, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemRedLevel)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemRedLevel" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemRedLevel) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemRedLevel" << std::endl;
}

uintptr_t addressDivaPrayerGemYellowSkill = (uintptr_t)GetModuleHandle + 0xE6CCF18;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemYellowSkill, &BaseMod::DivaPrayerGemYellowSkill, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemYellowSkill)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemYellowSkill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemYellowSkill) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemYellowSkill" << std::endl;
}

uintptr_t addressDivaPrayerGemYellowLevel = (uintptr_t)GetModuleHandle + 0xE6CCF1A;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemYellowLevel, &BaseMod::DivaPrayerGemYellowLevel, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemYellowLevel)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemYellowLevel" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemYellowLevel) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemYellowLevel" << std::endl;
}

uintptr_t addressDivaPrayerGemGreenSkill = (uintptr_t)GetModuleHandle + 0xE6CCF1C;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemGreenSkill, &BaseMod::DivaPrayerGemGreenSkill, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemGreenSkill)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemGreenSkill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemGreenSkill) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemGreenSkill" << std::endl;
}

uintptr_t addressDivaPrayerGemGreenLevel = (uintptr_t)GetModuleHandle + 0xE6CCF1E;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemGreenLevel, &BaseMod::DivaPrayerGemGreenLevel, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemGreenLevel)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemGreenLevel" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemGreenLevel) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemGreenLevel" << std::endl;
}

uintptr_t addressDivaPrayerGemBlueSkill = (uintptr_t)GetModuleHandle + 0xE6CCF20;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemBlueSkill, &BaseMod::DivaPrayerGemBlueSkill, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemBlueSkill)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemBlueSkill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemBlueSkill) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemBlueSkill" << std::endl;
}

uintptr_t addressDivaPrayerGemBlueLevel = (uintptr_t)GetModuleHandle + 0xE6CCF22;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemBlueLevel, &BaseMod::DivaPrayerGemBlueLevel, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemBlueLevel)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemBlueLevel" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemBlueLevel) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemBlueLevel" << std::endl;
}

uintptr_t addressGuildPoogie1Skill = (uintptr_t)GetModuleHandle + 0xE76BBDB;
if (MH_CreateHook((LPVOID)addressGuildPoogie1Skill, &BaseMod::GuildPoogie1Skill, reinterpret_cast<LPVOID*>(&BaseMod::originalGuildPoogie1Skill)) != MH_OK) {
    std::cerr << "Failed to create hook for GuildPoogie1Skill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressGuildPoogie1Skill) != MH_OK) {
    std::cerr << "Failed to enable hook for GuildPoogie1Skill" << std::endl;
}

uintptr_t addressGuildPoogie2Skill = (uintptr_t)GetModuleHandle + 0xE76BBEB;
if (MH_CreateHook((LPVOID)addressGuildPoogie2Skill, &BaseMod::GuildPoogie2Skill, reinterpret_cast<LPVOID*>(&BaseMod::originalGuildPoogie2Skill)) != MH_OK) {
    std::cerr << "Failed to create hook for GuildPoogie2Skill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressGuildPoogie2Skill) != MH_OK) {
    std::cerr << "Failed to enable hook for GuildPoogie2Skill" << std::endl;
}

uintptr_t addressGuildPoogie3Skill = (uintptr_t)GetModuleHandle + 0xE76BBFB;
if (MH_CreateHook((LPVOID)addressGuildPoogie3Skill, &BaseMod::GuildPoogie3Skill, reinterpret_cast<LPVOID*>(&BaseMod::originalGuildPoogie3Skill)) != MH_OK) {
    std::cerr << "Failed to create hook for GuildPoogie3Skill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressGuildPoogie3Skill) != MH_OK) {
    std::cerr << "Failed to enable hook for GuildPoogie3Skill" << std::endl;
}

uintptr_t addressGuildFoodSkill = (uintptr_t)GetModuleHandle + 0xE6CCD9E;
if (MH_CreateHook((LPVOID)addressGuildFoodSkill, &BaseMod::GuildFoodSkill, reinterpret_cast<LPVOID*>(&BaseMod::originalGuildFoodSkill)) != MH_OK) {
    std::cerr << "Failed to create hook for GuildFoodSkill" << std::endl;
}
if (MH_EnableHook((LPVOID)addressGuildFoodSkill) != MH_OK) {
    std::cerr << "Failed to enable hook for GuildFoodSkill" << std::endl;
}

uintptr_t addressGuildFoodStart = (uintptr_t)GetModuleHandle + 0xE7FED08;
if (MH_CreateHook((LPVOID)addressGuildFoodStart, &BaseMod::GuildFoodStart, reinterpret_cast<LPVOID*>(&BaseMod::originalGuildFoodStart)) != MH_OK) {
    std::cerr << "Failed to create hook for GuildFoodStart" << std::endl;
}
if (MH_EnableHook((LPVOID)addressGuildFoodStart) != MH_OK) {
    std::cerr << "Failed to enable hook for GuildFoodStart" << std::endl;
}

uintptr_t addressDivaPrayerGemStart = (uintptr_t)GetModuleHandle + 0xE820DF8;
if (MH_CreateHook((LPVOID)addressDivaPrayerGemStart, &BaseMod::DivaPrayerGemStart, reinterpret_cast<LPVOID*>(&BaseMod::originalDivaPrayerGemStart)) != MH_OK) {
    std::cerr << "Failed to create hook for DivaPrayerGemStart" << std::endl;
}
if (MH_EnableHook((LPVOID)addressDivaPrayerGemStart) != MH_OK) {
    std::cerr << "Failed to enable hook for DivaPrayerGemStart" << std::endl;
}


} // End of OnAttach()


//Will run once at game end, loader doesn't use it for now
void BaseMod::OnDetach() {

}

//Will run once the ImGUI and Dx9 Context has been initialized, use this function to create texture data
void BaseMod::OnImGUIInit() {

}

//Has access to the main ImGui context, can draw anything related to the mod in there
void BaseMod::DrawModMenu() {
	if (ImGui::CollapsingHeader(DISPLAY_NAME.c_str())) {
		if (ImGui::BeginTabBar("Player Info Tabs")) {
			if (ImGui::BeginTabItem("General Info")) {
				ImGui::Text("Hunter HP: %d", BaseMod::HunterHP());
				ImGui::Text("Total Raw: %d", BaseMod::WeaponRaw());
				ImGui::Text("");
				ImGui::Text("Party Size: %d / %d", BaseMod::PartySize(), BaseMod::PartySizeMax());
				ImGui::Text("");
				ImGui::Text("Area ID: %d", BaseMod::AreaID());
				ImGui::Text("Position: X: %f, Y: %f, Z: %f", BaseMod::PlayerPositionX(), BaseMod::PlayerPositionY(), BaseMod::PlayerPositionZ());
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Weapon Info")) {
				ImGui::Text("Weapon Type: %d", BaseMod::WeaponType());
				ImGui::Text("");
				if (BaseMod::WeaponType() == 5 || BaseMod::WeaponType() == 1 || BaseMod::WeaponType() == 10) {
					ImGui::Text("Gunner Weapon ID: %d", BaseMod::BlademasterWeaponID());
				} else {
					ImGui::Text("Blademaster Weapon ID: %d", BaseMod::BlademasterWeaponID());
				}
				ImGui::Text("Automatic Skill Weapon: %d", BaseMod::AutomaticSkillWeapon());
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Armor Info")) {
				ImGui::Text("Head ID: %d", BaseMod::ArmorHeadID());
				ImGui::Text("Automatic Skill Head: %d", BaseMod::AutomaticSkillHead());
				ImGui::Text("");
				ImGui::Text("Chest ID: %d", BaseMod::ArmorChestID());
				ImGui::Text("Automatic Skill Chest: %d", BaseMod::AutomaticSkillChest());
				ImGui::Text("");
				ImGui::Text("Arms ID: %d", BaseMod::ArmorArmsID());
				ImGui::Text("Automatic Skill Arms: %d", BaseMod::AutomaticSkillArms());
				ImGui::Text("");
				ImGui::Text("Waist ID: %d", BaseMod::ArmorWaistID());
				ImGui::Text("Automatic Skill Waist: %d", BaseMod::AutomaticSkillWaist());
				ImGui::Text("");
				ImGui::Text("Legs ID: %d", BaseMod::ArmorLegsID());
				ImGui::Text("Automatic Skill Legs: %d", BaseMod::AutomaticSkillLegs());
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Armor Skills")) {
				ImGui::Text("Armor Skill 1: %d", BaseMod::ArmorSkill1());
				ImGui::Text("Armor Skill 2: %d", BaseMod::ArmorSkill2());
				ImGui::Text("Armor Skill 3: %d", BaseMod::ArmorSkill3());
				ImGui::Text("Armor Skill 4: %d", BaseMod::ArmorSkill4());
				ImGui::Text("Armor Skill 5: %d", BaseMod::ArmorSkill5());
				ImGui::Text("Armor Skill 6: %d", BaseMod::ArmorSkill6());
				ImGui::Text("Armor Skill 7: %d", BaseMod::ArmorSkill7());
				ImGui::Text("Armor Skill 8: %d", BaseMod::ArmorSkill8());
				ImGui::Text("Armor Skill 9: %d", BaseMod::ArmorSkill9());
				ImGui::Text("Armor Skill 10: %d", BaseMod::ArmorSkill10());
				ImGui::Text("Armor Skill 11: %d", BaseMod::ArmorSkill11());
				ImGui::Text("Armor Skill 12: %d", BaseMod::ArmorSkill12());
				ImGui::Text("Armor Skill 13: %d", BaseMod::ArmorSkill13());
				ImGui::Text("Armor Skill 14: %d", BaseMod::ArmorSkill14());
				ImGui::Text("Armor Skill 15: %d", BaseMod::ArmorSkill15());
				ImGui::Text("Armor Skill 16: %d", BaseMod::ArmorSkill16());
				ImGui::Text("Armor Skill 17: %d", BaseMod::ArmorSkill17());
				ImGui::Text("Armor Skill 18: %d", BaseMod::ArmorSkill18());
				ImGui::Text("Armor Skill 19: %d", BaseMod::ArmorSkill19());
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Zenith Skills")) {
				ImGui::Text("Zenith Skill 1: %d", BaseMod::ZenithSkill1());
				ImGui::Text("Zenith Skill 2: %d", BaseMod::ZenithSkill2());
				ImGui::Text("Zenith Skill 3: %d", BaseMod::ZenithSkill3());
				ImGui::Text("Zenith Skill 4: %d", BaseMod::ZenithSkill4());
				ImGui::Text("Zenith Skill 5: %d", BaseMod::ZenithSkill5());
				ImGui::Text("Zenith Skill 6: %d", BaseMod::ZenithSkill6());
				ImGui::Text("Zenith Skill 7: %d", BaseMod::ZenithSkill7());
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Diva Defense")) {
				ImGui::Text("Diva Skill: %d, Uses Left: %d", BaseMod::DivaSkill(), BaseMod::DivaSkillUsesLeft());
				ImGui::Text("");
				ImGui::Text("Diva Prayer Gem Timer: %d", BaseMod::DivaPrayerGemStart());
				ImGui::Text("");
				ImGui::Text("Diva Prayer Gem Red: %d, Level: %d", BaseMod::DivaPrayerGemRedSkill(), BaseMod::DivaPrayerGemRedLevel());
				ImGui::Text("Diva Prayer Gem Yellow: %d, Level: %d", BaseMod::DivaPrayerGemYellowSkill(), BaseMod::DivaPrayerGemYellowLevel());
				ImGui::Text("Diva Prayer Gem Green: %d, Level: %d", BaseMod::DivaPrayerGemGreenSkill(), BaseMod::DivaPrayerGemGreenLevel());
				ImGui::Text("Diva Prayer Gem Blue: %d, Level: %d", BaseMod::DivaPrayerGemBlueSkill(), BaseMod::DivaPrayerGemBlueLevel());
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Guild Skills")) {
				ImGui::Text("Guild Food Skill: %d, Timer: %d", BaseMod::GuildFoodSkill(), BaseMod::GuildFoodStart());
				ImGui::Text("");
				if (BaseMod::GuildPoogie1Skill() != 0) {
					ImGui::Text("Guild Poogie 1: %d", BaseMod::GuildPoogie1Skill());
				}
				if (BaseMod::GuildPoogie2Skill() != 0) {
					ImGui::Text("Guild Poogie 2: %d", BaseMod::GuildPoogie2Skill());
				}
				if (BaseMod::GuildPoogie3Skill() != 0) {
					ImGui::Text("Guild Poogie 3: %d", BaseMod::GuildPoogie3Skill());
				}
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}



	}
}


void BaseMod::DrawUI(bool show_menu) {

}

//TO DO: Will hook the main lobby update function and run once every game frame
void BaseMod::OnUpdateLobby() {

}

//Will hook the main quest update function and run once every game frame
void BaseMod::OnUpdateQuest() {
	counter++;
}

extern "C" {
	__declspec(dllexport) Mod* createMod() {
		return new BaseMod(NAME, DISPLAY_NAME, VERSION, REQUIRED_VERSION, HGE_ONLY);
	}
}

inline int BaseMod::WeaponType() {
	return *(short*)(mhfdll_addy + 0xDC6B753);
}
int (*BaseMod::originalWeaponType)();

int BaseMod::BlademasterWeaponID() {
	return *(short*)(mhfdll_addy + 0xDC6BB52);
}
int (*BaseMod::originalBlademasterWeaponID)();

int BaseMod::AutomaticSkillWeapon() {
	return *(short*)(mhfdll_addy + 0xDC6C352);
}
int (*BaseMod::originalAutomaticSkillWeapon)();

int BaseMod::WeaponRaw() {
	return *(short*)(mhfdll_addy + 0xDC6BEFA);
}
int (*BaseMod::originalWeaponRaw)();

int BaseMod::ArmorHeadID() {
	return *(short*)(mhfdll_addy + 0xDC6BB12);
}
int (*BaseMod::originalArmorHeadID)();

int BaseMod::AutomaticSkillHead() {
	return *(short*)(mhfdll_addy + 0xDC6C34A);
}
int (*BaseMod::originalAutomaticSkillHead)();

int BaseMod::ArmorChestID() {
	return *(short*)(mhfdll_addy + 0xDC6BB22);
}
int (*BaseMod::originalArmorChestID)();

int BaseMod::AutomaticSkillChest() {
	return *(short*)(mhfdll_addy + 0xDC6C34C);
}
int (*BaseMod::originalAutomaticSkillChest)();

int BaseMod::ArmorArmsID() {
	return *(short*)(mhfdll_addy + 0xDC6BB32);
}
int (*BaseMod::originalArmorArmsID)();

int BaseMod::AutomaticSkillArms() {
	return *(short*)(mhfdll_addy + 0xDC6C34E);
}
int (*BaseMod::originalAutomaticSkillArms)();

int BaseMod::ArmorWaistID() {
	return *(short*)(mhfdll_addy + 0xDC6BB42);
}
int (*BaseMod::originalArmorWaistID)();

int BaseMod::AutomaticSkillWaist() {
	return *(short*)(mhfdll_addy + 0xDC6C350);
}
int (*BaseMod::originalAutomaticSkillWaist)();

int BaseMod::ArmorLegsID() {
	return *(short*)(mhfdll_addy + 0xDC6BAF2);
}
int (*BaseMod::originalArmorLegsID)();

int BaseMod::AutomaticSkillLegs() {
	return *(short*)(mhfdll_addy + 0xDC6C346);
}
int (*BaseMod::originalAutomaticSkillLegs)();

int BaseMod::AreaID() {
	return *(short*)(mhfdll_addy + 0xDC6BF48);
}
int (*BaseMod::originalAreaID)();

int BaseMod::HunterHP() {
    return *(short*)(mhfdll_addy + 0xE7FE178);
}
int (*BaseMod::originalHunterHP)();

int BaseMod::PartySize() {
    return *(short*)(mhfdll_addy + 0xE3CE388);
}
int (*BaseMod::originalPartySize)();

int BaseMod::PartySizeMax() {
    return *(short*)(mhfdll_addy + 0xEDF0828);
}
int (*BaseMod::originalPartySizeMax)();

float BaseMod::PlayerPositionX() {
    return *(float*)(mhfdll_addy + 0xE8E6640);
}
float (*BaseMod::originalPlayerPositionX)();

float BaseMod::PlayerPositionY() {
    return *(float*)(mhfdll_addy + 0xE8E6644);
}
float (*BaseMod::originalPlayerPositionY)();

float BaseMod::PlayerPositionZ() {
    return *(float*)(mhfdll_addy + 0xE8E6648);
}
float (*BaseMod::originalPlayerPositionZ)();

int BaseMod::ArmorSkill1() {
    return *(short*)(mhfdll_addy + 0xDC6C300);
}
int (*BaseMod::originalArmorSkill1)();

int BaseMod::ArmorSkill2() {
    return *(short*)(mhfdll_addy + 0xDC6C302);
}
int (*BaseMod::originalArmorSkill2)();

int BaseMod::ArmorSkill3() {
    return *(short*)(mhfdll_addy + 0xDC6C304);
}
int (*BaseMod::originalArmorSkill3)();

int BaseMod::ArmorSkill4() {
    return *(short*)(mhfdll_addy + 0xDC6C306);
}
int (*BaseMod::originalArmorSkill4)();

int BaseMod::ArmorSkill5() {
    return *(short*)(mhfdll_addy + 0xDC6C308);
}
int (*BaseMod::originalArmorSkill5)();

int BaseMod::ArmorSkill6() {
    return *(short*)(mhfdll_addy + 0xDC6C30A);
}
int (*BaseMod::originalArmorSkill6)();

int BaseMod::ArmorSkill7() {
    return *(short*)(mhfdll_addy + 0xDC6C30C);
}
int (*BaseMod::originalArmorSkill7)();

int BaseMod::ArmorSkill8() {
    return *(short*)(mhfdll_addy + 0xDC6C30E);
}
int (*BaseMod::originalArmorSkill8)();

int BaseMod::ArmorSkill9() {
    return *(short*)(mhfdll_addy + 0xDC6C310);
}
int (*BaseMod::originalArmorSkill9)();

int BaseMod::ArmorSkill10() {
    return *(short*)(mhfdll_addy + 0xDC6C312);
}
int (*BaseMod::originalArmorSkill10)();

int BaseMod::ArmorSkill11() {
    return *(short*)(mhfdll_addy + 0xDC6C314);
}
int (*BaseMod::originalArmorSkill11)();

int BaseMod::ArmorSkill12() {
    return *(short*)(mhfdll_addy + 0xDC6C316);
}
int (*BaseMod::originalArmorSkill12)();

int BaseMod::ArmorSkill13() {
    return *(short*)(mhfdll_addy + 0xDC6C318);
}
int (*BaseMod::originalArmorSkill13)();

int BaseMod::ArmorSkill14() {
    return *(short*)(mhfdll_addy + 0xDC6C31A);
}
int (*BaseMod::originalArmorSkill14)();

int BaseMod::ArmorSkill15() {
    return *(short*)(mhfdll_addy + 0xDC6C31C);
}
int (*BaseMod::originalArmorSkill15)();

int BaseMod::ArmorSkill16() {
    return *(short*)(mhfdll_addy + 0xDC6C31E);
}
int (*BaseMod::originalArmorSkill16)();

int BaseMod::ArmorSkill17() {
    return *(short*)(mhfdll_addy + 0xDC6C320);
}
int (*BaseMod::originalArmorSkill17)();

int BaseMod::ArmorSkill18() {
    return *(short*)(mhfdll_addy + 0xDC6C322);
}
int (*BaseMod::originalArmorSkill18)();

int BaseMod::ArmorSkill19() {
    return *(short*)(mhfdll_addy + 0xDC6C324);
}
int (*BaseMod::originalArmorSkill19)();

int BaseMod::ZenithSkill1() {
    return *(short*)(mhfdll_addy + 0xDCD1DC8);
}
int (*BaseMod::originalZenithSkill1)();

int BaseMod::ZenithSkill2() {
    return *(short*)(mhfdll_addy + 0xDCD1DCA);
}
int (*BaseMod::originalZenithSkill2)();

int BaseMod::ZenithSkill3() {
    return *(short*)(mhfdll_addy + 0xDCD1DCC);
}
int (*BaseMod::originalZenithSkill3)();

int BaseMod::ZenithSkill4() {
    return *(short*)(mhfdll_addy + 0xDCD1DCE);
}
int (*BaseMod::originalZenithSkill4)();

int BaseMod::ZenithSkill5() {
    return *(short*)(mhfdll_addy + 0xDCD1DD0);
}
int (*BaseMod::originalZenithSkill5)();

int BaseMod::ZenithSkill6() {
    return *(short*)(mhfdll_addy + 0xDCD1DD2);
}
int (*BaseMod::originalZenithSkill6)();

int BaseMod::ZenithSkill7() {
    return *(short*)(mhfdll_addy + 0xDCD1DD4);
}
int (*BaseMod::originalZenithSkill7)();

int BaseMod::DivaSkill() {
    return *(short*)(mhfdll_addy + 0xE6CCF24);
}
int (*BaseMod::originalDivaSkill)();

int BaseMod::DivaSkillUsesLeft() {
    return *(short*)(mhfdll_addy + 0xED3EB0A);
}
int (*BaseMod::originalDivaSkillUsesLeft)();

int BaseMod::DivaPrayerGemStart() {
    return *(int*)(mhfdll_addy + 0xE820DF8);
}
int (*BaseMod::originalDivaPrayerGemStart)();

int BaseMod::DivaPrayerGemRedSkill() {
    return *(short*)(mhfdll_addy + 0xE6CCF26);
}
int (*BaseMod::originalDivaPrayerGemRedSkill)();

int BaseMod::DivaPrayerGemRedLevel() {
    return *(short*)(mhfdll_addy + 0xE6CCF28);
}
int (*BaseMod::originalDivaPrayerGemRedLevel)();

int BaseMod::DivaPrayerGemYellowSkill() {
    return *(short*)(mhfdll_addy + 0xE6CCF2A);
}
int (*BaseMod::originalDivaPrayerGemYellowSkill)();

int BaseMod::DivaPrayerGemYellowLevel() {
    return *(short*)(mhfdll_addy + 0xE6CCF2C);
}
int (*BaseMod::originalDivaPrayerGemYellowLevel)();

int BaseMod::DivaPrayerGemGreenSkill() {
    return *(short*)(mhfdll_addy + 0xE6CCF2E);
}
int (*BaseMod::originalDivaPrayerGemGreenSkill)();

int BaseMod::DivaPrayerGemGreenLevel() {
    return *(short*)(mhfdll_addy + 0xE6CCF30);
}
int (*BaseMod::originalDivaPrayerGemGreenLevel)();

int BaseMod::DivaPrayerGemBlueSkill() {
    return *(short*)(mhfdll_addy + 0xE6CCF32);
}
int (*BaseMod::originalDivaPrayerGemBlueSkill)();

int BaseMod::DivaPrayerGemBlueLevel() {
    return *(short*)(mhfdll_addy + 0xE6CCF34);
}
int (*BaseMod::originalDivaPrayerGemBlueLevel)();

int BaseMod::GuildPoogie1Skill() {
    return *(int*)(mhfdll_addy + 0xE76BBDB);
}
int (*BaseMod::originalGuildPoogie1Skill)();

int BaseMod::GuildPoogie2Skill() {
    return *(int*)(mhfdll_addy + 0xE76BBEB);
}
int (*BaseMod::originalGuildPoogie2Skill)();

int BaseMod::GuildPoogie3Skill() {
    return *(int*)(mhfdll_addy + 0xE76BBFB);
}
int (*BaseMod::originalGuildPoogie3Skill)();

int BaseMod::GuildFoodSkill() {
    return *(short*)(mhfdll_addy + 0xE6CCD9E);
}
int (*BaseMod::originalGuildFoodSkill)();

int BaseMod::GuildFoodStart() {
    return *(int*)(mhfdll_addy + 0xE7FED08);
}
int (*BaseMod::originalGuildFoodStart)();