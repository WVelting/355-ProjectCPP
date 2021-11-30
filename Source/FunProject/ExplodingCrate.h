// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObject.h"
#include "UObject/ConstructorHelpers.h"
#include "ExplodingCrate.generated.h"

UCLASS()
class FUNPROJECT_API AExplodingCrate : public AActor, public IInteractableObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplodingCrate();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* TheRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TheCrate;

	UPROPERTY(EditAnywhere, Category = "Explosives")
	TSubclassOf<AActor> ExplosiveCache;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact();

};
