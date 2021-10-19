// Copyright Badsardines 2021.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Geometry/Meshes/1M_Cube"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MainMaterial(TEXT("/Game/FirstPerson/Meshes/Default"));
	
	UMaterialInterface* Material = MainMaterial.Object;
	UStaticMesh* MyMesh = StaticMesh.Object;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	Mesh->SetStaticMesh(MyMesh);
	Mesh->SetMaterial(0, Material);
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	//...
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
