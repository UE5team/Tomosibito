// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class ALamp;

#include "Lantern.generated.h"

UCLASS()
class TOMOSIBITO_API ALantern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALantern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	double elapsed_time = 0.0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Lantern | Stats" )
	int fuel = 100;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Lantern | Stats" )
	int max_fuel = 100;

	UPROPERTY( BlueprintReadWrite, Category = "Lantern | Stats" )
	bool is_lit = true;

	//これを呼ぶとBP側で「火が消えた時の音やパーティクル」を設定できる
	UFUNCTION( BlueprintImplementableEvent, Category = "Lantern|Effects" )
	void OnExtinguish( );

	UFUNCTION( BlueprintImplementableEvent, Category = "Lantern|Effects" )
	void OnIgnite( );

	UFUNCTION( BlueprintCallable, Category = "Lantern | Actions" )
	void AddFuel( int Amount );

	UFUNCTION( BlueprintCallable, Category = "Lantern | Actions" )
	void TryIgniteLamp( AActor* OverlappedActor );

};
