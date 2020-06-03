/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) 2008-2020, Alliance for Sustainable Energy, LLC, and other contributors. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
*  following conditions are met:
*
*  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
*  disclaimer.
*
*  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
*  disclaimer in the documentation and/or other materials provided with the distribution.
*
*  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote products
*  derived from this software without specific prior written permission from the respective party.
*
*  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative works
*  may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without specific prior
*  written permission from Alliance for Sustainable Energy, LLC.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
*  STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
*  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
*  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************************************************************/

#include "CoilCoolingDXCurveFitOperatingMode.hpp"
#include "CoilCoolingDXCurveFitOperatingMode_Impl.hpp"

#include "Model.hpp"
#include "Model_Impl.hpp"
#include "CoilCoolingDXCurveFitPerformance.hpp"
#include "CoilCoolingDXCurveFitPerformance_Impl.hpp"
#include "CoilCoolingDXCurveFitSpeed.hpp"
#include "CoilCoolingDXCurveFitSpeed_Impl.hpp"

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_Coil_Cooling_DX_CurveFit_OperatingMode_FieldEnums.hxx>
#include "../utilities/units/Unit.hpp"
#include "../utilities/core/Assert.hpp"
#include "../utilities/idf/WorkspaceExtensibleGroup.hpp"

namespace openstudio {
namespace model {

namespace detail {

  CoilCoolingDXCurveFitOperatingMode_Impl::CoilCoolingDXCurveFitOperatingMode_Impl(const IdfObject& idfObject,
                                                                                   Model_Impl* model,
                                                                                   bool keepHandle)
    : ResourceObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == CoilCoolingDXCurveFitOperatingMode::iddObjectType());
  }

