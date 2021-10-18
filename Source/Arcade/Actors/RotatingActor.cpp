// Copyright Badsardines 2021.


#include "Arcade/Actors/RotatingActor.h"

#include "Algo/Rotate.h"
#include "Arcade/Characters/ArcadeCharacter.h"
#include "Components/SphereComponent.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereCollider->SetSphereRadius(250.f);
	SphereCollider->SetHiddenInGame(false);

	RootComponent = SphereCollider;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComp->SetupAttachment(SphereCollider);

	bCanRotate = false;
}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

	// Find the player pawn
	PlayerPawn = Cast<AArcadeCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ARotatingActor::OnBeginOverlap); // Setup a notification when the sphere collider is overlapping with player pawn
	SphereCollider->OnComponentEndOverlap.AddDynamic(this, &ARotatingActor::OnEndOverlap); // Setup a notification when the sphere collider is no longer overlapping with player pawn
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bCanRotate == true)
	{
		RotateMeshComponent(RotateRate);
	}
}

void ARotatingActor::SetbCanRotate(bool value)
{
	bCanRotate = value;
}

void ARotatingActor::RotateMeshComponent(float RotateSpeed)
{
	MeshComp->AddWorldRotation(FRotator(0.f, 2.f, 0.f) * RotateSpeed * GetWorld()->GetDeltaSeconds());
}

void ARotatingActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult)
{
	if ((OtherActor == PlayerPawn) && (OtherActor != this))
	{
		SetbCanRotate(true);
	}
}

void ARotatingActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if ((OtherActor == PlayerPawn) && (OtherActor != this))
	{
		SetbCanRotate(false);
	}
}
