#pragma once

#include "Physics/RModel.h"
#include "Controller/ControllerType/JointController/RJointController.h"
// clang-format off
#include "RGripperControllerBase.generated.h"
// clang-format on

USTRUCT()
struct FGraspComponentSetting
{
  GENERATED_BODY()
public:
  UPROPERTY(EditAnywhere)
  FString GripperName;

  UPROPERTY(EditAnywhere)
  FVector ToolCenterPoint = FVector(15.0f, 0.0f, 0.0f);

};

UCLASS()
class UROBOSIM_API URGripperControllerBaseParameter : public URControllerParameter
{
  GENERATED_BODY()
public:

  UPROPERTY(EditAnywhere)
  FString GripperJointName;

  UPROPERTY(EditAnywhere)
  FString GraspComponentName;

  UPROPERTY(EditAnywhere)
  FGraspComponentSetting GraspCompSetting;
};

UCLASS()
class UROBOSIM_API URGripperControllerBase : public URController
{
  GENERATED_BODY()

public:
  URGripperControllerBase();

public:
  virtual void Init() override;

  virtual void SetControllerParameters(URControllerParameter *&ControllerParameters) override;

  virtual bool Grasp();

  virtual void Release();

  virtual void Tick(const float &InDeltaTime);

public:
  URGraspComponent *GraspComponent;

  UPROPERTY(EditAnywhere)
  FGraspComponentSetting GraspCompSetting;

  float OldPosition;

  UPROPERTY(EditAnywhere)
  FString GripperJointName;

  URJoint *GripperJoint;

  UPROPERTY(EditAnywhere)
    bool bInvertGraspCondition = false;
protected:
  URJointController *JointController;

  UPROPERTY(EditAnywhere)
  FString GraspComponentName;

  int GraspInversion = 1;

};
