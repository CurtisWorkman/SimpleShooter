// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "ShooterCharacter.h"




UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

}

AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag("PickUpHealth"))
		{
			return Actor;
		}
	}
	return nullptr;
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* Actor = GetAcceptableActor();
	if (Actor != nullptr)
	{
		AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(Actor);
		if (ShooterCharacter != nullptr)
		{
		//	const char* ObjectHitName = StringCast<ANSICHAR>(*Actor->GetClass()->GetName()).Get();
		//	if (ObjectHitName != nullptr)
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("Yep %s"), ObjectHitName);
		//	}
			ShooterCharacter->PickUpHealth(HealthValue);
			this->GetOwner()->Destroy();
			
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("null"));
		}
	}
}