  CoilCoolingDXCurveFitOperatingMode_Impl::CoilCoolingDXCurveFitOperatingMode_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                   Model_Impl* model,
                                                                                   bool keepHandle)
    : ResourceObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == CoilCoolingDXCurveFitOperatingMode::iddObjectType());
  }

  CoilCoolingDXCurveFitOperatingMode_Impl::CoilCoolingDXCurveFitOperatingMode_Impl(const CoilCoolingDXCurveFitOperatingMode_Impl& other,
                                                                                   Model_Impl* model,
                                                                                   bool keepHandle)
    : ResourceObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& CoilCoolingDXCurveFitOperatingMode_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType CoilCoolingDXCurveFitOperatingMode_Impl::iddObjectType() const {
    return CoilCoolingDXCurveFitOperatingMode::iddObjectType();
  }

  ModelObject CoilCoolingDXCurveFitOperatingMode_Impl::clone(Model model) const {
    auto t_clone = ModelObject_Impl::clone(model).cast<CoilCoolingDXCurveFitOperatingMode>();

    auto t_speeds = speeds();
    for( auto speed: t_speeds ) {
      auto speedClone = speed.clone(model).cast<CoilCoolingDXCurveFitSpeed>();
      t_clone.addSpeed(speedClone);
    }
    return t_clone;
  }

  std::vector<ModelObject> CoilCoolingDXCurveFitOperatingMode_Impl::children() const {
    std::vector<ModelObject> result = subsetCastVector<ModelObject>(speeds());

    return result;
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::ratedGrossTotalCoolingCapacity() const {
    return getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedGrossTotalCoolingCapacity,true);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::isRatedGrossTotalCoolingCapacityAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedGrossTotalCoolingCapacity, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::ratedEvaporatorAirFlowRate() const {
    return getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedEvaporatorAirFlowRate,true);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::isRatedEvaporatorAirFlowRateAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedEvaporatorAirFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::ratedCondenserAirFlowRate() const {
    return getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedCondenserAirFlowRate,true);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::isRatedCondenserAirFlowRateAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedCondenserAirFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  double CoilCoolingDXCurveFitOperatingMode_Impl::maximumCyclingRate() const {
    boost::optional<double> value = getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::MaximumCyclingRate,true);
    OS_ASSERT(value);
    return value.get();
  }

  double CoilCoolingDXCurveFitOperatingMode_Impl::ratioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity() const {
    boost::optional<double> value = getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity,true);
    OS_ASSERT(value);
    return value.get();
  }

  double CoilCoolingDXCurveFitOperatingMode_Impl::latentCapacityTimeConstant() const {
    boost::optional<double> value = getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::LatentCapacityTimeConstant,true);
    OS_ASSERT(value);
    return value.get();
  }

  double CoilCoolingDXCurveFitOperatingMode_Impl::nominalTimeforCondensateRemovaltoBegin() const {
    boost::optional<double> value = getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalTimeforCondensateRemovaltoBegin,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::applyLatentDegradationtoSpeedsGreaterthan1() const {
    boost::optional<std::string> value = getString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::ApplyLatentDegradationtoSpeedsGreaterthan1,true);
    OS_ASSERT(value);
    return openstudio::istringEqual(value.get(), "Yes");
  }

  std::string CoilCoolingDXCurveFitOperatingMode_Impl::condenserType() const {
    boost::optional<std::string> value = getString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::CondenserType,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::nominalEvaporativeCondenserPumpPower() const {
    return getDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalEvaporativeCondenserPumpPower,true);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::isNominalEvaporativeCondenserPumpPowerAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalEvaporativeCondenserPumpPower, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  unsigned CoilCoolingDXCurveFitOperatingMode_Impl::numberOfSpeeds() const {
    return numExtensibleGroups();
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::isNominalSpeedNumberDefaulted() const {
    return isEmpty(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalSpeedNumber);
  }

  unsigned CoilCoolingDXCurveFitOperatingMode_Impl::nominalSpeedNumber() const {
    if (isNominalSpeedNumberDefaulted()) {
      return numberOfSpeeds();
    } else {
      boost::optional<int> nominalSpeedNumber = getInt(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalSpeedNumber, false);
      OS_ASSERT(nominalSpeedNumber);
      return static_cast<unsigned>(nominalSpeedNumber.get());
    }
  }

  std::vector<CoilCoolingDXCurveFitPerformance> CoilCoolingDXCurveFitOperatingMode_Impl::coilCoolingDXCurveFitPerformances() const {
    return getObject<ModelObject>().getModelObjectSources<CoilCoolingDXCurveFitPerformance>(CoilCoolingDXCurveFitPerformance::iddObjectType());
  }

  std::vector<CoilCoolingDXCurveFitSpeed> CoilCoolingDXCurveFitOperatingMode_Impl::speeds() const {
    std::vector<CoilCoolingDXCurveFitSpeed> result;
    auto groups = extensibleGroups();
    for( auto group: groups ) {
      auto target = group.cast<WorkspaceExtensibleGroup>().getTarget(OS_Coil_Cooling_DX_CurveFit_OperatingModeExtensibleFields::Speed);
      if( target ) {
        if( auto speed = target->optionalCast<CoilCoolingDXCurveFitSpeed>() ) {
          result.push_back(speed.get());
        }
      }
    }
    return result;
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setRatedGrossTotalCoolingCapacity(double ratedGrossTotalCoolingCapacity) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedGrossTotalCoolingCapacity, ratedGrossTotalCoolingCapacity);
    return result;
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::autosizeRatedGrossTotalCoolingCapacity() {
    bool result = setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedGrossTotalCoolingCapacity, "autosize");
    OS_ASSERT(result);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setRatedEvaporatorAirFlowRate(double ratedEvaporatorAirFlowRate) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedEvaporatorAirFlowRate, ratedEvaporatorAirFlowRate);
    return result;
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::autosizeRatedEvaporatorAirFlowRate() {
    bool result = setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedEvaporatorAirFlowRate, "autosize");
    OS_ASSERT(result);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setRatedCondenserAirFlowRate(double ratedCondenserAirFlowRate) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedCondenserAirFlowRate, ratedCondenserAirFlowRate);
    return result;
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::autosizeRatedCondenserAirFlowRate() {
    bool result = setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatedCondenserAirFlowRate, "autosize");
    OS_ASSERT(result);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setMaximumCyclingRate(double maximumCyclingRate) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::MaximumCyclingRate, maximumCyclingRate);
    return result;
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setRatioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity(double ratioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::RatioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity, ratioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity);
    return result;
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setLatentCapacityTimeConstant(double latentCapacityTimeConstant) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::LatentCapacityTimeConstant, latentCapacityTimeConstant);
    return result;
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setNominalTimeforCondensateRemovaltoBegin(double nominalTimeforCondensateRemovaltoBegin) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalTimeforCondensateRemovaltoBegin, nominalTimeforCondensateRemovaltoBegin);
    return result;
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setApplyLatentDegradationtoSpeedsGreaterthan1(bool applyLatentDegradationtoSpeedsGreaterthan1) {
    if (applyLatentDegradationtoSpeedsGreaterthan1) {
      return setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::ApplyLatentDegradationtoSpeedsGreaterthan1, "Yes");
    } else {
      return setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::ApplyLatentDegradationtoSpeedsGreaterthan1, "No");
    }
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setCondenserType(const std::string& condenserType) {
    bool result = setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::CondenserType, condenserType);
    return result;
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setNominalEvaporativeCondenserPumpPower(double nominalEvaporativeCondenserPumpPower) {
    bool result = setDouble(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalEvaporativeCondenserPumpPower, nominalEvaporativeCondenserPumpPower);
    return result;
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::autosizeNominalEvaporativeCondenserPumpPower() {
    bool result = setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalEvaporativeCondenserPumpPower, "autosize");
    OS_ASSERT(result);
  }

  bool CoilCoolingDXCurveFitOperatingMode_Impl::setNominalSpeedNumber(unsigned nominalSpeedNumber) {
    unsigned nSpeeds = numberOfSpeeds();
    if (nominalSpeedNumber > nSpeeds) {
      LOG(Warn, "For " << briefDescription() << ", cannot set a nominalSpeedNumber (=" << nominalSpeedNumber
             << ") greater than the number of speeds (=" << nSpeeds << ").");
      return false;
    }

    bool result = setInt(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalSpeedNumber, nominalSpeedNumber);
    return result;
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::resetNominalSpeedNumber() {
    bool result = setString(OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::NominalSpeedNumber, "");
    OS_ASSERT(result);
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::addSpeed(CoilCoolingDXCurveFitSpeed& speed) {
    auto group = getObject<ModelObject>().pushExtensibleGroup().cast<WorkspaceExtensibleGroup>();
    OS_ASSERT(!group.empty());
    group.setPointer(OS_Coil_Cooling_DX_CurveFit_OperatingModeExtensibleFields::Speed,speed.handle());
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::autosizedRatedGrossTotalCoolingCapacity() {
    return getAutosizedValue("TODO_CHECK_SQL Rated Gross Total Cooling Capacity", "W");
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::autosizedRatedEvaporatorAirFlowRate() {
    return getAutosizedValue("TODO_CHECK_SQL Rated Evaporator Air Flow Rate", "m3/s");
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::autosizedRatedCondenserAirFlowRate() {
    return getAutosizedValue("TODO_CHECK_SQL Rated Condenser Air Flow Rate", "m3/s");
  }

  boost::optional<double> CoilCoolingDXCurveFitOperatingMode_Impl::autosizedNominalEvaporativeCondenserPumpPower() {
    return getAutosizedValue("TODO_CHECK_SQL Nominal Evaporative Condenser Pump Power", "W");
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::autosize() {
    autosizeRatedGrossTotalCoolingCapacity();
    autosizeRatedEvaporatorAirFlowRate();
    autosizeRatedCondenserAirFlowRate();
    autosizeNominalEvaporativeCondenserPumpPower();
  }

  void CoilCoolingDXCurveFitOperatingMode_Impl::applySizingValues() {
    boost::optional<double> val;
    val = autosizedRatedGrossTotalCoolingCapacity();
    if (val) {
      setRatedGrossTotalCoolingCapacity(val.get());
    }

    val = autosizedRatedEvaporatorAirFlowRate();
    if (val) {
      setRatedEvaporatorAirFlowRate(val.get());
    }

    val = autosizedRatedCondenserAirFlowRate();
    if (val) {
      setRatedCondenserAirFlowRate(val.get());
    }

    val = autosizedNominalEvaporativeCondenserPumpPower();
    if (val) {
      setNominalEvaporativeCondenserPumpPower(val.get());
    }

  }

} // detail

CoilCoolingDXCurveFitOperatingMode::CoilCoolingDXCurveFitOperatingMode(const Model& model)
  : ResourceObject(CoilCoolingDXCurveFitOperatingMode::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>());

  autosizeRatedGrossTotalCoolingCapacity();
  autosizeRatedEvaporatorAirFlowRate();
  autosizeRatedCondenserAirFlowRate();
  setMaximumCyclingRate(0.0);
  setRatioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity(0.0);
  setLatentCapacityTimeConstant(0.0);
  setNominalTimeforCondensateRemovaltoBegin(0.0);
  setApplyLatentDegradationtoSpeedsGreaterthan1(false);
  setCondenserType("AirCooled");
  autosizeNominalEvaporativeCondenserPumpPower();
}

IddObjectType CoilCoolingDXCurveFitOperatingMode::iddObjectType() {
  return IddObjectType(IddObjectType::OS_Coil_Cooling_DX_CurveFit_OperatingMode);
}

std::vector<std::string> CoilCoolingDXCurveFitOperatingMode::condenserTypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_Coil_Cooling_DX_CurveFit_OperatingModeFields::CondenserType);
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::ratedGrossTotalCoolingCapacity() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->ratedGrossTotalCoolingCapacity();
}

bool CoilCoolingDXCurveFitOperatingMode::isRatedGrossTotalCoolingCapacityAutosized() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->isRatedGrossTotalCoolingCapacityAutosized();
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::ratedEvaporatorAirFlowRate() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->ratedEvaporatorAirFlowRate();
}

bool CoilCoolingDXCurveFitOperatingMode::isRatedEvaporatorAirFlowRateAutosized() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->isRatedEvaporatorAirFlowRateAutosized();
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::ratedCondenserAirFlowRate() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->ratedCondenserAirFlowRate();
}

