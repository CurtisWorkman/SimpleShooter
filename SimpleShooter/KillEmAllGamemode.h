// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameModeBase.h"
#include "KillEmAllGamemode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AKillEmAllGamemode : public ASimpleShooterGameModeBase
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void PawnKilled(APawn* PawnKilled) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float NumberOfAi = 0;

	UFUNCTION(BlueprintPure)
		float GetAICharacters();

private:
	void EndGame(bool bIsPlayerWinner);

	
};
