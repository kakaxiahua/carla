// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "GameFramework/Actor.h"

#include "Carla/Sensor/DataStream.h"

#include "Sensor.generated.h"

/// Base class for sensors.
UCLASS(Abstract, hidecategories=(Collision, Attachment, Actor))
class CARLA_API ASensor : public AActor
{
  GENERATED_BODY()

public:

  virtual void Set(const FActorDescription &) {}

  /// Replace the FDataStream associated with this sensor.
  ///
  /// @warning Do not change the stream after BeginPlay. It is not thread-safe.
  void SetDataStream(FDataStream InStream)
  {
    Stream = std::move(InStream);
  }

protected:

  /// Return the FDataStream associated with this sensor.
  FDataStream &GetDataStream()
  {
    return Stream;
  }

private:

  FDataStream Stream;
};