bool CoilCoolingDXCurveFitOperatingMode::isRatedCondenserAirFlowRateAutosized() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->isRatedCondenserAirFlowRateAutosized();
}

double CoilCoolingDXCurveFitOperatingMode::maximumCyclingRate() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->maximumCyclingRate();
}

double CoilCoolingDXCurveFitOperatingMode::ratioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->ratioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity();
}

double CoilCoolingDXCurveFitOperatingMode::latentCapacityTimeConstant() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->latentCapacityTimeConstant();
}

double CoilCoolingDXCurveFitOperatingMode::nominalTimeforCondensateRemovaltoBegin() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->nominalTimeforCondensateRemovaltoBegin();
}

bool CoilCoolingDXCurveFitOperatingMode::applyLatentDegradationtoSpeedsGreaterthan1() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->applyLatentDegradationtoSpeedsGreaterthan1();
}

std::string CoilCoolingDXCurveFitOperatingMode::condenserType() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->condenserType();
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::nominalEvaporativeCondenserPumpPower() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->nominalEvaporativeCondenserPumpPower();
}

bool CoilCoolingDXCurveFitOperatingMode::isNominalEvaporativeCondenserPumpPowerAutosized() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->isNominalEvaporativeCondenserPumpPowerAutosized();
}

bool CoilCoolingDXCurveFitOperatingMode::isNominalSpeedNumberDefaulted() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->isNominalSpeedNumberDefaulted();
}

