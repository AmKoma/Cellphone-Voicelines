class Phonebox extends BuildingSuper
{
    protected bool m_IsPlaying = false;
    protected ref set<string> m_AlreadyInteractedPlayers;
    protected const float TRIGGER_RADIUS = 75.0;
    protected const int APPROACH_INTERVAL = 180000;

    void Phonebox()
    {
        m_AlreadyInteractedPlayers = new set<string>();
        RegisterNetSyncVariableBool("m_IsPlaying");

        if (GetGame().IsServer())
        {
            Print("[PHONEBOX] Server: Starting approach check loop.");
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckApproachSound, APPROACH_INTERVAL, true);
        }
    }

    void CheckApproachSound()
    {
        if (m_IsPlaying)
        {
            Print("[PHONEBOX] Skipped: Sound is currently playing.");
            return;
        }

        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);

        foreach (Man man : players)
        {
            PlayerBase player = PlayerBase.Cast(man);
            if (!player || !player.IsAlive())
                continue;

            float distance = vector.Distance(player.GetPosition(), GetPosition());
            string guid = player.GetIdentity().GetId();

            if (distance <= TRIGGER_RADIUS && m_AlreadyInteractedPlayers.Find(guid) == -1)
            {
                string soundSet = GetRandomSoundSet();

                ScriptRPC rpc = new ScriptRPC();
                rpc.Write(soundSet);
                rpc.Send(this, RPC_PLAY_APPROACH_SOUND, true);

                Print("[PHONEBOX] Sent approach sound: " + soundSet + " to clients.");

                break;
            }
        }
    }

    void StartPhoneboxSound(PlayerBase player)
    {
        if (!player || !GetGame().IsServer())
            return;

        if (!CanPlaySound())
            return;

        string soundSetName;
        if (GetGame().ConfigGetText("CfgVehicles " + GetType() + " soundSet", soundSetName))
        {
            Print("[PHONEBOX] Broadcasting MAIN sound: " + soundSetName);

            m_IsPlaying = true;
            m_AlreadyInteractedPlayers.Insert(player.GetIdentity().GetId());

            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetSoundCooldown, 120000, false);

            ScriptRPC rpc = new ScriptRPC();
            rpc.Write(soundSetName);
            rpc.Send(this, RPC_PLAY_MAIN_SOUND, true);
        }
    }

    string GetRandomSoundSet()
    {
        switch (Math.RandomInt(0, 4))
        {
            case 0: return "Phonebox_Generic_01_SoundSet";
            case 1: return "Phonebox_Generic_02_SoundSet";
            case 2: return "Phonebox_Generic_03_SoundSet";
            case 3: return "Phonebox_Generic_04_SoundSet";
        }
        return "Phonebox_Generic_01_SoundSet";
    }

    void PlayApproachSound(string soundSet)
    {
        Print("[PHONEBOX] Client: Playing approach sound: " + soundSet);
        EffectSound sound = SEffectManager.PlaySoundOnObject(soundSet, this);
        if (sound)
            sound.SetAutodestroy(true);
    }

    void PlayMainSound(string soundSet)
    {
        Print("[PHONEBOX] Client: Playing MAIN phonebox sound: " + soundSet);
        EffectSound sound = SEffectManager.PlaySoundOnObject(soundSet, this);
        if (sound)
            sound.SetAutodestroy(true);
    }

    void ResetSoundCooldown()
    {
        Print("[PHONEBOX] Cooldown reset – m_IsPlaying = false");
        m_IsPlaying = false;
    }

    bool CanPlaySound()
    {
        return !m_IsPlaying;
    }

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

        string soundSet;
        if (!ctx.Read(soundSet))
            return;

        switch (rpc_type)
        {
            case RPC_PLAY_APPROACH_SOUND:
                PlayApproachSound(soundSet);
                break;

            case RPC_PLAY_MAIN_SOUND:
                PlayMainSound(soundSet);
                break;
        }
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionInteractPhonebox);
    }

    override bool CanPutInCargo(EntityAI parent) { return false; }
    override bool CanPutIntoHands(EntityAI parent) { return false; }
    override bool IsBuilding() { return true; }
    bool IsInventoryItem() { return false; }
    bool IsHealthVisible() { return false; }
}
