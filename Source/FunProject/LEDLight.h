// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


#include "InteractableObject.h"
#include "UObject/ConstructorHelpers.h"

#include "LEDLight.generated.h"

UCLASS()
class FUNPROJECT_API ALEDLight : public AActor, public IInteractableObject
{
	GENERATED_BODY()

public:	
	ALEDLight();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	class USceneComponent* TheRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	class UStaticMeshComponent* TheLED;

	UPROPERTY(EditAnywhere, Category = "Materials")
	class UMaterialInterface* LEDMatOn;

	UPROPERTY(EditAnywhere, Category = "Materials")
	class UMaterialInterface* LEDMatOff;

	UPROPERTY(EditAnywhere, Category = "Component")
	bool TurnedOn;


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void Interact();

};
