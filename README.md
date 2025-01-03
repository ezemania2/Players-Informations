# Player-informations for [Pax's MHFZ Mod Loader](https://github.com/Paxlord/Pax-Mhfz-Loader)
This repo is meant to act as a mod template and documentation for my mod loader.

## Requirements
- Visual Studio 2018+

## Getting Started
1. Clone the repo or use the "use as template" option
2. Open the project .sln and change the project name to the .dll name you want
3. Change the target to Release/x86 or Debug/x86 depending on the loader build target (if installed through github releases it's Release/x86)
4. Edit the config.h
5. Every function that should be edited is exposed in BaseMod.cpp having to edit any other existing files in this template should be very rare.
6. Building the project will output a (ProjectName).dll, this is your mod. 

## Mod Structure
The base mod class derives from a Mod virtual class. This base mod class has to expose the same functions and members as the virtual class for it to be considered a valid Mod that can be loaded by the mod loader. 

Here's the class definition : 
```cpp
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
};
```

- ```OnAttach()``` : Is executed once when the mod is loaded into memory, this should be used as an initialization function for 90% of cases. This is also where you should set up your hooks and where you should offset your addresses. 
- ```OnDetach()``` : Is meant to be used as a clean up function, (**Not Implemented Yet** will be implemented when I find a decent way to detect the game shutting down in the loader.)
- ```OnImGUIInit()``` : Is run after ImGui and DX9 have been fully initialized, should be used mainly for Creating Images through the CreateImage function located in mod.h
- ```DrawUI(bool show_menu)``` : Has direct access to the injected ImGUI context and can call any ImGUI function from there. Contrary to the DrawModMenu method, this method is just called within the ImGui context without any checks at all, so drawing a window in this function would always display this window regardless of the state of the mod menu. The "show_menu" passed as parameter is a boolean that indicates the state of the mod menu display and can be used to change the state of things drawn in this function (for example, for an overlay type of mod, you could draw a window that would be transparent and unmovable if show_menu is false, but this same window could become editable if show_menu is set to true).  
- ```DrawModMenu()``` : Every call to imgui made here will be drawn in the main "Mod Menu" window in game. This is an easy way to centralize config options for mods.
- ```OnUpdateQuest()``` : Direct access to the main update function in game. The code here runs every GAME frame while the player is inside a quest. Pretty useful for catching unstable pointers and doing stuff like reading inputs.
- ```OnUpdateLobby()``` : Same as UpdateQuest but runs every game frame while the player is in Mezeporta. (**Not Implemented Yet** will be implemented when I find a good enough hooking point.)
- ```InitImGUIContext()``` : Should not be touched, is used to pass the main context at initialization. 


