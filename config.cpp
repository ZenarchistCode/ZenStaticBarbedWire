class CfgPatches
{
	class ZenStaticBarbedWire
	{
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
		units[] = {};
	};
};

class CfgMods
{
	class ZenStaticBarbedWire
	{
		dir = "ZenStaticBarbedWire";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenStaticBarbedWire";
		credits = "";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenStaticBarbedWire/scripts/3_game"; };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenStaticBarbedWire/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenStaticBarbedWire/scripts/5_mission" };
			};
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class ZenObj_Debug_Razorwire : HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\military\misc\misc_razorwire.p3d";
	};
};
