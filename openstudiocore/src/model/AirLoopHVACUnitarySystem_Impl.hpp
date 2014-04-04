/**********************************************************************
 *  Copyright (c) 2008-2014, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef MODEL_AIRLOOPHVACUNITARYSYSTEM_IMPL_HPP
#define MODEL_AIRLOOPHVACUNITARYSYSTEM_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject_Impl.hpp>

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class ThermalZone;
class Schedule;
class Connection;
class Connection;
class FansCVandOnOffandVAV;
class Schedule;
class HeatingCoilsDX;
class CoolingCoilsDX;
class HeatingCoilName;
class Connection;
class Connection;
class UnitarySystemPerformace;

namespace detail {

  /** AirLoopHVACUnitarySystem_Impl is a ModelObject_Impl that is the implementation class for AirLoopHVACUnitarySystem.*/
  class MODEL_API AirLoopHVACUnitarySystem_Impl : public ModelObject_Impl {
    Q_OBJECT;
   public:
    /** @name Constructors and Destructors */
    //@{

    AirLoopHVACUnitarySystem_Impl(const IdfObject& idfObject,
                                  Model_Impl* model,
                                  bool keepHandle);

    AirLoopHVACUnitarySystem_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                  Model_Impl* model,
                                  bool keepHandle);

    AirLoopHVACUnitarySystem_Impl(const AirLoopHVACUnitarySystem_Impl& other,
                                  Model_Impl* model,
                                  bool keepHandle);

    virtual ~AirLoopHVACUnitarySystem_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const;

    //@}
    /** @name Getters */
    //@{

    std::string controlType() const;

    bool isControlTypeDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: ThermalZone.
    boost::optional<ThermalZone> controllingZoneorThermostatLocation() const;

    std::string dehumidificationControlType() const;

    bool isDehumidificationControlTypeDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: Schedule.
    boost::optional<Schedule> availabilitySchedule() const;

    // TODO: Check return type. From object lists, some candidates are: Connection.
    Connection airInletNode() const;

    // TODO: Check return type. From object lists, some candidates are: Connection.
    Connection airOutletNode() const;

    // TODO: Check return type. From object lists, some candidates are: FansCVandOnOffandVAV.
    boost::optional<FansCVandOnOffandVAV> supplyFan() const;

    boost::optional<std::string> fanPlacement() const;

    // TODO: Check return type. From object lists, some candidates are: Schedule.
    boost::optional<Schedule> supplyAirFanOperatingModeSchedule() const;

    // TODO: Check return type. From object lists, some candidates are: HeatingCoilsDX, HeatingCoilsDXMultiSpeed, HeatingCoilsDXVariableSpeed, HeatingCoilsWaterToAirHP, HeatingCoilsWaterToAirVSHP, HeatingCoilName, HeatingCoilsElectricMultiStage, HeatingCoilsGasMultiStage, HeatingCoilsDesuperheater.
    boost::optional<HeatingCoilsDX> heatingCoil() const;

    double dXHeatingCoilSizingRatio() const;

    bool isDXHeatingCoilSizingRatioDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: CoolingCoilsDX, CoolingCoilsDXMultiSpeed, CoolingCoilsDXVariableSpeed, CoolingCoilsWaterToAirHP, CoolingCoilsWaterToAirVSHP, CoolingCoilsWater.
    boost::optional<CoolingCoilsDX> coolingCoil() const;

    bool useDOASDXCoolingCoil() const;

    bool isUseDOASDXCoolingCoilDefaulted() const;

    double dOASDXCoolingCoilLeavingMinimumAirTemperature() const;

    bool isDOASDXCoolingCoilLeavingMinimumAirTemperatureDefaulted() const;

    std::string latentLoadControl() const;

    bool isLatentLoadControlDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: HeatingCoilName, HeatingCoilsDesuperheater.
    boost::optional<HeatingCoilName> supplementalHeatingCoil() const;

    boost::optional<std::string> supplyAirFlowRateMethodDuringCoolingOperation() const;

    boost::optional<double> supplyAirFlowRateDuringCoolingOperation() const;

    bool isSupplyAirFlowRateDuringCoolingOperationAutosized() const;

    boost::optional<double> supplyAirFlowRatePerFloorAreaDuringCoolingOperation() const;

    boost::optional<double> fractionofAutosizedDesignCoolingSupplyAirFlowRate() const;

    boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperation() const;

    boost::optional<std::string> supplyAirFlowRateMethodDuringHeatingOperation() const;

    boost::optional<double> supplyAirFlowRateDuringHeatingOperation() const;

    bool isSupplyAirFlowRateDuringHeatingOperationAutosized() const;

    boost::optional<double> supplyAirFlowRatePerFloorAreaduringHeatingOperation() const;

    boost::optional<double> fractionofAutosizedDesignHeatingSupplyAirFlowRate() const;

    boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperation() const;

    boost::optional<std::string> supplyAirFlowRateMethodWhenNoCoolingorHeatingisRequired() const;

    boost::optional<double> supplyAirFlowRateWhenNoCoolingorHeatingisRequired() const;

    bool isSupplyAirFlowRateWhenNoCoolingorHeatingisRequiredAutosized() const;

    boost::optional<double> supplyAirFlowRatePerFloorAreaWhenNoCoolingorHeatingisRequired() const;

    boost::optional<double> fractionofAutosizedDesignCoolingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired() const;

    boost::optional<double> fractionofAutosizedDesignHeatingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired() const;

    boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperationWhenNoCoolingorHeatingisRequired() const;

    boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperationWhenNoCoolingorHeatingisRequired() const;

    boost::optional<double> maximumSupplyAirTemperature() const;

    bool isMaximumSupplyAirTemperatureDefaulted() const;

    bool isMaximumSupplyAirTemperatureAutosized() const;

    double maximumOutdoorDryBulbTemperatureforSupplementalHeaterOperation() const;

    bool isMaximumOutdoorDryBulbTemperatureforSupplementalHeaterOperationDefaulted() const;

    boost::optional<std::string> outdoorDryBulbTemperatureSensorNodeName() const;

    double maximumCyclingRate() const;

    bool isMaximumCyclingRateDefaulted() const;

    double heatPumpTimeConstant() const;

    bool isHeatPumpTimeConstantDefaulted() const;

    double fractionofOnCyclePowerUse() const;

    bool isFractionofOnCyclePowerUseDefaulted() const;

    double heatPumpFanDelayTime() const;

    bool isHeatPumpFanDelayTimeDefaulted() const;

    double ancilliaryOnCycleElectricPower() const;

    bool isAncilliaryOnCycleElectricPowerDefaulted() const;

    double ancilliaryOffCycleElectricPower() const;

    bool isAncilliaryOffCycleElectricPowerDefaulted() const;

    double designHeatRecoveryWaterFlowRate() const;

    bool isDesignHeatRecoveryWaterFlowRateDefaulted() const;

    double maximumTemperatureforHeatRecovery() const;

    bool isMaximumTemperatureforHeatRecoveryDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: Connection.
    boost::optional<Connection> heatRecoveryWaterInletNode() const;

    // TODO: Check return type. From object lists, some candidates are: Connection.
    boost::optional<Connection> heatRecoveryWaterOutletNode() const;

    // TODO: Check return type. From object lists, some candidates are: UnitarySystemPerformace.
    boost::optional<UnitarySystemPerformace> designSpecificationMultispeedHeatPumpObject() const;

    //@}
    /** @name Setters */
    //@{

    bool setControlType(std::string controlType);

    void resetControlType();

    // TODO: Check argument type. From object lists, some candidates are: ThermalZone.
    bool setControllingZoneorThermostatLocation(const boost::optional<ThermalZone>& thermalZone);

    void resetControllingZoneorThermostatLocation();

    bool setDehumidificationControlType(std::string dehumidificationControlType);

    void resetDehumidificationControlType();

    // TODO: Check argument type. From object lists, some candidates are: Schedule.
    bool setAvailabilitySchedule(Schedule& schedule);

    void resetAvailabilitySchedule();

    // TODO: Check argument type. From object lists, some candidates are: Connection.
    bool setAirInletNode(const Connection& connection);

    // TODO: Check argument type. From object lists, some candidates are: Connection.
    bool setAirOutletNode(const Connection& connection);

    // TODO: Check argument type. From object lists, some candidates are: FansCVandOnOffandVAV.
    bool setSupplyFan(const boost::optional<FansCVandOnOffandVAV>& fansCVandOnOffandVAV);

    void resetSupplyFan();

    bool setFanPlacement(boost::optional<std::string> fanPlacement);

    void resetFanPlacement();

    // TODO: Check argument type. From object lists, some candidates are: Schedule.
    bool setSupplyAirFanOperatingModeSchedule(Schedule& schedule);

    void resetSupplyAirFanOperatingModeSchedule();

    // TODO: Check argument type. From object lists, some candidates are: HeatingCoilsDX, HeatingCoilsDXMultiSpeed, HeatingCoilsDXVariableSpeed, HeatingCoilsWaterToAirHP, HeatingCoilsWaterToAirVSHP, HeatingCoilName, HeatingCoilsElectricMultiStage, HeatingCoilsGasMultiStage, HeatingCoilsDesuperheater.
    bool setHeatingCoil(const boost::optional<HeatingCoilsDX>& heatingCoilsDX);

    void resetHeatingCoil();

    bool setDXHeatingCoilSizingRatio(double dXHeatingCoilSizingRatio);

    void resetDXHeatingCoilSizingRatio();

    // TODO: Check argument type. From object lists, some candidates are: CoolingCoilsDX, CoolingCoilsDXMultiSpeed, CoolingCoilsDXVariableSpeed, CoolingCoilsWaterToAirHP, CoolingCoilsWaterToAirVSHP, CoolingCoilsWater.
    bool setCoolingCoil(const boost::optional<CoolingCoilsDX>& coolingCoilsDX);

    void resetCoolingCoil();

    void setUseDOASDXCoolingCoil(bool useDOASDXCoolingCoil);

    void resetUseDOASDXCoolingCoil();

    bool setDOASDXCoolingCoilLeavingMinimumAirTemperature(double dOASDXCoolingCoilLeavingMinimumAirTemperature);

    void resetDOASDXCoolingCoilLeavingMinimumAirTemperature();

    bool setLatentLoadControl(std::string latentLoadControl);

    void resetLatentLoadControl();

    // TODO: Check argument type. From object lists, some candidates are: HeatingCoilName, HeatingCoilsDesuperheater.
    bool setSupplementalHeatingCoil(const boost::optional<HeatingCoilName>& heatingCoilName);

    void resetSupplementalHeatingCoil();

    bool setSupplyAirFlowRateMethodDuringCoolingOperation(boost::optional<std::string> supplyAirFlowRateMethodDuringCoolingOperation);

    void resetSupplyAirFlowRateMethodDuringCoolingOperation();

    bool setSupplyAirFlowRateDuringCoolingOperation(boost::optional<double> supplyAirFlowRateDuringCoolingOperation);

    void resetSupplyAirFlowRateDuringCoolingOperation();

    void autosizeSupplyAirFlowRateDuringCoolingOperation();

    bool setSupplyAirFlowRatePerFloorAreaDuringCoolingOperation(boost::optional<double> supplyAirFlowRatePerFloorAreaDuringCoolingOperation);

    void resetSupplyAirFlowRatePerFloorAreaDuringCoolingOperation();

    bool setFractionofAutosizedDesignCoolingSupplyAirFlowRate(boost::optional<double> fractionofAutosizedDesignCoolingSupplyAirFlowRate);

    void resetFractionofAutosizedDesignCoolingSupplyAirFlowRate();

    bool setDesignSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperation(boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperation);

    void resetDesignSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperation();

    bool setSupplyAirFlowRateMethodDuringHeatingOperation(boost::optional<std::string> supplyAirFlowRateMethodDuringHeatingOperation);

    void resetSupplyAirFlowRateMethodDuringHeatingOperation();

    bool setSupplyAirFlowRateDuringHeatingOperation(boost::optional<double> supplyAirFlowRateDuringHeatingOperation);

    void resetSupplyAirFlowRateDuringHeatingOperation();

    void autosizeSupplyAirFlowRateDuringHeatingOperation();

    bool setSupplyAirFlowRatePerFloorAreaduringHeatingOperation(boost::optional<double> supplyAirFlowRatePerFloorAreaduringHeatingOperation);

    void resetSupplyAirFlowRatePerFloorAreaduringHeatingOperation();

    bool setFractionofAutosizedDesignHeatingSupplyAirFlowRate(boost::optional<double> fractionofAutosizedDesignHeatingSupplyAirFlowRate);

    void resetFractionofAutosizedDesignHeatingSupplyAirFlowRate();

    bool setDesignSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperation(boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperation);

    void resetDesignSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperation();

    bool setSupplyAirFlowRateMethodWhenNoCoolingorHeatingisRequired(boost::optional<std::string> supplyAirFlowRateMethodWhenNoCoolingorHeatingisRequired);

    void resetSupplyAirFlowRateMethodWhenNoCoolingorHeatingisRequired();

    bool setSupplyAirFlowRateWhenNoCoolingorHeatingisRequired(boost::optional<double> supplyAirFlowRateWhenNoCoolingorHeatingisRequired);

    void resetSupplyAirFlowRateWhenNoCoolingorHeatingisRequired();

    void autosizeSupplyAirFlowRateWhenNoCoolingorHeatingisRequired();

    bool setSupplyAirFlowRatePerFloorAreaWhenNoCoolingorHeatingisRequired(boost::optional<double> supplyAirFlowRatePerFloorAreaWhenNoCoolingorHeatingisRequired);

    void resetSupplyAirFlowRatePerFloorAreaWhenNoCoolingorHeatingisRequired();

    bool setFractionofAutosizedDesignCoolingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired(boost::optional<double> fractionofAutosizedDesignCoolingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired);

    void resetFractionofAutosizedDesignCoolingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired();

    bool setFractionofAutosizedDesignHeatingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired(boost::optional<double> fractionofAutosizedDesignHeatingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired);

    void resetFractionofAutosizedDesignHeatingSupplyAirFlowRateWhenNoCoolingorHeatingisRequired();

    bool setDesignSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperationWhenNoCoolingorHeatingisRequired(boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperationWhenNoCoolingorHeatingisRequired);

    void resetDesignSupplyAirFlowRatePerUnitofCapacityDuringCoolingOperationWhenNoCoolingorHeatingisRequired();

    bool setDesignSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperationWhenNoCoolingorHeatingisRequired(boost::optional<double> designSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperationWhenNoCoolingorHeatingisRequired);

    void resetDesignSupplyAirFlowRatePerUnitofCapacityDuringHeatingOperationWhenNoCoolingorHeatingisRequired();

    void setMaximumSupplyAirTemperature(boost::optional<double> maximumSupplyAirTemperature);

    void resetMaximumSupplyAirTemperature();

    void autosizeMaximumSupplyAirTemperature();

    void setMaximumOutdoorDryBulbTemperatureforSupplementalHeaterOperation(double maximumOutdoorDryBulbTemperatureforSupplementalHeaterOperation);

    void resetMaximumOutdoorDryBulbTemperatureforSupplementalHeaterOperation();

    void setOutdoorDryBulbTemperatureSensorNodeName(boost::optional<std::string> outdoorDryBulbTemperatureSensorNodeName);

    void resetOutdoorDryBulbTemperatureSensorNodeName();

    bool setMaximumCyclingRate(double maximumCyclingRate);

    void resetMaximumCyclingRate();

    bool setHeatPumpTimeConstant(double heatPumpTimeConstant);

    void resetHeatPumpTimeConstant();

    bool setFractionofOnCyclePowerUse(double fractionofOnCyclePowerUse);

    void resetFractionofOnCyclePowerUse();

    bool setHeatPumpFanDelayTime(double heatPumpFanDelayTime);

    void resetHeatPumpFanDelayTime();

    bool setAncilliaryOnCycleElectricPower(double ancilliaryOnCycleElectricPower);

    void resetAncilliaryOnCycleElectricPower();

    bool setAncilliaryOffCycleElectricPower(double ancilliaryOffCycleElectricPower);

    void resetAncilliaryOffCycleElectricPower();

    bool setDesignHeatRecoveryWaterFlowRate(double designHeatRecoveryWaterFlowRate);

    void resetDesignHeatRecoveryWaterFlowRate();

    bool setMaximumTemperatureforHeatRecovery(double maximumTemperatureforHeatRecovery);

    void resetMaximumTemperatureforHeatRecovery();

    // TODO: Check argument type. From object lists, some candidates are: Connection.
    bool setHeatRecoveryWaterInletNode(const boost::optional<Connection>& connection);

    void resetHeatRecoveryWaterInletNode();

    // TODO: Check argument type. From object lists, some candidates are: Connection.
    bool setHeatRecoveryWaterOutletNode(const boost::optional<Connection>& connection);

    void resetHeatRecoveryWaterOutletNode();

    // TODO: Check argument type. From object lists, some candidates are: UnitarySystemPerformace.
    bool setDesignSpecificationMultispeedHeatPumpObject(const boost::optional<UnitarySystemPerformace>& unitarySystemPerformace);

    void resetDesignSpecificationMultispeedHeatPumpObject();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.AirLoopHVACUnitarySystem");

    // TODO: Check the return types of these methods.
    // Optional getters for use by methods like children() so can remove() if the constructor fails.
    // There are other ways for the public versions of these getters to fail--perhaps all required
    // objects should be returned as boost::optionals
    boost::optional<Connection> optionalAirInletNode() const;
    boost::optional<Connection> optionalAirOutletNode() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_AIRLOOPHVACUNITARYSYSTEM_IMPL_HPP

