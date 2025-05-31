class CfgPatches
{
    class DZ_Sounds_Effects
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    class HouseNoDestruct;
    class Phonebox : HouseNoDestruct
    {
        scope = 1;
        model = "DZ\structures\Furniture\Eletrical_appliances\phonebox\phonebox.p3d";
    };

    class PhoneBox_Trader : PhoneBox
    {
        scope = 2;
        soundSet = "Phonebox_Trader_SoundSet";
    }

    class PhoneBox_Zelenogorsk : PhoneBox
    {
        scope = 2;
        soundSet = "PhoneBox_Zelenogorsk_SoundSet";
    }

    class PhoneBox_NWAF : PhoneBox
    {
        scope = 2;
        soundSet = "Phonebox_NWAF_SoundSet";
    }
}