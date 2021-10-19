// Copyright Badsardines 2021.


#include "Arcade/Actors/DestructibleActor.h"
#include "Arcade/ActorComponents/HealthComponent.h"

// Sets default values
ADestructibleActor::ADestructibleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	HealthComp = CreateDefaultSubobject<UHealthComponent>("Health Component");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetSimulatePhysics(true);
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ADestructibleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructibleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ADestructibleActor::TeleportToDefault()
{
	Mesh->SetWorldLocation(FVector(-200.f, 0.f, 1250.f));
}