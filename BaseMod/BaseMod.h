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

	static int WeaponRaw();
	static int (*originalWeaponRaw)();
	static int ArmorSkill1();
	static int (*originalArmorSkill1)();
	static int ArmorSkill2();
	static int (*originalArmorSkill2)();
	static int ArmorSkill3();
	static int (*originalArmorSkill3)();
	static int ArmorSkill4();
	static int (*originalArmorSkill4)();
	static int ArmorSkill5();
	static int (*originalArmorSkill5)();
	static int ArmorSkill6();
	static int (*originalArmorSkill6)();
	static int ArmorSkill7();
	static int (*originalArmorSkill7)();
	static int ArmorSkill8();
	static int (*originalArmorSkill8)();
	static int ArmorSkill9();
	static int (*originalArmorSkill9)();
	static int ArmorSkill10();
	static int (*originalArmorSkill10)();
	static int ArmorSkill11();
	static int (*originalArmorSkill11)();
	static int ArmorSkill12();
	static int (*originalArmorSkill12)();
	static int ArmorSkill13();
	static int (*originalArmorSkill13)();
	static int ArmorSkill14();
	static int (*originalArmorSkill14)();
	static int ArmorSkill15();
	static int (*originalArmorSkill15)();
	static int ArmorSkill16();
	static int (*originalArmorSkill16)();
	static int ArmorSkill17();
	static int (*originalArmorSkill17)();
	static int ArmorSkill18();
	static int (*originalArmorSkill18)();
	static int ArmorSkill19();
	static int (*originalArmorSkill19)();

	static int ZenithSkill1();
	static int (*originalZenithSkill1)();
	static int ZenithSkill2();
	static int (*originalZenithSkill2)();
	static int ZenithSkill3();
	static int (*originalZenithSkill3)();
	static int ZenithSkill4();
	static int (*originalZenithSkill4)();
	static int ZenithSkill5();
	static int (*originalZenithSkill5)();
	static int ZenithSkill6();
	static int (*originalZenithSkill6)();
	static int ZenithSkill7();
	static int (*originalZenithSkill7)();

	static int DivaSkill();
	static int (*originalDivaSkill)();
	static int DivaSkillUsesLeft();
	static int (*originalDivaSkillUsesLeft)();

	static int DivaPrayerGemStart();
	static int (*originalDivaPrayerGemStart)();
	static int DivaPrayerGemRedSkill();
	static int (*originalDivaPrayerGemRedSkill)();
	static int DivaPrayerGemRedLevel();
	static int (*originalDivaPrayerGemRedLevel)();
	static int DivaPrayerGemYellowSkill();
	static int (*originalDivaPrayerGemYellowSkill)();
	static int DivaPrayerGemYellowLevel();
	static int (*originalDivaPrayerGemYellowLevel)();
	static int DivaPrayerGemGreenSkill();
	static int (*originalDivaPrayerGemGreenSkill)();
	static int DivaPrayerGemGreenLevel();
	static int (*originalDivaPrayerGemGreenLevel)();
	static int DivaPrayerGemBlueSkill();
	static int (*originalDivaPrayerGemBlueSkill)();
	static int DivaPrayerGemBlueLevel();
	static int (*originalDivaPrayerGemBlueLevel)();

	static int GuildPoogie1Skill();
	static int (*originalGuildPoogie1Skill)();
	static int GuildPoogie2Skill();
	static int (*originalGuildPoogie2Skill)();
	static int GuildPoogie3Skill();
	static int (*originalGuildPoogie3Skill)();

	static int GuildFoodSkill();
	static int (*originalGuildFoodSkill)();
	static int GuildFoodStart();
	static int (*originalGuildFoodStart)();


};
