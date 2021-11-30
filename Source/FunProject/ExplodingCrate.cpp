// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplodingCrate.h"

// Sets default values
AExplodingCrate::AExplodingCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ExplosiveCache = nullptr;
	
	TheRoot = CreateDefaultSubobject<USceneComponent>(FName("TheRoot"));
	TheRoot->SetupAttachment(RootComponent);

	TheCrate = CreateDefaultSubobject<UStaticMeshComponent>(FName("TheCrate"));
	TheCrate->SetupAttachment(TheRoot);

	ConstructorHelpers::FObjectFinder<UStaticMesh> CrateMesh(TEXT("/Game/Art/Meshes/1M_Cube"));

	if (CrateMesh.Succeeded()) TheCrate->SetStaticMesh(CrateMesh.Object);

}

// Called when the game starts or when spawned
void AExplodingCrate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplodingCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExplodingCrate::Interact()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Player is trying to interact");

	if (ExplosiveCache)
	{
		
		FVector pos = GetActorLocation();

		
		for (int i = 0; i < 50; i = i + 1)	GetWorld()->SpawnActor<AActor>(ExplosiveCache, pos + FMath::VRand(), FRotator(0, 0, 0));

	}

	Destroy();


}

