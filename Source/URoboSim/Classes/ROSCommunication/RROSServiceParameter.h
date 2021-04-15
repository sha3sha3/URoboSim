#pragma once

#include "CoreMinimal.h"
// clang-format off
#include "RROSServiceParameter.generated.h"
// clang-format on

UCLASS(BlueprintType, DefaultToInstanced, collapsecategories, hidecategories = Object, editinlinenew)
class UROBOSIM_API URROSServiceParameter : public UObject
{
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	FString Type;
};