unsigned CoilCoolingDXCurveFitOperatingMode::nominalSpeedNumber() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->nominalSpeedNumber();
}

std::vector<CoilCoolingDXCurveFitPerformance> CoilCoolingDXCurveFitOperatingMode::coilCoolingDXCurveFitPerformances() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->coilCoolingDXCurveFitPerformances();
}

std::vector<CoilCoolingDXCurveFitSpeed> CoilCoolingDXCurveFitOperatingMode::speeds() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->speeds();
}

bool CoilCoolingDXCurveFitOperatingMode::setRatedGrossTotalCoolingCapacity(double ratedGrossTotalCoolingCapacity) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setRatedGrossTotalCoolingCapacity(ratedGrossTotalCoolingCapacity);
}

void CoilCoolingDXCurveFitOperatingMode::autosizeRatedGrossTotalCoolingCapacity() {
  getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizeRatedGrossTotalCoolingCapacity();
}

bool CoilCoolingDXCurveFitOperatingMode::setRatedEvaporatorAirFlowRate(double ratedEvaporatorAirFlowRate) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setRatedEvaporatorAirFlowRate(ratedEvaporatorAirFlowRate);
}

void CoilCoolingDXCurveFitOperatingMode::autosizeRatedEvaporatorAirFlowRate() {
  getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizeRatedEvaporatorAirFlowRate();
}

