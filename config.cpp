class CfgPatches
{
	class AlbtrauminselCellphoneVoicelines
	{
		requiredVersion = 0.1;
		units[] = {};
		requiredAddons[] =
			{
				"DZ_Data",
				"DZ_Scripts"};
	};
};

class CfgMods
{
	class AlbtrauminselCellphoneVoicelines
	{
		dir = "AlbtrauminselCellphoneVoicelines";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Cellphone Voicelines";
		credits = "";
		author = "KOMA";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"AlbtrauminselCellphoneVoicelines/scripts/3_game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"AlbtrauminselCellphoneVoicelines/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"AlbtrauminselCellphoneVoicelines/scripts/5_mission"};
			};
		};
	};
};