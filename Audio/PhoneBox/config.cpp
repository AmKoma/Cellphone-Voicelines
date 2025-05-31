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


class CfgSoundShaders
{
    class Phonebox_Trader_SoundShader
    {
        samples[] = {{"\AlbtrauminselCellphoneVoicelines\Audio\PhoneBox\PhoneBox_Trader", 0.9}};
        volume = 1;
        range = 25;
    };

    class Phonebox_Zelenogorsk_SoundShader
    {
        samples[] = {{"\AlbtrauminselCellphoneVoicelines\Audio\PhoneBox\PhoneBox_Zelenogorsk", 0.9}};
        volume = 1;
        range = 25;
    };

    class Phonebox_NWAF_SoundShader
    {
        samples[] = {{"\AlbtrauminselCellphoneVoicelines\Audio\PhoneBox\PhoneBox_NWAF", 0.9}};
        volume = 1;
        range = 25;
    };

    class Phonebox_Generic_01_SoundShader
    {
        samples[] = {{"\AlbtrauminselCellphoneVoicelines\Audio\PhoneBox\PhoneBox_Generic_01", 0.9}};
        volume = 1;
        range = 75;
    };
    class Phonebox_Generic_02_SoundShader
    {
        samples[] = {{"\AlbtrauminselCellphoneVoicelines\Audio\PhoneBox\PhoneBox_Generic_02", 0.9}};
        volume = 1;
        range = 75;
    };
    class Phonebox_Generic_03_SoundShader
    {
        samples[] = {{"\AlbtrauminselCellphoneVoicelines\Audio\PhoneBox\PhoneBox_Generic_03", 0.9}};
        volume = 1;
        range = 75;
    };
    class Phonebox_Generic_04_SoundShader
    {
        samples[] = {{"\AlbtrauminselCellphoneVoicelines\Audio\PhoneBox\PhoneBox_Generic_04", 0.9}};
        volume = 1;
        range = 75;
    };
};

class CfgSoundSets
{
    class Phonebox_Trader_SoundSet
    {
        sound3DProcessingType = "infected3DProcessingType";
        volumeCurve = "infectedAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
        soundShaders[] = {"Phonebox_Trader_SoundShader"};
    };

    class PhoneBox_Zelenogorsk_SoundSet
    {
        sound3DProcessingType = "infected3DProcessingType";
        volumeCurve = "infectedAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
        soundShaders[] = {"Phonebox_Zelenogorsk_SoundShader"};
    };

    class Phonebox_NWAF_SoundSet
    {
        sound3DProcessingType = "infected3DProcessingType";
        volumeCurve = "infectedAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
        soundShaders[] = {"Phonebox_NWAF_SoundShader"};
    };

    class Phonebox_Generic_01_SoundSet
    {
        sound3DProcessingType = "infected3DProcessingType";
        volumeCurve = "infectedAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
        soundShaders[] = {"Phonebox_Generic_01_SoundShader"};
    };
    class Phonebox_Generic_02_SoundSet
    {
        sound3DProcessingType = "infected3DProcessingType";
        volumeCurve = "infectedAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
        soundShaders[] = {"Phonebox_Generic_02_SoundShader"};
    };
    class Phonebox_Generic_03_SoundSet
    {
        sound3DProcessingType = "infected3DProcessingType";
        volumeCurve = "infectedAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
        soundShaders[] = {"Phonebox_Generic_03_SoundShader"};
    };
    class Phonebox_Generic_04_SoundSet
    {
        sound3DProcessingType = "infected3DProcessingType";
        volumeCurve = "infectedAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
        soundShaders[] = {"Phonebox_Generic_04_SoundShader"};
    };
}