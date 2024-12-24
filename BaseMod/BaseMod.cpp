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
} // End of OnAttach()

// Change function definitions to use inline keyword
inline int BaseMod::WeaponType() {
	return *(short*)(mhfdll_addy + 0xDC6B753);
}

int (*BaseMod::originalWeaponType)();

/*inline int BaseMod::GunnerWeaponID() {
	return *(short*)(mhfdll_addy + 0xDC6BB92);
}

int (*BaseMod::originalGunnerWeaponID)();*/

int BaseMod::BlademasterWeaponID() {
	return *(short*)(mhfdll_addy + 0xDC6BB52);
}

int (*BaseMod::originalBlademasterWeaponID)();


int BaseMod::AutomaticSkillWeapon() {
	return *(short*)(mhfdll_addy + 0xDC6C352);
}

int (*BaseMod::originalAutomaticSkillWeapon)();

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

int BaseMod::AutomaticSkillWaist() {
	return *(short*)(mhfdll_addy + 0xDC6C350);
}

int (*BaseMod::originalAutomaticSkillWaist)();

int BaseMod::ArmorWaistID() {
	return *(short*)(mhfdll_addy + 0xDC6BB42);
}

int (*BaseMod::originalArmorWaistID)();


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



//Will run once at game end, loader doesn't use it for now
void BaseMod::OnDetach() {

}

//Will run once the ImGUI and Dx9 Context has been initialized, use this function to create texture data
void BaseMod::OnImGUIInit() {

}

//Has access to the main ImGui context, can draw anything related to the mod in there
void BaseMod::DrawModMenu() {
	if (ImGui::CollapsingHeader(DISPLAY_NAME.c_str())) {
		ImGui::Text("Hunter HP: %d", BaseMod::HunterHP());
		ImGui::Text("");
		ImGui::Text("Party Size: %d / %d", BaseMod::PartySize(), BaseMod::PartySizeMax());
		ImGui::Text("");
		ImGui::Text("Area ID: %d", BaseMod::AreaID());
		ImGui::Text("Position: X: %f, Y: %f, Z: %f", BaseMod::PlayerPositionX(), BaseMod::PlayerPositionY(), BaseMod::PlayerPositionZ());
		ImGui::Text("");
		ImGui::Text("Weapon Type: %d", BaseMod::WeaponType());
		ImGui::Text("");
		if (BaseMod::WeaponType() == 5 || BaseMod::WeaponType() == 1 || BaseMod::WeaponType() == 10) {
			ImGui::Text("Gunner Weapon ID: %d", BaseMod::BlademasterWeaponID());
		} else {
			ImGui::Text("Blademaster Weapon ID: %d", BaseMod::BlademasterWeaponID());
		}
		ImGui::Text("Automatic Skill Weapon: %d", BaseMod::AutomaticSkillWeapon());
		ImGui::Text("");
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