bool CoilCoolingDXCurveFitOperatingMode::setRatedCondenserAirFlowRate(double ratedCondenserAirFlowRate) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setRatedCondenserAirFlowRate(ratedCondenserAirFlowRate);
}

void CoilCoolingDXCurveFitOperatingMode::autosizeRatedCondenserAirFlowRate() {
  getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizeRatedCondenserAirFlowRate();
}

bool CoilCoolingDXCurveFitOperatingMode::setMaximumCyclingRate(double maximumCyclingRate) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setMaximumCyclingRate(maximumCyclingRate);
}

bool CoilCoolingDXCurveFitOperatingMode::setRatioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity(double ratioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setRatioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity(ratioofInitialMoistureEvaporationRateandSteadyStateLatentCapacity);
}

bool CoilCoolingDXCurveFitOperatingMode::setLatentCapacityTimeConstant(double latentCapacityTimeConstant) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setLatentCapacityTimeConstant(latentCapacityTimeConstant);
}

bool CoilCoolingDXCurveFitOperatingMode::setNominalTimeforCondensateRemovaltoBegin(double nominalTimeforCondensateRemovaltoBegin) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setNominalTimeforCondensateRemovaltoBegin(nominalTimeforCondensateRemovaltoBegin);
}

bool CoilCoolingDXCurveFitOperatingMode::setApplyLatentDegradationtoSpeedsGreaterthan1(bool applyLatentDegradationtoSpeedsGreaterthan1) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setApplyLatentDegradationtoSpeedsGreaterthan1(applyLatentDegradationtoSpeedsGreaterthan1);
}

bool CoilCoolingDXCurveFitOperatingMode::setCondenserType(const std::string& condenserType) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setCondenserType(condenserType);
}

bool CoilCoolingDXCurveFitOperatingMode::setNominalEvaporativeCondenserPumpPower(double nominalEvaporativeCondenserPumpPower) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setNominalEvaporativeCondenserPumpPower(nominalEvaporativeCondenserPumpPower);
}

void CoilCoolingDXCurveFitOperatingMode::autosizeNominalEvaporativeCondenserPumpPower() {
  getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizeNominalEvaporativeCondenserPumpPower();
}

bool CoilCoolingDXCurveFitOperatingMode::setNominalSpeedNumber(unsigned nominalSpeedNumber) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->setNominalSpeedNumber(nominalSpeedNumber);
}

void CoilCoolingDXCurveFitOperatingMode::resetNominalSpeedNumber() {
  getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->resetNominalSpeedNumber();
}

void CoilCoolingDXCurveFitOperatingMode::addSpeed(CoilCoolingDXCurveFitSpeed& speed) {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->addSpeed(speed);
}

unsigned CoilCoolingDXCurveFitOperatingMode::numberOfSpeeds() const {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->numberOfSpeeds();
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::autosizedRatedGrossTotalCoolingCapacity() {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizedRatedGrossTotalCoolingCapacity();
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::autosizedRatedEvaporatorAirFlowRate() {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizedRatedEvaporatorAirFlowRate();
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::autosizedRatedCondenserAirFlowRate() {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizedRatedCondenserAirFlowRate();
}

boost::optional<double> CoilCoolingDXCurveFitOperatingMode::autosizedNominalEvaporativeCondenserPumpPower() {
  return getImpl<detail::CoilCoolingDXCurveFitOperatingMode_Impl>()->autosizedNominalEvaporativeCondenserPumpPower();
}

void CoilCoolingDXCurveFitOperatingMode::autosize() {
  return getImpl<detail::CoilCoolingDXCurveFitSpeed_Impl>()->autosize();
}

void CoilCoolingDXCurveFitOperatingMode::applySizingValues() {
  return getImpl<detail::CoilCoolingDXCurveFitSpeed_Impl>()->applySizingValues();
}

/// @cond
CoilCoolingDXCurveFitOperatingMode::CoilCoolingDXCurveFitOperatingMode(std::shared_ptr<detail::CoilCoolingDXCurveFitOperatingMode_Impl> impl)
  : ResourceObject(impl)
{}
/// @endcond

} // model
} // openstudio

