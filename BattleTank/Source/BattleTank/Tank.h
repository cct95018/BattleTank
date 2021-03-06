// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	void AimAt(FVector HitLoc);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UPROPERTY(EditAnyWhere, Category = Firing)
	float LaunchSpeed = 6000;
	UPROPERTY(EditAnyWhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Barrel for projectile
	UTankBarrel* Barrel = nullptr;
	UPROPERTY(EditAnyWhere, Category = Firing)
	float ReloadTime = 5;
	double LastFireTime = 0;
}; 
