#pragma once
#include "mod.h"

class BaseMod :
	public Mod
{
public:

	using Mod::Mod;

	void OnAttach() override;
	void OnDetach() override;
	void DrawUI(bool show_menu) override;
	void DrawModMenu() override;
	void OnUpdateQuest() override;
	void OnUpdateLobby() override;
	void OnImGUIInit() override;
	void InitImGUIContext(ImGuiContext* ctx) override {
		ImGui::SetCurrentContext(ctx);
	}
	static int WeaponType();
	static int (*originalWeaponType)();

	static int BlademasterWeaponID();
	static int (*originalBlademasterWeaponID)();

	//static int GunnerWeaponID();
	//static int (*originalGunnerWeaponID)();

	static int AutomaticSkillWeapon();
	static int (*originalAutomaticSkillWeapon)();
	
	static int ArmorHeadID();
	static int (*originalArmorHeadID)();
	
	static int ArmorChestID();
	static int (*originalArmorChestID)();

	static int ArmorArmsID();
	static int (*originalArmorArmsID)();

	static int ArmorWaistID();
	static int (*originalArmorWaistID)();

	static int ArmorLegsID();
	static int (*originalArmorLegsID)();

	static int AutomaticSkillHead();
	static int (*originalAutomaticSkillHead)();

	static int AutomaticSkillChest();
	static int (*originalAutomaticSkillChest)();

	static int AutomaticSkillArms();
	static int (*originalAutomaticSkillArms)();

	static int AutomaticSkillWaist();
	static int (*originalAutomaticSkillWaist)();

	static int AutomaticSkillLegs();
	static int (*originalAutomaticSkillLegs)();
	
	
	static int AreaID();
	static int (*originalAreaID)();

	static int HunterHP();
    static int (*originalHunterHP)();
	
	static int PartySize();
    static int (*originalPartySize)();

	static int PartySizeMax();
	static int (*originalPartySizeMax)();

	static float PlayerPositionX();
	static float (*originalPlayerPositionX)();

	static float PlayerPositionY();
	static float (*originalPlayerPositionY)();

	static float PlayerPositionZ();
	static float (*originalPlayerPositionZ)();
};
