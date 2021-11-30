// Fill out your copyright notice in the Description page of Project Settings.


#include "LEDLight.h"

// Sets default values
ALEDLight::ALEDLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(FName("TheRoot"));
	TheRoot->SetupAttachment(RootComponent);

	TheLED = CreateDefaultSubobject<UStaticMeshComponent>(FName("TheLED"));
	TheLED->SetupAttachment(TheRoot);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TheLEDMesh(TEXT("/Game/Art/Meshes/Cylinder"));

	if (TheLEDMesh.Succeeded()) TheLED->SetStaticMesh(TheLEDMesh.Object);

	ConstructorHelpers::FObjectFinder<UMaterialInterface> TheLEDMatOff(TEXT("/Game/Art/Materials/LEDMatOff"));
	ConstructorHelpers::FObjectFinder<UMaterialInterface> TheLEDMatOn(TEXT("/Game/Art/Materials/LEDMatOn"));

	
	
	if (TheLEDMatOff.Succeeded())
	{
		TheLED->SetMaterial(0, TheLEDMatOff.Object);
		TheLED->SetMaterialByName("LEDMatOff", TheLEDMatOff.Object);
	}

	if (TheLEDMatOn.Succeeded()) TheLED->SetMaterialByName("LEDMatOn", TheLEDMatOn.Object);

	

	


}

// Called when the game starts or when spawned
void ALEDLight::BeginPlay()
{
	Super::BeginPlay();
	

	
	
}

// Called every frame
void ALEDLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALEDLight::Interact()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Player wants to Interact");

	if (TurnedOn)
	{
		TheLED->SetMaterial(0, LEDMatOff);
		TurnedOn = false;
	}
	else
	{
		TheLED->SetMaterial(0, LEDMatOn);
		TurnedOn = true;
	}
	

}

