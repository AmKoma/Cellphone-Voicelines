class ActionInteractPhonebox : ActionInteractBase
{

    void ActionPlayPhoneboxSound()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTObject();
    }

    override string GetText()
    {
        return "Telefon abheben";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        Phonebox phonebox = Phonebox.Cast(target.GetObject());
        return phonebox && phonebox.CanPlaySound();
    }

    override void OnStartServer(ActionData action_data)
    {
        super.OnStartServer(action_data);

        Phonebox phonebox = Phonebox.Cast(action_data.m_Target.GetObject());
        if (phonebox)
        {
            phonebox.StartPhoneboxSound(action_data.m_Player);
        }
    }
}
