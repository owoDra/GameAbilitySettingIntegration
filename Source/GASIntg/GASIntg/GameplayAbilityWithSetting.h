// Copyright (C) 2024 owoDra

#pragma once

#include "GAEGameplayAbility.h"

#include "GameplayAbilityWithSetting.generated.h"

class UGSCGameUserSettings;


/**
 * GameplayAbility class with caching of user setting values additionally.
 */
UCLASS(Abstract)
class GASINTG_API UGameplayAbilityWithSetting : public UGAEGameplayAbility
{
	GENERATED_BODY()
public:
	UGameplayAbilityWithSetting(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

protected:
	UFUNCTION() 
	virtual void HandleSettingApplied(UGSCGameUserSettings* Settings) {}

};
