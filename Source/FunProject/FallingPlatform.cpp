// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingPlatform.h"

// Sets default values
AFallingPlatform::AFallingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(FName("TheRoot"));
	TheRoot->SetupAttachment(RootComponent);

	ThePlatform = CreateDefaultSubobject<UStaticMeshComponent>(FName("ThePlatform"));
	ThePlatform->SetupAttachment(TheRoot);

	TheCollider = CreateDefaultSubobject<UBoxComponent>(FName("TheCollider"));
	TheCollider->SetupAttachment(ThePlatform);
	TheCollider->SetBoxExtent(FVector(PlatformWidth/5, PlatformDepth/5, PlatformHeight + 30));
	TheCollider->SetRelativeLocation(FVector(0, 0, PlatformHeight / 2));

	PlatformTimelineComp = CreateDefaultSubobject<UTimelineComponent>(FName("PlatformTimelineComp"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> PlatformMesh(TEXT("/Game/Art/Meshes/1M_Cube"));

	if (PlatformMesh.Succeeded()) ThePlatform->SetStaticMesh(PlatformMesh.Object);



}

// Called when the game starts or when spawned
void AFallingPlatform::BeginPlay()
{
	Super::BeginPlay();

	UpdateFunctionFloat.BindDynamic(this, &AFallingPlatform::UpdateTimelineComp);

	if (TimeToFall) PlatformTimelineComp->AddInterpFloat(TimeToFall, UpdateFunctionFloat);
	TheCollider->OnComponentBeginOverlap.AddDynamic(this, &AFallingPlatform::OnOverlapBegin);

	
	
}

void AFallingPlatform::UpdateTimelineComp(float Output)
{
	if (Output == 1)
	{
		ThePlatform->SetSimulatePhysics(true);
	}
}
// Called every frame
void AFallingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFallingPlatform::OnConstruction(const FTransform& xform)
{
	Super::OnConstruction(xform);
	ThePlatform->SetWorldScale3D(FVector(PlatformWidth, PlatformDepth, PlatformHeight) / 100);
	ThePlatform->SetRelativeLocation(FVector(PlatformWidth / 2, 0, PlatformHeight / 2));
}

void AFallingPlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlatformTimelineComp->Play();
}
