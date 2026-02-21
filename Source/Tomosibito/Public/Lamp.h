// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lamp.generated.h"



UCLASS()
class TOMOSIBITO_API ALamp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALamp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Lamp" )
	bool on_fire = false;

	UFUNCTION( BlueprintCallable )
	void IgniteLamp( ) {
		if ( !on_fire ) {
			on_fire = true;
			// ここでBPの点灯イベントを呼ぶなど
			BP_OnIgniteEffect( );
		}
	}

	UFUNCTION( BlueprintImplementableEvent )
	void BP_OnIgniteEffect( );
};
