// Copyright (C) 2024 owoDra

#include "GameplayAbilityWithSetting.h"

#include "GSCGameUserSettings.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GameplayAbilityWithSetting)


UGameplayAbilityWithSetting::UGameplayAbilityWithSetting(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
}


void UGameplayAbilityWithSetting::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (ActorInfo->IsLocallyControlled())
	{
		if (auto* Settings{ UGSCGameUserSettings::GetGSCGameUserSettings()})
		{
			Settings->CallAndRegister_OnGameSettingsApplied(
				UGSCGameUserSettings::FGameSettingsAppliedDelegate::FDelegate::CreateUObject(this, &ThisClass::HandleSettingApplied));
		}
	}
}

void UGameplayAbilityWithSetting::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnRemoveAbility(ActorInfo, Spec);

	if (ActorInfo->IsLocallyControlled())
	{
		if (auto* Settings{ UGSCGameUserSettings::GetGSCGameUserSettings() })
		{
			Settings->OnGameSettingsApplied.RemoveAll(this);
		}
	}
}
