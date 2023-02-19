// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "ShooterCharacter.h"
#include "TriggerComponent.generated.h"


/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BluePrintSpawnableComponent))
class SIMPLESHOOTER_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()


public:

	UTriggerComponent();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		FName AcceptableActorTag;

	UPROPERTY(EditAnywhere)
		float HealthValue = 10;

	AShooterCharacter* Player;

	AActor* GetAcceptableActor() const;
};
