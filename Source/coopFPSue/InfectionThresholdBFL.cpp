// InfectionThresholdBFL.cpp
#include "InfectionThresholdBFL.h"
#include "GameFramework/Actor.h"

void UInfectionThresholdBFL::SortActorsByDistance(
    const TArray<AActor*>& Actors,
    const FVector& Location,
    TArray<AActor*>& SortedActors,
    TArray<float>& Distances
)
{
    // Clear output arrays
    SortedActors.Empty();
    Distances.Empty();

    if (Actors.Num() == 0)
    {
        return;
    }

    // Create a temporary array of pairs (actor, distance)
    TArray<TPair<AActor*, float>> ActorDistancePairs;
    ActorDistancePairs.Reserve(Actors.Num());

    for (AActor* Actor : Actors)
    {
        if (IsValid(Actor))
        {
            const float Distance = FVector::Dist(Actor->GetActorLocation(), Location);
            ActorDistancePairs.Emplace(Actor, Distance);
        }
    }

    // Sort by distance (ascending - closest first)
    ActorDistancePairs.Sort([](const TPair<AActor*, float>& A, const TPair<AActor*, float>& B)
        {
            return A.Value < B.Value;
        });

    // Fill output arrays
    SortedActors.Reserve(ActorDistancePairs.Num());
    Distances.Reserve(ActorDistancePairs.Num());

    for (const TPair<AActor*, float>& Pair : ActorDistancePairs)
    {
        SortedActors.Add(Pair.Key);
        Distances.Add(Pair.Value);
    }
}

TArray<AActor*> UInfectionThresholdBFL::GetActorsSortedByDistance(
    const TArray<AActor*>& Actors,
    const FVector& Location
)
{
    TArray<AActor*> SortedActors;
    TArray<float> Distances;

    SortActorsByDistance(Actors, Location, SortedActors, Distances);

    return SortedActors;
}