// Fill out your copyright notice in the Description page of Project Settings.


#include "Lantern.h"
#include "Lamp.h"

// Sets default values
ALantern::ALantern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALantern::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ALantern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if ( is_lit && fuel > 0 ) {
		
		elapsed_time += DeltaTime;

		if ( elapsed_time >= 1.0 ) {
			fuel--;
			elapsed_time = 0.0;

			if ( fuel <= 0 ) {
				fuel = 0;
				is_lit = false;

				OnExtinguish( );
			}
		}
	}
}

void ALantern::AddFuel( int Amount ) {
	// 燃料が0の状態で補給されたら、火を再点灯させるロジック
	if ( !is_lit && Amount > 0 ) {
		is_lit = true;
		OnIgnite( ); // BP側の点火演出を呼び出す
	}

	// 現在の燃料に加算し、0〜最大値の間に収める（クランプ処理）
	fuel = FMath::Clamp( fuel + Amount, 0, max_fuel );
}

void ALantern::TryIgniteLamp( AActor* OverlappedActor ) {
	if ( !is_lit ) {
		return;
	}
	// 2. 相手はランプか？
	ALamp* TargetLamp = Cast<ALamp>( OverlappedActor );

	// 3. ランプが存在し、かつまだ火がついていないか？
	if ( TargetLamp && !TargetLamp->on_fire ) {
		TargetLamp->IgniteLamp( ); // 火をつける！

		
	}
}