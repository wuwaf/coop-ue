// InfectionThresholdBFL.h
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InfectionThresholdBFL.generated.h"

UCLASS()
class COOPFPSUE_API UInfectionThresholdBFL : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Sorts an array of actors by their distance to a given location (closest first)
     * @param Actors - The array of actors to sort
     * @param Location - The location to measure distance from
     * @param SortedActors - Output array of actors sorted by distance (closest first)
     * @param Distances - Output array of corresponding distances
     */
    UFUNCTION(BlueprintCallable, Category = "Infection Threshold|Utilities", meta = (AutoCreateRefTerm = "Location"))
    static void SortActorsByDistance(
        const TArray<AActor*>& Actors,
        const FVector& Location,
        TArray<AActor*>& SortedActors,
        TArray<float>& Distances
    );

    /**
     * Sorts an array of actors by their distance to a given location and returns only the sorted array
     * @param Actors - The array of actors to sort
     * @param Location - The location to measure distance from
     * @return Sorted array of actors by distance (closest first)
     */
    UFUNCTION(BlueprintCallable, Category = "Infection Threshold|Utilities", meta = (AutoCreateRefTerm = "Location"))
    static TArray<AActor*> GetActorsSortedByDistance(
        const TArray<AActor*>& Actors,
        const FVector& Location
    );
};